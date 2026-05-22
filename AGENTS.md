# Universal AI-Agent Instructions

This file contains universal instructions for AI agents working on the Electric Sheep fork.

## Code Standards
- **Preserve Functionality:** When refactoring, ensure that the existing behavior is not altered unless explicitly fixing a bug.
- **Dependency Management:** Do not add new submodules or external libraries without a clear technical justification. Prefer utilizing existing dependencies (Boost, libcurl, TinyXML, FFmpeg).
- **Commenting:** Add comments only to explain non-obvious logic, architectural decisions, side effects, or workarounds. Do not over-comment obvious code.
- **API Keys & Secrets:** NEVER hardcode, print, log, or commit API keys. Use `.env` or environment variables for local testing.

## Build and Verification
- **Testing:** Always run `make` after making C/C++ changes to verify compilation.
- **Verification:** After compilation, verify the logic if applicable (e.g. by checking logs or running test scripts).
- **Documentation:** Keep `CHANGELOG.md`, `VERSION.md`, `TODO.md`, and `ROADMAP.md` updated as you complete tasks.

## Versioning
- `VERSION.md` is the single source of truth for the project version. When updating the version, make sure to update this file and reference it in the git commit message.

*Note: For model-specific quirks, refer to CLAUDE.md, GEMINI.md, GPT.md, or copilot-instructions.md.*
