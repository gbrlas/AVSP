#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ext/hash_set>
using namespace std;
using namespace __gnu_cxx;
struct Coord
{
       Coord():x(0),y(0){}
       int x;
       int y;
       Coord(int xx,int yy):x(xx),y(yy){}
};
namespace __gnu_cxx{
template<>
struct hash<Coord>
{
       size_t operator ()(const Coord& a) const
       {
              return (a.x<<6)+a.y;
       }
};
}
bool operator ==(const Coord& a,const Coord& b)
{
     return a.x == b.x && a.y==b.y;
}
bool operator <(const Coord& a,const Coord& b)
{
     return a.x < b.x || (a.x==b.x && a.y<b.y);
}

hash_set<Coord,hash<Coord> > S;
hash_set<Coord,hash<Coord> > T;
int main(int argc, char *argv[])
{
    ifstream in("C-small-attempt1.in");
    ofstream out("result.txt");
    int cases;
    in>>cases;
    int k;
    for(int i=0;i<cases;++i)
    {
            S.clear();
            int R;
            in>>R;
            int x1,y1,x2,y2;
            for(int j=0;j<R;++j)
            {
                    in>>x1>>y1>>x2>>y2;
                    for(int m=x1;m<=x2;++m) for(int n=y1;n<=y2;++n){
                            S.insert(Coord(m,n));
                    }
            }
            int cnt=0;
            while(S.size()>0)
            {
               hash_set<Coord,hash<Coord> >::iterator it;
               for(it=S.begin();it!=S.end();++it)
               {
                   if( S.find( Coord(it->x-1,it->y+1))!=S.end()){
                       T.insert(Coord(it->x,it->y+1));
                   }
                   if( S.find( Coord(it->x-1,it->y))==S.end() && S.find( Coord(it->x,it->y-1))==S.end()) continue;
                   T.insert(*it);
               }
               ++cnt;
               //cout<<++cnt<<endl;
               S.clear();
               S.swap(T);
            }
            cout<<"Case #"<<i+1<<": "<<cnt<<endl;
            out<<"Case #"<<i+1<<": "<<cnt<<endl;
    }
    out.close();
    
    return EXIT_SUCCESS;
}
