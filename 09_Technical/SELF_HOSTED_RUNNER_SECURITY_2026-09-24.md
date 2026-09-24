# Self-Hosted Runner Security Policy

Status: **SECURITY STANDARD — RUNNER NOT YET VERIFIED**

The repository is public. Do not run untrusted fork/PR code on a personal or persistent self-hosted Unreal build machine.

Minimum policy:
- trusted/manual or protected-branch triggers only;
- isolated dedicated Windows runner, preferably ephemeral/rebuildable;
- no personal credentials in the runner account;
- least-privilege `GITHUB_TOKEN` permissions;
- no production secrets exposed to build jobs unless explicitly required and protected;
- keep runner/OS/UE/toolchain patched;
- clear workspaces/artifacts appropriately between jobs;
- preserve external runner logs if ephemeral infrastructure is used;
- never use `pull_request_target` to execute untrusted checked-out fork code.

GitHub's current security guidance warns that self-hosted runners can be persistently compromised by untrusted workflow code and recommends against unrestricted use with public repositories.
