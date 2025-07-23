#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

void getSongs(vector<string>& all_songs) {
	int song_value = 1;
	cout << "Enter your songs here. Enter at least one song and type '#done'" << endl;
	cout << "without the '' when you're done inputing songs." << endl;
	cout << "Type '#delete' without the '' to delete your most recent input." << endl;
	while(true) {
		string input;
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

string checkDuplicate(string a, string b, vector<string> check_duplicate) {
	if (check_duplicate.size() < 4) return "no duplicate";
	for (size_t i = 0; i < check_duplicate.size() - 1 ; i += 2) {
		if ((a == check_duplicate[i] && b == check_duplicate[i + 1]) || 
		(b == check_duplicate[i] && a == check_duplicate[i + 1])) {
			return check_duplicate[i];
		}
	}
	return "no duplicate";
}

string compareSongs(string song1, string song2, vector<string>& check_duplicate) {
	string duplicate = checkDuplicate(song1, song2, check_duplicate);
	if (duplicate != "no duplicate") return duplicate;
	int choice;
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
		if (choice == 1|| choice == 2) break;
		else cout << "Bruh...you know that aint what I asked" << endl;
	}
	if (choice == 1) {
		check_duplicate.push_back(song1); check_duplicate.push_back(song2);
	}
	else {
		check_duplicate.push_back(song2); check_duplicate.push_back(song1);
	}
	if (choice == 1) return song1;
	else return song2;
}

vector<string> round(vector<string>& current_round, vector<string>& losers_bracket, vector<string>& check_duplicate) {
	vector<string> next_round;

	if (current_round.size() % 2 == 1) {
		//cout << current_round.back() << " gets a bye." << endl;
		next_round.push_back(current_round.back());
		current_round.pop_back();
	}
	for (size_t i = 0; i < current_round.size() - 1; i+=2) {
		string winner = compareSongs(current_round[i], current_round[i + 1], check_duplicate);
		string loser;
		if (winner == current_round[i]) loser = current_round[i + 1];
		else loser = current_round[i];
		next_round.push_back(winner);
		losers_bracket.push_back(loser);
	}
	return next_round;
}

void tournament(vector<string> all_songs, vector<string>&rankings /*songs in order*/) {
	vector<string> current_round = all_songs;
	vector<string> losers_bracket;
	vector<string> check_duplicate;

	while(!current_round.empty()) {
		if (current_round.size() == 1) {
			rankings.push_back(current_round[0]);
			break;
		}
		current_round = round(current_round, losers_bracket, check_duplicate);
		if (current_round.size() == 1) {
			rankings.push_back(current_round[0]);
			current_round = losers_bracket;
			losers_bracket.clear();
		}
	}
}

int main() {
	vector<string> songs;
	getSongs(songs);

	vector<string> final_rankings;
	tournament(songs, final_rankings);

	cout << "\nYour final rankings good sir: " << endl;
	for (size_t i = 0; i < final_rankings.size(); ++i) {
		cout << i + 1 << ". " << final_rankings[i] << endl; 
	}

	string answer;
	cout << "Would you like to write these results to a text file?(y/n) ";
	cin >> answer;
	if (answer == "y") {
		ofstream fout;
		fout.open("ranking_results.txt");
		if (fout.fail()) {
			cerr << "File failed to open for writing" << endl;
			return 1;
		}
		for (size_t i = 0; i < final_rankings.size(); ++i) {
			fout << i + 1 << ". " << final_rankings[i] << endl; 
		}
		
		fout.close();
	}
}

