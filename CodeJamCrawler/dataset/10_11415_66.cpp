// hila4321 gmail.com
#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	ifstream input("C-large.in");
	ofstream output("C-large.out");

	int T,R,k,N;
	int g[1000];
	int next[1000]; // points to the next group that will be in the head of the queue if we're first now
	int size[1000]; // number of people that ride when group i is in the head of the queue
	//bool visit[1000]; // have we been here before?

	input >> T;
	for (int i=1; i<=T; i++)
	{
		unsigned long long money = 0;
		int current = 0;

		input >> R >> k >> N;

		for (int j=0; j<N; j++){
			input >> g[j];
		//	visit[j] = false;
		}

		// set the "next group" and "size current people on te ride" arrays
		int people = 0; int next_index = 0;
		for (int j=0; j<N; j++)
		{
			int p = next[j] = next_index;
			while (people +g[p]<=k)
			{
				people += g[p];
				p++;
				if (p>=N){p-=N;}
				next[j] = p;
				if (p==j)
					break;
			}
			size[j] = people;
			people -= g[j];
			next_index = p;
		}

		// go over the array, and sum up the money.
		for (int j=1; j<=R; j++)
		{
			//if ( (current == 0) && (visit[current]==true) && (R/(j-1)>0) )
			//	// then it's a cycle! we can save time.
			//{
			//	int p = j-1;
			//	money = (R/p)*money;
			//	j = (R/p)*p + 1;
			//}
			//else
			//{
				money += size[current];
				//visit[current] = true;
				current = next[current];
			//}
		}

		output << "Case #" << i << ": " << money << endl;
	}

	input.close();
	output.close();
}
