#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream infile("C-small-attempt4.in");
	ofstream outfile("out.txt");
	char str[] = "welcome to code jam";
	int  pos[19];
	char temp[501],ch;
	int tempLen = 0;
	int caseCount = 0;
	int i,j,count,k;
	infile>>caseCount;
	ch=infile.get();
	for(k=1;k<=caseCount;k++)
	{
		count=0;
		j=0;
		i=0;
		infile.getline(temp,501);
		tempLen = strlen(temp);
		while(1)
		{
			if(i<0)
				break;
			if(temp[j]==str[i])
			{
				pos[i] = j;
				if(i==18)
				{
					count++;
					if(count>=10000)
						count = count%10000;
					if(j<tempLen-19+i)
						j++;
					else
					{
						i--;
						j = pos[i]+1;
					}
				}
				else
				{
					i++;
					j++;
					if(tempLen-j<19-i)
					{
						i-=2;
						j = pos[i]+1;
					}
				}
			}
			else
			{
				j++;
				if(tempLen-j<19-i)
				{
					i-=1;
					j = pos[i]+1;
				}
			}
		}
		outfile<<"Case #"<<k<<": ";
		for(i=1000;i>=10;i/=10)
			if(count/i==0)
				outfile<<'0';
		outfile<<count<<endl;
	}
	infile.close();
	outfile.close();
	return 0;
}