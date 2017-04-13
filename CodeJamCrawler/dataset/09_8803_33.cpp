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
  
string next_num (string, string);
void main(void)
{
		int num_ips;
		string ip;
		string num, lang, dest_lang;

		fstream file_ip("c:\\ipfile.txt",ios::in);

		fstream file_op("c:\\opfile.txt",ios::out);

		file_ip>> ip;
		ISS iss1(ip);
		iss1>>num_ips;



	
		string cur_num, dest_num;
		long long count = 1, count_dest = 1;

		REP(i, num_ips){
			count = 1;
			count_dest = 1;
			file_ip >> num;
			file_ip >> lang;
			file_ip >> dest_lang;

			cout<<"Num = "<<num <<"  lang = "<<lang<<"destination lang = "<<dest_lang<<endl;

			cur_num = lang[1];

			while(cur_num != num){
				
				count++;
				cur_num = next_num(lang, cur_num);
			}
			cout<<"Current count = "<<count<<endl;

			dest_num = dest_lang[1];

			while(count_dest < count){
				count_dest++;
				dest_num = next_num(dest_lang, dest_num);			
			}

			cout<<"Case #"<<i+1<<": "<<dest_num<<endl;
			file_op<<"Case #"<<i+1<<": "<<dest_num<<endl;

		}
        file_op.close();
		file_ip.close();

}


inline string next_num(string lang, string cur_num)
{
	int inc = 0;

	FORD(i, cur_num.length(), 0){
		FOR(j, 0, lang.length()){
			if(cur_num[i] == lang[j]){
				if(j != lang.length()-1){
					inc = 1;
					cur_num[i] = lang[j+1];
					FOR(k, i+1, cur_num.length()){
						cur_num[k] = lang[0];
					}
				}
				break;
			}		
		}
		if(inc == 1)
			break;	
	}
	if(inc == 0){
		string result="" ;
		result += lang[1];

		REP(i, cur_num.length()){
			result += lang[0];
		}
		return result;
	}else{
		return cur_num;
	}
}