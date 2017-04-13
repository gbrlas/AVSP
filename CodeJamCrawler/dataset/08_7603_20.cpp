// #include<iostream>
// #include<queue>
// #include<vector>
// using namespace std;
// vector<int>v1[203],v2[203];
// int ins[203][2],num;
// bool hash[403][2];
// void bfs(int d,int p)
// {
// 	int i,len,q,r,n1=0,n2=0;
// 	queue<int>tem,tem2;
// 	tem.push(p);
// 	tem2.push(d);
// 	hash[p][d]=1;
// 	while(!tem.empty()){
// 		q=tem.front();
// 		r=tem2.front();
// 		tem.pop();
// 		tem2.pop();
// 		if(r==0){
// 			n1++;
// 			len=v1[q].size();
// 			for(i=0;i<len;i++){
// 				if(hash[v1[q][i]][1])continue;
// 				tem.push(v1[q][i]);
// 				tem2.push(1);
// 				hash[v1[q][i]][1]=1;
// 			}
// 		}
// 		else{
// 			n2++;
// 			len=v2[q].size();
// 			for(i=0;i<len;i++){
// 				if(hash[v2[q][i]][0])continue;
// 				tem.push(v2[q][i]);
// 				tem2.push(0);
// 				hash[v2[q][i]][0]=1;
// 			}
// 		}
// 	}
// 	ins[++num][0]=n1;
// 	ins[num][1]=n2;
// }
// bool dp[2][203][203];
// int main()
// {
// 	int t,n,k,i,a,b,j,h;
// 	scanf("%d",&t);
// 	while(t--){
// 		scanf("%d%d",&n,&k);
// 		for(i=1;i<=n;i++){
// 			v1[i].clear();
// 			v2[i].clear();
// 		}
// 		memset(hash,0,sizeof(hash));
// 		while(k--){
// 			scanf("%d%d",&a,&b);
// 			v1[a].push_back(b);
// 			v2[b].push_back(a);
// 		}
// 		num=0;
// 		for(i=1;i<=n;i++){
// 			if(!hash[i][0])bfs(0,i);
// 			if(!hash[i][1])bfs(1,i);
// 		}
// 		memset(dp,0,sizeof(dp));
// 		dp[0][0][0]=1;
// 		int s=n/2,ma=0;
// 		for(i=1;i<=num;i++){
// 			a=i%2;
// 			b=(i-1)%2;
// 			for(j=0;j<=s;j++){
// 				for(h=0;h<=s;h++){
// 					if(j-ins[i][0]>=0&&h-ins[i][1]>=0)dp[a][j][h]|=dp[b][j-ins[i][0]][h-ins[i][1]];
// 					dp[a][j][h]|=dp[b][j][h];
// 					if(dp[a][j][h]&&j==h&&i>ma)ma=j;
// 				}
// 			}
// 		}
// 		printf("%d\n",ma);
// 	}
// 	return 0;
// }

// #include<iostream>
// #include<cmath>
// using namespace std;
// int t,n,m,c;
// int main()
// {
// // 	freopen("d://B-small-attempt0.in","r",stdin);
// // 	freopen("d://B.out","w",stdout);
// 	int i,j,h,k;
// 	scanf("%d",&t);
// 	k=1;
// 	while(t--){
// 		printf("Case #%d: ",k++);
// 		scanf("%d%d%d",&n,&m,&c);
// 		h=sqrt(c+0.0);
// 		int ma=n>m?n:m;
// 		int mi=n<m?n:m;
// 		if(h>mi)h=mi;
// 		for(i=1;i<=h;i++){
// 			if(c%i)continue;
// 			if(c/i>ma)continue;
// 			break;
// 		}
// 		if(i>h)printf("IMPOSSIBLE\n");
// 		else{
// 			if(n>m){
// 				printf("0 0 0 %d %d %d\n",c/i,c/i,i);
// 			}
// 			else{
// 				printf("0 0 0 %d %d %d\n",i,i,c/i);
// 			}
// 		}
// 	}
// 	return 0;
// }


// #include<iostream>
// #include<cmath>
// using namespace std;
// int t,n,m,c;
// int main()
// {
// 	//freopen("d://B-small-attempt0.in","r",stdin);
// 	//freopen("d://B.out","w",stdout);
// 	int i0,i1,j0,j1,h,k;
// 	scanf("%d",&t);
// 	k=1;
// 	while(t--){
// 		printf("Case #%d: ",k++);
// 		scanf("%d%d%d",&n,&m,&c);
// 		for(i0=0;i0<=n;i0++){
// 			for(i1=0;i1<=m;i1++){
// 				for(j0=0;j0<=n;j0++){
// 					for(j1=0;j1<=m;j1++){
// 						if(j0==i0&&i1==j1)continue;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	return 0;
// }


#include <iostream>
#include <algorithm>
using namespace std;
char ss[1020];
char pp[1020];
int a[]={1,2,3,4,5};
int main()
{
	int i,N,k,len,x,y ,lmin , ff , ee = 1;
	freopen("d://D-small-attempt1.in","r",stdin);
	freopen("d://d.out","w",stdout);
	cin >> N;
	while(N--){
		cin >> k;
		cin >> ss;
		len = strlen(ss);
		lmin = len;
		do 
		{
			for(i =0; i < len; i ++)
			{
				x = i/k;
				y = i%k;
				pp[i] = ss[x*k+a[y]-1];
			}
			pp[len] = '\0';
			ff = 1;
			for(i =1; i < len; i ++)if(pp[i] != pp[i-1])	ff++;
			if(ff < lmin)	lmin = ff;
		}
		while(next_permutation(a,a+k));
		printf("Case #%d: %d\n",ee++,lmin);
	}
	return 0;
}