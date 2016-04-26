#include "std_lib_facilities_4.h"
#include "screens.h"

//Structure for each score entry
struct Entry {
	Entry(string initiall, int scoree)
		:initial{initiall}, score{scoree}
			{
			}
	Entry()
		:initial{""},score{0}
			{
			}		
	string initial;
	int score;
};

//Track_scores read,sorts, and outputs scores to textfile
class Track_scores{
	public:
		Track_scores()
			:scores(5)
			{
			}
		vector<Entry> scores;
		
		vector<Entry> read_entries();
		Entry make_entry(string a, int b);
		void sort_entries(string a, int b, vector<Entry> &scores );
		void output_entries(vector<Entry> &scores);
		
};
