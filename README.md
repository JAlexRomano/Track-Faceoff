# Track-Faceoff 🎵

> A C++ console application that fully ranks your favorite songs through a series of head-to-head face-offs.

---

## How It Works

You provide a text file with one song per line. The program then presents you with a series of binary choices — pick which of two songs you prefer — and uses your answers to build a complete ranking from best to worst. Once enough comparisons have been made, your full ranked list is displayed, and you can optionally save it to a file.

---

## Prerequisites

- A C++ compiler supporting C++11 or later (g++ or clang++)
- `make` (Linux/macOS only — see Windows instructions below)

---

## Getting Started

```bash
git clone https://github.com/JAlexRomano/Track-Faceoff.git
cd Track-Faceoff
```

### Linux / macOS

`make` comes pre-installed on most Linux distros and macOS (via Xcode Command Line Tools). To build and run:

```bash
make
./bin/track_faceoff your_songs.txt
```

To try the included example:

```bash
make
./bin/track_faceoff example.txt
```

To clean build output:

```bash
make clean
```

### Windows

Windows does not include `make` or `g++` by default, so you'll need to install a toolchain to compile from source.

**Option 1 — MSYS2 (recommended)**

1. Install [MSYS2](https://www.msys2.org/), which provides both `g++` and `make` on Windows.
2. Open the MSYS2 MinGW terminal and install the toolchain if prompted:
   ```bash
   pacman -S mingw-w64-x86_64-gcc make
   ```
3. Navigate to the repo folder and build:
   ```bash
   make
   ./bin/track_faceoff your_songs.txt
   ```

**Option 2 — Compile manually with MinGW-w64**

If you already have [MinGW-w64](https://www.mingw-w64.org/) installed, you can compile without `make` from PowerShell:

```powershell
g++ -std=c++11 -Wall -Iinclude -o bin/track_faceoff src/main.cpp src/track_faceoff.cpp
.\bin\track_faceoff.exe your_songs.txt
```

---

## Input File Format

Create a plain `.txt` file with one song (or any item) per line:

```
Bohemian Rhapsody
Hotel California
Stairway to Heaven
Smells Like Teen Spirit
Lose Yourself
```

An `example.txt` is included in the repo to try out right away.

---

## Project Structure

```
Track-Faceoff/
├── src/
│   ├── main.cpp              # Entry point
│   └── track_faceoff.cpp     # Core ranking logic
├── include/
│   └── track_faceoff.hpp     # Header file
├── bin/                      # Compiled executable output
├── obj/                      # Object file output
├── makefile                  # Build rules
└── example.txt               # Sample input file
```

---

## Built With

- C++11 (standard library only — no external dependencies)
- GNU Make

---

## License

MIT
