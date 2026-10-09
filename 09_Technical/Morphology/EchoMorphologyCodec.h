#pragma once
#include "CoreMinimal.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/MemoryWriter.h"
#include "Serialization/Archive.h"
#include "EchoMorphologyTypes.h"

// Binary format: magic, version, UE-serialized payload length, payload, CRC32.
// Untrusted cloud bytes must pass size and checksum checks before decoding.
struct FEchoMorphologyCodec {
 static constexpr uint32 Magic = 0x454B4D31; // EKM1
 static constexpr uint32 Version = 1;
 static constexpr int32 MaxPayloadBytes = 64 * 1024;
 static bool Encode(const FEchoMorphologyState& S, TArray<uint8>& Out) {
  if (!S.IsValid()) return false;
  TArray<uint8> Payload;
  FMemoryWriter W(Payload, true);
  FString Eco = S.EcoKinId.ToString(), Habitat = S.HabitatId.ToString(), Morph = S.MorphologyId.ToString();
  uint8 Tier = static_cast<uint8>(S.GrowthTier), Phen = static_cast<uint8>(S.Phenotype), Band = static_cast<uint8>(S.Overlay);
  W << Eco << Habitat << Morph << Tier << Phen << Band;
  float V=S.Attributes.Vibrance,D=S.Attributes.Density,H=S.Attributes.Harmony,P=S.Attributes.Purity,Scale=S.ScaleMultiplier;
  int32 Revision=S.MutationRevision;
  W << V << D << H << P << Scale << Revision;
  if (W.IsError() || Payload.Num() > MaxPayloadBytes) return false;
  Out.Reset();
  FMemoryWriter O(Out,true);
  uint32 M=Magic, Ver=Version, Size=static_cast<uint32>(Payload.Num()), CRC=FCrc::MemCrc32(Payload.GetData(),Payload.Num());
  O << M << Ver << Size;
  O.Serialize(Payload.GetData(),Payload.Num());
  O << CRC;
  return !O.IsError();
 }
 static bool Decode(const TArray<uint8>& Bytes, FEchoMorphologyState& Result) {
  if (Bytes.Num() < 16 || Bytes.Num() > MaxPayloadBytes + 16) return false;
  FMemoryReader R(Bytes,true);
  uint32 M=0,Ver=0,Size=0;
  R << M << Ver << Size;
  if (R.IsError() || M!=Magic || Ver!=Version || Size>MaxPayloadBytes || static_cast<int64>(Size)+16 != Bytes.Num()) return false;
  TArray<uint8> Payload; Payload.SetNumUninitialized(static_cast<int32>(Size));
  R.Serialize(Payload.GetData(),Payload.Num());
  uint32 CRC=0; R << CRC;
  if (R.IsError() || CRC != FCrc::MemCrc32(Payload.GetData(),Payload.Num())) return false;
  FMemoryReader P(Payload,true);
  FString Eco,Habitat,Morph; uint8 Tier=0,Phen=0,Band=0;
  FEchoMorphologyState Temp;
  P << Eco << Habitat << Morph << Tier << Phen << Band;
  P << Temp.Attributes.Vibrance << Temp.Attributes.Density << Temp.Attributes.Harmony << Temp.Attributes.Purity << Temp.ScaleMultiplier << Temp.MutationRevision;
  if (P.IsError() || P.Tell()!=Payload.Num() || Eco.Len()>128 || Habitat.Len()>128 || Morph.Len()>128) return false;
  Temp.EcoKinId=FName(*Eco); Temp.HabitatId=FName(*Habitat); Temp.MorphologyId=FName(*Morph);
  Temp.GrowthTier=static_cast<EEchoGrowthTier>(Tier);
  Temp.Phenotype=static_cast<EEchoPhenotype>(Phen);
  Temp.Overlay=static_cast<EEchoFrequencyBand>(Band);
  if (!Temp.IsValid()) return false;
  Result=MoveTemp(Temp); return true;
 }
};
