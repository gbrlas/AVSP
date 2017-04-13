#include<iostream>
#include<stdio.h>
#include<fstream>
#include<map>

using namespace std;

int main()
{
	char ch;
	int no,n = 0;
	int p,q,u,t,h,choice=0;
	
	int a,b,c,num;
	
	ifstream file("C-small-attempt3.in");
	ofstream f("output");
	file>>no;
	cout<<no;
	f<<"Case #"<<n+1<<": ";		
	file>>p;
	file>>q;
	while(!file.eof())
	{	
		int count = 0;
		int common = 0;
		cout<<p<<"and"<<q<<endl;
		if(p/10==0)
		{
			cout<<"ent";
			f<<"0"<<endl;
			file>>p;
			file>>q;
			n++;
			if(!file.eof())
				f<<"Case #"<<n+1<<": ";		
			continue;
		}
		if((p>9)&(p<100))
			choice = 1;
		if((p>99)&(p<=1000))
			choice = 2;
		switch(choice)
		{
			case 1: 
				for(int i = p;i<=q;i++)
				{
					cout<<i;
					u = i%10;
					t = i/10;			
					a = t;
					t = u;
					u = a;
					num = t*10 + u;
					if((num>=p)&&(num<=q)&&((num-i)!=0))
					{
						count++;				
						cout<<num<<endl;
					}					
				}
				count = count/2;
				cout<<count;
				break;
			case 2:		
				for(int i = p;i<=q;i++)
				{
					u = i%10;
					t = (i/10)%10;			
					h = i/100;
					a = h;
					b = t;
					h = u;
					t = a;
					u = b;
					num = h*100 + t*10 + u;
					if((num>=p)&&(num<=q)&&((num-i)!=0))
					{
						count++;				
//						cout<<num<<endl;
					}
					u = i%10;
					t = (i/10)%10;			
					h = i/100;
					a = h;
					b = t;
					h = t;
					t = u;
					u = a;			
					num = h*100 + t*10 + u;								
					if((num>=p)&&(num<=q)&&((num-i)!=0))
					{
						count++;				
//						cout<<num<<endl;
					}

				}
				count = count/2;				
				break;
		}			
		f<<count<<endl;		
		file>>p;
		file>>q;
		n++;
		if(!file.eof())
		{
			f<<"Case #"<<n+1<<": ";		
			cout<<endl;
		}
	}
	file.close();
	f.close();
	return 0;		
}
