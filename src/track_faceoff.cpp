#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include "track_faceoff.hpp"
using namespace std;

void TrackFaceoff::GetSongs() {
	string input;
	int song_value;

	song_value = 1;
	cout << "Enter your songs here. Enter at least one song and type '#done'" << endl;
	cout << "without the '' when you're done inputing songs." << endl;
	cout << "Type '#delete' without the '' to delete your most recent input." << endl;
	while(true) {
		cout << "Enter song #" << song_value << ": ";
		getline(cin, input);
		if (input == "#done") break;
		if (input == "#delete") {
			all_songs.pop_back();
			song_value--;
			continue;
		}
		all_songs.push_back(input);
		song_value++;
	}
}

string TrackFaceoff::CheckDuplicate(const string &a, const string &b) {
	size_t i;

	if (check_duplicate.size() < 4) return "no duplicate";
	for (i = 0; i < check_duplicate.size() - 1 ; i += 2) {
		if ((a == check_duplicate[i] && b == check_duplicate[i + 1]) || 
		(b == check_duplicate[i] && a == check_duplicate[i + 1])) {
			return check_duplicate[i];
		}
	}
	return "no duplicate";
}

string TrackFaceoff::CompareSongs(const string &song1, const string &song2) {
	string duplicate;
	int choice;
	
	duplicate = CheckDuplicate(song1, song2);
	if (duplicate != "no duplicate") return duplicate;
	while(true) {
		cout << "\nKindly select a song, but choose wisely...(or else)" << endl;
		cout << "1. " << song1 << endl;
		cout << "2. " << song2 << endl;
		cout << "1 or 2? ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nBruh...you know that aint what I asked. Try again" << endl;
			continue;
		}
		if (choice == 1 || choice == 2) break;
		else cout << "Bruh...you know that aint what I asked" << endl;
	}
	if (choice == 1) {
		check_duplicate.push_back(song1);
		check_duplicate.push_back(song2);
	} else {
		check_duplicate.push_back(song2); 
		check_duplicate.push_back(song1);
	}
	return (choice == 1) ? song1 : song2;
}

vector <string> TrackFaceoff::OneRound() {
	size_t i;
	string winner, loser;
	vector<string> next_round;

	if (current_round.size() % 2 == 1) {
		next_round.push_back(current_round.back());
		current_round.pop_back();
	}
	for (i = 0; i < current_round.size() - 1; i += 2) {
		winner = CompareSongs(current_round[i], current_round[i + 1]);
		if (winner == current_round[i]) loser = current_round[i + 1];
		else loser = current_round[i];
		next_round.push_back(winner);
		losers_bracket.push_back(loser);
	}
	return next_round;
}

void TrackFaceoff::Tournament() {
	current_round = all_songs;
	while(!current_round.empty()) {
		if (current_round.size() == 1) {
			rankings.push_back(current_round[0]);
			break;
		}
		current_round = OneRound();
		if (current_round.size() == 1) {
			rankings.push_back(current_round[0]);
			current_round = losers_bracket;
			losers_bracket.clear();
		}
	}
}

void TrackFaceoff::Print() const {
	size_t i;
	string answer;
        ofstream fout;

        cout << "\nYour final rankings good sir: " << endl;
        for (i = 0; i < rankings.size(); i++) {
                cout << i + 1 << ". " << rankings[i] << endl;
        }

	cout << "Would you like to write these results to a text file?(y/n) ";
        cin >> answer;
        if (answer == "y") {
                fout.open("ranking_results.txt");
                if (fout.fail()) {
                        cerr << "File failed to open for writing" << endl;
                        exit(1);
                }
                for (i = 0; i < rankings.size(); i++) {
                        fout << i + 1 << ". " << rankings[i] << endl;
                }
        	fout.close();
        }
}
