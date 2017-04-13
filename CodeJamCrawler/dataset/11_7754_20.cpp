#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class FreeCell
{

    int pd,pg;
    long long int n;
    ifstream fin;
    ofstream fout;
    public:
    FreeCell():fin("A-large.in"),fout("output.out")
    {
    }
    void readInput()
    {
        int i,T;
        fin>>T;
        for(i=0;i<T;i++)
        {
            fin>>n;
            fin>>pd;
            fin>>pg;
            fout<<"Case #"<<i+1<<": "<<processRecord()<<endl;
        }

    }
    string processRecord()
    {
        if(pd!=100&&pg==100)
            return "Broken";
        if(pd>0&&pg==0)
            return "Broken";
        for(long long int i=1;i<=n;i++)
        {
           double num=((double)pd*i)/100;
           long long int n=(int)num;
           //cout<<i<<endl;

           if(num-((double)n)==0)
                return "Possible";
        }
        return "Broken";
    }
};

int main()
{
 FreeCell obj;
 obj.readInput();
}
