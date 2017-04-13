#include<iostream>
using namespace std;
char m[4][4];
bool WonO=0,WonX=0;
int kolt=0;
void Obrob();
void main()
{
	FILE *f;	
	f=fopen("D:\\inp.txt","r");
		FILE *f2;
		f2=fopen("D:\\out.txt","w");
	int kol=0;
	fscanf(f,"%d\n",&kol);
	for(int p=0;p<kol;++p)
	{
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				fscanf(f,"%c\n",&m[i][j]);
		kolt=WonO=WonX=0;
		Obrob();
	
		if(WonO)
			fprintf(f2,"Case #%d: O won\n",p+1);
		else if(WonX)
			   fprintf(f2,"Case #%d: X won\n",p+1);
		     else if(kolt==0)
				    fprintf(f2,"Case #%d: Draw\n",p+1);
			      else fprintf(f2,"Case #%d: Game has not completed\n",p+1);
		
	}
	fclose(f);fclose(f2);
}
void Obrob()
{
	for(int reg=1;reg<5;++reg)
	{
	int kolO=0,kolX=0,i1,j1;
	    for(int i=0;i<4;++i)
		{
			if(reg<3)
			kolO=kolX=0;
			for(int j=0;j<4;++j)
			{
				
				switch (reg) 
				{
				case 1:{i1=i;j1=j;break;}
				case 2:{i1=j;j1=i;break;}
				case 3:{i1=j1=i;j=5;break;}
				case 4:{i1=i;j1=3-i;j=5;break;}
				}
				if (m[i1][j1]=='T')
				{
					kolO++;
					kolX++;
				}
				else if(m[i1][j1]=='O')
					    kolO++;
				     else if(m[i1][j1]=='X')
						     kolX++;
					       else kolt++;
			}
             if(kolO==4)
				WonO=1;
			 if(kolX==4)				 
				 WonX=1;
			 if(kolO==4||kolX==4)
				 break;
		}
	}
}