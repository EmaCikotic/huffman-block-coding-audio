#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#include "searchdata.h"

#define WAV_FILE "Kanye West - Cant Tell Me Nothing.wav"

// gcc -Wall -o huffman main.c buffer.c searchdata.c

int main(void) {
    printf("[ Step 1 ] Reading WAV file: %s\n", WAV_FILE);
    FileBuffer wav = readFile(WAV_FILE);
    if (!wav.data) {
        fprintf(stderr, "Failed to read WAV file. Exiting.\n");
        return 1;
    }

    DataChunk dc = findDataChunk(wav.data, wav.size);
    if (dc.offset < 0) {
        fprintf(stderr, "Error: 'data' chunk not found.\n");
        freeFileBuffer(&wav);
        return 1;
    }

    printf("  WAV file size : %ld bytes\n", wav.size);
    printf("  Audio data at : byte %ld\n", dc.offset);
    printf("  Audio size    : %u bytes\n", dc.size);

    freeFileBuffer(&wav);
    return 0;
}