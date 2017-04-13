#include<cstdio>
#include<vector>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>

#define TEST
using namespace std;
class problem
{
	private:
		int board[4][4];
		int TestCaseNo;
	public:
		static int TestNo;
		explicit problem()
		{
			TestNo++;
			TestCaseNo=TestNo;
			getchar();
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					char temp;
					int val=5;
					scanf("%c",&temp);
					switch(temp)
					{
						case 'X':
						{
							val=1;
							break;
						}
						case 'O':
						{
							val=100;
							break;
						}
						case 'T':
						{
							val=10;
							break;
						}
						case '.':
						{
							val=0;
							break;
						}
						default:
						{
							val=3;
							break;
						}
					}
					board[i][j]=val;
				}
				getchar();
			}
			//getchar();
		}
		
		/*void display()
		{
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					printf("%d\t",board[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}*/
		
		char check()
		{
			int sum;
			char winner;
			for(int i=0;i<4;i++)
			{
				sum=0;
				for(int j=0;j<4;j++)
					sum+=board[i][j];
				if(sum==4||sum==13)
				{
					winner='x';
					return winner;
				}
				else if(sum==400||sum==310)
				{
					winner='o';
					return winner;
				}
			}
			
			
			for(int i=0;i<4;i++)
			{
				sum=0;
				for(int j=0;j<4;j++)
					sum+=board[j][i];
				if(sum==4||sum==13)
				{
					winner='x';
					return winner;
				}
				else if(sum==400||sum==310)
				{
					winner='o';
					return winner;
				}
			}
			sum=board[0][0]+board[1][1]+board[2][2]+board[3][3];
			if(sum==4||sum==13)
			{
				winner='x';
				return winner;
			}
			else if(sum==400||sum==310)
			{
				winner='o';
				return winner;
			}
			sum=board[0][3]+board[1][2]+board[2][1]+board[3][0];
			if(sum==4||sum==13)
			{
				winner='x';
				return winner;
			}
			else if(sum==400||sum==310)
			{
				winner='o';
				return winner;
			}
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					if(board[i][j]==0)
					{
						winner='n';
						return winner;
					}
				}
			}
			return 'd';
		}
			
		void solve()
		{
			char ans=check();
			char Sol[20];
			if(ans=='x') strcpy(Sol,"X won");
			else if(ans=='o') strcpy(Sol,"O won");
			else if(ans=='n') strcpy(Sol,"Game has not completed");
			else if(ans=='d') strcpy(Sol,"Draw");
			printf("Case #%d: %s\n",TestCaseNo,Sol);
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
		p.solve();
	}
	#ifdef TEST
	fclose(stdin);
	fclose(stdout);
	#endif

	return 0;
}