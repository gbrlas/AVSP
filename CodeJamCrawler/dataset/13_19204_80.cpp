#include<iostream> 
using namespace std; 


int main()
{
	freopen("file.in","r",stdin);
	freopen("file.out","w",stdout);
	int t,i=1,rr,cc,r,c;
	cin>>t;

	int x[100][100];
	for(;i<=t;i++){
		bool yes=true;
		cin>>rr>>cc;
		for(r=0;r<rr;r++){
			for(c=0;c<cc;c++){
				cin>>x[r][c];
			}
		}
		
		for(r=0;r<rr;r++){
			for(c=0;c<cc;c++){
				bool fr = false,fc = false;

				//rows
				for(int ir=0;ir<rr;ir++)
					if(x[ir][c] > x[r][c])
						fr=true;

				//cols
				for(int ic=0;ic<cc;ic++)
					if(x[r][ic] > x[r][c])
						fc=true;
				if(fr && fc)
					goto end;
			}
		}
end:
		if(r<rr)
			printf("Case #%d: NO\n",i);
		else
			printf("Case #%d: YES\n",i);
	}

	return 0;
}
