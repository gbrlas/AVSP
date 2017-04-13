#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>


#define FOR(x,b,e) for (int x = (b); x < (e); ++x)
#define FORD(x,b,e) for (int x = (b); x >= (e); --x)
#define REP(x,n) for (int x = 0; x < (n); ++x)
#define ALL(c) c.begin(), c.end()
#define SIZE(x) (int)x.size()
#define PB push_back
 
using namespace std;

typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000001;

typedef istringstream ISS;
typedef ostringstream OSS;


void	main(void)
{
		int L, D, N;
		string ip;
		string num, lang, dest_lang;
	
		char file_line[10000];

		fstream file_ip("c:\\ipfile.txt",ios::in);

		fstream file_op("c:\\opfile.txt",ios::out);

		file_ip.getline( file_line, 10000);
		ISS iss1(file_line);
		iss1>>L>>D>>N;
		cout<<"Number of ip : "<<N<<endl;
		
		vector<string> dict(D, "");

		REP(i, D){

			file_ip.getline( file_line, 10000);
			ISS iss1(file_line);
			dict[i] = file_line;			
		}

		cout<<"Dictionary : "<<endl;
		REP(i, D){
			cout<<dict[i]<<endl;
		}

		REP(i, N){
			vector<string> cur_word(L,"");

			file_ip.getline( file_line, 10000);
			ISS iss1(file_line);

			bool in_bracket = false;
			int cur_letter = 0;

			string initial = file_line;

			REP(j, initial.size()){
				if(initial[j] == '('){
					in_bracket = true;
					continue;
				}else if(initial[j] == ')'){
					in_bracket = false;
					cur_letter++;
					continue;
				}else{
					cur_word[cur_letter] += initial[j];
					if(in_bracket == false)
						cur_letter++;
				}

			}

			int count = 0;

			REP(j, D){
				bool found = true;
				REP(k, L){
					if(find(cur_word[k].begin(), cur_word[k].end(), dict[j][k]) ==  cur_word[k].end()){
						found = false;
						break;
					}
				}
				if(found == true)
					count++;					
			}

			cout<<"Case #"<<i+1<<": "<<count<<endl;

			file_op<<"Case #"<<i+1<<": "<<count<<endl;

		}
		
}
