#include<cstdio>
#include<vector>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>

#define TEST
using namespace std;

//const double pi=3.14159265359;

class problem
{
	private:
		int TestCaseNo;
		int r;
		int t;
		int n;
		double Area;
		double TestArea;
	public:
		static int TestNo;
		explicit problem()
		{
			TestNo++;
			TestCaseNo=TestNo;
			scanf("%d %d",&r,&t);
			Area=t;
			int n=0;
			TestArea=0;
			while(!(TestArea>Area))
			{
				double A=(r+2*n+1)*(r+2*n+1)-(r+2*n)*(r+2*n);
				TestArea+=A;
				//if(TestArea==Area)n++;
				n++;
			}
			n--;
			printf("Case #%d: %d \n",TestCaseNo,n);
		}
};

int problem::TestNo=0;

int main()
{
	#ifdef TEST
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif
	
	int T;
	scanf("%d",&T);
	while(T--)
		problem p=problem();
		
	#ifdef TEST
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}




