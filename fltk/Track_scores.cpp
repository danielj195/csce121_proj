#include "std_lib_facilities_4.h"
#include "Track_scores.h"

//#include "GUI.h"

//Track_scores::
istream& operator>>(istream& ist, Entry& r){
	string b;
	int c;
	ist >> b >> c;
	r.initial = b;
	r.score = c;
	return ist;
}

//Track_scores::
 ostream& operator<<(ostream& ost, Entry& r){
	return ost << " " << r.initial << " " << r.score << " \r\n";
} 

vector<Entry> Track_scores::read_entries()
{
	string iname = "scores.txt";
	Entry b;
	vector<Entry> c;
	ifstream ist{iname};
	if(!ist)error("can't open input file ",iname);
	while(!ist.eof()){
		ist >> b;
		c.push_back(b);
	}
	return c;
}

Entry Track_scores::make_entry(string a, int b) 
{  
	Entry c = {a,b};
	return c;
}

void Track_scores::sort_entries(string a, int b, vector<Entry> &d)
{
	Entry c = make_entry(a,b);
	Entry val = make_entry("-",0);
	for (int i = 0; i < 5; i++){
		if (c.score > d[i].score){
			int j = i;
			for(int k = 4; k > j; --k){
				d[k] = d[k-1];
			}
			d[i] = c;
			break;
		}
	}
	d.resize(5,val);
	//d.remove(5);
	/* d.push_back(c);
	for(int i=0; i < d.size(); ++i){
		if(c.score >= d[i].score && i < 5){
			d[i] = c;
			break;
		}
	} 
	sort(d.begin(),d.end(),compare_scores); */
}

/*bool Track_scores::compare_scores(const Entry& a, const Entry& b)
{
    return a.score > b.score;
}*/

void Track_scores::output_entries(vector<Entry> &a)
{
	string oname = "scores.txt";
	ofstream ost;
	ost.open(oname, std::fstream::out | std::fstream::trunc);   //, std::fstream::out | std::fstream::trunc);
	if(!ost)error("can't open output file ",oname);
	for(int i = 0; i < a.size(); ++i){
		ost << a[i];
	}
}

