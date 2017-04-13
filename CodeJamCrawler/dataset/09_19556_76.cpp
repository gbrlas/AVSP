//google code jame 2009 qualification round
//Watersheds
#include <stdio.h>
#include <map>
using namespace std;

#define MAXN 110
#define GetID(A)    ((A.x) + w*((A.y)-1))
typedef struct _Point
{
    int x,y;
} Point;

int w,h;
int graph[MAXN][MAXN];
Point set[MAXN][MAXN];
int rank[MAXN][MAXN];
bool visited[MAXN][MAXN];
int direction[4][2] = {{-1,0},   //North
                  {0,-1},   //West
                  {0,1},    //East
                  {1,0}};   //South
                

void input();
void work();
void GenerateSet();
void dfs(Point pt);
void Union(Point, Point);
void Link(Point, Point);
Point FindSet(Point);

//operator overload
bool operator== (Point pt1, Point pt2)
{
    if(pt1.x==pt2.x && pt1.y == pt2.y)
        return true;
    else
        return false;
}

bool operator!= (Point pt1, Point pt2)
{
    return !(pt1==pt2);
}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=0;i<t;++i)
    {
        printf("Case #%d:\n",i+1);
        input();
        work();
    }
    return 0;
}

void input()
{
    int i,j;
    Point tmpPoint;
    scanf("%d %d",&h,&w);
    for(i=1;i<=h;++i)
        for(j=1;j<=w;++j)
        {
            scanf("%d",&graph[i][j]);    
            tmpPoint.x=i;
            tmpPoint.y=j;
            set[i][j]=tmpPoint;
        }
    memset(visited,0,sizeof(visited));
    memset(rank,0,sizeof(rank));
    
}


void work()
{
    int i,j;
    int curID;
    char curChar;
    map<int,char> dict;
    map<int,char>::iterator pos;
    
    GenerateSet();
    curChar='a';
    for(i=1;i<=h;++i)
    {
        for(j=1;j<=w;++j)
        {
            curID=GetID(FindSet(set[i][j]));
            pos=dict.find(curID);
            if(pos==dict.end())
            {
                dict.insert(pair<int,char>(curID,curChar));
                printf("%c",curChar);
                ++curChar;
            }
            else
                printf("%c",pos->second);
            if(j!=w) printf(" ");
        }
        printf("\n");
    }
}

void GenerateSet()
{
    int i,j,k;
    Point curPos;
    for(i=1;i<=h;++i)
    {
        for(j=1;j<=w;++j)
        {
            if(visited[i][j]) continue;
            curPos.x=i, curPos.y=j;
            dfs(curPos);
        }   //end for(width)
    }   //end for(height)
}

void dfs(Point curPos)
{
    int i;
    Point tmpPos;
    Point bestPos;
    visited[curPos.x][curPos.y]=true;
    bestPos=curPos;
    for(i=0;i<4;++i)
    {
        tmpPos.x = curPos.x + direction[i][0];
        tmpPos.y = curPos.y + direction[i][1];
        if(tmpPos.x < 1 || tmpPos.x > h
            || tmpPos.y < 1 || tmpPos.y >w)
            continue;   //Ô½½ç
        if(graph[tmpPos.x][tmpPos.y] < graph[bestPos.x][bestPos.y])
            bestPos=tmpPos;
    }
    if(bestPos!=curPos)
    {
        Union(bestPos,curPos);
        if(!visited[bestPos.x][bestPos.y])
            dfs(bestPos);
    }
}

void Union(Point pt1, Point pt2)
{
    Link(FindSet(pt1), FindSet(pt2));
}

void Link(Point pt1, Point pt2)
{
    if(rank[pt1.x][pt1.y] < rank[pt2.x][pt2.y])
    {
        set[pt1.x][pt1.y]=pt2;
    }
    else    //rank[pt1.x][pt1.y] >=rank[pt2.x][pt2.y]
    {
        set[pt2.x][pt2.y]=pt1;
        if(rank[pt1.x][pt1.y]==rank[pt2.x][pt2.y])
            ++rank[pt1.x][pt1.y];
    }
}

Point FindSet(Point pt)
{
    int tmp;
    tmp = pt.x + (pt.y-1)*w;
    if(set[pt.x][pt.y]!=pt)
        set[pt.x][pt.y]=FindSet(set[pt.x][pt.y]);
    return set[pt.x][pt.y];
}
