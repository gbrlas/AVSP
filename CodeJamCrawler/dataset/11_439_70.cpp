#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fi("B-large.in");
	ofstream fo("output.txt");

	char a,b,c;
	int C,D,N,NO;
	char output[100];

	int T;fi >> T;
	for(int i = 0; i<T; i++)
	{

		fi >> C;
		char com[256][256] = {0};
		for(int j=0; j<C; j++)
		{
			fi >> a;
			fi >> b;
			fi >> c;
			com[a][b]=com[b][a]=c;
		}
		fi >> D;
		bool opp[28][28] = {0};
		for(int j=0; j<D; j++)
		{
			fi >> a;
			fi >> b;
			opp[a][b]=opp[b][a]=true;
		}

		int exist[256]={0};

		fi >> N;
		
		//cout << "Case " << i+1 << " coms " << C << " opps " << D << " chars " << N << endl;

		if(N>0)
		{
			fi >> output[0];
			NO = 1;
			exist[output[0]]++;

			//cout << output[0] << endl;
			
			for(int j=1; j<N; j++)
			{
				fi >> a;
				if(NO > 0 && com[a][output[NO-1]]!=0)
				{exist[output[NO-1]]--;output[NO-1]=com[a][output[NO-1]];}//cout << "combine\n";}
				else
				{
					c = 0;
					for(int k=0; k<256; k++)
					{
						if(exist[k] && opp[a][k])
						{
							//cout << "oppose\n";
							NO = 0;
							c = 1;
							memset(exist,0,256*sizeof(int));
							break;
						}
					}
					if(c==0)
					{
						output[NO++] = a;
						exist[a]++;
					}
				}

				//cout << NO << " : ";
				//for(int z = 0; z < NO; z++) cout << output[z];
				//cout << endl;

			}
		}
		else
			NO = 0;

		fo << "Case #" << i+1 << ": [";
		for(int i=0;i<NO-1;i++) fo << output[i] << ", ";
		if(NO>0)fo << output[NO-1];fo << "]\n";

	}

	return 0;
}