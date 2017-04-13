#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;
char kal[105];
int pos[105];

int mut(int x)
{
	if(x<0)return (-1*x);
	return x;
}

int main()
{
    int t;
    int n;
    scanf("%d",&t);
    vector <int> o;
    vector <int> b;
    for(int it=0;it<t;it++)
    {
		scanf("%d",&n);
		getchar();
		o.clear();
		b.clear();
		int po,pb,p;
		po=pb=p=0;//pointer array
		int rb,ro;
		rb=ro=1;//posisi robot
		for(int i=0;i<n;i++)
		{
			scanf("%c %d",&kal[i],&pos[i]);
			getchar();
			if(kal[i]=='B')b.push_back(pos[i]);
			else o.push_back(pos[i]);
		}
	
		int bb,bo;
		int ub = b.size();
		int uo = o.size();
		
		int jum = 0;
		while(p!=n)
		{
			bb=bo=200;
			if(kal[p]=='B')
			{
				if(rb!=pos[p])
				{
					bb = mut(rb-b[pb]);
					rb = b[pb];
					if(po<uo)
					{
						bo = mut(ro-o[po]);
						if(o[po]<ro)
						{
							if(bo<=bb)ro-=bo;
							else ro-=bb;
						}
						else if(o[po]>ro)
						{
							if(bo<=bb)ro+=bo;
							else ro+=bb;
						}
					}
					jum+=bb;
					//printf("1 %d %d\n",ro,rb);
				}
				if(rb==pos[p])
				{
					jum++;
					pb++;
					if(po<uo)
					{
						if(o[po]<ro)ro--;
						else if(o[po]>ro)ro++;
					}
				//	printf("2 %d %d\n",ro,rb);
				}
			}
			else
			{
				if(ro!=pos[p])
				{
					bo = mut(ro-o[po]);
					ro = o[po];
				//	printf("%d\n",ro);
					if(pb<ub)
					{
						bb = mut(rb-b[pb]);
						if(b[pb]<rb)
						{
							if(bb<=bo)rb-=bb;
							else rb-=bo;
						}
						else if(b[pb]>rb)
						{
							if(bb<=bo)rb+=bb;
							else rb+=bo;
						}
					}
					jum+=bo;
				//	printf("3 %d %d\n",ro,rb);
				}
				if(ro==pos[p])
				{
					jum++;
					po++;
					if(pb<ub)
					{
						if(b[pb]<rb)rb--;
						else if(b[pb]>rb)rb++;
					}
				//	printf("4 %d %d\n",ro,rb);
				}
			}
		//	printf("%d %d\n",ro,rb);
			p++;
		}
	//	printf("aa\n");
		printf("Case #%d: %d\n",it+1,jum);
	}
            
    return 0;
}
