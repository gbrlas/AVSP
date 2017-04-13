#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;


int main()
{
 	ifstream infile("/tmp/A-large.in");
	ofstream aout("Akash.out");
	int l,d,n;
        char s[10000],lang[5000][50],pattern[100000];
	infile.getline(s,20);
    	s[20]='\n';
	int digit[16][27];
        
	// Get the value of l,d and n
		char lc[21];
	 	int j=0;int k;
         	for( k=0;s[j]!=' '&&s[j]!='\n';j++,k++)	lc[k]=s[j];
  	 	lc[k]='\n'; l=atoi(lc);j++;
	 	for(k=0;s[j]!=' '&&s[j]!='\n';j++,k++)     lc[k]=s[j];              
	 	lc[k]='\n'; d=atoi(lc);j++;
	 	for(k=0;s[j]!=' '&&s[j]!='\n';j++,k++)     lc[k]=s[j];
	 	lc[k]='\n'; n=atoi(lc); 
       
	
	// Read the Language
	for(int i=0;i<d;i++)
	{
		infile.getline(s,20);
		strcpy(lang[i],s);
	}

	// Read the pattern and display the answer
	for(int i=0;i<n;i++)
        {
		memset(digit,0,sizeof(digit));
		infile.getline(s,100000);
             	strcpy(pattern,s);
		int open=0;
		for(int j=0,k=0;j<strlen(pattern);j++)
 		{
			if(pattern[j]=='('){open=1; continue;}
			else if(open==1&&pattern[j]==')'){open=0; k++; }
			else { digit[k][pattern[j]-'a']=1; if(open==0) k++;}
		}
		int count1=0;
		for(int j=0;j<d;j++)
		{ 	int flag=0;
			for(int k=0;k<l;k++)
			if(digit[k][lang[j][k]-'a']==0) { flag=1;  break;} 
			if(flag==0) count1++;
		}	   
		aout<<"Case #"<<i+1<<": "<<count1<<endl;     
        }
	aout.close();
	infile.close();
}
