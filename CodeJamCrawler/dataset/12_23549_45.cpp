#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif

#ifdef LOCAL
#define cin in
#define cout out
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))

using namespace std;


int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif

    int nb_cas;
    cin>>nb_cas;
    for(int c=0;c<nb_cas;c++)
    {
        int S,N,P;
        cin>>N>>S>>P;
        int tot=0;
        for(int truc=0;truc<N;truc++)
        {
                int score;
                cin>>score;
                bool trouve=false;
                for(int c2=0;c2<=10;c2++)
                    for(int c3=0;c3<=10;c3++)
                        for(int c4=0;c4<=10;c4++)
                            if(abs(c2-c3)<=2&&abs(c3-c4)<=2&&abs(c2-c4)<=2&&c2+c3+c4==score&&max(max(c2,c3),c4)>=P)
                            {
                                trouve=true;
                                if(abs(c2-c3)<2&&abs(c3-c4)<2&&abs(c2-c4)<2)
                                {
                                    tot++;
                                    goto end;
                                }
                            }
                if(trouve&&S)
                {
                    S--;
                    tot++;
                }
                end:;
        }

        cout<<"Case #"<<c+1<<": "<<tot<<endl;
    }
}
