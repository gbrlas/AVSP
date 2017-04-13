#include<cstdio>
#include<vector>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>

#define TEST
using namespace std;

struct pack
{
	bool row;
	int no;
};

pack funct(int lawn[][100],int N,int M)
{
	int min=101;
	pack res;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(lawn[i][j]<min)min=lawn[i][j];
	for(int i=0;i<N;i++)
	{
		int sum=0;
		for(int j=0;j<M;j++)
		{
			sum+=lawn[i][j];
		}
		if(sum==M*min)
		{
	 		res.row=true;
	 		res.no=i;
	 		return res;
		}
	}
	for(int i=0;i<M;i++)
	{
		int sum=0;
		for(int j=0;j<N;j++)
		{
			sum+=lawn[j][i];
		}
		if(sum==N*min)
		{
			res.row=false;
			res.no=i;
			return res;
		}
	}
	res.row=false;
	res.no=-999;
	return res;
}

class problem
{
	private:
		int TestCaseNo;
		int N,M;
		int lawn[100][100];
	public:
		friend pack funct(int lawn[][100],int N,int M);
		static int TestNo;
		explicit problem()
		{
			TestNo++;
			TestCaseNo=TestNo;
			scanf("%d %d",&N,&M);
			for(int i=0;i<N;i++)
				for(int j=0;j<M;j++)
					scanf("%d",&lawn[i][j]);
		}
		void change(pack p)
		{
			if(p.row)
			{
				for(int i=p.no;i<N;i++)
					for(int j=0;j<M;j++)
						lawn[i][j]=lawn[i+1][j];
				N--;
			}
			if(!p.row)
			{
				for(int i=p.no;i<M;i++)
					for(int j=0;j<N;j++)
						lawn[j][i]=lawn[j][i+1];
				M--;
			}
		}
		
		bool solve()
		{
			bool res=true;
			while(!(N==1||M==1))
			{
				pack p=funct(lawn,N,M);
				if(p.no==-999)
				{	
					res=false;
					break;
				}
				change(p);
			}
			return res;
		}
		
		void answer()
		{
			if(solve())	
				printf("Case #%d: YES\n",TestCaseNo);
			else
				printf("Case #%d: NO\n",TestCaseNo);
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
	{
		problem p=problem();
		p.answer();
	}
	#ifdef TEST
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}