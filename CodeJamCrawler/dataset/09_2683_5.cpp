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
		int  C;

		fstream file_ip("c:\\ipfile.txt",ios::in);
		fstream file_op("c:\\opfile.txt",ios::out);

		file_ip.getline( file_line, 1000);
		ISS iss1(file_line);

		iss1>>C;
		REP(i, C){
			
			file_ip.getline( file_line, 1000);
			iss1.clear();
			iss1.str(file_line);

			int n;

			iss1>>n;

			int x[50];
			int y[50];
			int r[50];

			REP(j, n){

				file_ip.getline( file_line, 1000);
			iss1.clear();
			iss1.str(file_line);

				iss1>>x[j]>>y[j]>>r[j];
					
			}

			long double rv = 0.0;
			if(n == 1){
				cout<<"Case #"<<i+1<<": "<<r[0]<<endl;
					file_op<<"Case #"<<i+1<<": "<<r[0]<<endl;
					continue;

			}
			if(n == 2){
	//return max(r[0], r[1]);
	cout<<"Case #"<<i+1<<": "<<max(r[0], r[1])<<endl;
					file_op<<"Case #"<<i+1<<": "<<max(r[0], r[1])<<endl;
					continue;
			}
//cout << "here\n";

long double v1,v2,v3;
long dx1 = x[1]-x[0];
long dy1 = y[1]-y[0];
long dr1 = r[1]+r[0];
long r1 = r[2];
long dx2 = x[2]-x[0];
long dy2 = y[2]-y[0];
long dr2 = r[2]+r[0];
long r2 = r[1];
long dx3 = x[1]-x[2];
long dy3 = y[1]-y[2];
long dr3 = r[1]+r[2];
long r3 = r[0];

long dx = dx1;
long dy = dy1;
v1 = sqrt((long double)(dx*dx*1.0) + (long double)(dy*dy*1.0))+dr1;

dx = dx2;
dy = dy2;
v2 = sqrt((long double)(dx*dx*1.0) + (long double)(dy*dy*1.0))+dr2;
dx = dx3;
dy = dy3;
v3 = sqrt((long double)(dx*dx*1.0) + (long double)(dy*dy*1.0))+dr3;

v1 = max((long double)v1, (long double)r1);
v2 = max((long double)v2, (long double)r2);
v3 = max((long double)v3, (long double)r3);
rv = v1;
//rv = max((long double)rv, (long double)v1);
rv = min((long double)rv, (long double)v2);
rv = min((long double)rv, (long double)v3);







					cout<<"Case #"<<i+1<<": "<<rv/2.0<<endl;
					file_op<<"Case #"<<i+1<<": "<<rv/2.0<<endl;
		}
		
}
