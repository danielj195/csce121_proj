#include "std_lib_facilities_4.h"
#include "Track_scores.h"



istream& operator>>(istream& ist, Entry& r){
	string b;
	int c;
	ist >> b >> c;
	r.initial = b;
	r.score = c;
	return ist;
}


 ostream& operator<<(ostream& ost, Entry& r){
	return ost << " " << r.initial << " " << r.score << " \r\n";
} 

vector<Entry> Track_scores::read_entries() //Reads scores from textfile and inputs into vector
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

void Track_scores::sort_entries(string a, int b, vector<Entry> &d) //Inputs entry and sorts vector
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
}

void Track_scores::output_entries(vector<Entry> &a) //Outputs scores to textfile
{
	string oname = "scores.txt";
	ofstream ost;
	ost.open(oname, std::fstream::out | std::fstream::trunc);   
	if(!ost)error("can't open output file ",oname);
	for(int i = 0; i < a.size(); ++i){
		ost << a[i];
	}
}

