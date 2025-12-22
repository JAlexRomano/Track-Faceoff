CFLAGS ?= -std=c++11 -Wall -Wextra -Iinclude
$(shell mkdir -p obj bin)

# -------------------------
# This means that when you just type "make", you make all of the executables

ALL = bin/track_faceoff \

all: $(ALL)

# -------------------------
# "make clean" deletes the object files and binaries

clean:
	rm -f obj/* bin/*

# -------------------------
# Object files

obj/track_faceoff.o: src/track_faceoff.cpp include/track_faceoff.hpp
	g++ $(CFLAGS) -c -o obj/track_faceoff.o src/track_faceoff.cpp

obj/main.o: src/main.cpp include/track_faceoff.hpp
	g++ $(CFLAGS) -c -o obj/main.o src/main.cpp

# -------------------------
# Executables

bin/track_faceoff: obj/main.o obj/track_faceoff.o
	g++ $(CFLAGS) -o bin/track_faceoff obj/main.o obj/track_faceoff.o
