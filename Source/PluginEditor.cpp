#include "PluginEditor.h"
#include "PluginProcessor.h"

VoSynthAudioProcessorEditor::VoSynthAudioProcessorEditor(VoSynthAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(400, 300);
}

VoSynthAudioProcessorEditor::~VoSynthAudioProcessorEditor() = default;

void VoSynthAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void VoSynthAudioProcessorEditor::resized()
{
}
