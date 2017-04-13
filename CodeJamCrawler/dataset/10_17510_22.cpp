#include <iostream>

using namespace std;





void main()
{
	int nlines = 0;
	int N;
    int Num[2][2];
	memset(Num,0,sizeof(Num));

	if(freopen("A-small-attempt1.in","r",stdin) == NULL)
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
				for (int k = 0; k<=1;k++)
					cin>>Num[j][k];


			if (Num[0][0]-Num[1][0] > 0 && Num[0][1] - Num[1][1] < 0 || Num[0][0]-Num[1][0] < 0 && Num[0][1] - Num[1][1] > 0)
			{
				cout<<"Case #"<<i<<": 1"<<endl;
			}
			else
			{
               cout<<"Case #"<<i<<": 0"<<endl;
			}
		}


	}


	return;
}