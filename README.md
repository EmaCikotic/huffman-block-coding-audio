# Huffman Block Coding for Audio

A university project focused on implementing Huffman-based lossless compression for WAV audio files using the C programming language.

The project demonstrates the core concepts behind Huffman coding, frequency analysis, binary trees, and low-level file processing.

---

# Overview

The application reads audio data from a `.wav` file, dynamically locates the audio `"data"` chunk, calculates byte frequencies, and constructs a Huffman tree from the detected symbols.

The project was created to demonstrate:
- lossless compression concepts
- binary tree structures
- frequency analysis
- file parsing in C
- modular software design

---

# Features

## WAV Processing
- Reads `.wav` audio files
- Dynamically detects the `"data"` chunk
- Extracts raw audio data

## Huffman Compression Logic
- Counts byte frequencies
- Builds a Huffman tree using a MinHeap
- Supports up to 256 distinct byte symbols

## General
- Modular C project structure
- Separate `.c` and `.h` files
- Console-based execution
- Memory allocation and pointer usage

---

# Tech Stack

| Component | Technology |
|---|---|
| Language | C |
| Compiler | GCC |
| Data Structures | Binary Trees, MinHeap |
| Concepts | Huffman Coding, File Compression |

---

# Project Structure

```text
huffman-block-coding-audio/
├── main.c
├── buffer.c
├── buffer.h
├── frequency.c
├── frequency.h
├── huffman_tree.c
├── huffman_tree.h
├── code_table.c
├── code_table.h
├── encoder.c
├── encoder.h
├── searchdata.c
├── searchdata.h
├── Kanye West - Cant Tell Me Nothing.wav
└── README.md
```

---

# Compilation

Compile the project using GCC:

```bash
gcc -Wall -o huffman \
main.c \
buffer.c \
frequency.c \
huffman_tree.c \
code_table.c \
encoder.c \
searchdata.c
```

---

# Running the Program

Run the executable:

```bash
./huffman
```

Example output:

```text
[ Step 1 ] Reading WAV file: Kanye West - Cant Tell Me Nothing.wav
Found 'data' chunk at byte 70 (size = 47923200 bytes)

WAV file size : 47923278 bytes
Audio data at : byte 78
Audio size    : 47923200 bytes

[ Step 2 ] Counting the byte frequencies...
Frequency table built successfully.

[ Step 3 ] Building Huffman tree...
Building Huffman tree from 256 distinct symbols...
Huffman tree built successfully.
```

---

# Concepts Used

- Huffman Coding
- Lossless Compression
- Binary Trees
- MinHeap / Priority Queue
- Frequency Analysis
- WAV File Parsing
- Dynamic Memory Allocation
- File I/O in C

---


# Author

Created by:

- Ema Čikotić - [GitHub](https://github.com/EmaCikotic)
- Nade Belovinova - [GitHub](https://github.com/bel-n)
- Samoil Gjorgiev - [GitHub](https://github.com/sam0il)

---

# Academic Context

This project was developed for the TOR III (Theory of Information) course as part of a university assignment focused on data compression and low-level systems programming using the C programming language.
