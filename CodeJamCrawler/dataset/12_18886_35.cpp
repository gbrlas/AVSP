#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const char target [27][2]={
    {'a', 'y'},
{'b', 'h'},
{'c', 'e'},
{'d', 's'},
{'e', 'o'},
{'f', 'c'},
{'g', 'v'},
{'h', 'x'},
{'i', 'd'},
{'j', 'u'},
{'k', 'i'},
{'l', 'g'},
{'m', 'l'},
{'n', 'b'},
{'o', 'k'},
{'p', 'r'},
{'q', 'z'},
{'r', 't'},
{'s', 'n'},
{'t', 'w'},
{'u', 'j'},
{'v', 'p'},
{'w', 'f'},
{'x', 'm'},
{'y', 'a'},
{'z', 'q'},
{' ',' '}
    };


int indexTarget(char alpha)
{
  for(int i=0;i<27;i++)
      {if(alpha==target[i][0])
        return i;
	}
return 0;
}

int main()
{
    char testString[100];
    int noOfCase;
    string l;

    ifstream cin("A-small-attempt0.in");
    ofstream cout("A-small.out");

    cin>>noOfCase;

    getline(cin,l);


    for(int cc=1;cc<=noOfCase;cc++)
    {
        char output[100];
        string ss;
        getline(cin,ss);
        int testsize;
        testsize=ss.length();
        for(int ic=0;ic<testsize;ic++)
        {
            int id;
            id=indexTarget(ss[ic]);
            output[ic]=target[id][1];

        }

        string o(output,testsize);

        cout<<"Case #"<<cc<<": "<<o<<endl;
    }


return 0;




    }
