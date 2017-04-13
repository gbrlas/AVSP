#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void PartString(vector <string> & parts, string str)
{
	int len = str.length();
	
	if (str.find("(")==-1)
	{
		for (int n=0; n<len; n++)
		{
			string x;
			x += str[n];
			parts.push_back(x);
		}
		return;
	}	

	bool in; 
	string x;
	for (int n=0; n<len; n++)
	{
		

		if (str[n]=='(')
		{
//			x += str[n++];
			in = true;
		}
		else if (str[n]==')')
		{
			parts.push_back(x);
			x = "";
			in = false;
		}
		else 
		{
			if (in==true)
			{
				x += str[n];
			}
			else
			{
				x += str[n];
				parts.push_back(x);
				x = "";
			}
		}
	}

};

int main(int argc,char *argv[])
{
	char infile[256];
	char outfile[256];
	strcpy(infile,argv[1]);
	strcpy(outfile,argv[2]);
	FILE * fp = fopen(infile,"rt");
	FILE * fpout = fopen(outfile,"wt");

	int i,j;

	int length;
	int i_Numwords;
	int i_NumTest;

	fscanf(fp,"%d %d %d",&length,&i_Numwords,&i_NumTest);

	vector <string> language;

	for (i=0; i<i_Numwords; i++)
	{
		string temp;
		char str[256];
		fscanf(fp,"%s",str);
		temp = str;
		language.push_back(temp);
	}


	vector <int> results;
	for (j=0; j<i_NumTest; j++)
	{
		vector <string> parts;
		string temp;
		char str[256];
		fscanf(fp,"%s",str);
		temp = str;

		PartString(parts,temp);
		
		int total = 1;
		for (int tt =0; tt<parts.size(); tt++)
		{
			total *= parts[tt].length();
		}
		
		int match = 0;
		for (i=0; i<i_Numwords; i++)
		{
				int sucess = 0;
				string words = language[i];
				for (int k=0; k<length; k++)
				{
					if (parts[k].find(words[k])!=-1)
					{
						sucess++;
					}
				}

				if (sucess==length)
				{
					match++;
				}
			//see if the word in the part
		}

		results.push_back(match);
	}
	

	for(i=1; i<=i_NumTest; i++)
	{
		fprintf(fpout,"Case #%d: %d\n",i,results[i-1]);
	}
	
	fclose(fp);
	fclose(fpout);
}