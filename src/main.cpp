#include <vector>
#include <string>
#include <iostream>
#include "track_faceoff.hpp"
using namespace std;

int main() 
{
	TrackFaceoff tf;

	tf.Print();

        /*string answer;
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
        }*/
	return 0;
}
