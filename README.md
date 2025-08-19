# VoSynth

VoSynth is an experimental additive synthesizer project. The current version provides a minimal JUCE-based VST3 plugin with an empty GUI.

## Building

This project uses CMake and downloads JUCE automatically at configure time.

```bash
cmake -S . -B build
cmake --build build
```

The first command will fetch JUCE from GitHub. The resulting plugin binary will be located in `build/`.
