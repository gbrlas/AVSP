#include <iostream>
#include <string.h>

using namespace std;

bool isPall(unsigned int n)
{
    unsigned int reverse=0, rem,temp;
    temp=n;
    while(temp!=0)
    {
        rem=temp%10;
        reverse=reverse*10+rem;
        temp/=10;
    }
    /* Checking if number entered by user and it's reverse number is equal. */
    if(reverse==n)
        return true;
    else
        return false;
    
    return 0;
}

int main()
{
    unsigned int nTestCases = 0;
    cin>>nTestCases;
    
    int *output = new int[nTestCases];
    int **storage = new int*[nTestCases];
    
    for(unsigned int iii = 0; iii < nTestCases; iii++)
    {
        unsigned int a;
        unsigned int b;
        cin>>a;
        cin>>b;
        
        storage[iii] = new int[2];
        storage[iii][0] = a;
        storage[iii][1] = b;
    }
    
    for(unsigned int iii = 0; iii < nTestCases; iii++)
    {
        unsigned int a = storage[iii][0];
        unsigned int b = storage[iii][1];
        
        int n = 0;
        
        for(unsigned int jjj = 0; jjj <= b; jjj++)
        {
            if(isPall(jjj) == true)
            {
                unsigned int x = jjj * jjj;
                
                if(isPall(x) == true && x <= b && x >= a)
                {
                    n++;
                }
            }
        }

        output[iii] = n;
    }
    
    for(int iii = 0; iii < nTestCases; iii++)
    {
        //Case #1: 2
        cout<<"Case #"<<iii+1<<": "<<output[iii]<<"\n";
    }
    
    cin.get();
    cin.ignore();

    return 0;
}