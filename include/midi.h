#ifndef MEGAFM_CMAKE_MIDI_H
#define MEGAFM_CMAKE_MIDI_H

void handleAftertouch(byte channel, byte val);
void handleClock();
void handleBendy(byte channel, int bend);
void handleStop();
void handleStart();
void handleProgramChange(byte channel, byte program);
// void handleNoteOn(byte channel, byte note, byte velocity);
// void handleNoteOff(byte channel, byte note, byte velocity);
void sendCC(byte number, int value);
void sendMidiButt(byte number, int value);
void HandleControlChange(byte channel, byte number, byte val);
void midiOut(byte note);
void pedalUp();
void pedalDown();
void dumpPreset();
void resyncArpLfo();
void sendControlChange(byte number, byte value, byte channel);
void sendNoteOff(byte note, byte velocity, byte channel);
void sendTool(byte note, byte velocity);
void sendNoteOn(byte note, byte velocity, byte channel);
void midiRead();

#endif // MEGAFM_CMAKE_MIDI_H
