#include<stdio.h>
#include<windows.h>
#include<fstream> 
#include<vector>
#include<string>

using namespace std;

int l,d,n;
char buff[1000];

char possibleletters[20][25];


vector<string> words;
vector<string> cases;
string temp;

int isPossible(char * tempbuff)
{
	int j=0, flag=0;
	if(strlen(tempbuff)!=l)
	{
		printf("weirtd length\n");
		return 0;
	}
	for(int i=0; i <strlen(tempbuff);i++)
	{
		j=0;
		flag =0;
		while(possibleletters[i][j] != '\0')
		{
		//printf("%c%c ",tempbuff[i] ,possibleletters[i][j]);
			if(tempbuff[i] == possibleletters[i][j] )
			{
			//	printf("(%d,%d) %s\n",i , j,tempbuff);
				flag=1;
				break;
			}
			j++;
		}
		if(flag==0)
		{
			//printf("flag 0\n");
			return 0;
		}
	
	}
	return 1;

}

int solve2()
{
	int count=0, i=0;
	char tempbuff[10000];
	for(i=0;i<d;i++)
	{
		strcpy(tempbuff,words[i].c_str());
	//	printf("calling ispossible with %s\n",tempbuff);
		if(isPossible(tempbuff) == 1)
		{
		//	printf("%d\t",i+1);
		//	printf("%s\n",tempbuff);

			count++;
		}
	}
//	printf("count = %d\n",count);
	return count;
}



void init(char *tempbuff)
{
	
	int j=0;
	int k=0;
	for(int i=0; i<l; i++,j++)
	{		
		k=0;
		if(tempbuff[j] == '(')
		{			
			j++;
			while(tempbuff[j] != ')')
			{
				possibleletters[i][k++]= tempbuff[j];
				j++;
			
			}
		}
		else
		{
			possibleletters[i][k++]= tempbuff[j];		
		}
		
		possibleletters[i][k++]= '\0';
		possibleletters[i][k++]= '\0';
		//printf("%s\n",possibleletters[i]);
	
	}
}
void main()
{
	int ret=0;
	char tempbuff[1000];
	ifstream inf;
	inf.open("C:\\input.txt",ifstream::in);
	freopen("C:\\output.txt","w",stdout);
	inf.getline(buff,1000,' ');
	l=atoi(buff);
	inf.getline(buff,1000,' ');
	d=atoi(buff);
	inf.getline(buff,1000);
	n=atoi(buff);
//	printf("l = %d, D= %d, n = %d\n",l,d,n);
	words.clear();
	cases.clear();
	for(int i=0; i < d ; i++)
	{
		inf.getline(buff,1000);
		words.push_back(buff);
	
	}
	for(i=0; i < n ; i++)
	 {
		inf.getline(buff,1000);
		cases.push_back(buff);
	}

	for(i=0;i<n;i++)
	{
		strcpy(tempbuff,cases[i].c_str());
		init(tempbuff);
	//	printf("\n\n");
		ret=solve2();
		printf("Case #%d: %d\n",i+1,ret);
		fflush(stdout);
	}
}






/*
int compareletters(string substring)
{
	
	int found=0;	
	for(int i =0; i < d; i++)
	{
		found=words[i].find(substring);
		if(found!=string::npos && found==0)
		{
		//	printf("%s\n",substring.c_str());
			return 1;
		}
	}
	return 0;

}
int compare(string str)
{
	for(int i=0;i<d;i++)
	{
		if(str == words[i])
			return 1;	
	}

	return 0;

}
void getnextletter(int whichletter, string tempstr)
{
	int tempindex=0;
	string tempstr2=tempstr;
	
	if(whichletter == l)
	{
		//printf("wl = %d, str = %s\n",whichletter,tempstr.c_str());
		if(compare(tempstr) == 1)
			count++;
		return;
	
	}
	else
	{
		while(possibleletters[whichletter][tempindex] != '\0')
			{
				tempstr2 = tempstr;
				tempstr2+=possibleletters[whichletter][tempindex];
				if(compareletters(tempstr2) == 1)
				{					
					getnextletter(whichletter+1,tempstr2);
				}
				tempindex++;
			}
		
		
	}
}
int solve()
{
	string tempstr="";
	count =0;
	getnextletter(0,tempstr);
	return count;

}
*/