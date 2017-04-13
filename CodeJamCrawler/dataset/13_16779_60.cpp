#include <fstream>
using namespace std;
fstream f("input.in");
ofstream g("output.out");
int T,i,j,k,ok,okX,okO;
int AX[1001][1001],AO[1001][1001];
char c;
int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
        for(j=1;j<=4;j++)
        {
            ok=1;
            for(k=1;k<=4;k++)
            {
                f>>c;
                AX[j][k]=int(c);
                AO[j][k]=AX[j][k];
                if(AX[j][k]==84)
                AX[j][k]=88;
                if(AO[j][k]==84)
                AO[j][k]=79;
                if(AX[j][k]==46 && ok)
                ok=0;
            }
        }
        okX=1;
        okO=1;
        if(AX[1][1]==AX[2][2] && AX[2][2]==AX[3][3] && AX[3][3]==AX[4][4] && AX[4][4]==88 && AX[4][4]!=46 && okX && okO)
        okX=0;
        if(AO[1][1]==AO[2][2] && AO[2][2]==AO[3][3] && AO[3][3]==AO[4][4] && AO[4][4]==79 && AO[4][4]!=46 && okX && okO)
        okO=0;
        if(AX[1][4]==AX[2][3] && AX[2][3]==AX[3][2] && AX[3][2]==AX[4][1] && AX[4][1]==88 && AX[4][1]!=46 && okX && okO)
        okX=0;
        if(AO[1][4]==AO[2][3] && AO[2][3]==AO[3][2] && AO[3][2]==AO[4][1] && AO[4][1]==79 && AO[4][1]!=46 && okX && okO)
        okO=0;
        for(j=1;j<=4 && okX && okO;j++)
        {
            if(AX[j][1]==AX[j][2] && AX[j][2]==AX[j][3] && AX[j][3]==AX[j][4] && AX[j][4]==88 && AX[j][4]!=46)
            okX=0;
        }
        for(j=1;j<=4 && okX && okO;j++)
        {
            if(AX[1][j]==AX[2][j] && AX[2][j]==AX[3][j] && AX[3][j]==AX[4][j] && AX[4][j]==88 && AX[4][j]!=46)
            okX=0;
        }
        for(j=1;j<=4 && okX && okO;j++)
        {
            if(AO[j][1]==AO[j][2] && AO[j][2]==AO[j][3] && AO[j][3]==AO[j][4] && AO[j][4]==79 && AO[j][4]!=46)
            okO=0;
        }
        for(j=1;j<=4 && okX && okO;j++)
        {
            if(AO[1][j]==AO[2][j] && AO[2][j]==AO[3][j] && AO[3][j]==AO[4][j] && AO[4][j]==79 && AO[4][j]!=46)
            okO=0;
        }
        g<<"Case #"<<i<<": ";
        if(!okX)
        g<<"X won";
        else if(!okO)
        g<<"O won";
        else if(ok)
        g<<"Draw";
        else
        g<<"Game has not completed";
        g<<"\n";
    }
    return 0;
}
