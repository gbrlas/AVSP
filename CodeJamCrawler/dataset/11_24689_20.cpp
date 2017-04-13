#include <iostream>
#include <utility>
#include <fstream>
#include <vector>

using namespace std;
int main()
{
    ifstream f;
    f.open("A-large.in",ios::binary);
    ofstream of;
    of.open("out.txt",ios::binary);
    int cases;
    f >> cases;
    int i = 1;
    while(cases--)
    {
        int x;
        f >> x;
        char c;
        int size = x*2;
        int *ar = new int[size];
        for(int i = 0;i < size;i++,i++)
        {
            f.get(c),f.get(c);
            ar[i] = (int)c;
            f >> ar[i+1];
        }
        int steps = 0;
        int m1 = 0,m2 = 0;
        int ar1=1,ar2=1;
        while(m1 < size || m2 < size)
        {
            steps++;
            while(m1 < size && ar[m1] != 'O')
                m1++,m1++;
            while(m2 < size && ar[m2] != 'B')
                m2++,m2++;
            bool b1 =true, b2 = true;
            if(ar1 != ar[m1+1])
                ar1 = ar[m1+1] > ar1 ? ar1+1 : ar1-1 ,b1=false ;

            if(ar2 != ar[m2+1])
                ar2 = ar[m2+1] > ar2? ar2+1 : ar2-1,b2=false;

            if(m1 < m2)
            {
                if(ar1 == ar[m1+1] && b1)
                    m1+=2;
            }
            else
            {
                if(ar2 == ar[m2+1] && b2)
                    m2+=2;
            }
        }
        of << "Case #";
        of << i++;
        of << ": ";
        of << steps << endl;
        of.flush();
    }
    getwchar();
    return 0;
}
