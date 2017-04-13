#include<stdio.h>
#include<windows.h>
#include<string>
#include<vector>
#include<fstream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

char buff[2000];
char index[20][1000];
int totalcount=0;


int  getcount(int currentletter, int posofprevletter)
{
	int tempindex=0;
	int count =0;

	if(index[currentletter][tempindex] == -1) 
	{
		//totalcount=0;
		return 0;
	}

	while(index[currentletter][tempindex] < posofprevletter && index[currentletter][tempindex] != -1) 
	{		
		tempindex++;
	//	printf("1tempindex = %d %d\n",tempindex,index[currentletter][tempindex]);
	}

	if(index[currentletter][tempindex] == -1)
	{
	//	printf("2tempindex = %d\n",tempindex);
		return 0;
	}
	while(index[currentletter][tempindex] != -1 )
		{
		
			if(currentletter+1 != 19)
			{
			//	printf("get count with %d %d\n",currentletter+1,index[currentletter][tempindex] );
				//if( != 0)
				//{
				//	printf("incremented count\n");
					totalcount+=getcount(currentletter+1,index[currentletter][tempindex] );
				//}
			}
			else
				count++;
			//else
		//	{
		//	printf("incrementing\n");
		//		totalcount++;
		//	}
			tempindex++;
		}
	if(count!=0)
	{
	//	totalcount+=count;
		//totalcount=totalcount*count;
	//	printf("total cnt : %d\n",totalcount);
		return count;
	}
	else
		return 0;

}

void solve()
{

	getcount(0,0);
	return;
}

void init()
{

	int i1=0,i2=0,i3=0,i4=0,i5=0,i6=0,i7=0,i8=0,i9=0,i10=0,i11=0;

	for(int i=0;i<strlen(buff);i++)
	{
		switch(buff[i])
		{
		case 'w': 
			index[0][i1]=i;
			i1++;
			break;
		case 'e':
			index[1][i2]=i;
			index[6][i2]=i;
			index[14][i2]=i;
			i2++;
			break;
		case 'l': 
			index[2][i3]=i;
			i3++;
			break;
		case 'c': 
			index[3][i4]=i;
			index[11][i4]=i;
			i4++;
			break;
		case 'o': 
			index[4][i5]=i;
			index[9][i5]=i;
			index[12][i5]=i;
			i5++;
			break;
		case 'm': 
			index[5][i6]=i;
			index[18][i6]=i;
			i6++;
			break;

		case 't': 
			index[8][i7]=i;
			i7++;
			break;
		case 'd': 
			index[13][i8]=i;
			i8++;
			break;
		case 'j': 
			index[16][i9]=i;
			i9++;
			break;
		case 'a': 
			index[17][i10]=i;
			i10++;
			break;
		case ' ':
			index[7][i11]=i;
			index[10][i11]=i;
			index[15][i11]=i;
			i11++;
			break;


		default:
			break;
		
		
		}
	
	}


			index[0][i1]=-1;
			index[1][i2]=-1;
			index[6][i2]=-1;
			index[14][i2]=-1;
			index[2][i3]=-1;
			index[3][i4]=-1;
			index[11][i4]=-1;
			index[4][i5]=-1;
			index[9][i5]=-1;
			index[12][i5]=-1;
			index[5][i6]=-1;
			index[18][i6]=-1;
			index[8][i7]=-1;
			index[13][i8]=-1;
			index[16][i9]=-1;
			index[17][i10]=-1;
			index[7][i11]=-1;
			index[10][i11]=-1;
			index[15][i11]=-1;
			

}
void printindex()
{
	int i=0,j=0;
	for(i=0;i<=18;i++)
	{
		while(index[i][j]!=-1)
			printf("%d  ",index[i][j++]);
		printf("\n");
		j=0;
	}

}


void main()
{
	ifstream inf ;

	int casenumber=1;
	inf.open("C:\\input.txt",ifstream::in);
	
	inf.getline(buff,1000);
	int numCases = atoi(buff);
//	printf("%d",numCases);
	freopen("C:\\out.txt","w",stdout);

	while (inf.getline(buff,1000))
	 {
		totalcount=0;
		printf("Case #%d:",casenumber);
	//printf("%s\n",buff);
		init();

	//	printindex();
		solve();
		printf(" %04d\n",(totalcount%1000));
		
		
		casenumber++;
	 }

  inf.close();


}