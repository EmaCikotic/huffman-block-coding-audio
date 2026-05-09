#include <stdio.h>
#include <string.h>
#include "frequency.h"

void buildFrequencyTable(const unsigned char *data, long size, FreqTable freq) {
    memset(freq, 0, sizeof(FreqTable));

    for (long i = 0; i < size; i++) {
        freq[ data[i] ]++;
    }
}
