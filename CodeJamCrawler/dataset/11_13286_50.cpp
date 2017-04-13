#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 10010
int i,j,n,m;

int len[maxn];

char dict[maxn][20];

bool q[maxn][26];

char s[maxn];

int p[maxn];

int cmpOn(char* a,char* b,int r){
  int i,j;
  for(i=0;a[i];i++){
    if(a[i]==s[r]&&a[i]!=b[i])
      return 1;
    if(a[i]!=s[r]&&s[r]==b[i])
      return -1;
  }
  return 0;
}
int cmpD(char* a,char* b){
  int i,j,r;
  for(r=0;r<26;r++){
    for(i=0;a[i];i++){
      if(a[i]==s[r]&&a[i]!=b[i])
	return 1;
      if(a[i]!=s[r]&&s[r]==b[i])
	return -1;
    }
  }
  return 0;
}

bool cmp(int a,int b){
  if(len[a]!=len[b])
    return len[a]<len[b];
  int temp=cmpD(dict[a],dict[b]);
  if(temp==0)
    return a<b;
  return temp>0;
}
int nowAns,ansi;
void guess(int a){
  int t=0,i,j,r,k,ans=0;
  for(i=0;i<n;i++){
    if(len[a]==len[i]){
      p[t++]=i;
    }
  }
  for(r=0;r<26;r++){
    for(i=0;i<t;i++){
      if(q[p[i]][s[r]-'a'])
	break;
    }
    if(i==t)
      continue;
    if(!q[a][s[r]-'a'])
      ans++;
    for(i=0;i<t;i++){
      for(j=0;dict[a][j];j++){
	if(dict[a][j]==s[r]&&dict[p[i]][j]!=s[r]){
	  p[i]=p[t-1];
	  t--;
	  i--;
	  goto aaa;
	}
	if(dict[a][j]!=s[r]&&dict[p[i]][j]==s[r]){
	  p[i]=p[t-1];
	  t--;
	  i--;
	  goto aaa;
	}
      }
    aaa:;}
  }
  if(ansi<0||ans>nowAns){
    ansi=a;
    nowAns=ans;
  }
}

int rank[maxn],ansRank[maxn];

void make(int i,int j,int r){
  if(i==j)
    return;
  int k;
  while(r<26){
    for(k=i;k<=j;k++){
      if(q[p[k]][s[r]-'a'])
	break;
    }
    if(k>j){
      r++;
    }else
      break;
  }
  if(r==26)
    return;
  for(k=i;k<=j;k++){
    if(!q[p[k]][s[r]-'a'])
      ansRank[p[k]]++;
  }
  while(i<=j){
    k=i;
    while(k<=j&&cmpOn(dict[p[i]],dict[p[k]],r)==0){
      k++;
    }
    make(i,k-1,r+1);
    i=k;
  }
}

void cal(){
  int i=0;
  while(i<n){
    j=i;
    while(j<n&&len[p[j]]==len[p[i]])
      j++;
    make(i,j-1,0);
    i=j;
  }
  ansi=-1;
  for(i=0;i<n;i++){
    if(ansi<0||ansRank[i]>nowAns){
      ansi=i;
      nowAns=ansRank[i];
    }
  }
}



int main(){
  int ii,nn;
  scanf("%d",&nn);
  for(ii=1;ii<=nn;ii++){
    printf("Case #%d:",ii);
    scanf("%d %d",&n,&m);
    memset(q,0,sizeof(q));
    for(i=0;i<n;i++){
      scanf("%s",dict[i]);
      len[i]=strlen(dict[i]);
      p[i]=i;
    }
    for(i=0;i<n;i++){
      for(j=0;dict[i][j];j++){
	q[i][dict[i][j]-'a']=1;
      }
    }
    for(i=0;i<m;i++){
      scanf("%s",s);
      memset(ansRank,0,sizeof(ansRank));
      sort(p,p+n,cmp);
      cal();
      printf(" %s %d",dict[ansi],nowAns);
    }
    printf("\n");
  }

  return 0;
}
