
#include <iostream>
#include <string>
#include <queue>

using namespace std;

void main()
{
	int nlines;
	int Round, Capacity,groups;
	int total = 0;
    queue<int> q;



	if(freopen("C-small-attempt1.in","r",stdin) == NULL)
		fprintf(stderr, "error redirecting\stdin\n");

	if(freopen("out.out", "w", stdout )==NULL)
		fprintf(stderr, "error redirecting\stdout\n");

	cin>>nlines; 

	for (int i = 1; i<= nlines;i++)
	{
		cin>>Round>>Capacity>>groups;
		int tmp;
		int totalpeople = 0;

		for(int j = 1; j<=groups;j++)
		{
			cin>>tmp;
			q.push(tmp);
			totalpeople += tmp;
		}

		int rr = 1;
		
		while (rr<=Round)
		{
			if (totalpeople <= Capacity)
			{
				total += totalpeople;
			}
			else
			{
		   int test = 0;
           while(test + q.front()<= Capacity)
           {
			   q.push(q.front());		   
               test += q.front();
			   q.pop();
           }
		   total += test;
			}
		   rr++;
		}


		cout<<"Case #"<<i<<": "<<total<<endl;
		total = 0;
		while(!q.empty())
			q.pop();
	}


	return;
}
