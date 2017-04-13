#include<iostream>
#include<fstream>
#include<strstream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;


void solve(int num);
ifstream input("test");
ofstream output("result");

void main()
{
	int nCase;	
	input>>nCase;

	for(int nc = 1; nc <= nCase; nc++)
	{
		//string temp;
		//getline(input, temp);
		//istrstream ost(temp.c_str());
		solve(nc);	
	}

		//output<<"Case #"<<nc<<": "<<"IMPOSSIBLE"<<endl;
		//cout<<"Case #"<<nc<<": "<<"IMPOSSIBLE"<<endl;	

}

void solve(int num)
{
		int M, N;
		long A;
		input>>N>>M>>A;
		int flag = 1;
		//for(int x1 = 0; x1 <= N; x1++)
		//{
		//	for(int x2 = x1; x2<=N; x2++ )
		//	{
		//		for(int x3 = x2; x3<=N; x3++)
		//		{
		//			for(int y1=x1;y1<=M;y1++)
		//			{
		//				for(int y2=0; y2<=M;y2++)
		//				{
		//					for(int y3=0;y3<=M;y3++)
		//					{
		//						if( (x1==x2 && x2==x3) || (y1 == y2 && y2 == y3) ||(x1==x2 && y1==y2) || (x1==x3 && y1==y3) || (x2 ==x3 && y2==y3) )
		//							continue;
		//						else
		//						{
		//							long area = x1*y2+x2*y3+x3*y1 - x1*y3-x2*y1-x3*y2;
		//							if(area < 0)
		//								area = -area;
		//							if(area == A)
		//							{
		//								//output<<"Case #"<<num<<": "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
		//								cout<<"Case #"<<num<<": "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
		//								return;
		//							}
		//						}
		//					}
		//				}
		//			}
		//		}
		//	}
		//}

		for(int x2 = 0; x2 <= N; x2++)
		{
			for(int x3 = x2; x3<=N; x3++)
			{
				if(x2 == 0 && x3 == 0)
					continue;
				for(int y2 = 0; y2 <= M; y2++)
				{
					for(int y3 = 0; y3<= M; y3++)
					{
						if(y2 == y3 && x2 == x3)
							continue;
						if(y2 == 0 && y3 == 0)
							continue;
						long area = abs(x2 * y3 - x3 * y2);
						if(area == A)
						{
									output<<"Case #"<<num<<": "<<"0"<<" "<<"0"<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
									//cout<<"Case #"<<num<<": "<<"0"<<" "<<"0"<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
									return;
						}
						
					}
				}
			}
		}

		output<<"Case #"<<num<<": "<<"IMPOSSIBLE"<<endl;
		//cout<<"Case #"<<num<<": "<<"IMPOSSIBLE"<<endl;	

}
