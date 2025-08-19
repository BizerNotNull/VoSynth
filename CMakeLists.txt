cmake_minimum_required(VERSION 3.15)
project(VoSynth VERSION 0.1.0)

include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        7.0.9
)
FetchContent_MakeAvailable(JUCE)

juce_add_plugin(VoSynth
    COMPANY_NAME "VoSynth"
    PLUGIN_MANUFACTURER_CODE VSyn
    PLUGIN_CODE Vsyn
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    FORMATS VST3
    PRODUCT_NAME "VoSynth")

juce_generate_juce_header(VoSynth)

target_sources(VoSynth PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
)

target_compile_definitions(VoSynth PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
)

target_link_libraries(VoSynth PRIVATE
    juce::juce_audio_utils
)
