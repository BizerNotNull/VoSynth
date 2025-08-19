#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

class VoSynthAudioProcessor;

class VoSynthAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    explicit VoSynthAudioProcessorEditor(VoSynthAudioProcessor&);
    ~VoSynthAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    VoSynthAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VoSynthAudioProcessorEditor)
};
