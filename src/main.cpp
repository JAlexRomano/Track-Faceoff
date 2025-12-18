#include "track_faceoff.hpp"
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char **argv) 
{
	TrackFaceoff tf;
	ifstream fin;	
	string file, song;
	vector <string> songs;

	if (argc != 2) {
		cerr << "Invalid arguments" << endl;
		return 1;
	}

	file = (string) argv[1];	
	fin.open(file);

	if (fin.fail()) {
		cerr << "Invalid file input" << endl;
		return 1;
	}

	while (getline(fin, song)) {
		songs.push_back(song);
	}
	fin.close();

	tf.GetSongs(songs);
	tf.Tournament();
	tf.Print();

	return 0;
}
