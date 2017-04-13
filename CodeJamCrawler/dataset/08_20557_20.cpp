#include <fstream>

using namespace std;

long long int n;

//int marray[2000000000];
double sq = 5.23606797749978969640917366873127623544061835961152572427089; //59 dupa virgula
long double rez=1;

int sqit[61] = {40,5,2,3,6,0,6,7,9,7,7,4,9,9,7,8,9,6,9,6,4,0,9,1,7,3,6,6,8,7,3,1,2,7,6,2,3,5,4,4,0};
int sqi[61] = {40};
int rezi[200]= {1,1};

void mul(int A[], int B[])
{
      int i, j, t, C[200];
      memset(C, 0, sizeof(C));
      for (i = 1; i <= A[0]; i++)
      {
              for (t=0, j=1; (j <= B[0]) || t; j++, t/=10)
                      C[i+j-1]=(t+=C[i+j-1]+A[i]*B[j])%10;
              if (i + j - 2 > C[0]) C[0] = i + j - 2;
      }
      memcpy(A, C, sizeof(C));
}

void calculate()
{
	mul(rezi,sqi);
	for(long long int i=1;i<n;i++)
	{
		//rez=rez*sq;
		mul(rezi,sqi);
		for(int z=40;z<=rezi[0];z++)
		{
			rezi[z-39]=rezi[z];
		}
		rezi[0]-=39;
	}
}

int combo(long long int k)
{
	return (0);
}

int TKplus1()
{
	// combinatii de n cate k * a^n-k * b^k

	return 0;
}

int main()
{
	ifstream f("input.in");
	ofstream f2("output.out");

	for(int i=1;i<41;i++)
	{
		sqi[40-i+1]=sqit[i];
	}

	int X;
	f>>X;
	for(int T=0;T<X;T++)
	{
		f>>n;
		calculate();
		//f2<<rez<<endl;
		f2<<"Case #"<<T+1<<": ";
		for(int i=42;i>=40;--i)
		{
			if(rezi[0]>=i)
				f2<<rezi[i];
			else
				f2<<0;
		}
		f2<<endl;
		rez=1;
		for(int h=0;h<200;h++)
			rezi[h]=0;
		rezi[0]=1;
		rezi[1]=1;

	}


	f.close();
	f2.close();

	return 0;
}