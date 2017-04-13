#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
	int iLoop,jLoop,counter=0;
	int tcCount=0;
	string* input = NULL;
	
	ifstream inFile("C:\\Users\\Shrumang\\Downloads\\A-large.in");
	ofstream opFile("C:\\Users\\Shrumang\\Downloads\\output.in");
	
	if(inFile.is_open())
	{
		inFile>>tcCount;
		input= new string[tcCount*4+1];

		while(inFile.good())
		{
			getline(inFile,input[counter]);		
			if(!input[counter].empty())
			{
				counter++;
			}
		}
		
		inFile.close();
		
		counter = 0;
		while(counter<tcCount*4)
		{
			string TT[4];
			int incomplete=0;
			int sum[10]={0,0,0,0,0,0,0,0,0};
			

			for(iLoop=0;iLoop<4;iLoop++)
			{
				TT[iLoop]=input[counter];
				counter++;
			}
			
			opFile<<"Case #"<<counter/4<<": ";
			
			for(iLoop=0;iLoop<4;iLoop++)
			{
				for(jLoop=0;jLoop<4;jLoop++)
				{
					if(TT[iLoop][jLoop]=='X')
					{
						sum[iLoop]=sum[iLoop]+1;
						sum[jLoop+4]=sum[jLoop+4]+1;
						if(iLoop==jLoop)
						{
							sum[8]=sum[8]+1;
						}
						else if (iLoop+jLoop==3)
						{
							sum[9]=sum[9]+1;
						}
					}
					else if(TT[iLoop][jLoop]=='O')
					{
						sum[iLoop]=sum[iLoop]-1;	
						sum[jLoop+4]=sum[jLoop+4]-1;
						if(iLoop==jLoop)
						{
							sum[8]=sum[8]-1;
						}
						else if (iLoop+jLoop==3)
						{
							sum[9]=sum[9]-1;
						}
					}
					else if(TT[iLoop][jLoop]=='T')
					{
						sum[iLoop]=sum[iLoop]+10;
						sum[jLoop+4]=sum[jLoop+4]+10;
						if(iLoop==jLoop)
						{
							sum[8]=sum[8]+10;
						}
						else if (iLoop+jLoop==3)
						{
							sum[9]=sum[9]+10;
						}
					}
					else if(TT[iLoop][jLoop]=='.')
					{
						incomplete=1;
					}
				}
			}
			
			for(iLoop=0;iLoop<10;iLoop++)
			{
				if(sum[iLoop]==4 || sum[iLoop]==13)
				{
					opFile<<"X won\n";
					incomplete=0;
					break;
				}
				else if(sum[iLoop]==-4 || sum[iLoop]==7)
				{			
					opFile<<"O won\n";
					incomplete=0;
					break;
				}
			}
			if(incomplete==1 && iLoop==10)
			{
				opFile<<"Game has not completed\n";
			}
			else if(iLoop==10)
			{
				opFile<<"Draw\n";
			}
		}
		
		opFile.close();
		
		delete [] input;
	}
	else 
	{
		cout<<"File not found"<<"\n"; 
	}
}

