#include <string>
#include <vector>

class TrackFaceoff {
	public:
		void GetSongs();
		std::string CheckDuplicate(const std::string &a, const std::string &b);
		std::string CompareSongs(const std::string &song1, const std::string &song2);
		vector <std::string> OneRound();
		void Tournament();

	protected:
		std::vector <std::string> all_songs;
		std::vector <std::string> check_duplicate;
		std::vector <std::string> current_round;
		std::vector <std::string> losers_bracket;
		std::vector <std::string> rankings;
};
