#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class SquareTiles
{
    vector<string> input;
    int record;
    ifstream fin;
    ofstream fout,question;
    public:
    SquareTiles():fin("A-small-attempt1 (1).in"),fout("output.out"),question("question.out")
    {
        record=0;
    }
    void readInput()
    {
        int i,R,j,T;
        string temp;
        fin>>T;
        question<<T<<endl;
        for(i=0;i<T;i++)
        {
            fin>>R;
            fin>>j;
            question<<R<<" "<<j<<endl;
            for(j=0;j<R;j++)
            {
                fin>>temp;
                question<<temp<<endl;
                input.push_back(temp);
            }
            question<<endl<<endl;
            writeOutput(processRecord());
            input.clear();
        }
    }

    void display()
    {
         for(int i=0;i<input.size();i++)
                cout<<input[i]<<endl;
            cout<<endl<<endl;
    }
    int makeRed(int x,int y)
    {
        if(x+1>=input.size()||y+1>=input[0].size())
            return 0;
        if(input[x+1][y+1]!='#'||input[x][y+1]!='#'||input[x+1][y]!='#')
            return 0;
        input[x][y]=input[x+1][y+1]='/';
        input[x+1][y]=input[x][y+1]='\\';
    }

    int processRecord()
    {

        for(int i=0;i<input.size();i++)
        {
           for(int j=0;j<input[0].size();j++)
           {
               if(input[i][j]=='#')
               {
                   if(!makeRed(i,j))
                        return 0;
               }
           }
        }
        return 1;
    }

    void writeOutput(int n)
    {
        if(!n)
        {
            fout<<"Case #"<<++record<<":"<<endl<<"Impossible"<<endl;
            return;
        }
        else
        {
            fout<<"Case #"<<++record<<": "<<endl;
            for(int i=0;i<input.size();i++)
                fout<<input[i]<<endl;
        }
    }

};

int main()
{
SquareTiles obj;
 obj.readInput();
}
