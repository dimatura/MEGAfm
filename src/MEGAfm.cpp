
/*

cd /Users/a/Documents/bootloaderT cd /Users/a/Documents/bootloaderT&&cp -f /private/var/hex/megaFM_R2.4.ino.hex /Users/a/Documents/bootloaderT&&python tools/hex2sysex/hex2sysex.py --syx -o firmware.syx megaFM_R2.4.ino.hex


Poly12 sustain pedal bug
I’ve found that when playing with a sustain pedal in Poly12 mode, pressing a key twice does not cause the sustained note to retrigger. Interestingly, it does do this in Wide6 mode. Would it be possible to implement this in a future firmware update, or is there a way to turn this on for Poly12 that I just completely missed?


Hey again! So when i was in setup mode (SE), after activating ‘midi thru’ on LFO 1 link button ..
it seems that i couldn’t exit SE mode by pushing voice 1 time, and i could not flip thru different voice modes…
and i believe the screen was blank… perhaps im not doing something right. because it took me about 4 tries to successfully activate midi thru… i didn’t want to try and replicate the problem again because it’s working now… but like i said i may have pushed a button or hit another knob, or did something wrong.


DONE
Fix PA function (not updating all faders/pots)

TODO

Steal closest note so it glides logically
figure out issue with detun3

check tuning?!

Was playing around with the dual ch3 mode and found some odd behaviour, that I'm guessing is not intentional?
Firstly, seems like the detune sliders are affecting the wrong operators. OP1 detune slider detunes OP4, OP2 slider detunes OP1, OP3 slider detunes OP3 and OP4 slider detunes OP1.
Secondly, detuning an operator only has effect while playing the same note. Playing different notes seems to reset the detune again.
And lastly, just wondering if it's as intended that only OP4 pitch is tracking the keyboard, whereas the other three are fixed?

- pitchbend cc
When im sequencing the pitchbend cc from my sequencer after a few playback the mega starts sounding weird. Rebooting fixes it for a while. Maybe its an lfo acting up. Cant figure it out. I have cleared out all 3 lfos first but maybe its these that dont reset properly.

- programchange. When this is used sometimes a completely wrong program is selected. Rebooting fixes it temporarily.

*/

#include <Arduino.h>
#include <Wire.h>
#include <EEPROM.h>
#include <TimerOne.h>

#include "megafm.h"
#include "lfo.h"
#include "mux.h"
#include "FM.h"
#include "leds.h"
#include "isr.h"
#include "preset.h"

// Whether one second has elapsed since device boot.
// Used in: loop.cpp, pots.cpp
bool secPast = false;
// Whether the knobs/sliders should use 'pickup' behavior
// Used in: buttons.cpp, megafm.cpp, pots.cpp
bool pickupMode = true;
// Whether each knob/slider has been picked up.
// Used in: pickup.cpp, pots.cpp, preset.cpp
bool pickup[49];
// Similar to pickup? Ignore volume knob immediately after loading a preset
// Used in: buttons.cpp, megafm.cpp, pots.cpp, preset.cpp
bool ignoreVolume;
// Some kind of defer countdown for pitch bend
// Used in: loop.cpp, midi.cpp
int bendyCounter;
// True for each MIDI note included in arpeggiation
// Used in: arp.cpp, voice.cpp
bool arpNotes[128];
// Note priority: lowest (0), highest (1), or last (2).
// Used in: buttons.cpp, megafm.cpp, midi.cpp, voice.cpp
byte notePriority = 2;
// Track the last note for glide
// Used in: midi.cpp, voice.cpp
byte lastNotey[40];
// When the arp needs to be resynced; MIDI clock changes or arp mode change
// Used in: buttons.cpp, midi.cpp
bool resyncArp = false;
bool stereoCh3;
byte bank;
int lfoLedCounter;
byte seq[16];
byte seqStep;
byte seqLength;
bool seqRec;
bool flasher;
int flashCounter, flashCounter2, bankCounter;
bool test;
byte sendReceive;
byte rootNote, rootNote1;
bool thru = true;
int setupCounter;
bool justQuitSetup;
bool invertedSquare[3];
bool invertedSaw[3];


byte muxChannel;
bool voiceSlots[12];
byte noteOfVoice[12];

bool lfoVel;//velocity affects lfo1
bool lfoMod;// mod affect lfo2
bool lfoAt;//at affect lfo3
float mpeBend[12];
byte bendUp = 12;
byte bendDown = 12;
int bendRoot = -1;
float destiFreq[12];
float freq[12];
float freqTotal[12];//freq + vib *bend
float freqLast[12];
float glideIncrement[12];
int volumeCounter;
bool changeVol;
bool dotOn;
bool arpClockEnable;
bool lfoClockEnable[3];
bool vibratoClockEnable;
byte glide = 0;
byte lastVol, vol;
bool arpJustWentOff;
bool setupMode;
bool fineChanged;
byte arpMidiSpeedPending, arpMidiSpeed;
byte fine;
byte presetCounts;
bool presetTargetMode;
byte presetTargetModeChanged;
int targetPresetModeTimer;
bool targetPresetFlasher;
int scrollDelay, scrollCounter;
byte noiseTableLength[3];
byte mem[3950];//buffer for sysex preset dumps
int notey[12];
byte arpMode, arpModeLast;
byte version = 1;
bool looping[3];
int arpIndex;
bool resetHeld;
bool shuffled;
bool voiceHeld;
int lastNumber = 255;
byte lfoClockSpeed[3];
byte lfoClockSpeedPending[3];
byte absoluteClockCounter;
YM2612 ym;
int heldKeys;
byte lastNote, dotTimer;
int arpCounter, arpStep, preset;
float lfoStepF[3];
bool arpModeHeld;
byte inputChannel = 1;
bool changedChannel;
bool pedalOff[12];
bool pedal;
bool emptyStack;
bool fatMode;
int arpButtCounter;
float finey = 1;
int ledNumberTimeOut;
LedControl mydisplay = LedControl(13, 29, 12, 1);
int presetLast;
int secCounter;
int vibIndex, vibIndexLast;
int arpDivider;
byte voiceMode = 0;
bool sync;
bool ab;
int potLast[64];
int lfoDepth[3];
bool buttLast[19];
int algoLast;
byte fmBase[51], fmBaseLast[51], fmBaseLastNumber[51];
int fmData[51], fmDataLast[51];
bool linked[3][51];
bool dontShow[50];
byte lfoRandom[3][32];
byte randomIndex[3];
bool pressedUp, pressedDown;
bool saved;
int presetFlasher;
byte updatePitchCounter;
int shuffleCounter2;
bool shuffleAlternator;
int shuffleCounter;
byte linkCounter;
byte selectedLfo, selectedLfoLast;
bool cleared;
byte chainPressed;
byte targetPot, targetPotLast;
byte masterChannelOut = 1;
float ch3x[4];
byte lfoShape[3];
byte lfo[3], lfoLast[3];
int lfoStep[3];
int lfoStepLast[3];
int at, atDest, atLast, atGlideCounter;
bool lfoNewRand[3];
int lfoCounter[3], lfoSpeed[3];
bool retrig[3];
int fatLast;
float fat;
float bendy = 0;
bool setupChanged;
bool lastLfoSetting[3];
int vibPitch;
byte presetTp;
int vibCounter;
int shuffleTimer;
byte seed;
byte potClock;
bool mpe;

void enterSetup() {
  digit(0, 5);
  digit(1, 18);
  setupMode = true;
  ledSet(13, thru);
  ledSet(14, pickupMode);
}

void setup() {

  fillAllLfoTables();

  Wire.begin();

  potClock = 19;

  //dPot
  digitalWrite(13, LOW);
  digitalWrite(29, LOW);
  digitalWrite(21, LOW);

  //dPot
  pinMode(potClock, OUTPUT); //clock
  pinMode(18, OUTPUT); //data
  pinMode(21, OUTPUT); //latch




// LOAD SETTINGS


//3950 = bit 0 thru
//3950 = bit 1 ignore preset volume


//3951 = midi channel
//3952 = last preset
//3953 bit0  =  midi clock lfo1
// 3953 bit1    midi clock lfo2
// 3953 bit2 =  midi clock lfo3
// 3953 bit3 =  midi clock vibra
// 3953 bit4 =  midi clock  arp
// 3953 bit5 =  fatMode

//3954 = pickup mode (0=on)

//3958 =bendDown
//3959 =bendUp
//3960 =mpe mode

//3961 =vel >lfo1 depth
//3962 =mod >lfo2 depth
//3963 =at >lfo3 depth

//3964 lastbank

//3965 brightness.

//3966 = bit 0 inv saw1
//3966 = bit 1 inv saw2
//3966 = bit 2 inv saw3
//3966 = bit 3 inv square1
//3966 = bit 4 inv square2
//3966 = bit 5 inv square3
//3966 = bit 6 stereoCh3

//3967 = note priority 0=low 1=high 2=last

  notePriority = EEPROM.read(3967);
  if (notePriority > 2)notePriority = 0;

  invertedSaw[0] = bitRead(EEPROM.read(3966), 0);
  invertedSaw[1] = bitRead(EEPROM.read(3966), 1);
  invertedSaw[2] = bitRead(EEPROM.read(3966), 2);
  invertedSquare[0] = bitRead(EEPROM.read(3966), 3);
  invertedSquare[1] = bitRead(EEPROM.read(3966), 4);
  invertedSquare[2] = bitRead(EEPROM.read(3966), 5);

  stereoCh3 = bitRead(EEPROM.read(3966), 6);

  noiseTableLength[0] = 0;
  bitWrite(noiseTableLength[0], 0, bitRead(EEPROM.read(3950), 2));
  bitWrite(noiseTableLength[0], 1, bitRead(EEPROM.read(3950), 3));
  noiseTableLength[0] += 2;

  noiseTableLength[1] = 0;
  bitWrite(noiseTableLength[1], 0, bitRead(EEPROM.read(3950), 4));
  bitWrite(noiseTableLength[1], 1, bitRead(EEPROM.read(3950), 5));
  noiseTableLength[1] += 2;

  noiseTableLength[2] = 0;
  bitWrite(noiseTableLength[2], 0, bitRead(EEPROM.read(3950), 6));
  bitWrite(noiseTableLength[2], 1, bitRead(EEPROM.read(3950), 7));
  noiseTableLength[2] += 2;

  if (bitRead(EEPROM.read(3950), 0)) {
    thru = 0;
  } else {
    thru = 1;
  }

  if (EEPROM.read(3961)) {
    lfoVel = 1;
  } else {
    lfoVel = 0;
  }
  if (EEPROM.read(3962)) {
    lfoMod = 1;
  } else {
    lfoMod = 0;
  }
  if (EEPROM.read(3963)) {
    lfoAt = 1;
  } else {
    lfoAt = 0;
  }

  if (EEPROM.read(3954)) { pickupMode = true; } else { pickupMode = false; }

  lfoClockEnable[0] = bitRead(EEPROM.read(3953), 0);
  lfoClockEnable[1] = bitRead(EEPROM.read(3953), 1);
  lfoClockEnable[2] = bitRead(EEPROM.read(3953), 2);
  vibratoClockEnable = bitRead(EEPROM.read(3953), 3);
  arpClockEnable = bitRead(EEPROM.read(3953), 4);
  fatMode = bitRead(EEPROM.read(3953), 5);

  ignoreVolume = bitRead(EEPROM.read(3950), 1);

  bank = EEPROM.read(3964);
  if (bank > 5)bank = 0;
  preset = EEPROM.read(3952);
  if (preset > 99) {
    preset = 0;
  }

  arpModeLast = 6;

  for (int i = 0; i < 16; i++) {
    readMux();
  }

  ym.setup(30, 10, 11, 11, 20, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23);

  setupFM();

  pinMode(A1, INPUT);
  digitalWrite(A1, HIGH);

  pinMode(22, INPUT);
  digitalWrite(22, HIGH); //pc6 retrig

  mydisplay.shutdown(0, false);  // turns on display\\

  byte brightness = EEPROM.read(3965);
  if (brightness > 15)brightness = 10;//default;
  mydisplay.setIntensity(0, brightness); // 15 = brightest

  //show version
  digit(0, version0);
  digit(1, version1);
  //show dot
  mydisplay.setLed(0, 7, 6, 1);
  delay(500);
  mydisplay.setLed(0, 7, 6, 0);
  Timer1.initialize(150); //
  Timer1.attachInterrupt(isr); // attach the service routine here



  inputChannel = EEPROM.read(3951);
  if ((inputChannel > 16) || (inputChannel < 1)) {
    inputChannel = 1;
    EEPROM.write(3951, inputChannel);
  }

  //check if enter setup mode
  mux(15);
  if (!digitalRead(A1)) {

    enterSetup();

  }




  //mux(5);//preset up


  Serial.begin(31250);
  //midiSetup();

  mux(14);
  if (!digitalRead(A1)) {
    sendReceive = 2;  //preset down = send midi dump
    bank = 0;
    showSendReceive();
  }
  mux(5);
  if (!digitalRead(A1)) {
    sendReceive = 1;  //preset up = get midi dump
    bank = 0;
    showSendReceive();
  }

  mux(13);
  if ((!digitalRead(A1)) ||
      ((EEPROM.read(0) == 255) && (EEPROM.read(1) == 255) && (EEPROM.read(2) == 255) && (EEPROM.read(3) == 255))) {
    //test mode
    digit(0, 16);
    digit(1, 18);

    for (int i = 0; i < 4000; i++) {
      EEPROM.write(i, factoryPresets[i]);
    }

    loadPreset();
    eWrite(69, 69);
    if (eRead(69) != 69) {

      while (1) {

        digit(0, 18);
        digit(1, 18);
        delay(200);
        digit(0, 21);
        digit(1, 21);
        delay(200);

      }

    }
    EEPROM.write(3964, 0); //bank 0
    test = true;
    bank = 0;
    preset = 0;

  }

  for (int i = 0; i < 50; i++) {
    ledSet(i, test);
  }

  for (int i = 0; i < 16; i++) {
    readMux();
  }
  loadPreset();
  loadPreset();

  bendUp = EEPROM.read(3959);
  if ((bendUp > 48) || (!bendUp)) {
    bendUp = 48;
  }
  bendDown = EEPROM.read(3958);
  if ((bendDown > 48) || (!bendDown)) {
    bendDown = 48;
  }

  if (EEPROM.read(3960) == 1) {
    mpe = 1;
  } else {
    mpe = 0;
  }

  if (preset == 0) {
    digit(0, 0);
    digit(1, 0);
  }
}

