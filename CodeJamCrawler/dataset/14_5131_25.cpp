/// بسم الله الرحمن الرحيم

/* *********************************************************************
   *                       Problem: --------------                     *
   *                   Runtime: 0.000 sec; Rank: 0000                  *
   *                     Algo Used: ----------------                   *
   *                    Solved By : Niloy - JU-CSE-21                  *
   ********************************************************************* */

#include <bits/stdc++.h>

#define S scanf
#define P printf

#define LL long long int
#define ULL unsigned long long int

#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SQR(n) (n*n)
#define eps 1e-9
#define PI 2.0*acos(0.0) //#define PI acos(-1.0)
#define MEM(a,val) memset(a,val,sizeof(a))

#define all(a) a.begin(),a.end()
#define X first
#define Y second

#define PCC cout<<"Case "<<cas++<<": ";
#define PC printf("Case %d:",cas++);
#define PCN printf("Case %d:\n",cas++);
#define NL printf("\n");

#define SET(a,i) memset(a,i,sizeof a)
#define open freopen("B-small-attempt1.in","r",stdin)
#define close freopen ("B-small-attempt1.out","w",stdout)
#define Case(a) printf("Case %d:",a)
#define caseh(a) printf("Case #%d: ",a)
#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL1(a) scanf("%lld",&a)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define CHR getchar()
#define PB(x) push_back(x)
#define PP pop_back()
#define PF(x) push_front(x)
#define PPF(x) pop_front()
#define PS(x) push(x)
#define SZ() size()
#define MOD 1000000007
#define INF (1<<28)
#define UB upper_bound
#define LB lower_bound
#define mxe(a,n) (*max_element(a,a+n))
#define mne(a,n) (*min_element(a,a+n))
#define SUM(a,n) (accumulate(a,a+n,0))
#define onbits  __builtin_popcount
#define VI vector<int>
#define DBG(n) P("Done %d\n",n);

using namespace std;

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> void ia (T a[],int n){for (int i=0; i<n; i++) cin >> a[i];}
template <typename T> void pa (T a[],int n){for (int i=0; i<n-1; i++) cout << a[i] << " ";cout << a[n-1] << endl;}
template <typename T> LL isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T>inline T Bigmod(T b,T p,T m){ if(p==0) return 1; else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;else return ((b % m) * Bigmod(b,p-1,m)) % m;}
template<typename T>inline T Dis(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template<typename T>inline T Angle(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template<typename T>inline T DIFF(T a,T b) { T d = a-b;if(d<0)return -d;else return d;}
template<typename T>inline T ABS(T a) {if(a<0)return -a;else return a;}
template<typename T>inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<typename T>inline T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

int Set(int N,int pos){ return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int toLlint(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}
int cdigittoint(char ch){return ch-'0';}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}

/* ------------------------------------------------------------------------------------------------------- */
//         0123456789
#define MX 100007

double DP[MX][2];

int main ()
{
    int t,cc=0;

    open;close;

    S1(t);
    while (t--)
    {
        double c,f,x,y;

        scanf ("%lf%lf%lf",&c,&f,&x);

        y = 2.0;
        double mn = x/y;
        double tot = 0;
        double tmp;

        while (1)
        {
            tot += c/y;
            y += f;

            tmp = tot + x/y;

            if (tmp > mn+eps)
                break;

            mn = tmp;
        }

        caseh(++cc);
        P("%.10lf\n",mn);

    }
return 0;
}
