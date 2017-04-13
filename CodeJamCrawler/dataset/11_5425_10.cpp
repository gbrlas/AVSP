// inserting into a vector
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main ()
{
  int T_C=1,T,R,C;char Arr[50][50];
  cin >> T;
  while(T_C<=T)
  {
    cin >>R>>C;
    cout <<"Case #"<<T_C<<":"<<endl;
    for(int i=0;i<R;i++)
        //for(int j=0;j<C;j++)
            scanf("%s",Arr[i]);


	int c_hash=0;int possible=0;
    for(int i=0;i<R;i++)
       for(int j=0;j<C;j++)
         if(Arr[i][j]=='#')
            c_hash++;

     if(c_hash >0 && c_hash % 4 != 0)
     {	cout <<"Impossible"<<endl;
	T_C++;
      continue;
     }
     else if(c_hash==0)
     {   for(int i=0;i<R;i++)
        //for(int j=0;j<C;j++)
            printf("%s\n",Arr[i]); 
	T_C++;
       continue;
     }	
     else{      
		for(int i=0;i<R;i++)
                   for(int j=0;j<C;j++)
                       if(Arr[i][j]=='#')
			{
				if(Arr[i][j+1]=='#' && Arr[i+1][j] == '#' && Arr[i+1][j+1] == '#')
				{
					possible =1;
					Arr[i][j]='/';
					Arr[i][j+1]='\\';
					Arr[i+1][j]='\\';
					Arr[i+1][j+1] = '/';
				}
				else{
				      possible=0;
				}
			}
	}
	if (possible == 0)
		cout <<"Impossible"<<endl;
	else
	{
		for(int i=0;i<R;i++)
        //for(int j=0;j<C;j++)
            printf("%s\n",Arr[i]); 
	}


      


    T_C++;
}


  return 0;
}


