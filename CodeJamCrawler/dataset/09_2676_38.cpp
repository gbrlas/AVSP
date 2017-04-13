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


long long process(int P, vector<int> &seq)
{

	long long result = 0;

	vector<int> jail;

	REP(i, P+1){
		jail.push_back(1);
	}

	REP(i, seq.size()){
		jail[seq[i]] = 0;
		FOR(j, seq[i]+1, jail.size()){
			if(jail[j] == 0){
				break;
			}else{
				result++;
			}
		}
		FORD(j, seq[i]-1, 1){
			if(jail[j] == 0){
				break;
			}else{
				result++;
			}
		}
		
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

			int P, Q;

			iss1>>P>>Q;

			file_ip.getline( file_line, 1000);
			iss1.clear();
			iss1.str(file_line);

			vector<int> priss;


			REP(j, Q){
				int cur_pris;
				iss1>>cur_pris;
				priss.push_back(cur_pris);
			}

			sort(priss.begin(), priss.end());

			long long min = 999999999;

			do{
				long long cur_min = process(P, priss);
				
			//	cout<<"Seq used = "<<endl;

			//	REP(k, priss.size()){
		//			cout<<"  "<<priss[k]<<"  ";
		//		}


			//	cout<<"Cur min : "<<cur_min;
				
				if(cur_min < min){
					min = cur_min;
				}
				
			}while(next_permutation(priss.begin(), priss.end()));

			cout<<"Case #"<<i+1<<": "<<min<<endl;
			file_op<<"Case #"<<i+1<<": "<<min<<endl;
		}
		
}
