#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

const int inf = 100000000;


const int NMAX = 1000;
int p, q;
int num[NMAX];
bool isEmpty[NMAX];

int result;



void f(int leftToRelease, int price)
{

	if(leftToRelease == 0)
	{
		result = min(price,result);
   	    
	}
	else
	{
		for(int i=0;i<q;i++)
		{
			if(!isEmpty[num[i]])
			{
			    int t1 = num[i]-1;
				int t2 = num[i]+1;
                isEmpty[num[i]]=true;

				int gold=0;
				while(!isEmpty[t1])
				{
				    gold++;
					t1--;
				}

				while(!isEmpty[t2])
				{
				    gold++;
					t2++;
				}

				f(leftToRelease-1,price+gold);
				isEmpty[num[i]]=false;

			}
		}
	
	}

}




int main()
{

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int N; 
	fin >> N;
	


	for(int T=0;T<N; ++T)
	{
	    fin >>  p >> q;

		result = inf;
		for(int i=0;i<q;i++)
		{
		   fin >> num[i];
		}


		for(int i=1;i<=p; ++i)isEmpty[i]=false;

		isEmpty[0]=true;
		isEmpty[p+1]=true;

		

		f(q,0);

		
		fout <<"Case #" << T+1 <<": " << result <<std::endl;
		


	}




    return 0;
}