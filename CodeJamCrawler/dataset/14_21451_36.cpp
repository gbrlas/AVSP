#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <stdio.h>

class Magic
{
    int TrickCount;
    int FirstNumber;
    int SecondNumber;

    public:
    void DoTricks()
    {
        std::cin>>TrickCount;
        for(int i=0; i<TrickCount; i++)
            std::cout<<"Case #"<<i+1<<": "<<SingleTrick().c_str()<<std::endl;
    }
    std::string SingleTrick()
    {
        std::cin>>FirstNumber;
        std::vector<int> FirstRow=ReadRow(FirstNumber);
        std::cin>>SecondNumber;
        std::vector<int> SecondRow=ReadRow(SecondNumber);

        int SharedCard=-1;
        int SharedCount=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(FirstRow[i]==SecondRow[j])
                {
                    SharedCard=FirstRow[i];
                    ++SharedCount;
                }
            }
        }
        if(SharedCount==0)
            return "Volunteer cheated!";
            if(SharedCount==1)
            {
                char str[4];
                sprintf(str, "%d", SharedCard);
                return str;
            }
            return "Bad magician!";
    }
    std::vector<int> ReadRow(int rowNumber)
    {
        int ignoredNumber;
        std::vector<int> Result;
        for(int i=0; i<(rowNumber-1)*4; i++)
        {
            std::cin>>ignoredNumber;
        }
        for(int i=0; i<4; i++)
        {
            int toPush;
            std::cin>>toPush;
            Result.push_back(toPush);
        }
        for(int i=rowNumber*4; i<16; i++)
        {
            std::cin>>ignoredNumber;
        }
        return Result;
    }
};

int main(int argc, char* argv[])
{
    Magic M;
    M.DoTricks();
    return 0;
}
