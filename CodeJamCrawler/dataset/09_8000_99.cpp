#include <fstream>

using namespace std;

int map[102][102];
int b[102][102];
int h,w;
int no;
int color[100002];
int missing[100002];

void process(int x,int y)
{
    int dx[] = {-1,0,0,1};
    int dy[] = {0,-1,1,0};
    ++no;
    while(1)
    {
        b[x][y] = no;
        int way = -1;
        int min = map[x][y];
        for(int i=0;i<4;++i)
            if(min>map[x+dx[i]][y+dy[i]])
                min = map[x+dx[i]][y+dy[i]], way = i;
        if(way==-1) { color[no] = no; missing[no] = missing[no-1]; break; }
        x += dx[way];
        y += dy[way];
        if(b[x][y]) { color[no] = color[b[x][y]]; missing[no] = missing[no-1] + 1; break; }
    }
}

int main()
{
    ifstream f("ws.in");
    ofstream f2("ws.out");
    int tn;
    f>>tn;
    for(int hh=0;hh<tn;++hh)
    {
        f>>h>>w;
        for(int i=0;i<=101;++i) memset(b[i],0,sizeof(b[i]));
        memset(color,0,sizeof(color));
        no = 0;
        memset(missing,0,sizeof(missing));
        for(int x=0;x<=h+1;++x) for(int y=0;y<=w+1;++y)
        {
            if(!x || !y || x==h+1 || y==w+1) map[x][y] = 10001;
            else f>>map[x][y];
        }

        for(int x=1;x<=h;++x)
            for(int y=1;y<=w;++y)
            {
                if(!b[x][y]) process(x,y);
            }

        f2<<"Case #"<<hh+1<<":\n";



        for(int x=1;x<=h;++x)
        {
            for(int y=1;y<=w;++y)
            {
                int rawc = color[b[x][y]];
                rawc -= missing[rawc];
                f2<<(char)(rawc+'a'-1)<<" ";
            }
            f2<<"\n";
        }
    }
    return 0;
}
