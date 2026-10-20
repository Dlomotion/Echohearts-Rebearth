using System;
namespace Echohearts.Rebearth.Adapter
{
    // Data-only optional Unity prototype. Unreal remains authoritative.
    [Serializable]
    public struct EcoKinEcology
    {
        public float Vibrance, Density, Harmony, Purity;
    }
    [Serializable]
    public sealed class DomainSnapshot
    {
        public int SchemaVersion = 1;
        public string DomainId = "";
        public EcoKinEcology Ecology;
        public bool AquaticHabitatRestored;
        public bool ClinicSupplied;
    }
    public static class DomainValidation
    {
        private static bool Valid(float x) => !float.IsNaN(x) && !float.IsInfinity(x) && x >= 0 && x <= 100;
        public static bool IsValid(DomainSnapshot x) =>
            x != null && x.SchemaVersion == 1 && !string.IsNullOrWhiteSpace(x.DomainId) &&
            Valid(x.Ecology.Vibrance) && Valid(x.Ecology.Density) &&
            Valid(x.Ecology.Harmony) && Valid(x.Ecology.Purity);
    }
}
