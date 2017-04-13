#include <iostream>
#include <fstream>

using namespace std;

void GetEachUnit(char rule[300], char unit[10][26])
{
    long i,j;
    // clear unit
    for(i = 0; i < 10 ; i++)
        for(j=0;j<26;j++)
            unit[i][j]='\0';

    long pos = 0, num = 0;
    while(rule[pos] != '\0')
    {
        if(rule[pos] == '(')
        {
            pos++;
            for( i = 0; rule[pos] != ')'; i++)
            {
                unit[num][i] = rule[pos++];
            }
            num++;
            pos++;
        }
        else
        {
            //cout<<rule[pos]<<endl;
            unit[num++][0] = rule[pos++];
        }
        //cout<<unit[num-1]<<endl;
    }
}

int main(int argc, char* argv[])
{
    //ifstream input("test.in");
    ifstream input("A-small-attempt1.in");
    ofstream output("A-small-attempt1.out");
    long L,D,N,i,j,k,w;
    char words[25][10];
    char rule[300];
    char unit[10][26];
    long res[10];
    int flag = 0;
    long count;

    input >> L >> D >> N;

    //cout << L << " " << D << " " << N << endl;

    for(i=0;i<D;i++)
    {
        input >> words[i];
    }

    for(i=1;i<=N;i++)
    {
        output<<"Case #"<<i<<": ";
        input >> rule;
        GetEachUnit(rule,unit);

        count = 0;

        for(w=0;w<D;w++)
        {
            for(j=0;j<L;j++)
            {
                flag = 0;
                for(k=0;unit[j][k]!='\0';k++)
                {
                    if(unit[j][k] == words[w][j])
                        flag = 1;
                }
                if(flag == 0)
                    break;
            }
            if(j==L) count++;
        }

        output<<count<<endl;
    }

    return 0;
}
