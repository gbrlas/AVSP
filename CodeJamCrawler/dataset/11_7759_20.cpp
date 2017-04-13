#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class RPI
{
    int N,record;
    vector<string> input;
    vector<double> output;
    vector<double> wp,owp,oowp;
    ifstream fin;
    ofstream fout;
    public:
    RPI():fin("A-small-attempt0 (1).in"),fout("output.out")
    {
        record=0;
    }
    void readInput()
    {
        string temp;
        int i,j,T;
        fin>>T;
        for(i=0;i<T;i++)
        {
            fin>>N;
            for(j=0;j<N;j++)
            {
                fin>>temp;
                input.push_back(temp);
            }
            processRecord();
            writeOutput();
            input.clear();
            wp.clear();
            owp.clear();
            oowp.clear();
            output.clear();

        }
    }
    void display(vector<double> in)
    {
        for(int i=0;i<in.size();i++)
            cout<<in[i]<<" ";
        cout<<endl;
    }
    void fillwp()
    {
        int played,won;
        for(int i=0;i<input.size();i++)
        {
            played=won=0;
            for(int j=0;j<input[i].size();j++)
            {
             if(input[i][j]=='1')
             {
                    ++played;
                    ++won;
             }
             else if(input[i][j]=='0')
                ++played;
            }
            wp.push_back(((double)won)/played);
        }
    }

    void fillowp()
    {
        vector<double> temp;
        double owp_c=0;
        int played,won;
        for(int i=0;i<input.size();i++)
        {
            for(int j=0;j<input.size();j++)
            {
                if(i==j||input[i][j]=='.')
                    continue;
                played=won=0;
                for(int k=0;k<input[j].size();k++)
                {
                    if(k==i)
                        continue;
                    if(input[j][k]=='1')
                    {
                        ++played;
                        ++won;
                    }
                    else if(input[j][k]=='0')
                        ++played;
                }
                temp.push_back(((double)won)/played);

            }
            for(int k=0;k<temp.size();k++)
                owp_c+=temp[k];
            owp.push_back(owp_c/((double)temp.size()));
            temp.clear();
            owp_c=0;
        }
    }

    void filloowp()
    {
        double oowp_c;
        int count;
        for(int i=0;i<input.size();i++)
        {
            oowp_c=0;
            count=0;
            for(int j=0;j<input[i].size();j++)
            {
                if(input[i][j]!='.')
                {
                    oowp_c+=owp[j];
                    count++;
                }
            }
            oowp.push_back(oowp_c/((double)count));
        }
    }
        void processRecord()
        {
            fillwp();
            fillowp();
            filloowp();
            for(int i=0;i<input.size();i++)
                output.push_back(0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]);

        }
        void writeOutput()
        {
            fout<<"Case #"<<++record<<": "<<endl;
            for(int i=0;i<output.size();i++)
                fout<<output[i]<<endl;
        }


};

int main()
{
 RPI obj;
 obj.readInput();
}
