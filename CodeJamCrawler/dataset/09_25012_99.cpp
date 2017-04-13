#include<iostream>
#include<string>

using namespace std;

int T,H,W,mflag,enc;
int z[102][102],flag[102][102],slist[102*102][3];
bool v[102][102];
char list[27];


int cmp(const void *a,const void *b){
	return ((int*)b)[2] - ((int*)a)[2];
}

void flow(int a,int b){
	v[a][b] = 1;
	
	int ht = z[a][b],id=-1;
	if( !v[a-1][b] && z[a-1][b]!=-1  && z[a-1][b]<ht){
		id = 0;
		ht = z[a-1][b];
		if(flag[a-1][b])
			enc = flag[a-1][b];
		else
			enc = 0;
	}
	if( !v[a][b-1] && z[a][b-1]!=-1 && z[a][b-1]<ht){
		id = 3;
		ht = z[a][b-1];
		if(flag[a][b-1])
			enc = flag[a][b-1];
		else
			enc = 0;
	}
	if( !v[a][b+1] &&z[a][b+1]!=-1 && z[a][b+1]<ht){
		id = 1;
		ht = z[a][b+1];
		if(flag[a][b+1])
			enc = flag[a][b+1];
		else
			enc = 0;
	}
	if( !v[a+1][b] &&z[a+1][b]!=-1 && z[a+1][b]<ht){
		id = 2;
		ht = z[a+1][b];
		if(flag[a+1][b])
			enc = flag[a+1][b];
		else
			enc = 0;
	}
	if(enc)return;

	switch(id){
	case 0:
		flow(a-1,b);
		break;
	case 1:
		flow(a,b+1);
		break;
	case 2:
		flow(a+1,b);
		break;
	case 3:
		flow(a,b-1);
		break;
	}
}

int main(){

	freopen("in.txt","r",stdin);
	freopen("out.out","w",stdout);
	
	int i,j,t,a,b,ii,jj,cs,color,pre,cnt;
	char mk;
	
	scanf("%d",&T);

	for(cs=1;cs<=T;cs++){

		scanf("%d %d",&H,&W);

		printf("Case #%d:\n",cs);

		memset(z,-1,sizeof(z));
		memset(flag,0,sizeof(flag));

		cnt = 0;
		for(i=1;i<=H;i++)
			for(j=1;j<=W;j++){
				scanf("%d",&z[i][j]);
				slist[cnt][0] = i;
				slist[cnt][1] = j;
				slist[cnt][2] = z[i][j];
				cnt++;
			}

		qsort(slist,cnt,sizeof(*slist),cmp);

		mflag = 0;
		for(i=0;i<cnt;i++){
			a = slist[i][0];
			b = slist[i][1];
			if(!flag[a][b]){
				memset(v,0,sizeof(v));
				enc = 0;
				flow(a,b);
				if(!enc)
					color = ++mflag;
				else
					color = enc;
				for(ii=1;ii<=H;ii++)
					for(jj=1;jj<=W;jj++)
						if(v[ii][jj])
							flag[ii][jj] = color;
			}
		}
		mk = 'a'-1;
		pre = -1;
		memset(list,0,sizeof(list));
		for(i=1;i<=H;i++)
			for(j=1;j<=W;j++)
				if(flag[i][j]!=pre && !list[flag[i][j]]){
					mk++;
					list[flag[i][j]] = mk;
					pre = flag[i][j];
				}

		for(i=1;i<=H;i++){
			for(j=1;j<W;j++)
				printf("%c ",list[flag[i][j]]);
			printf("%c\n",list[flag[i][W]]);
		}

	}
	return 0;
}