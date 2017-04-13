#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;

static map<char, char> trans_map;

class Pair
{
public:
	char eng;
	char goog;
};

void translate(string goog, char* eng)
{
	int i;
	for(i = 0; i<goog.size(); i++)
	{
		if(goog[i]==' ')
		{
			eng[i]=' ';
		}
		else
			eng[i] = trans_map[goog[i]];
	}
	eng[i]='\0';

}

int main()
{
	//vector<Pair> maps;
	trans_map.insert(make_pair('y','a'));
	trans_map.insert(make_pair('n','b'));
	trans_map.insert(make_pair('f','c'));
	trans_map.insert(make_pair('i','d'));
	trans_map.insert(make_pair('c','e'));
	trans_map.insert(make_pair('w','f'));
	trans_map.insert(make_pair('l','g'));
	trans_map.insert(make_pair('b','h'));
	trans_map.insert(make_pair('k','i'));
	trans_map.insert(make_pair('u','j'));
	trans_map.insert(make_pair('o','k'));
	trans_map.insert(make_pair('m','l'));
	trans_map.insert(make_pair('x','m'));
	trans_map.insert(make_pair('s','n'));
	trans_map.insert(make_pair('e','o'));
	trans_map.insert(make_pair('v','p'));
	trans_map.insert(make_pair('z','q'));
	trans_map.insert(make_pair('p','r'));
	trans_map.insert(make_pair('d','s'));
	trans_map.insert(make_pair('r','t'));
	trans_map.insert(make_pair('j','u'));
	trans_map.insert(make_pair('g','v'));
	trans_map.insert(make_pair('t','w'));
	trans_map.insert(make_pair('h','x'));
	trans_map.insert(make_pair('a','y'));
	trans_map.insert(make_pair('q','z'));
	

	ifstream infile("A-small-attempt2.in");
	int k = 0;
	infile>>k;
	int i = 0;
	string line;
	vector<char*> new_line_addrs;

	

	while(i<=k)
	{
		getline(infile,line);
		if(i>0)
		{
		char* new_line = new char[line.size()+1];
		translate(line,new_line);
		new_line_addrs.push_back(new_line);
		}
		i++;
	}
	infile.close();
	infile.clear();

	ofstream outfile;
	outfile.open("output");


	i =0;
	while(i<k)
	{
		outfile<<"Case #"<<i+1<<": "<<new_line_addrs[i]<<endl;
		i++;
	}
	outfile.close();
	outfile.clear();

}
