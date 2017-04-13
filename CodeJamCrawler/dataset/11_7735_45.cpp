#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class magicka
{
    string base;
    vector<char> oppose[26];
    typedef pair<char,char> combination;
    vector<combination> combine[26];
    int linecount;
    string final;
    ifstream fin;
    ofstream fout;
    public:
    magicka():fin("B-small-attempt1.in",ios::in),fout("output1",ios::out)
    {
    if(!fin||!fout)
        exit(1);
    linecount=0;
    }
    void readInput();
    void processOneRecord();
    void printVector();
    char canCombine(char,char);
    bool isOpposing(char);
    void printOutput();
    void clear();
};
    void magicka::readInput()
    {
        int i,j;
        int T,read;
        string temp;
        fin>>T;
        for(i=0;i<T;i++)
        {
            fin>>read;
            for(j=0;j<read;j++)
            {
             fin>>temp;
             combination t1(temp[1],temp[2]),t2(temp[0],temp[2]);
             combine[temp[0]-65].push_back(t1);
             combine[temp[1]-65].push_back(t2);
            }
            fin>>read;
            for(j=0;j<read;j++)
            {
                fin>>temp;
                oppose[temp[0]-65].push_back(temp[1]);
                oppose[temp[1]-65].push_back(temp[0]);
            }
            fin>>read;
            fin>>base;
            //printVector();
            processOneRecord();
            printOutput();
            clear();
        }


    }
    void magicka::processOneRecord()
    {
        char temp;
        final.append(1,base[0]);
        for(int i=1;i<base.size();i++)
        {
         if(final.size())
         {
            if(temp=canCombine(base[i],final[final.size()-1]))
            {
                final.erase(final.size()-1,1);
                final.append(1,temp);
            }
            else if(isOpposing(base[i]))
                final.clear();
            else
              final.append(1,base[i]);
         }
        else
            final.append(1,base[i]);
        }
    }
    char magicka::canCombine(char c1,char c2)
    {
        int index=c1-65;
        for(int i=0;i<combine[index].size();i++)
            if(combine[index][i].first==c2)
                return combine[index][i].second;
        return 0;

    }
    bool magicka::isOpposing(char in)
    {
        for(int i=0;i<final.size();i++)
        {
        vector<char>::iterator iter=find(oppose[final[i]-65].begin(),oppose[final[i]-65].end(),in);
        if(iter!=oppose[final[i]-65].end())
            return 1;
        }
        return 0;
    }
    void magicka::printOutput()
    {
        fout<<"Case #"<<++linecount<<": [";
        for(int i=0;i<final.size();i++)
        {
            if(i)
            fout<<", ";
            fout<<final[i];
        }
        fout<<"]"<<endl;
    }
    void magicka::clear()
    {
        for(int i=0;i<26;i++)
        {
            combine[i].clear();
            oppose[i].clear();
        }
        base.clear();
        final.clear();

    }

    void magicka::printVector()
    {
        for(int i=0;i<26;i++)
        {
            cout<<(char)(i+65)<<"\t";
            for(int j=0;j<combine[i].size();j++)
            cout<<combine[i][j].first<<combine[i][j].second<<"\t";
            cout<<endl;
        }
        cout<<endl<<endl;
        for(int i=0;i<26;i++)
        {
            cout<<(char)(i+65)<<"\t";
            for(int j=0;j<oppose[i].size();j++)
            cout<<oppose[i][j]<<"\t";
            cout<<endl;
        }
    }
int main()
{
magicka game;
game.readInput();
}




