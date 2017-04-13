#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int min(int x,int y)
{
    return (x>y)?y:x;
}
class BotTrust
{
    int time,num;
    int curr_blue,curr_orange;
    string line;
    int *arr,arr_size;
    int linecount;
    ifstream fin;
    ofstream fout;
    ofstream qn;
    public:
    BotTrust():fin("A-small-attempt1.in",ios::in),fout("output",ios::out),qn("question",ios::out)
    {
    if(!fin||!fout)
        exit(1);
    linecount=arr_size=0;
    curr_blue=curr_orange=1;
    }
    void readInput();
    void processOneRecord();
};
    void BotTrust::readInput()
    {
        int i,j;
        int T;
        char robot;
        int button;
        fin>>T;
        qn<<T<<endl;
        for(i=0;i<T;i++)
        {
            fin>>num;
            qn<<num;
            arr=new int[num];
            arr_size=0;
            for(j=0;j<num;j++)
            {
             fin>>robot;
             fin>>button;
             qn<<" "<<robot<<" "<<button;
             line.append(1,robot);
             arr[arr_size++]=button;
            }
            qn<<endl;
            processOneRecord();
            fout<<"Case #"<<++linecount<<": "<<time<<endl;
            curr_blue=curr_orange=1;
            line.clear();
            delete arr;
        }
    }
    void BotTrust::processOneRecord()
    {
        bool flag=false;
        time=0;
        char robot;
        int button;
        int prev_orange=1,prev_blue=1;
        for(int i=0;i<num;i++)
        {
            flag=false;
            robot=line[i];
            button=arr[i];
            if(robot=='O')
            {
                if(prev_orange<=button)
                {
                    if(curr_orange<button)
                    {
                    time+=(button-curr_orange);
                    curr_blue+=(button-curr_orange);
                    }
                    curr_orange=prev_orange=button;
                    time+=1;
                    curr_blue+=1;
                }
                else
                {
                    int diff=curr_orange-prev_orange;
                    curr_orange=prev_orange-diff;
                    if(button<curr_orange)
                    {
                        time+=(curr_orange-button);
                        curr_blue+=(curr_orange-button);
                    }
                    curr_orange=prev_orange=button;
                    time+=1;
                    curr_blue+=1;
                }
            }
            else
            {
                if(prev_blue<=button)
                {
                    if(curr_blue<button)
                    {
                    time+=(button-curr_blue);
                    curr_orange+=(button-curr_blue);
                    }
                    curr_blue=prev_blue=button;
                    time+=1;
                    curr_orange+=1;
                }
                else
                {
                    int diff=curr_blue-prev_blue;
                    curr_blue=prev_blue-diff;
                    if(button<curr_blue)
                    {
                        time+=(curr_blue-button);
                        curr_orange+=(curr_blue-button);
                    }
                    curr_blue=prev_blue=button;
                    time+=1;
                    curr_orange+=1;
                }
            }
        }

    }



int main()
{
BotTrust obj;
obj.readInput();
}




