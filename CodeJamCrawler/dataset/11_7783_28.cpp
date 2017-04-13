#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class PerfectHarmony
{
    vector<int> frequencies;
    int L,H;
    int record;
    ifstream fin;
    ofstream fout,question;
    public:
    PerfectHarmony():fin("C-small-attempt0 (1).in"),fout("output.out"),question("question.out")
    {
        record=0;
    }
    void readInput()
    {
        int i,j,T,N;
        int temp;
        fin>>T;
        for(i=0;i<T;i++)
        {
            fin>>N>>L>>H;
            for(j=0;j<N;j++)
            {
                fin>>temp;
                frequencies.push_back(temp);
            }
            processRecord();
            frequencies.clear();
        }
    }

    void processRecord()
    {
        int flag;
        for(int i=L;i<=H;i++)
        {
            flag=0;
            for(int j=0;j<frequencies.size();j++)
            {
                if(frequencies[j]%i==0||i%frequencies[j]==0)
                    continue;
                else
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                fout<<"Case #"<<++record<<": "<<i<<endl;
                return;
            }
        }
        fout<<"Case #"<<++record<<": NO"<<endl;
    }

};

int main()
{
PerfectHarmony obj;
 obj.readInput();
}
