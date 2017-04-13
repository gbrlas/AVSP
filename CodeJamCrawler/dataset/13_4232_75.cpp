#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<math.h>
#include<vector>
#include<string>
#include<map>
using namespace std;

char input[4][4];

int rowcheck(){
    int i,j,f;
    f=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(input[i][j] == 'X'|| input[i][j] == 'T')
                f = 1;
            else{
                f=0;
                break;
            }
        }
		if(f)
			break;
	}
    if(!f){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(input[i][j] == 'O'|| input[i][j] == 'T')
                    f = 2;
                else{
                    f=0;
                    break;
                }
            }
			if(f)
				break;
		}
    }
    return f;
}

int colcheck(){
    int i,j,f;
    f=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(input[j][i] == 'X'|| input[j][i] == 'T')
                f = 1;
            else{
                f=0;
                break;
            }
        }
		if(f)
			break;
	}
    if(!f){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(input[j][i] == 'O'|| input[j][i] == 'T')
                    f = 2;
                else{
                    f=0;
                    break;
                }
            }
			if(f)
				break;
		}
    }
    return f;
}

int diagcheck(){
    int i,j,f;
    f=0;
    if((input[0][0] == 'X'||input[0][0] == 'T')&&(input[1][1]=='X'||input[1][1]=='T')&&(input[2][2]=='X'||input[2][2]=='T')&&(input[3][3]=='X'||input[3][3]=='T'))
        f=1;
	else if((input[0][3] == 'X'||input[0][3] == 'T')&&(input[1][2]=='X'||input[1][2]=='T')&&(input[2][1]=='X'||input[2][1]=='T')&&(input[3][0]=='X'||input[3][0]=='T'))
        f=1;
    else if((input[0][0] == 'O'||input[0][0] == 'T')&&(input[1][1]=='O'||input[1][1]=='T')&&(input[2][2]=='O'||input[2][2]=='T')&&(input[3][3]=='O'||input[3][3]=='T'))
        f=2;
	else if((input[0][3] == 'O'||input[0][3] == 'T')&&(input[1][2]=='O'||input[1][2]=='T')&&(input[2][1]=='O'||input[2][1]=='T')&&(input[3][0]=='O'||input[3][0]=='T'))
        f=2;
    else
        f=0;
    return f;
}

int completenesscheck(){
    int i,j,f;
    f=0;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(input[i][j]=='.'){
                f = 3;
                break;
            }
        return f;
}

void initialize(){
    for(int i=0;i<4;i++)
        memset(input[i],NULL,sizeof(input[i]));
}

int main()
{
    freopen("A-large.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    int t,f,caseno=1,n;
    scanf("%d\n",&n);
    while(n--){
        int i = 0;

        initialize();

        while(i<4)
            gets(input[i++]);
//        f = completenesscheck();
        f=0;
        f = rowcheck();
        if(!f)
            f = colcheck();
        if(!f)
            f = diagcheck();
        printf("Case #%d: ",caseno++);
        if(f == 1)
            printf("X won\n");
        else if(f == 2)
            printf("O won\n");
        else if(f == 0)
        {
            f = completenesscheck();
            if(f == 3)
                printf("Game has not completed\n");
            else
                printf("Draw\n");
        }
        gets(input[0]);
    }
	return 0;
}
