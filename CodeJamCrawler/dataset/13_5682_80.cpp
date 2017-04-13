//submitted by rs
#include<stdio.h>
#define XW ("X won")
#define OW ("O won") 
#define DR ("Draw") 
#define NC ("Game has not completed") 
char M[4][4];
int main()
{
	int T;scanf("%d",&T);
	int t_c=0;char *str;
	while (T-->0){	
		if(t_c>0) gets(str);	
		++t_c;
		//read the matrix
		for(int i=0;i<4;++i)
			scanf("%s",M[i]);
		//processing the matrix
		int x,o,t,bflag=0,dot=0;
		//diagonal
		if( (M[0][0]=='X' || M[0][0]=='T') && (M[1][1]=='X' || M[1][1]=='T') && (M[2][2]=='X' || M[2][2]=='T') && (M[3][3]=='X' || M[3][3]=='T'))
		{	printf("Case #%d: %s\n", t_c,XW); continue; 	}
		
		if( (M[0][0]=='O' || M[0][0]=='T') && (M[1][1]=='O' || M[1][1]=='T') && (M[2][2]=='O' || M[2][2]=='T') && (M[3][3]=='O' || M[3][3]=='T'))
		{	printf("Case #%d: %s\n", t_c,OW); continue; 	}
		if( (M[0][3]=='X' || M[0][3]=='T') && (M[1][2]=='X' || M[1][2]=='T') && (M[2][1]=='X' || M[2][1]=='T') && (M[3][0]=='X' || M[3][0]=='T'))
		{	printf("Case #%d: %s\n", t_c,XW); continue; 	}
		
		if( (M[0][3]=='O' || M[0][3]=='T') && (M[1][2]=='O' || M[1][2]=='T') && (M[2][1]=='O' || M[2][1]=='T') && (M[3][0]=='O' || M[3][0]=='T'))
		{	printf("Case #%d: %s\n", t_c,OW); continue; 	};
		
		
		//row wise
		for(int i=0;i<4;++i){
			x=0,o=0,t=0;
			for(int j=0;j<4;++j)
			{
				if(M[i][j]=='X') ++x;
				else if(M[i][j]=='O') ++o;
				else if(M[i][j]=='T') ++t;
				else if(M[i][j]=='.') ++dot;
			}
			if(x+t == 4 )
			{
				printf("Case #%d: %s\n", t_c,XW); bflag=1;
				break;
			}else if(o+t == 4){
				printf("Case #%d: %s\n", t_c,OW); bflag=1;
				break;
			}
		}
		if(bflag) continue;
		//column wise	
		for(int i=0;i<4;++i){
			x=0,o=0,t=0;
			for(int j=0;j<4;++j)
			{
				if(M[j][i]=='X') ++x;
				else if(M[j][i]=='O') ++o;
				else if(M[j][i]=='T') ++t;
			}
			if(x+t == 4 )
			{
				printf("Case #%d: %s\n", t_c,XW); bflag=1;
				break;
			}else if(o+t == 4){
				printf("Case #%d: %s\n", t_c,OW); bflag=1;
				break;
			}
		}
		if(bflag) continue;
		// handling the draw and not completed
		if(dot > 0)
			printf("Case #%d: %s\n", t_c,NC);
		else
			printf("Case #%d: %s\n", t_c,DR);
	}//end of while
	return 0;
}
