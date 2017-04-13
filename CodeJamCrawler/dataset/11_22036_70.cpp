#include <iostream>
#include <fstream>
using namespace std;

int Trans(char a)
{
    int nResult = -1;
    switch(a)
    {
        case 'Q':
            nResult = 0;
            break;
        case 'W':
            nResult = 1;
            break;
        case 'E':
            nResult = 2;
            break;
        case 'R':
            nResult = 3;
            break;
        case 'A':
            nResult = 4;
            break;
        case 'S':
            nResult = 5;
            break;
        case 'D':
            nResult = 6;
            break;
        case 'F':
            nResult = 7;
            break;
    }
    return nResult;
}


class Combin_C
{
public:
    void Init();
    void AddCombin(char a, char b, char c);
    char CheckCombin(char a, char b);
private:
    char m_Tbl[64];
};

class Oppose_C
{
public:
    void Init();
    void AddOppose(char a, char b);
    bool CheckOppose(char a, char b);
private:
    bool m_Tbl[64];
};

void Combin_C::Init()
{
    for(int i=0; i<64; ++i)
        m_Tbl[i]=0;
}

void Combin_C::AddCombin(char a, char b, char c)
{
    int nA = Trans(a);
    int nB = Trans(b);
    m_Tbl[nA*8+nB] = c;
    m_Tbl[nB*8+nA] = c;
}

char Combin_C::CheckCombin(char a, char b) 
{
     int nA = Trans(a);
     int nB = Trans(b);
     if( -1 == nA || -1 == nB)
         return 0;
     return m_Tbl[Trans(a)*8+Trans(b)]; 
}

void Oppose_C::Init()
{
    for(int i=0; i<64; ++i)
        m_Tbl[i]=false;
}

void Oppose_C::AddOppose(char a, char b)
{
    int nA = Trans(a);
    int nB = Trans(b);
    m_Tbl[nA*8+nB] = true;
    m_Tbl[nB*8+nA] = true;
}

bool Oppose_C::CheckOppose(char a, char b) 
{ 
    int nA = Trans(a);
    int nB = Trans(b);
    if( -1 == nA || -1 == nB)
         return false;
     return m_Tbl[Trans(a)*8+Trans(b)]; 
}

int main()
{
    ifstream fileIn("in.txt");
    ofstream fileOut("out.txt");
    Combin_C oCombin;
    Oppose_C oOppose;
    char elem[100];
    
    int nCaseNum = 0;
    fileIn >> nCaseNum;
    for(int nCurCase = 1; nCurCase<=nCaseNum; ++nCurCase)
    {
        oCombin.Init();
        oOppose.Init();
        char a,b,c;
        
        int nInputNum = 0;
        fileIn >> nInputNum;  //combin
        for(int i=0; i<nInputNum; ++i)
        {
            fileIn >> a;
            fileIn >> b;
            fileIn >> c;
            oCombin.AddCombin(a,b,c);
        }
        
        fileIn >> nInputNum; //oppose
        for(int i=0; i<nInputNum; ++i)
        {
            fileIn >> a;
            fileIn >> b;
            oOppose.AddOppose(a,b);
        } 
        
        int nLast = -1;
        fileIn >> nInputNum;
        for(int i=0; i<nInputNum; ++i)
        {
            fileIn >> a;
            if(-1 == nLast)
            {
                nLast = 0;
                elem[nLast] = a;
            }
            else
            {
                b = oCombin.CheckCombin(a, elem[nLast]);
                if(b)
                    elem[nLast] = b;
                else
                    elem[++nLast] = a;
            }
            
            for(int j=0; j<nLast; ++j)
            {
                if(oOppose.CheckOppose(elem[j],elem[nLast]))
                    nLast = -1;
            }
        }
        fileOut << "Case #" << nCurCase << ": [" ;
        int n=0;
        for(n=0; n<nLast; ++n)
            fileOut << elem[n] <<", ";
        if(n == nLast)
            fileOut << elem[n];
        fileOut << "]" << endl;
    }
    return 0;
}
