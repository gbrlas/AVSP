#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <string>
#include <fstream>

using namespace std;

const int inf = 100000000;
char res[102][102];
char res2[102][102];

int a[102][102];

struct vert
{
	int i;
	int j;
	
};


bool compare(vert aa,vert bb)
{
	return a[aa.i][aa.j]<a[bb.i][bb.j];

}
vert arr[100100];
vert q[100100];

int dx[4] = {-1, 0,0,1};
int dy[4] = { 0,-1,1,0};

int main()
{

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	for(int t=0;t<n;t++)
	{
 
		int h,w;
		fin >> h >>w;

		char curletter = 'a';
		for(int i=0;i<=h+1;i++)
		{
		   a[i][0]=inf;
		   a[i][w+1]=inf;
		}

		for(int j=0;j<=w+1;j++)
		{
		    a[0][j]=inf;
			a[h+1][j]=inf;
		}

		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
			       res[i][j]='.';	

		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
			   fin >> a[i][j];
               arr[(i-1)*w+j].i=i;
			   arr[(i-1)*w+j].j=j;
			 

			}
		}



		sort(arr+1,arr+w*h+1,compare);

		
		for(int i=1;i<=w*h;i++)
		{
		   if(res[arr[i].i][arr[i].j]!='.')continue;

		   int head = 0;
		   int tail = 1;
		   q[0].i=arr[i].i;
		   q[0].j=arr[i].j;

		   vert u;
		   while(head<tail)
		   {
			   u=q[head++];
			   res[u.i][u.j]=curletter;

			   for(int j=0;j<4;j++)
			   {
				 
				   if(a[u.i][u.j]>=a[u.i+dx[j]][u.j+dy[j]] || a[u.i+dx[j]][u.j+dy[j]]==inf)continue;
				  
				   vert v;
				   v.i=-1;
				   v.j=-1;
				   int h = inf;
				   for(int k=0;k<4;k++)
				   {
					   if(h>a[u.i+dx[j]+dx[k]][u.j+dy[j]+dy[k]])
					   {
						   v.i=u.i+dx[j]+dx[k];
						   v.j=u.j+dy[j]+dy[k];
                           h = a[u.i+dx[j]+dx[k]][u.j+dy[j]+dy[k]];					  
					   }
				   }
                   
				   if(u.i == v.i && u.j==v.j)
				   {
					   v.i=u.i+dx[j];
					   v.j=u.j+dy[j];
				       res[v.i][v.j] = curletter;
					   q[tail++]=v;
				   }
			   }
		   
		   }

		   curletter+=1;


		}

		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				res2[i][j]='.';

		curletter = 'a';
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
		
				if(res2[i][j]!='.')continue;
			   char c = res[i][j];



			   int head = 0;
			   int tail =1;
			   q[0].i=i;
			   q[0].j=j;
               
			   res2[q[0].i][q[0].j] = curletter;
			   vert u;
			   while(head < tail)
			   {
			       u=q[head++];

				   for(int ii=0;ii<4;ii++)
				   {
					   if(res[u.i+dx[ii]][u.j+dy[ii]] == c && res2[u.i+dx[ii]][u.j+dy[ii]]=='.')
					   {
					       res2[u.i+dx[ii]][u.j+dy[ii]] = curletter;
						   vert v;
						   v.i = u.i+dx[ii];
						   v.j = u.j+dy[ii];
						   q[tail++] = v;
					   }
				   }
			   }
               curletter+=1; 

			}
		
		}


		fout << "Case #"<<t+1<<": "<<endl;
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
			   fout << res2[i][j] <<" ";
			}
			fout << endl;
		}

	}




    return 0;
}