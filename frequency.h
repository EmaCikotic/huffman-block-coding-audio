#ifndef FREQUENCY_H
#define FREQUENCY_H
#define NUM_SYMBOLS 256

typedef unsigned long long FreqTable[NUM_SYMBOLS];

void     buildFrequencyTable (const unsigned char *data, long size, FreqTable freq);

#endif
