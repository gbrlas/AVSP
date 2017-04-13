
#include <iostream>


using namespace std;

void main()
{
	long nlines;
    long N,K;


	if(freopen("A-large.in","r",stdin) == NULL)
		fprintf(stderr, "error redirecting\stdin\n");

	if(freopen("out.out", "w", stdout )==NULL)
		fprintf(stderr, "error redirecting\stdout\n");

	cin>>nlines; 

	for (long i = 1; i<= nlines;i++)
	{
      cin>>N>>K;
	  long mi = 1;
	  for (long i = 1; i<=N;i++)
	  {
		  mi = mi *2;
	  }
	  long tmp = (K % mi);
      if (tmp == (mi -1))
      {
		  cout<<"Case #"<<i<<": ON"<<endl;
      }
	  else
	  {
          cout<<"Case #"<<i<<": OFF"<<endl;
	  }
	}


	return;
}
