# UE5.8 CI Activation Gate

The build workflow remains a template until all are true:
- canonical `.uproject` path exists;
- canonical module/target files exist;
- UE5.8 toolchain path is verified on runner;
- Git LFS is installed and fresh-clone tested;
- trusted-runner security policy is implemented;
- Development build/cook/package command succeeds manually once;
- artifact destination and retention are defined.

Only then move the template into `.github/workflows/` and enable protected/manual execution.
