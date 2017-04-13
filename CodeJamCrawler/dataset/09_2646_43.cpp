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

int		input[100][100];
int		rows, cols;

inline pair<int, int> find_SN(int x, int y)
{
	pair <int, int>  result;

	int cur_min = input[x][y];

	int ptr = -1;

	if((x-1) >=0){
		if(input[x-1][y] < cur_min){
			cur_min = input[x-1][y];
			ptr = 1;
		}
	}
	if((y-1) >=0 ){
		if(input[x][y-1] < cur_min){
			cur_min = input[x][y-1];
			ptr = 2;
		}
	}

	if(y+1 < cols){
		if(input[x][y+1] < cur_min){
			cur_min = input[x][y+1];
			ptr = 3;
		}
	}
	if(x+1 < rows){
		if(input[x+1][y] < cur_min){
			cur_min = input[x+1][y];
			ptr = 4;
		}
	}
	
		switch(ptr){

			case -1:
				result.first = -1;
				result.second = -1;
				break;

			case 1:
				result.first = x-1;
				result.second = y;
				break;
			
			case 2:
				result.first = x;
				result.second = y-1;
				break;
			case 3:
				result.first = x;
				result.second = y+1;
				break;
			case 4:
				result.first = x+1;
				result.second = y;
				break;
			default:
				result.first = -1;
				result.second = -1;
				break;
		}

		return result;

}

void	main(void)
{
		int N;
		string ip;
		string num, lang, dest_lang;
	
		char file_line[10000];

		fstream file_ip("c:\\ipfile.txt",ios::in);

		fstream file_op("c:\\opfile.txt",ios::out);

		file_ip.getline( file_line, 10000);
		ISS iss1(file_line);
		iss1>>N;
		cout<<"Number of ip : "<<N<<endl;

		REP(i, N){

			file_ip.getline( file_line, 10000);
			ISS iss1(file_line);

			iss1>>rows>>cols;

			char	color[1000][1000];

			//char	all_colors[] = "abcdefghijklmnopqrstuvwxyz";
			char	cur_color = 'a';

			REP(j, rows){
				file_ip.getline( file_line, 10000);
				ISS iss2(file_line);

				REP(k, cols){
					color[j][k] = 'A';
					iss2>>input[j][k];
				
				}
			}

			REP(j, rows){
				REP(k, cols){
					if(color[j][k] == 'A'){
						pair<int, int> SN = find_SN(j, k);
						if(SN.first != -1){
							if(color[SN.first][SN.second] == 'A'){
								color[SN.first][SN.second] = cur_color;
								color[j][k] = cur_color;
								cur_color++;
							}else{
								color[j][k] = color[SN.first][SN.second];
							
							}
						}else{
							color[j][k] = cur_color;
							cur_color++;				
						}
					}else{

						pair<int, int> SN = find_SN(j, k);
						if(SN.first != -1){
							if(color[SN.first][SN.second] == 'A'){
								color[SN.first][SN.second] = color[j][k];						
							}else{
								char ll = min(color[SN.first][SN.second],color[j][k]);
								char lh = max(color[SN.first][SN.second],color[j][k]);
								cout<<"That condition !!  x = "<< j<<"  y = "<<k<<" low col : "<<ll <<"  high col : "<<lh<<endl;
								REP(l, rows){
									REP(m, cols){
										if(color[l][m] == 'A')
											continue;
										if(color[l][m] == lh)
											color[l][m] = ll;
										if(color[l][m] > lh)
											color[l][m]--;

									}
								}
								cur_color--;
							}
						}
					}
				}
				
			}
			cout<<"Case #"<<i+1<<":"<<endl;

			file_op<<"Case #"<<i+1<<":"<<endl;

			REP(j, rows){
				REP(k, cols){
					cout<<" "<<color[j][k]<<" ";
					file_op<<" "<<color[j][k]<<" ";
					
				}
				cout<<endl;
				file_op<<endl;
			}
		}	

}
		

