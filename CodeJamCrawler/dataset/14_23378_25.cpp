#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>
#define clr(x,a) memset(x,a,sizeof(x))
#define FN(a,n) for(int a=0;a<n;a++)
#define FOR(a,ini,fin) for(int a=(ini);a<=(fin);a++)
#define ull unsigned long long
#define scan1(x) scanf("%d",&x)
#define scan2(x,y) scanf("%d %d",&x,&y)
#define scan3(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define all(v) v.begin(),v.end()
#define pb push_back
#define F first
#define S second
#define endl "\n"
using namespace std;

#define MAXN 500
int main()
{
    int tc;
    scan1(tc);
    FN(itc,tc)
    {
        printf("Case #%d: ",itc+1);
        int a,b;
        scan1(a);
        int v1[4];
        int v2[4];
        FN(i,4)
        {
            FN(j,4)
            {
                int aux;
                scan1(aux);
                if(i+1==a)
                {
                    v1[j]=aux;
                }
            }
        }
        scan1(b);
        FN(i,4)
        {
            FN(j,4)
            {
                int aux;
                scan1(aux);
                if(i+1==b)
                {
                    v2[j]=aux;
                }
            }
        }
        int cont=0;
        int ind;
        FN(i,4)
        {
            FN(j,4)
            {
                if(v1[i]==v2[j])
                {
                    cont++;
                    ind=v1[i];
                }
            }
        }
        if(cont==1)
        {
            printf("%d\n",ind);
        }else if (cont==0)
        {
            puts("Volunteer cheated!");
        }else{
            puts("Bad magician!");
        }
    }

    /*no['a']="Amy Nichole";
    no['m']="Mia Abigail";
    m['a']=5;
    m['m']=37;
    while(1)
    {
        int a,b;
        puts("siguiente multiplicacion:");
        scanf("%d", &a);
        printf("x\n");
        scanf("%d", &b);
        puts("respondan ya!!");
        int res=a*b;
        while(1)
        {
            int n;
            char as[4];
            scanf("%s %d",as,&n);
            char c=as[0];
            if (n== res) {
                printf("\nRespuesta correcta \n+10 puntos a ");
                cout<<no[c]<<" !!\n ";
                if(m.find(c)!=m.end()) m[c]=m[c]+10;
                else m[c]=10;
                break;
            }else{
                printf("\nRespuesta incorrecta :(\n Menos 1 punto a ");
                cout<<no[c]<<endl;
                if(m.find(c)!=m.end())  m[c]-=1;
                else m[c]=-1;
            }

            puts("\n\n\nPuntajes:");
            cout<<no['a']<<" "<<m['a']<<" puntos.          "<<no['m']<<" "<<m['m']<<" puntos.\n\n";

        }
        puts("\n\nPuntajes:");
        cout<<no['a']<<" "<<m['a']<<" puntos.          "<<no['m']<<" "<<m['m']<<" puntos.\n";
    }
*/
}
