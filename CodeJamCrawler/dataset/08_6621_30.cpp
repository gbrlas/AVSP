#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

struct node{
	int left,arrival;
}aa[102],bb[102];

int t;

int le1(node a,node b){
	return a.arrival<b.arrival;
}

int le2(node a,node b){
	return a.left<b.left;
}

int count(char aa[]){
    int temp=0;
	temp+=(aa[0]-'0')*1000;
	temp+=(aa[1]-'0')*100;
	temp+=(aa[3]-'0')*10;
	temp+=aa[4]-'0';
	return temp;
}

int compare(int a,int b){
	int temp=a;
	a=a+t;
	if(temp%10+t>9&&temp/10%10==5)
	    a=a+40;
	return a<=b;
}
	
	  
int main(){
	freopen("B-small-attempt2.in.txt","r",stdin);
	freopen("B-small-attempt2.out.txt","w",stdout);
	int n,na,nb,i,j,ra,rb,tt=0;
	int flaga[102],flagb[102];
	char ch[10];
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d",&t,&na,&nb);
		ra=na;rb=nb;
		for(i=0;i<na;++i){
		   scanf("%s",ch);
		   aa[i].left=count(ch);
		   scanf("%s",ch);
		   aa[i].arrival=count(ch);
		}
		for(j=0;j<nb;++j){
		   scanf("%s",ch);
		   bb[j].left=count(ch);
		   scanf("%s",ch);
		   bb[j].arrival=count(ch);
		}
		sort(aa,aa+na,le1);
		sort(bb,bb+nb,le2);
		memset(flaga,0,sizeof(flaga));
		memset(flagb,0,sizeof(flagb));
		for(i=0;i<na;++i)
		   for(j=0;j<nb;++j)
			 if(!flaga[i]&&!flagb[j]&&compare(aa[i].arrival,bb[j].left)){
			    flagb[j]=1;
			    flaga[i]=1;
			    rb--;
			}
		sort(aa,aa+na,le2);
		sort(bb,bb+nb,le1);	
		memset(flaga,0,sizeof(flaga));
		memset(flagb,0,sizeof(flagb));	
	    for(j=0;j<nb;++j)
		   for(i=0;i<na;++i)
			 if(!flaga[i]&&!flagb[j]&&compare(bb[j].arrival,aa[i].left)){
			    flagb[j]=1;
			    flaga[i]=1;
			    ra--;
			}
	    printf("Case #%d: %d %d\n",++tt,ra,rb);
       }
       return 0;
}
 		
		   
	
		  
	
		
		  
