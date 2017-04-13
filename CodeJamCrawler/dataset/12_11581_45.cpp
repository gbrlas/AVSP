#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int f(int x)
{
    switch (x)
    {
        case 1: return 0; break;
        case 2: return 10; break;
        case 3: return 100; break;
        case 4: return 1000; break;
        case 5: return 10000; break;
        case 6: return 100000; break;
        case 7: return 1000000; break;
    }
}

int NumberOfDigits(int a)
{
    int counter=0;
    while(a != 0)
    {
        a = a/10;
        counter++;
    }
    return counter;
}

void MakePairs(vector<int> &v, int x)
{
    v.push_back(x);
    int counter = NumberOfDigits(x),a,b;
    for (int i=1 ; i<counter ; i++)
    {
        a = v[i-1]/10;
        b = v[i-1]%10;
        if (b == 0)
        {
            a = v[i-1]/100;
            b = v[i-1]%100;
            v.push_back(b*f(counter)/10 + a);
        }
        else
        {
            v.push_back(b*f(counter) + a);
        }
    }
}

int main()
{
    string str;
    //******************************************
    ifstream fin("C-small-attempt0.in");
    //******************************************
    ofstream fout("output.out");
    int count = 0;

    int A;
    int B;
    int C;
    int counter = 0;
    vector<int> pairs;

    while (!fin.eof())//(fin.good())
    {
        if (count == 0)
        {
            fin>>C;
            count++;
        }
        else
        {
            fin>>A>>B;
            counter = 0;
            for (int i=A ; i<=B ; i++)
            {
                pairs.clear();
                MakePairs(pairs,i);
                for (int j=0 ; j<pairs.size() ; j++)
                {
                    if (i != pairs[j] && i < pairs[j] && pairs[j] <= B)
                    {
                        counter++;
                    }
                }
            }
            fout<<"Case #"<<count++<<": "<< counter <<endl;
        }
    }

    return 0;
}
