//
// Created by Matt Montag on 1/23/22.
//

#ifndef MEGAFM_CONSTANTS_H
#define MEGAFM_CONSTANTS_H

const byte kVersion0 = 3;
const byte kVersion1 = 0;

const byte kDefaultSeq[16] = {0, 0, 0, 0, 12, 12, 12, 12, 0, 0, 12, 0, 0, 12, 12, 0};

const bool kAllCC = true;

const byte kArpRateDisplay[] = {0, 0, 0, 2, 3, 4, 8, 12, 16, 32, 48};       // show tempo divisions
const int16_t kMidiArpTicks[] = {384, 192, 96, 48, 32, 24, 12, 8, 6, 3, 2}; // arp rates in MIDI ticks
const float kLfoClockRates[] = {0.6640625, 1.328125, 2.65625, 5.3125, 7.96875, 10.625, 21.25, 31.875, 42.5, 85, 127.5};
const uint16_t kBankOffsets[] = {0, 7900, 15800, 23700, 31600, 39500};

enum VoiceMode {
	kVoicingPoly12 = 0,
	kVoicingWide6 = 1,
	kVoicingDualCh3 = 2,
	kVoicingUnison = 3,
	kVoicingWide4 = 4,
	kVoicingWide3 = 5
};
const int kVoiceModeCount = 6;

const byte kFactoryPresets[] = {
    105, 22,  43,  52,  63,  5,   68,  91,  16,  31,  31,  243, 182, 78,  32,  62,  63,  3,   8,   127, 16,  21,  16,
    213, 89,  15,  73,  0,   4,   74,  7,   7,   6,   31,  0,   0,   255, 0,   0,   73,  8,   2,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   150, 96,  54,  9,   69,  11,  20,  21,  7,   4,   91,  16,  31,  31,  240, 186,
    83,  32,  62,  63,  208, 136, 127, 16,  21,  31,  208, 89,  15,  73,  0,   4,   74,  7,   7,   6,   31,  0,   0,
    255, 0,   0,   72,  8,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   64,  146, 55,  54,  10,  48,  0,
    8,   20,  7,   63,  0,   63,  63,  63,  144, 176, 0,   32,  32,  48,  240, 186, 127, 32,  51,  40,  184, 83,  46,
    73,  0,   214, 120, 5,   0,   6,   31,  24,  0,   255, 0,   0,   179, 136, 10,  0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   32,  0,   0,   127, 130, 134, 137, 139, 137, 134, 130, 129, 130, 132, 133, 134,
    135, 134, 132, 16,  66,  53,  54,  106, 107, 46,  62,  53,  7,   4,   91,  16,  31,  11,  240, 185, 83,  32,  62,
    63,  10,  8,   127, 16,  21,  13,  208, 89,  15,  73,  0,   4,   74,  7,   7,   6,   31,  0,   0,   46,  16,  0,
    73,  8,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   142, 53,  54,  9,   54,  64,  95,  95,  245,
    183, 0,   99,  112, 127, 197, 226, 122, 61,  32,  63,  165, 178, 123, 39,  51,  63,  213, 0,   55,  67,  142, 207,
    6,   0,   0,   0,   0,   34,  0,   0,   75,  0,   11,  75,  3,   0,   0,   128, 0,   0,   0,   0,   0,   0,   0,
    0,   4,   0,   0,   37,  128, 128, 127, 134, 139, 142, 141, 137, 139, 134, 132, 134, 129, 130, 125, 127, 122, 120,
    0,   151, 50,  0,   0,   56,  20,  15,  31,  8,   49,  75,  52,  47,  63,  249, 189, 82,  40,  48,  63,  56,  60,
    106, 52,  42,  63,  249, 31,  15,  167, 39,  18,  74,  0,   0,   6,   31,  0,   0,   40,  12,  0,   72,  10,  3,
    0,   0,   0,   0,   0,   0,   4,   0,   0,   0,   0,   0,   12,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   141, 2,   179, 0,   91,  7,   17,  0,   7,   7,   114, 4,
    30,  0,   249, 135, 83,  8,   16,  0,   8,   103, 127, 32,  47,  40,  251, 31,  15,  31,  0,   18,  74,  4,   5,
    6,   31,  0,   0,   40,  12,  0,   72,  8,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   12,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   205, 24,
    0,   0,   50,  64,  83,  85,  247, 190, 120, 111, 96,  125, 154, 177, 119, 49,  46,  45,  8,   56,  127, 52,  32,
    63,  248, 0,   55,  67,  142, 255, 199, 0,   5,   0,   0,   0,   0,   0,   0,   0,   9,   75,  3,   0,   0,   0,
    0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137, 134, 132, 0,
    134, 137, 130, 129, 125, 122, 120, 8,   146, 108, 117, 0,   68,  64,  94,  73,  255, 199, 124, 64,  82,  67,  155,
    217, 117, 0,   0,   31,  14,  119, 127, 32,  63,  35,  255, 99,  255, 209, 142, 255, 2,   5,   2,   0,   0,   0,
    0,   0,   75,  0,   131, 202, 3,   0,   6,   0,   0,   0,   0,   2,   0,   0,   0,   0,   5,   0,   0,   1,   128,
    196, 127, 130, 134, 137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 8,   203, 37,  0,   0,   20,
    18,  25,  31,  7,   97,  88,  42,  56,  63,  215, 141, 85,  8,   14,  31,  231, 178, 127, 45,  59,  63,  214, 158,
    168, 132, 252, 105, 41,  2,   4,   6,   31,  0,   0,   0,   0,   0,   75,  73,  1,   0,   0,   0,   0,   0,   8,
    0,   0,   0,   0,   0,   0,   12,  0,   0,   0,   64,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   147, 82,  0,   121, 111, 32,  49,  63,  5,   68,  127, 13,  0,   0,   3,   0,   125, 0,
    30,  27,  3,   0,   127, 0,   13,  16,  213, 89,  15,  73,  0,   4,   74,  5,   7,   6,   31,  0,   0,   255, 0,
    0,   83,  8,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   16,  143, 1,   0,   0,   0,   13,  24,  31,
    1,   10,  0,   0,   0,   20,  208, 226, 0,   40,  48,  59,  165, 129, 124, 0,   31,  27,  232, 117, 134, 190, 132,
    135, 255, 3,   0,   6,   31,  0,   0,   0,   0,   0,   131, 230, 0,   0,   16,  16,  0,   0,   8,   0,   0,   0,
    0,   0,   0,   12,  0,   0,   0,   64,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   146, 64,  0,   0,   110, 13,  18,  21,  13,  125, 122, 41,  45,  53,  126, 118, 98,  63,  63,  63,  245,
    129, 127, 0,   31,  28,  248, 141, 233, 255, 149, 75,  25,  4,   3,   6,   31,  0,   0,   0,   42,  0,   203, 119,
    2,   0,   24,  0,   0,   0,   8,   0,   0,   0,   132, 0,   0,   12,  0,   2,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   144, 58,  0,   1,   123, 13,  8,   29,  231, 255, 30,
    32,  32,  63,  14,  117, 112, 40,  47,  52,  245, 142, 82,  0,   0,   31,  8,   195, 91,  255, 149, 59,  83,  7,
    2,   6,   31,  0,   0,   0,   42,  0,   195, 167, 2,   0,   8,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   128, 128, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   96,  152,
    9,   50,  11,  89,  0,   8,   29,  224, 252, 49,  32,  32,  63,  14,  114, 127, 50,  47,  52,  245, 142, 82,  0,
    0,   31,  8,   254, 74,  255, 149, 202, 83,  7,   2,   6,   31,  0,   0,   0,   42,  0,   195, 59,  2,   0,   8,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 128, 0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   148, 64,  0,   1,   69,  65,  79,  95,  252, 131, 86,  76,  95,  95,
    124, 106, 111, 63,  47,  63,  8,   0,   127, 15,  20,  31,  93,  11,  0,   67,  3,   90,  66,  4,   6,   0,   0,
    0,   0,   0,   75,  0,   139, 199, 19,  0,   0,   0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   4,   4,   0,
    0,   0,   127, 130, 134, 137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 104, 152, 26,  0,   108,
    108, 32,  50,  63,  13,  48,  7,   32,  63,  59,  247, 230, 117, 40,  46,  59,  165, 129, 110, 0,   31,  27,  232,
    188, 81,  241, 218, 167, 254, 5,   0,   6,   31,  0,   0,   0,   0,   0,   139, 239, 1,   0,   16,  16,  0,   0,
    8,   0,   0,   0,   0,   0,   0,   12,  0,   0,   0,   64,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   153, 66,  0,   0,   112, 0,   8,   29,  224, 240, 1,   32,  32,  63,  14,  112, 127,
    40,  47,  52,  245, 135, 65,  0,   0,   31,  8,   255, 8,   242, 246, 202, 83,  5,   2,   6,   31,  0,   0,   0,
    42,  0,   203, 26,  3,   0,   8,   0,   0,   0,   0,   0,   0,   0,   4,   0,   0,   0,   0,   0,   128, 128, 0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   150, 54,  0,   0,   127, 0,   18,
    31,  13,  48,  127, 32,  63,  59,  247, 228, 127, 40,  50,  59,  165, 128, 127, 0,   2,   27,  232, 54,  69,  150,
    218, 55,  0,   6,   6,   6,   31,  0,   0,   0,   0,   0,   75,  118, 1,   0,   16,  24,  0,   0,   8,   0,   0,
    0,   0,   0,   0,   12,  0,   0,   0,   64,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   150, 86,  83,  104, 69,  43,  52,  63,  5,   64,  112, 16,  31,  31,  243, 179, 96,  32,  62,  63,
    3,   3,   127, 16,  21,  16,  213, 89,  15,  73,  0,   4,   74,  2,   7,   6,   31,  0,   0,   255, 0,   0,   73,
    8,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   150, 4,   0,   10,  14,  11,  15,  24,  0,   48,
    84,  32,  35,  61,  0,   89,  112, 8,   16,  25,  0,   62,  113, 33,  55,  57,  112, 31,  15,  31,  0,   18,  74,
    5,   4,   6,   31,  0,   0,   40,  12,  0,   72,  8,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   12,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    208, 17,  0,   0,   102, 0,   20,  30,  128, 231, 9,   34,  34,  63,  192, 137, 127, 8,   16,  31,  192, 142, 76,
    4,   3,   31,  192, 31,  15,  31,  0,   215, 10,  5,   7,   6,   31,  0,   0,   81,  0,   8,   75,  72,  2,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   14,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   104, 75,  49,  10,  8,   13,  26,  28,  78,  55,  92,  32,  58,
    59,  220, 191, 0,   40,  48,  59,  238, 231, 123, 32,  53,  59,  186, 31,  15,  31,  0,   192, 10,  6,   6,   6,
    31,  0,   0,   40,  12,  0,   72,  72,  2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   207, 39,  0,
    10,  82,  7,   24,  21,  135, 203, 0,   0,   31,  0,   11,  57,  83,  43,  48,  62,  0,   103, 117, 32,  47,  32,
    0,   31,  15,  31,  0,   18,  74,  3,   0,   6,   31,  0,   0,   40,  12,  0,   67,  8,   2,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   12,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   202, 19,  15,  10,  108, 11,  17,  30,  8,   75,  7,   0,   31,  0,   11,  55,
    83,  32,  47,  62,  0,   96,  123, 32,  34,  32,  0,   31,  15,  31,  0,   18,  74,  7,   0,   6,   31,  0,   0,
    255, 0,   0,   75,  8,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   71,  46,  15,  114, 111, 96,
    116, 117, 245, 230, 127, 98,  113, 115, 183, 255, 117, 49,  46,  63,  15,  120, 127, 63,  63,  63,  255, 0,   55,
    67,  142, 118, 93,  7,   5,   0,   0,   0,   0,   0,   75,  0,   0,   75,  3,   0,   0,   0,   0,   0,   0,   2,
    0,   0,   0,   0,   0,   4,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137, 134, 132, 0,   134, 137, 130, 129,
    125, 122, 120, 8,   141, 59,  53,  0,   0,   64,  84,  86,  247, 187, 117, 96,  110, 122, 242, 176, 73,  49,  46,
    63,  0,   51,  127, 32,  52,  62,  225, 0,   55,  67,  142, 102, 95,  4,   0,   0,   0,   0,   0,   0,   75,  0,
    8,   75,  3,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134,
    137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 8,   14,  83,  40,  0,   120, 30,  0,   21,  231,
    255, 127, 32,  45,  63,  240, 182, 83,  60,  41,  63,  0,   63,  15,  32,  61,  63,  240, 0,   0,   0,   0,   0,
    0,   5,   4,   0,   0,   0,   0,   148, 17,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    16,  172, 39,  35,  126, 48,  104, 116, 117, 255, 130, 58,  64,  89,  92,  95,  49,  83,  49,  46,  59,  14,  66,
    116, 0,   26,  23,  127, 0,   55,  67,  142, 255, 199, 3,   7,   0,   0,   0,   0,   0,   75,  0,   8,   75,  3,
    0,   0,   0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137,
    134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 8,   150, 10,  43,  0,   0,   1,   26,  22,  49,  55,  117, 58,
    61,  59,  215, 178, 31,  34,  48,  59,  238, 231, 123, 47,  53,  59,  178, 31,  15,  31,  0,   192, 10,  0,   0,
    6,   31,  0,   0,   96,  0,   0,   72,  72,  2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   203, 21,
    0,   9,   4,   31,  15,  21,  72,  7,   123, 4,   25,  25,  225, 177, 83,  63,  48,  57,  8,   48,  52,  60,  48,
    57,  168, 255, 255, 255, 123, 255, 255, 7,   0,   6,   31,  0,   0,   91,  0,   0,   137, 122, 0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   64,  0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   206, 26,  13,  0,   0,   0,   24,  22,  7,   0,   58,  0,   0,   31,  224,
    191, 115, 49,  63,  63,  240, 142, 127, 0,   0,   31,  176, 0,   0,   0,   0,   0,   0,   1,   6,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   16,  207, 10,  8,   9,   69,
    30,  0,   21,  231, 255, 127, 63,  32,  63,  240, 185, 83,  60,  32,  63,  240, 191, 127, 61,  61,  63,  240, 0,
    0,   0,   0,   0,   0,   5,   4,   0,   0,   36,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   174, 1,   1,   0,   14,  1,   26,  28,  49,  62,  125, 58,  61,  59,  215, 187, 0,   34,
    48,  59,  238, 231, 124, 47,  53,  59,  179, 31,  15,  31,  0,   192, 10,  0,   0,   6,   31,  0,   0,   192, 20,
    0,   72,  72,  2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   144, 202, 29,  0,   0,   10,  79,  75,  95,
    240, 142, 101, 88,  82,  95,  224, 217, 60,  0,   18,  31,  16,  103, 124, 54,  43,  63,  240, 113, 112, 25,  33,
    66,  249, 2,   7,   0,   0,   0,   0,   0,   0,   1,   136, 250, 2,   0,   16,  0,   0,   0,   0,   8,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122,
    120, 8,   207, 64,  7,   0,   10,  79,  75,  95,  240, 142, 74,  88,  82,  95,  224, 191, 60,  32,  50,  63,  16,
    103, 114, 54,  43,  63,  240, 75,  180, 117, 33,  66,  249, 2,   7,   0,   0,   0,   0,   0,   0,   0,   136, 122,
    2,   0,   16,  16,  0,   0,   0,   8,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134, 137, 139,
    137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 104, 204, 47,  7,   10,  6,   64,  75,  73,  240, 142, 90,
    91,  82,  95,  224, 211, 83,  17,  14,  3,   224, 238, 115, 47,  63,  63,  240, 0,   55,  67,  142, 118, 21,  4,
    2,   0,   0,   0,   0,   0,   130, 0,   9,   75,  3,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,   0,   0,
    4,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 8,   205,
    33,  10,  10,  6,   67,  95,  73,  247, 135, 119, 93,  82,  95,  224, 185, 122, 61,  46,  63,  240, 231, 115, 60,
    63,  63,  240, 0,   55,  67,  142, 255, 199, 4,   2,   0,   0,   0,   0,   134, 0,   0,   8,   75,  3,   0,   0,
    0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137, 134, 132,
    0,   134, 137, 130, 129, 125, 122, 120, 8,   206, 30,  7,   0,   100, 131, 148, 149, 213, 190, 127, 32,  41,  62,
    148, 164, 83,  249, 244, 240, 35,  127, 117, 50,  35,  58,  244, 190, 253, 232, 255, 240, 255, 7,   0,   138, 9,
    25,  24,  92,  13,  0,   192, 127, 0,   1,   1,   1,   64,  0,   0,   12,  0,   0,   0,   0,   1,   1,   0,   33,
    128, 128, 22,  15,  2,   13,  11,  3,   17,  22,  23,  1,   21,  11,  4,   9,   17,  15,  0,   174, 1,   0,   0,
    6,   93,  75,  95,  176, 135, 127, 64,  82,  95,  240, 218, 110, 0,   14,  3,   224, 239, 26,  32,  45,  47,  240,
    0,   55,  67,  142, 102, 93,  4,   2,   0,   0,   84,  0,   0,   75,  5,   51,  75,  3,   0,   0,   0,   0,   0,
    0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 134, 139, 146, 139, 134, 139, 134, 0,   134, 137,
    130, 129, 125, 122, 120, 8,   4,   68,  128, 9,   14,  64,  88,  95,  240, 135, 119, 64,  82,  93,  224, 215, 125,
    17,  14,  3,   224, 239, 91,  32,  63,  37,  240, 0,   55,  29,  205, 255, 95,  0,   2,   0,   0,   71,  235, 0,
    75,  5,   51,  107, 2,   0,   0,   0,   0,   0,   0,   2,   0,   0,   128, 8,   0,   0,   0,   0,   0,   0,   127,
    127, 128, 127, 127, 134, 127, 127, 127, 127, 128, 127, 127, 137, 127, 127, 0,   98,  68,  7,   9,   69,  64,  84,
    85,  247, 135, 107, 80,  84,  94,  235, 186, 83,  49,  46,  35,  224, 225, 111, 32,  63,  52,  240, 0,   55,  67,
    142, 255, 199, 7,   2,   0,   0,   67,  0,   0,   75,  0,   27,  75,  3,   0,   0,   0,   0,   0,   0,   2,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125,
    122, 120, 8,   204, 54,  7,   10,  6,   64,  75,  73,  240, 135, 116, 64,  82,  95,  224, 215, 100, 17,  14,  3,
    224, 238, 65,  32,  63,  47,  240, 5,   215, 114, 142, 255, 95,  4,   2,   0,   0,   22,  161, 0,   75,  255, 163,
    203, 3,   0,   0,   16,  0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134, 137,
    139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 8,   200, 86,  7,   0,   0,   64,  84,  79,  240, 128,
    71,  95,  95,  94,  224, 142, 125, 1,   14,  15,  160, 135, 121, 0,   19,  5,   234, 0,   55,  101, 8,   255, 95,
    4,   2,   0,   0,   65,  255, 0,   75,  1,   27,  74,  3,   0,   0,   0,   0,   0,   0,   2,   0,   0,   1,   128,
    0,   0,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 8,
    206, 88,  61,  10,  64,  75,  73,  80,  135, 243, 64,  114, 127, 96,  208, 234, 17,  46,  35,  32,  238, 238, 91,
    47,  61,  32,  18,  255, 67,  142, 255, 95,  7,   0,   0,   0,   61,  34,  0,   75,  2,   179, 203, 3,   0,   0,
    0,   0,   2,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 139, 127, 130, 142, 130, 132, 144,
    132, 128, 140, 140, 130, 142, 130, 113, 12,  8,   79,  88,  7,   106, 8,   45,  58,  60,  71,  55,  92,  32,  58,
    59,  220, 176, 119, 40,  48,  32,  14,  98,  127, 32,  54,  59,  176, 31,  15,  31,  0,   192, 10,  0,   6,   6,
    31,  0,   0,   40,  12,  0,   75,  72,  2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   140, 101, 0,
    10,  82,  64,  64,  77,  248, 191, 127, 96,  107, 127, 7,   54,  127, 49,  46,  50,  249, 176, 115, 32,  63,  34,
    7,   0,   55,  67,  142, 255, 199, 2,   7,   0,   0,   10,  0,   227, 75,  10,  11,  75,  3,   0,   0,   0,   0,
    0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   127, 130, 134, 137, 139, 137, 134, 132, 0,   134,
    137, 130, 129, 125, 122, 120, 8,   140, 66,  91,  0,   62,  64,  72,  85,  247, 176, 127, 96,  101, 115, 87,  48,
    0,   49,  46,  63,  255, 176, 127, 32,  48,  34,  7,   0,   55,  67,  142, 255, 199, 5,   5,   0,   0,   0,   0,
    227, 75,  0,   11,  75,  3,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
    127, 130, 134, 137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 8,   149, 43,  7,   0,   56,  64,
    64,  93,  255, 180, 105, 96,  96,  126, 255, 178, 117, 49,  46,  62,  255, 176, 127, 32,  54,  34,  1,   0,   55,
    67,  142, 107, 95,  1,   0,   0,   0,   0,   0,   227, 75,  166, 11,  79,  1,   0,   0,   0,   0,   0,   0,   2,
    0,   0,   0,   0,   0,   0,   0,   0,   0,   64,  127, 130, 134, 137, 139, 137, 183, 132, 0,   134, 137, 130, 129,
    125, 122, 120, 8,   5,   99,  42,  0,   48,  65,  69,  69,  247, 176, 127, 96,  108, 108, 199, 176, 127, 49,  46,
    35,  119, 63,  127, 32,  45,  47,  241, 136, 55,  67,  142, 255, 93,  5,   0,   0,   0,   0,   0,   227, 75,  0,
    11,  11,  3,   0,   0,   0,   0,   0,   0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   64,  127, 130, 134,
    137, 139, 137, 134, 132, 0,   134, 137, 130, 129, 125, 122, 120, 8,   0,   83,  1,   1,   1,   0,   0,   0,   0,
    0,   0,   12,  12,  0,   0,   0,   0,   0,   255, 255, 255, 255, 255, 127, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 7,   7,   255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
};
// patches 0-50 to be copied to a blank eeprom on first boot

const byte kSineTable[] = {
    128, 131, 134, 137, 140, 143, 146, 149, 152, 155, 158, 162, 165, 167, 170, 173, 176, 179, 182, 185, 188, 190,
    193, 196, 198, 201, 203, 206, 208, 211, 213, 215, 218, 220, 222, 224, 226, 228, 230, 232, 234, 235, 237, 238,
    240, 241, 243, 244, 245, 246, 248, 249, 250, 250, 251, 252, 253, 253, 254, 254, 254, 255, 255, 255, 255, 255,
    255, 255, 254, 254, 254, 253, 253, 252, 251, 250, 250, 249, 248, 246, 245, 244, 243, 241, 240, 238, 237, 235,
    234, 232, 230, 228, 226, 224, 222, 220, 218, 215, 213, 211, 208, 206, 203, 201, 198, 196, 193, 190, 188, 185,
    182, 179, 176, 173, 170, 167, 165, 162, 158, 155, 152, 149, 146, 143, 140, 137, 134, 131, 128, 124, 121, 118,
    115, 112, 109, 106, 103, 100, 97,  93,  90,  88,  85,  82,  79,  76,  73,  70,  67,  65,  62,  59,  57,  54,
    52,  49,  47,  44,  42,  40,  37,  35,  33,  31,  29,  27,  25,  23,  21,  20,  18,  17,  15,  14,  12,  11,
    10,  9,   7,   6,   5,   5,   4,   3,   2,   2,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   1,   1,
    1,   2,   2,   3,   4,   5,   5,   6,   7,   9,   10,  11,  12,  14,  15,  17,  18,  20,  21,  23,  25,  27,
    29,  31,  33,  35,  37,  40,  42,  44,  47,  49,  52,  54,  57,  59,  62,  65,  67,  70,  73,  76,  79,  82,
    85,  88,  90,  93,  97,  100, 103, 106, 109, 112, 115, 118, 121, 124, 128,
};

const int16_t lfoRateLT[] = {
    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   12,   13,   14,   15,   16,   17,   18,
    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,   35,   36,   37,
    38,   39,   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,
    57,   58,   59,   60,   61,   62,   63,   64,   68,   72,   76,   80,   84,   88,   92,   96,   100,  104,  108,
    112,  116,  120,  124,  128,  132,  136,  140,  144,  148,  152,  156,  160,  164,  168,  172,  176,  180,  184,
    188,  192,  196,  200,  204,  208,  212,  216,  220,  224,  228,  232,  236,  240,  244,  248,  252,  256,  260,
    264,  268,  272,  276,  280,  284,  288,  292,  296,  300,  304,  308,  312,  316,  320,  328,  336,  344,  352,
    360,  368,  376,  384,  392,  400,  408,  416,  424,  432,  440,  448,  456,  464,  472,  480,  488,  496,  504,
    512,  520,  528,  536,  544,  552,  560,  568,  576,  584,  592,  600,  608,  616,  624,  632,  640,  648,  656,
    664,  672,  680,  688,  696,  704,  712,  720,  728,  736,  744,  752,  760,  768,  776,  784,  792,  800,  808,
    816,  824,  850,  901,  953,  1004, 1056, 1107, 1159, 1210, 1262, 1313, 1365, 1417, 1468, 1520, 1571, 1623, 1674,
    1726, 1777, 1829, 1881, 1932, 1984, 2035, 2087, 2138, 2190, 2241, 2293, 2344, 2396, 2448, 2499, 2551, 2602, 2654,
    2705, 2757, 2808, 2860, 2912, 2963, 3015, 3066, 3118, 3169, 3221, 3272, 3324, 3375, 3427, 3479, 3530, 3582, 3633,
    3685, 3736, 3788, 3839, 3891, 3943, 3994, 4046, 4097};
#endif // MEGAFM_CONSTANTS_H
