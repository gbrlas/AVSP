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


inline	vector<int> intToVector(LL input)
	{
		ostringstream oss;
		oss<<input;
		vector<int> result;
		for(int i = 0 ; i < oss.str ().size (); i++){
			result.push_back(oss.str ()[i] - '0');
		}
		return result;
	}

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

			bool found_main = false;
			
			FORD(j, cur_num.size()-1, 0){
				bool found = false;
				int cur_min = 99, cur_min_pos = 0;
				FOR(k, j+1, cur_num.size()){
					if((cur_num[j] < cur_num[k])&&(cur_min > cur_num[k])){
						/*swap(cur_num[j], cur_num[k]);
						sort(cur_num.begin()+j+1,cur_num.end() );
						*/

						cur_min = cur_num[k];

						cur_min_pos = k;
						found = true;
					//	break;
					}
				}
			
				if(found == true){
					found_main = true;
					swap(cur_num[j], cur_num[cur_min_pos]);
					sort(cur_num.begin()+j+1,cur_num.end() );
					break;
				}
			}
			if(found_main == false){
				cur_num += "0";
				sort(cur_num.begin(), cur_num.end());

				if(cur_num[0] == '0'){
					REP(j, cur_num.size()){
						if(cur_num[j] != '0'){
							swap(cur_num[0], cur_num[j]);
							break;
						}	
					}
				}
			}
			

			
			cout<<"Case #"<<i+1<<": "<<cur_num<<endl;
			file_op<<"Case #"<<i+1<<": "<<cur_num<<endl;
		}
		
}
