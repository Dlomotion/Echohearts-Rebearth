# CI Templates

Files in this directory are **inactive reference templates**. They are not GitHub Actions workflows until intentionally moved under `.github/workflows/` after their dependencies and security assumptions are verified.

For the UE5.8 template, verify first:
- canonical `.uproject` path;
- Unreal 5.8 installation path on the runner;
- runner labels and isolation;
- Git LFS availability;
- trusted/manual or protected-branch trigger policy;
- least-privilege GitHub token permissions;
- artifact storage/retention plan.
