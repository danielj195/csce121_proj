#include "std_lib_facilities_4.h"
#include "screens.h"

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

class Track_scores{
	public:
		Track_scores()
			:scores(5)
			{
			}
		vector<Entry> scores;
		
		//Member functions
		vector<Entry> read_entries();
		Entry make_entry(string a, int b);
		void sort_entries(string a, int b, vector<Entry> &scores );
		void output_entries(vector<Entry> &scores);
		//static bool compare_scores(const Entry& a, const Entry& b);
};
