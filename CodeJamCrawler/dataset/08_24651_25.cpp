#include<iostream>
#include<cstring>

using namespace std;

#define MAX1 1000
#define MAX2 100
class Uni
{
	public:
		int num_queries,num_engines;
		int counter[MAX2];
		string queries[MAX1];
		string engines[MAX2];
		
		void initcounter()
		{
			
			
			for(int i=0;i<num_engines;i++)
			{
				counter[i]=0;
			
				
			}
		}

		int checkcounter()
		{
			for(int i=0;i<num_engines;i++)
			{
				if(counter[i]==0)
				{
					return(1);
				}
			}
			return(0);
		}

		int getswitch()
		{
			int count=0,num_switch=0;
		        	
			while(count!=num_queries)
			{
				initcounter();
				while(checkcounter())
				{
					for(int i=0;i<num_engines;i++)
					{
						
						if(queries[count].compare(engines[i])==0)
						{
							

							counter[i]++;
							
							break;
						}
					}
					count++;
					if(count==num_queries)
					{
						break;
					}
					
				}
				if((count==num_queries)&&(checkcounter()==0))
				{
					num_switch++;
				}
				if(!(count==num_queries))
                                {
                        		num_switch++;        
			                count--;
                                }
			}
			return(num_switch);
		}
};

int main()
{
	
	int cases,i=0;
	
	cin>>cases;
	while(i!=cases)
	{
		Uni a;
		
		i++;
		
		cin>>a.num_engines;
		cin.ignore(10,'\n');
		for(int j=0;j<a.num_engines;j++)
		{
		
			getline(cin,a.engines[j]);
		}
		
		cin>>a.num_queries;
		cin.ignore(10,'\n');
		for(int j=0;j<a.num_queries;j++)
		{
			
			getline(cin,a.queries[j]);
		}
		cout<<"Case #"<<i<<": "<<a.getswitch()<<"\n"; 
	}
	return(1);
}
