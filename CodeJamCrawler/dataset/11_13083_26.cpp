#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#define MAXN 10050
#define eps 1e-9
using namespace std;
struct Node{
    double w,len;
};

struct Seg{
    int l,r;
    double w;
}seg[MAXN];

int n,x;
int m,ref[MAXN];
double s,r,lv;
double mm[MAXN];

bool operator<(const Node &a,const Node &b)
{
		return a.w>b.w;
}//×î´ó¶Ñ
priority_queue<Node>pq;

int bs(int num)
{
    int ll,rr,mid;
    ll=1;
    rr=m;
    while(ll<rr){
        mid=(ll+rr)/2;
        if(ref[mid]>=num)
            rr=mid;
        else
            ll=mid+1;
    }
    return rr;
}
double cal()
{
    Node node;
    double need,ans=0;
    for(int i=1;i<m;i++)
        mm[i]=0;
    for(int i=1;i<=n;i++){
        seg[i].l=bs(seg[i].l);
        seg[i].r=bs(seg[i].r);
        while(seg[i].l<seg[i].r){
            mm[seg[i].l]=max(mm[seg[i].l],seg[i].w);
            seg[i].l++;
        }
    }
    while(!pq.empty())
        pq.pop();
    for(int i=1;i<m;i++){
        node.w=mm[i];
        node.len=ref[i+1]-ref[i];
        pq.push(node);
    }
    while(!pq.empty()){
        node=pq.top();
        pq.pop();
        if(lv>0){
            need=node.len/(node.w+r);
            if(lv>need+eps){
                ans+=need;
                lv-=need;
            }
            else{
                node.len-=lv*(node.w+r);
                ans+=lv;
                lv=0;
                ans+=node.len/(node.w+s);
            }
        }
        else
            ans+=node.len/(node.w+s);
    }
    return ans;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tmp,T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lf%lf%lf%d",&x,&s,&r,&lv,&n);
        m=0;
        ref[++m]=0;
        ref[++m]=x;
        for(int i=1;i<=n;i++){
            scanf("%d%d%lf",&seg[i].l,&seg[i].r,&seg[i].w);
            ref[++m]=seg[i].l;
            ref[++m]=seg[i].r;
        }
        sort(ref+1,ref+m+1);
        tmp=1;
        for(int i=2;i<=m;i++)
            if(ref[i]!=ref[i-1])
                ref[++tmp]=ref[i];
        m=tmp;
        printf("Case #%d: ",++cas);
        printf("%.6f\n",cal());
        //cout<<cal()<<endl;
    }
    //while(1);
    return 0;
}
