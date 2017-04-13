# include<iostream>
# include <string.h>
# include<stdlib.h>

using namespace std;

int land[102][102],q[10010],top,basin[102][102],h,w,nob,tt;
int abhisar[100];

void insert(int i,int j)
	{
	int l,m,flag = 0;
	for(l=0;l<top;l++)
		{
		if(land[i][j] >= land[q[l]%h][q[l]/h])
			{
			for(m=top;m>l-1;m--)
				{
				q[m+1] = q[m];
				}
			q[l] = j*h + i;
			top++;
			flag = 1;
			break;
			}
		}
	if(flag == 0)
		{
		top++;
		q[top -1] = j*h + i;
		}
		
	}

int main()
	{
	int no,zo=1;
	scanf("%d",&no);
	while(zo<=no)
		{
		int i,j,temp1,temp2;
	
		scanf("%d%d",&h,&w);
		//q = (int *)calloc(h*w,sizeof(int));
		//basin = (int *)calloc(h*w,sizeof(int));
		memset(abhisar,0,sizeof(int)*30);
		tt=0;
		memset(basin,0,sizeof(int)*10000);
		memset(land,0,sizeof(int)*10000);
		memset(q,0,sizeof(int)*10000);
		top = 0;
		nob = 0;
	
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				{
				scanf("%d",&land[i][j]);
				insert(i,j);
				}
		int mast = top;
		while(top)
			{
			int z = top -1;
			temp2 = 999;
			if(((basin[q[z]%h+1][q[z]/h]==0) || (q[z]%h == h-1)) && ((basin[q[z]%h - 1][q[z]/h]==0) || (q[z]%h == 0)) && ((basin[q[z]%h][(q[z]/h + 1)]==0) || (q[z]/h == w-1)) && ((basin[q[z]%h][(q[z]/h-1)]==0) || (q[z]/h == 0)))
				{
				nob++;
				basin[q[z]%h][(q[z]/h)] = nob;
				//printf("land[%d][%d] =  %d = %d \n",q[z]%h,q[z]/h,land[q[z]%h][q[z]/h],q[z]);
				}
			else
				{
				if((q[z]%h > 0) && (temp2 > land[q[z]%h - 1][q[z]/h]))
					{
					temp1 = basin[q[z]%h-1][(q[z]/h)];
					temp2 = land[q[z]%h - 1][q[z]/h];
					//printf("hi\n");
					}
				
				if((temp2 > land[q[z]%h][q[z]/h - 1]) && (q[z]/h > 0))
					{
					temp1 = basin[q[z]%h ][(q[z]/h-1)];
					temp2 = land[q[z]%h][q[z]/h - 1];
					//printf("hi\n");
					}
				
				if((temp2 > land[q[z]%h][q[z]/h + 1]) && (q[z]/h < w-1))
					{
					temp1 = basin[q[z]%h ][ (q[z]/h + 1)];
					temp2 = land[q[z]%h][q[z]/h + 1];
					//printf("hi\n");
					}
				if((q[z]%h < h-1) && (temp2 > land[q[z]%h + 1][q[z]/h]))
					{
					temp1 = basin[q[z]%h+1][(q[z]/h)];
					temp2 = land[q[z]%h + 1][q[z]/h];
				
					}			
							
				if(temp2 == land[q[z]%h][q[z]/h])
					{
					nob++;
					basin[q[z]%h][(q[z]/h)] = nob;
					}
				else
				basin[q[z]%h ][(q[z]/h)] = temp1;
				//printf("%d\n",basin[q[z]%h + q[z]]);
				}
			top--;
			}
		//abhisar = (char *)calloc(nob,sizeof(char));
		//for(i = 0;i<nob;i++)
		//	abhisar[i] = 0;
		
		tt = (int)'a';
		//cout<<basin[0][0] - 1<<" "<<tt<<endl;
		abhisar[basin[0][0] - 1] = tt;
		
	printf("Case #%d:\n",zo);
		for(i=0;i<h;i++)
			{
			for(j=0;j<w-1;j++)
				{
				if((int)abhisar[basin[i][j]- 1] != 0)
					{
					printf("%c ",(char)abhisar[basin[i][j]- 1]);
					}
				else
					{
					tt++;
					abhisar[basin[i][j]- 1] = (char)tt;
					printf("%c ",(char)abhisar[basin[i][j]- 1]);
					}
				}
				if((int)abhisar[basin[i][j]- 1] != 0)
					{
					printf("%c",(char)abhisar[basin[i][j]- 1]);
					}
				else
					{
					tt++;
					abhisar[basin[i][j]- 1] = (char)tt;
					printf("%c",(char)abhisar[basin[i][j]- 1]);
					}
			printf("\n");
			
			}
			zo++;
			//free(q);
			//free(abhisar);
			}
	}
