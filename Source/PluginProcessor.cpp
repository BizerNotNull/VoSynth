#include "PluginProcessor.h"
#include "PluginEditor.h"

VoSynthAudioProcessor::VoSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true))
#endif
{
}

VoSynthAudioProcessor::~VoSynthAudioProcessor() = default;

const juce::String VoSynthAudioProcessor::getName() const { return JucePlugin_Name; }

bool VoSynthAudioProcessor::acceptsMidi() const { return JucePlugin_WantsMidiInput; }
bool VoSynthAudioProcessor::producesMidi() const { return JucePlugin_ProducesMidiOutput; }
bool VoSynthAudioProcessor::isMidiEffect() const { return JucePlugin_IsMidiEffect; }
double VoSynthAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int VoSynthAudioProcessor::getNumPrograms() { return 1; }
int VoSynthAudioProcessor::getCurrentProgram() { return 0; }
void VoSynthAudioProcessor::setCurrentProgram(int) {}
const juce::String VoSynthAudioProcessor::getProgramName(int) { return {}; }
void VoSynthAudioProcessor::changeProgramName(int, const juce::String&) {}

void VoSynthAudioProcessor::prepareToPlay(double, int) {}
void VoSynthAudioProcessor::releaseResources() {}

bool VoSynthAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const {
#if ! JucePlugin_IsMidiEffect
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
        && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
#endif
    return true;
}

void VoSynthAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    buffer.clear();
}

bool VoSynthAudioProcessor::hasEditor() const { return true; }
juce::AudioProcessorEditor* VoSynthAudioProcessor::createEditor() { return new VoSynthAudioProcessorEditor (*this); }

void VoSynthAudioProcessor::getStateInformation(juce::MemoryBlock&) {}
void VoSynthAudioProcessor::setStateInformation(const void*, int) {}
