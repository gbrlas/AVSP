#include<iostream>
#include<string>


using namespace std;

void initialize(int x[],int size)
{
	for(int i=0;i<size;i++)
	{
	x[i]=0;
	}
}


int main()
{
    int t;
    cin>>t;
    int X[10],O[10],T[10],DOT[10];
    for(int i=0;i<t;i++)
    {
	initialize(X,10);
	initialize(O,10);
	initialize(T,10);
	initialize(DOT,10);
	
	string b[4];
        for(int j=0;j<4;j++)
        { 
            cin>>b[j];
        }

        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(b[j].at(k)=='X')
                {
                    X[j]++;
                }
                else if(b[j].at(k)=='O')
                {
                    O[j]++;
                }
                else if(b[j].at(k)=='T')
                {
                    T[j]++;
                }
                else
                    DOT[j]++;

                if(b[k].at(j)=='X')
                {
                    X[j+4]++;
                }
                else if(b[k].at(j)=='O')
                {
                    O[j+4]++;
                }
                else if(b[k].at(j)=='T')
                {
                    T[j+4]++;
                }
                else
                    DOT[j+4]++;
            }
        }

        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(j==k)
                {
                    if(b[k][j]=='X')
                    {
                        X[8]++;
                    }
                    else if(b[k][j]=='O')
                    {
                        O[8]++;
                    }
                    else if(b[k][j]=='T')
                    {
                        T[8]++;
                    }
                    else
                        DOT[8]++;
                }
                if(j+k==3)
                {
                    if(b[k][j]=='X')
                    {
                        X[9]++;
                    }
                    else if(b[k][j]=='O')
                    {
                        O[9]++;
                    }
                    else if(b[k][j]=='T')
                    {
                        T[9]++;
                    }
                    else
                        DOT[9]++;
                }
            }
        }
        int Xwin=0,Owin=0,dotcount=0;
        for(int j=0;j<10;j++)
        {
            dotcount+=DOT[j];
            if(X[j]==4 || (X[j]==3 && T[j]==1))
            {
		Xwin=1; break;
	    }
            else if(O[j]==4 || (O[j]==3 && T[j]==1))
            {
           	Owin=1; break;
	    }
        }
        if(Xwin)
        {
            cout<<"Case #"<<i+1<<": X won\n";
        }
        else if(Owin)
        {
            cout<<"Case #"<<i+1<<": O won\n";
        }
        else if(dotcount==0)
        {
            cout<<"Case #"<<i+1<<": Draw\n";
        }
        else
        {
            cout<<"Case #"<<i+1<<": Game has not completed\n";
        }

    }
}

