#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
bool r[4] = {true,true,true,true};
bool c[4] = {true,true,true,true};
bool d[2] = {true,true};
int all = 0;
int t_i = -1;
int t_j = -1;


bool checkwin2(char s[][4],int n)
{
    for(int row = 0 ; row < 4; row++)
    {
        if(!r[row])
            continue;
        if(t_i == row && t_j != 0)
            s[t_i][t_j] = s[row][0];
        else
            s[t_i][t_j] = s[row][1];
        if(s[row][0] == s[row][1] && s[row][0] == s[row][2] && s[row][0]==s[row][3])
        {
            printf("Case #%d: %c won\n",n,s[row][0]);
            return true;
        }
        s[t_i][t_j] = 'T';
    }

    for(int col = 0 ; col < 4; col++)
    {
        if(!c[col])
            continue;
        if(t_j == col && t_i != 0)
            s[t_i][t_j] = s[0][col];
        else
            s[t_i][t_j] = s[1][col];
        if(s[0][col] == s[1][col] && s[0][col] == s[2][col] && s[0][col]==s[3][col])
        {
            printf("Case #%d: %c won\n",n,s[0][col]);
            return true;
        }
        s[t_i][t_j] = 'T';
    }

    if(d[0])
    {
        if(t_i == t_j && t_i != 0)
            s[t_i][t_j] = s[0][0];
        else
            s[t_i][t_j] = s[1][1];
        if(s[0][0] == s[1][1] && s[0][0] == s[2][2] && s[0][0]==s[3][3])
        {
            printf("Case #%d: %c won\n",n,s[0][0]);
            return true;
        }
        s[t_i][t_j] = 'T';
    }
    if(d[1])
    {
        if(t_i+t_j==3 && t_i != 0)
            s[t_i][t_j] = s[0][3];
        else
            s[t_i][t_j] = s[1][2];
        if(s[0][3] == s[1][2] && s[0][3] == s[2][1] && s[0][3]==s[3][0])
        {
            printf("Case #%d: %c won\n",n,s[0][3]);
            return true;
        }
        s[t_i][t_j] = 'T';
    }
    //printf("Case #%d: Draw\n",n);
	return false;
}
int main()
{
    freopen("D:\\data.in","r",stdin);
    freopen("D:\\data.out","w",stdout);
    int count = 0;
    scanf("%d",&count);
    for(int n = 1; n <= count; n++)
    {
        char square[4][4];
        for(int i = 0; i< 4;++i)
        {
            for(int j = 0; j<4;++j)
            {
                //scanf("%c",&square[i][j]);
				cin >> square[i][j];
                if(square[i][j] == 'T')
                {
                    t_i = i;
                    t_j = j;
                }
                if(square[i][j] == '.')
                {
                    r[i] = false;
                    c[j] = false;
                    all += 2;
                    if(i == j)
                    {
                        d[0] = false;
                        all++;
                    }
                    if(i+j == 3)
                    {
                        d[1] = false;
                        all++;
                    }
                }
            }
        }
        if(!checkwin2(square,n))
		{
			if (all > 0)
				printf("Case #%d: Game has not completed\n",n);
			else
				printf("Case #%d: Draw\n",n);
		}
        for(int k = 0; k < 4;k++)
        {
            r[k] = true;
            c[k] = true;
        }
        d[0] = d[1] = true;
        all = 0;t_i = -1;t_j = -1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
