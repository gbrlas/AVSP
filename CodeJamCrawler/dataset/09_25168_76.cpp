#include<iostream>
using namespace std;
#define Inf 110
#include<queue>
int date[Inf][Inf];

bool used[Inf][Inf];
char resout[Inf][Inf];
int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
char markc;
struct node
{
    int x,y;
}node1,node2;
queue< struct node > q;
int h , w;
void date_in()
{
    int i,j;
    scanf("%d %d",&h,&w);
    markc = 'a';
    for( i = 0 ; i < h ; ++i)
    {
            for( j = 0  ;j < w ; ++j)
            {
                    scanf("%d",&date[i][j]);
            }
    }
    memset( used ,false , sizeof(used));
    for( i = 0 ; i < h ;  ++i)
    {
        for( j = 0  ;j < w ; ++j)
        {
            resout[i][j] = '\0';
        }
    }
    for( i = 0 ;i < h ; ++i)
    {
        for( j = 0 ;j < w ; ++j)
        {
            //cout << " i : " << i << " " << " J : " << j << endl;
            if( used[i][j] ) continue;
            used[i][j] = true;
            while( !q.empty())q.pop();
            node1.x = i;
            node1.y = j;
            q.push(node1);
            int mark1 = i;
            int mark2 = j;
          //  cout << i << "  " << j << endl;
            while( true)
            {
                int small = date[mark1][mark2];
                int flag = -1;
               // if( i == 1&& j == 2) cout <<" smmmmmmmmmall : " << small << endl;
                for( int ii = 0 ; ii < 4 ; ++ii)
                {
                    int xx = mark1 + dir[ii][0];
                    int yy = mark2 + dir[ii][1];
                   // if( i == 1 && j== 2) cout << " ( " <<  xx << " " << yy << " ) "<< endl;
                    if( xx >= 0 && xx < h && yy >= 0 && yy < w)
                    {
                       // if( i == 1 && j == 2) cout << xx << " " << yy << endl;
                        if( small > date[xx][yy] )
                        {
                          //  if( i == 1 && j == 2) cout << " in : " << endl;
                            small = date[xx][yy];
                            flag = ii;
                        }
                    }
                }
              //  if( i == 0 && j == 1) cout << flag << endl;
                if( flag == -1) break;
                else
                {
                    mark1 += dir[flag][0];
                    mark2 += dir[flag][1];
                    node1.x = mark1;
                    node1.y = mark2;
                  //  if( i == 0 && j == 1) cout << " fjdskfjasdk " << endl;
                    q.push(node1);
                }
            }
          //  cout << " ----------- " << endl;
          //  if( i == 0 && j == 0)cout << mark1 << " <> " << mark2 << endl;
          //  if( i == 0 && j == 0) cout << resout[mark1][mark2] << endl;
            if( resout[mark1][mark2] < 'a' || resout[mark1][mark2] > 'z')
            {
            //    if( i == 0  && j == 0) cout << " there " << endl;
                while( !q.empty())
                {
                    node1 = q.front();q.pop();
                 //   cout << node1.x << " " << node1.y << endl;
                    resout[node1.x][node1.y] = markc;
                    used[node1.x][node1.y] = true;
                }
                markc ++;
            }
            else
            {
                while( !q.empty())
                {
                    node1 = q.front();q.pop();
                    resout[node1.x][node1.y] = resout[mark1][mark2];
                }
            }
        }
    }
    for( i = 0 ; i <h ; ++i)
    {
        for( j = 0 ;j < w - 1 ; ++j)
        {
            printf("%c ",resout[i][j]);
        }
        printf("%c\n",resout[i][j]);
    }
}
int main()
{
        int cases;
        scanf("%d",&cases);
        int t = 1;
        while( cases --)
        {
            printf("Case #%d:\n" , t);
            t ++;
                date_in();
        }
        return 0;
}
