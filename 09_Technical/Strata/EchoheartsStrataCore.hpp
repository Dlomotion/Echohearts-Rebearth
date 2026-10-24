#pragma once
#include <algorithm>
#include <array>
#include <cstdint>

namespace Echohearts::Strata
{
enum class ECraftingTier : uint8_t { Field = 0, Sanctuary = 1, Vanguard = 2 };
enum class ETravelMode : uint8_t { Walk, Ride, Flight };
enum class EDriveKind : uint8_t { None, Field, Sanctuary, Vanguard };

struct FAttributes
{
    float Vibrance = 0.f;
    float Density = 0.f;
    float Harmony = 0.f;
    float Purity = 0.f;
};

inline bool IsValid(const FAttributes& A)
{
    return A.Vibrance >= 0.f && A.Density >= 0.f &&
           A.Harmony >= 0.f && A.Purity >= 0.f;
}

struct FEcoKinBond
{
    bool bBefriended = false;
    bool bPurified = false;
    FAttributes Attributes;
};

struct FHeartDrive
{
    EDriveKind Kind = EDriveKind::None;
    bool bGifted = false;
    bool bEquipped = false;

    bool CanActivate(const FEcoKinBond& Bond) const
    {
        return Kind != EDriveKind::None && bGifted && bEquipped &&
               Bond.bBefriended && IsValid(Bond.Attributes);
    }
};

struct FCoreExtractor
{
    uint8_t UpgradeLevel = 0;
    uint8_t MaximumLevel = 3;

    bool Upgrade(const FAttributes& Available, const FAttributes& Cost)
    {
        if (UpgradeLevel >= MaximumLevel || !IsValid(Available) || !IsValid(Cost))
            return false;
        if (Available.Vibrance < Cost.Vibrance || Available.Density < Cost.Density ||
            Available.Harmony < Cost.Harmony || Available.Purity < Cost.Purity)
            return false;
        ++UpgradeLevel;
        return true; // Caller must atomically deduct the cost from inventory.
    }
};

struct FRadar
{
    float Range = 0.f;
    bool Detect(float Distance, bool bValidSignal) const
    {
        return Range >= 0.f && Distance >= 0.f && Distance <= Range && bValidSignal;
    }
};

struct FEchoShield
{
    float Barrier = 0.f;
    float ImmunityRemainingSeconds = 0.f;

    float ReceiveDamage(float Incoming)
    {
        Incoming = std::max(0.f, Incoming);
        if (ImmunityRemainingSeconds > 0.f) return 0.f;
        const float Absorbed = std::min(std::max(0.f, Barrier), Incoming);
        Barrier = std::max(0.f, Barrier - Absorbed);
        return Incoming - Absorbed;
    }
    void Tick(float DeltaSeconds)
    {
        ImmunityRemainingSeconds =
            std::max(0.f, ImmunityRemainingSeconds - std::max(0.f, DeltaSeconds));
    }
};

struct FGnashtailEncounter
{
    float TaintRemaining = 100.f;
    bool bPurified = false;
    bool bVanguardGiftClaimed = false;

    bool ApplyPurification(float Amount)
    {
        if (bPurified || Amount <= 0.f) return false;
        TaintRemaining = std::max(0.f, TaintRemaining - Amount);
        bPurified = TaintRemaining <= 0.f;
        return bPurified;
    }

    bool ClaimGift(FHeartDrive& OutDrive)
    {
        if (!bPurified || bVanguardGiftClaimed) return false;
        bVanguardGiftClaimed = true;
        OutDrive = { EDriveKind::Vanguard, true, false };
        return true;
    }
};

inline bool CanCraft(ECraftingTier StationTier, ECraftingTier RecipeTier,
                     const FAttributes& Available, const FAttributes& Cost)
{
    return static_cast<uint8_t>(StationTier) >= static_cast<uint8_t>(RecipeTier) &&
           IsValid(Available) && IsValid(Cost) &&
           Available.Vibrance >= Cost.Vibrance && Available.Density >= Cost.Density &&
           Available.Harmony >= Cost.Harmony && Available.Purity >= Cost.Purity;
}
} // namespace Echohearts::Strata
