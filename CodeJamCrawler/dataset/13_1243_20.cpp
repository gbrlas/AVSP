#include<stdio.h>
#define X "X won"
#define O "O won"
#define draw "Draw"
#define empty "Game has not completed"
int main(){
	FILE *ip,*o;
	ip=fopen("A-small-attempt6.in","r");
	o=fopen("Output.out","w");
	int T,i,j,count=1,flag; char ch,a[4][4];
	fscanf(ip,"%d",&T);
	fscanf(ip,"%c",&ch);  
	do{
		flag=0;
		for(i=0;i<4;i++){	for(j=0;j<4;j++) fscanf(ip,"%c",&a[i][j]); fscanf(ip,"%c",&ch);}
		if((a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[2][2]==a[3][3]) || (a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[3][3]=='T') || (a[0][0]==a[1][1] && a[1][1]==a[3][3] && a[2][2]=='T') || (a[0][0]==a[2][2] && a[2][2]==a[3][3] && a[1][1]=='T'))
		{ if(a[0][0]=='X') {fprintf(o,"Case #%d: ",count);fprintf(o,X); goto label;}
		  else if(a[0][0]=='O') {fprintf(o,"Case #%d: ",count);fprintf(o,O);goto label;}
		}
		if(a[1][1]==a[2][2] && a[2][2]==a[3][3] && a[0][0]=='T')
		{ if(a[1][1]=='X') {fprintf(o,"Case #%d: ",count);fprintf(o,X); goto label;}
		  else if(a[1][1]=='O') {fprintf(o,"Case #%d: ",count);fprintf(o,O);goto label;}
		}
		if((a[0][3]==a[1][2] && a[1][2]==a[2][1] && a[2][1]==a[3][0]) || (a[0][3]==a[1][2] && a[1][2]==a[2][1] && a[3][0]=='T') || (a[0][3]==a[1][2] && a[1][2]==a[3][0] && a[2][1]=='T') || (a[0][3]==a[2][1] && a[2][1]==a[3][0] && a[1][2]=='T'))
		{ if(a[0][3]=='X') {fprintf(o,"Case #%d: ",count);fprintf(o,X); goto label;}
		  else if(a[0][3]=='O') {fprintf(o,"Case #%d: ",count);fprintf(o,O);goto label;}
		}
		if(a[1][2]==a[2][1] && a[2][1]==a[3][0] && a[0][3]=='T')
		{ if(a[1][2]=='X') {fprintf(o,"Case #%d: ",count);fprintf(o,X); goto label;}
		  else if(a[1][2]=='O') {fprintf(o,"Case #%d: ",count);fprintf(o,O);goto label;}
		}	
		for(i=0;i<4;i++){
			if((a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][2]==a[i][3]) || (a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][3]=='T') || (a[i][0]==a[i][1] && a[i][1]==a[i][3] && a[i][2]=='T') || (a[i][0]==a[i][2] && a[i][2]==a[i][3] && a[i][1]=='T'))
			{ if(a[i][0]=='X') {fprintf(o,"Case #%d: ",count);fprintf(o,X);goto label;}
			  else if (a[i][0]=='O') { fprintf(o,"Case #%d: ",count);fprintf(o,O); goto label;}
			}
			if(a[i][1]==a[i][2] && a[i][2]==a[i][3] && a[i][0]=='T')
			{ if(a[i][1]=='X') {fprintf(o,"Case #%d: ",count);fprintf(o,X);goto label;}
			  else if (a[i][1]=='O') { fprintf(o,"Case #%d: ",count);fprintf(o,O); goto label;}
			}
			if((a[0][i]==a[1][i] && a[1][i]==a[2][i] && a[2][i]==a[3][i]) || (a[0][i]==a[1][i] && a[i][i]==a[2][i] && a[3][i]=='T') || (a[0][i]==a[1][i] && a[1][i]==a[3][i] && a[2][i]=='T') || (a[0][i]==a[2][i] && a[2][i]==a[3][i] && a[1][i]=='T'))
			{ if(a[0][i]=='X') {fprintf(o,"Case #%d: ",count);fprintf(o,X);goto label;}
			  else if (a[0][i]=='O') {fprintf(o,"Case #%d: ",count);fprintf(o,O); goto label;}
			}
			if(a[1][i]==a[2][i] && a[2][i]==a[3][i] && a[0][i]=='T')
			{ if(a[1][i]=='X') {fprintf(o,"Case #%d: ",count);fprintf(o,X);goto label;}
			  else if (a[1][i]=='O') {fprintf(o,"Case #%d: ",count);fprintf(o,O); goto label;}
			}
		}
		for(i=0;i<4;i++)for(j=0;j<4;j++) if(a[i][j]=='.')flag=1;
		fprintf(o,"Case #%d: ",count);
		if(flag==0) fprintf(o,draw);
		else fprintf(o,empty);
		label:
		fprintf(o,"\n");	
		fscanf(ip,"%c",&ch);
		count++;
	}while(--T);
	fprintf(o,"\n");
	fclose(ip);
	fclose(o);
	return 0;
}
