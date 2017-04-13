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
#define LL long long
using namespace std;

typedef istringstream ISS;
typedef ostringstream OSS;


void main(void)
{
		char file_line[1000];
		int  N;

		fstream file_ip("c:\\ipfile.txt",ios::in);
		fstream file_op("c:\\opfile.txt",ios::out);

		file_ip.getline( file_line, 1000);
		ISS iss1(file_line);

		iss1>>N;
		REP(i, N){
			
			file_ip.getline( file_line, 1000);
			iss1.clear();
			iss1.str(file_line);


			string cur_num = file_line;

			vector<char> uniq;
			REP(j, cur_num.size()){
				if(find(uniq.begin(), uniq.end(), cur_num[j]) == uniq.end()){
					uniq.push_back(cur_num[j]);
				
				}else{
					continue;
				}
			}
			unsigned long long base = uniq.size();

			vector<int> vals;

			vals.push_back(1);
			vals.push_back(0);

			int trav = 2;

			REP(j, uniq.size()){
				vals.push_back(trav);
				trav++;
			}


			//string result_str;
			vector<int> result_vec;
			REP(j, cur_num.size()){
				REP(k, uniq.size()){
					if(cur_num[j] == uniq[k]){
						result_vec.push_back(vals[k]);
						break;
					}
				}
			}
			cout<<"Uniques = "<<endl;

			REP(j, uniq.size()){
				cout<<uniq[j]<<endl;
			}

			if (base == 1){
				base = 2;
			}

			unsigned long long cur_mult = 1;
			unsigned long long result = 0;

			FORD(j, result_vec.size()-1, 0){

				result += (cur_mult * result_vec[j]);

				cur_mult *= base;
			
			}
			cout<<"Case #"<<i+1<<": "<<result<<endl;
			file_op<<"Case #"<<i+1<<": "<<result<<endl;
		}
		
}
