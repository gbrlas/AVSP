#include <iostream>

using namespace std;


const int size = 1010;


void main()
{
	int nlines = 0;
	int N;
    int Num[size][2];
	memset(Num,0,sizeof(Num));

	long total = 0;

	if(freopen("A-large.in","r",stdin) == NULL)
		fprintf(stderr, "error redirecting\stdin\n");

	if(freopen("out.out", "w", stdout )==NULL)
		fprintf(stderr, "error redirecting\stdout\n");

	cin>>nlines; 

	for (int i = 1; i<= nlines; i++)
	{
		cin>>N;

		if (N == 1)
		{
			for (int j = 0; j <N;j++ )
				for (int k = 0; k<=1;k++)
					cin>>Num[j][k];
			cout<<"Case #"<<i<<": 0"<<endl;
		}
		else
		{
			for (int j = 0; j <N;j++ )
			{ 
                cin>>Num[j][0]>>Num[j][1];

				for (int k = 0; k<j; k++)
				{
					if (Num[k][0]-Num[j][0] > 0 && Num[k][1] - Num[j][1] < 0 || Num[k][0]-Num[j][0] < 0 && Num[k][1] - Num[j][1] > 0)
						total++;
				}
			}

			cout<<"Case #"<<i<<": "<<total<<endl;
		}
         total = 0;

	}


	return;
}