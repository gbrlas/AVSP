// #include<iostream>
// #include<algorithm>
// using namespace std;
// int w[2][105];
// char tem[105];
// int n,m;
// struct node{
// 	char str[105];
// 	bool operator<(const node a)const{
// 		return strcmp(str,a.str)<0;
// 	}
// };
// node tt[105];
// int cal(char tem[])
// {
// 	int hig=n-1,low=0,mid,h;
// 	while(low<hig){
// 		mid=(low+hig)/2;
// 		h=strcmp(tem,tt[mid].str);
// 		if(h==0)return mid;
// 		else if(h<0)hig=mid-1;
// 		else low=mid+1;
// 	}
// 	if(strcmp(tem,tt[low].str)==0)return low;
// 	return -1;
// }
// int main()
// {
// //	freopen("d://a-large.in","r",stdin);
// //	freopen("d://aa.out","w",stdout);
// 	int t,i,j,s;
// 	scanf("%d",&t);	
// 	int k=1;
// 	while(t--){
// 		scanf("%d",&n);
// 		getchar();
// 		for(i=0;i<n;i++){
// 			gets(tt[i].str);
// 		}
// 		sort(tt,tt+n);
// 		scanf("%d",&m);
// 		memset(w,0,sizeof(w));
// 		getchar();
// 		int h0,h1;
// 		for(i=1;i<=m;i++){
// 			h0=(i+1)%2;
// 			h1=i%2;
// 			gets(tem);
// 			int h=cal(tem);
// 			for(s=0;s<n;s++){
// 				if(s==h){
// 					w[h1][s]=10000;
// 					continue;
// 				}
// 				int min1=10000;
// 				for(j=0;j<n;j++){
// 					if(j==s){
// 						if(w[h0][j]<min1)min1=w[h0][j];
// 					}
// 					else if(w[h0][j]+1<min1){
// 						min1=w[h0][j]+1;
// 					}
// 				}
// 				w[h1][s]=min1;
// 			}
// 		}
// 		int min1=10000;
// 		h1=m%2;
// 		for(j=0;j<n;j++)if(w[h1][j]<min1)min1=w[h1][j];
// 		printf("Case #%d: %d\n",k++,min1);
// 	}
// 	return 0;
// }

#include<iostream>
#include<queue>
using namespace std;
int cc,na,nb,t;
int ta[102][2];
int tb[102][2];
int ma,mb,ha,hb;
queue<int>tm1,tm2;
int main()
{
 	freopen("d:\\B-small-attempt4.in","r",stdin);
 	freopen("d:\\4.out","w",stdout);
	int k=1,i,a,b,c,d,j;
	scanf("%d",&cc);
	while(cc--){
		while(!tm1.empty())tm1.pop();
		while(!tm2.empty())tm2.pop();
		scanf("%d",&t);
		scanf("%d%d",&na,&nb);
		for(i=0;i<na;i++){
			scanf("%d:%d %d:%d",&a,&b,&c,&d);
			ta[i][0]=a*60+b;
			ta[i][1]=c*60+d;
		}
		for(i=0;i<nb;i++){
			scanf("%d:%d %d:%d",&a,&b,&c,&d);
			tb[i][0]=a*60+b;
			tb[i][1]=c*60+d;
		}
		ma=0;
		mb=0;
		ha=0;
		hb=0;
		for(i=0;i<3600;i++){
			while(!tm1.empty()){
				int h=tm1.front();
				if(i-h==t){
					tm1.pop();
					ha++;
				}
				else break;
			}
			while(!tm2.empty()){
				int h=tm2.front();
				if(i-h==t){
					tm2.pop();
					hb++;
				}
				else break;
			}
			j=0;
			while(j<na){
				for(;j<na;j++){
					if(ta[j][1]==i)break;
				}
				if(j<na){
					if(t>0)tm2.push(i);
					else hb++;
					j++;
				}
			}
			j=0;
			while(j<nb){
				for(;j<nb;j++){
					if(tb[j][1]==i)break;
				}
				if(j<nb){
					if(t>0)tm1.push(i);
					else ha++;
					j++;
				}
			}



			j=0;
			while(j<na){
				for(;j<na;j++){
					if(ta[j][0]==i)break;
				}
				if(j<na){
					if(ha>0)ha--;
					else ma++;
					j++;
				}
			}

			j=0;
			while(j<nb){
				for(;j<nb;j++){
					if(tb[j][0]==i)break;
				}
				if(j<nb){
					if(hb>0)hb--;
					else mb++;
					j++;
				}
			}
		}
		printf("Case #%d: %d %d\n",k++,ma,mb);
	}
	return 0;
}
