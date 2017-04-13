#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ft first
#define sd second
#define VI vector<int>
#define VLL vector<long long int>
#define PII pair<int,int>
#define pb push_back
#define rsz(v,n) v.resize(n)
// input and output
#define scan(x) scanf("%d",&x)
#define scanll(x) scanf("%lld",&x)
#define ll long long int
#define rep(i,x,y) for(i=x;i<y;i++)
#define print(x) printf("%d\n",x)
#define printll(x) printf("%lld\n",x)
#define all(v) v.begin(),v.end()
#define ms(v) memset(v,0,sizeof(v))
#define FOR(i,a,b)  for(i=a;i<b;i++)
#define PIE 3.14159265358979323846264338327950
#ifdef ONLINE_JUDGE
 inline void inp( int &n )
 {
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
  }
#else
inline void inp(int &n){
 cin>>n;
}
#endif
int arr[17];
int main()
{
    int t,ans,x;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        memset(arr,0,sizeof(arr));
        cin>>ans;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                cin>>x;
                if(i==ans)
                arr[x]++;
            }
        }
        cin>>ans;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                cin>>x;
                if(i==ans)
                arr[x]++;
            }
        }
        int count=0;
        for(int i=1;i<=16;i++)
        {
            if(arr[i]==2){ count++; ans=i;}
        }
        cout<<"Case #"<<test<<": ";
        if(count==0) cout<<"Volunteer cheated!"<<endl;
        else if(count==1)cout<<ans<<endl;
        else cout<<"Bad magician!"<<endl;
    }
	return 0;
}
