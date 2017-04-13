#include<fstream.h>
#include<process.h>
#include<conio.h>

int check(char s[],int n, char a)
{
for(int i =n;s[i]!=')';i++)
	{
	}
for(int j =n;j<i;j++)
	{
	if(s[j]==a)
		{
		return i+1;
		}
	}
return 0;
}
	
		
void main()

{
clrscr();
char lang[25][10];
ifstream file("A-small.in");
ofstream filo("output.out");
if(!file)
	{
	cout<<" NO FILE FOUND";
	getch();
	exit(0);
	}
int l,d,n;
file>>l>>d>>n;
cout<<l<<d<<n<<"\n";

for(int i=0;i<d;i++)
	{
	file>>lang[i];
	}

char curr [1000];

for(i=0;i<n;i++)
	{
	file>>curr;
	cout<<curr<<"\n";
	int ctr=0;	// pos for curr...... posL for lang
	for(int j=0;j<d;j++)
		{
		int pos=0;
		int posL=0;
		A:int chk=0;
		if(posL==l)
			{
			ctr++;

			continue;
			}
		else if(curr[pos]=='(')
			{
			pos=check(curr,pos,lang[j][posL]);
			cout<<pos<<"\n";
				if(pos==0)
					continue;
				else
					posL++;
			}
		
		else if (curr[pos++]!=lang[j][posL++])
			{
			continue;
			}
		
		goto A;
		}
	cout<<ctr;
	filo<<"Case #"<<i+1<<": "<<ctr<<"\n";
	}
	filo.close();
	file.close();
	cout<<"DONE";
	getch();

	
}