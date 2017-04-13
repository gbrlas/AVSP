#include <iostream>
#include <fstream>
using namespace std;
int mag[] = { 0, 1, 10, 100, 1000, 10000, 100000, 1000000 };
int rngmin = 1;
int rngmax = 1;
int dig = 1;
bool done[2000001];
void Reset()
{
    for(int i=rngmin; i<=rngmax; ++i)
        done[i] = false;
}
void BuildDig()
{
    int i = 0;
    while(1)
    {
        if(rngmin/mag[++i] == 0)
            break;
    }
    dig = i-1;
}
        
void Rotate(int& input)
{
    int L = input%10;
    input /= 10;
    input += L * mag[dig];
}
int GetRotateNum(int input)
{
    int Arr[7];
    for(int i=0; i<7; ++i)
        Arr[i] = -1;
    Arr[0] = input;
    done[input] = true;
    int no = 1;
    for(int i =1; i<dig; ++i)
    {
        Rotate(input);
        if(input<rngmin || input >rngmax)
            continue;
        int j=0;
        while(Arr[j]>0)
        {
            if(Arr[j] == input)
                break;
            ++j;
        }
        if(no == j)
        {
            Arr[no++] = input;
            done[input] = true;
        }
    }
    return (no*(no-1)/2);
}


int main()
{
    ifstream fileIn("in.txt");
    ofstream fileOut("out.txt");
    int nCaseNum = 0;
    fileIn >> nCaseNum;
    for(int nCurCase = 1; nCurCase<=nCaseNum; ++nCurCase)
    {
        fileIn >> rngmin;
        fileIn >> rngmax;
        Reset();
        BuildDig();
        int result = 0;
        for(int i=rngmin; i<=rngmax; ++i)
        {
            if(true == done[i])
                continue;
            result += GetRotateNum(i);
        }
        fileOut << "Case #" << nCurCase << ": " << result << endl;
    }
    return 0;
}
    
    
    
