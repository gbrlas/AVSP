#include <iostream>

using namespace std;

int verificar(char mat[4][4])
{
    int respuesta=0;
    int x=5,y=5;
    int lasx=0,lasy=0;
    bool haypunto=false;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if (mat[i][j]=='T') {x=i;y=j;}
            if (mat[i][j]=='.') haypunto=true;
        }
    }

    if (x!=5 && y!=5)
    {
        for (int i=0;i<4;i++)
        {
            if (mat[x][i]=='X') lasx++;
            if (mat[x][i]=='O') lasy++;
        }

        if(lasx==3 || lasx==4) respuesta=1;
        if(lasy==3 || lasy==4) respuesta=2;
        else {lasx=0;lasy=0;}

        for (int i=0;i<4;i++)
        {
            if (mat[i][y]=='X') lasx++;
            if (mat[i][y]=='O') lasy++;
        }

        if(lasx==3) respuesta=1;
        if(lasy==3) respuesta=2;
        else {lasx=0;lasy=0;}

        mat[x][y]='X';
        if ((mat[0][0]==mat[1][1])&&(mat[1][1]==mat[2][2])&&(mat[2][2]==mat[3][3])&&(mat[3][3]=='X')) respuesta=1;
        if ((mat[0][3]==mat[1][2])&&(mat[1][2]==mat[2][1])&&(mat[2][1]==mat[3][0])&&(mat[3][0]=='X')) respuesta=1;

        mat[x][y]='O';
        if ((mat[0][0]==mat[1][1])&&(mat[1][1]==mat[2][2])&&(mat[2][2]==mat[3][3])&&(mat[3][3]=='O')) respuesta=2;
        if ((mat[0][3]==mat[1][2])&&(mat[1][2]==mat[2][1])&&(mat[2][1]==mat[3][0])&&(mat[3][0]=='O')) respuesta=2;
        mat[x][y]='T';

    }


        lasx=0;lasy=0;
        for (int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if (mat[i][j]=='X') lasx++;
                if (mat[i][j]=='O') lasy++;
            }
            if(lasx==4) {respuesta=1;i=5;}
            if(lasy==4) {respuesta=2;i=5;}
            else {lasx=0;lasy=0;}
        }

        for (int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if (mat[j][i]=='X') lasx++;
                if (mat[j][i]=='O') lasy++;
            }
            if(lasx==4) {respuesta=1;i=5;}
            if(lasy==4) {respuesta=2;i=5;}
            else {lasx=0;lasy=0;}
        }

        if ((mat[0][0]==mat[1][1])&&(mat[1][1]==mat[2][2])&&(mat[2][2]==mat[3][3])&&(mat[3][3]=='X')) respuesta=1;
        if ((mat[0][3]==mat[1][2])&&(mat[1][2]==mat[2][1])&&(mat[2][1]==mat[3][0])&&(mat[3][0]=='X')) respuesta=1;

        if ((mat[0][0]==mat[1][1])&&(mat[1][1]==mat[2][2])&&(mat[2][2]==mat[3][3])&&(mat[3][3]=='O')) respuesta=2;
        if ((mat[0][3]==mat[1][2])&&(mat[1][2]==mat[2][1])&&(mat[2][1]==mat[3][0])&&(mat[3][0]=='O')) respuesta=2;



    if (respuesta==0 && (haypunto==false)) respuesta=3;
    if (respuesta==0 && haypunto) respuesta=4;



    return respuesta;

}

int main()
{
    int t;
    char k;
    char mat[4][4];
    cin>>t;
    for(int c=0;c<t;c++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                cin>>k;
                mat[i][j]=k;
            }
        }
        cout<<"Case #"<<c+1<<": ";
        int respuesta=verificar(mat);
        if (respuesta==1) cout<<"X won";
        if (respuesta==2) cout<<"O won";
        if (respuesta==3) cout<<"Draw";
        if (respuesta==4) cout<<"Game has not completed";
        cout<<endl;
    }
}
