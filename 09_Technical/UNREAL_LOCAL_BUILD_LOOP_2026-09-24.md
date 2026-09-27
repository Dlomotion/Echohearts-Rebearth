# Corrected Unreal Local Build Loop

1. Work on a scoped feature/fix/infra branch.
2. For structural C++/UHT/module changes, close UE Editor before full rebuild.
3. Run the appropriate UE5.8 build/UHT/test command.
4. Reopen editor and reproduce the target behavior.
5. Run relevant automated/runtime/network tests.
6. Inspect `git status` and `git diff`.
7. Commit only reviewed intended changes.
8. Push branch and open/update PR.
9. Record evidence; do not label VERIFIED without it.

Do not chain `git add . && git commit` directly to a build command. Build success alone does not prove the diff is correct or complete.
