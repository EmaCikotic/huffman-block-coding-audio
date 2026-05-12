#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#include "searchdata.h"
#include "frequency.h"
#include "huffman_tree.h"
#include "code_table.h"

#define WAV_FILE "Kanye West - Cant Tell Me Nothing.wav"

// gcc -Wall -o huffman main.c buffer.c searchdata.c frequency.c huffman_tree.c code_table.c

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

    printf("\n[ Step 2 ] Counting the byte frequencies...\n");
    unsigned char *audioData = wav.data + dc.offset;
    long audioSize = (long)dc.size;

    FreqTable freq;
    buildFrequencyTable(audioData, audioSize, freq);
    printf(" Frequency table build successfully. \n");

    printf("\n[ Step 3 ] Building Huffman tree...\n");

    HuffNode *root = buildHuffmanTree(freq);

    if (!root) {
        fprintf(stderr, "Failed to build Huffman tree. Exiting.\n");
        freeFileBuffer(&wav);
        return 1;
    }

    printf(" Huffman tree built successfully.\n");

    printf("\n[ Step 4 ] Generating Huffman codes...\n");

    CodeTable table;
    buildCodeTable(root, table);
    
    printf(" Huffman code table generated successfully.\n");


    printf("\nSample's:\n");

    for (int i = 0; i < 10; i++) {
    if (table[i].length > 0) {
        printf("Byte %3d : %s (%d bits)\n",
               i,
               table[i].code,
               table[i].length);
    }
}

    freeHuffmanTree(root);

    freeFileBuffer(&wav);
    return 0;
}