#include <iostream>

using namespace std;

//returns is highscore poss
bool splittriplet(int tot, int bres, bool& issurpiseneededandpos)
{

    int trip1,trip2,trip3;
    if((tot)%3 ==0 )//n,n+1,n+2 || //n,n,n
    {
       trip1 = trip3 = trip2 = tot/3;
       if(trip3 >10 || trip1 <0)
            return false;
       if(trip3 >= bres)
       {
            issurpiseneededandpos = false;
            return true;
       }

        trip1 = trip2-1;
        trip3 = trip2+1;
        if(trip3 >= bres && trip3 <=10 && trip1 >=0)
        {
            issurpiseneededandpos = true;
            return true;
        }
       return false;
    }
    else if((tot-2)%3==0) //n,n, n+2 || n,n+1,n+1
    {
        trip1 =(tot-2)/3;
        trip2 = trip3 = trip1+1;
        if(trip3 >10 || trip1 <0)
            return false;
       if(trip3 >= bres)
       {
            issurpiseneededandpos = false;
            return true;
       }
        trip2 = trip1;
        trip3 = trip1+2;
        if(trip3 >= bres && trip3 <=10 && trip1 >=0)
        {
            issurpiseneededandpos = true;
            return true;
        }
       return false;
    }
    else if((tot-1)%3==0 )//n,n+2,n+2 || n,n,n+1

    {
        trip1 = (tot-1)/3;
        trip3=trip2 = trip1+1;

       if(trip3 >10 || trip1 <0)
            return false;
       if(trip3 >= bres)
       {
            issurpiseneededandpos = false;
            return true;
       }

        --trip1;
        trip3 = trip2 = trip1+2;
        if(trip3 >= bres && trip3 <=10 && trip1 >=0)
        {
            issurpiseneededandpos = true;
            return true;
        }
       return false;
    }
}

int main()
{
    int T;
    cin>>T;
    int c =0;
    while(c<T)
    {
        int possible =0, surprises =0;
        int no, tot, bres,s;
        cin >> no >> s >> bres;
        for(int i=0; i<no; ++i)
        {
          cin >> tot;
          bool issurpiseneededandpos;
          if(splittriplet(tot, bres, issurpiseneededandpos))
          {
             if(issurpiseneededandpos)
             {
                surprises++;
                if(surprises>s)
                {
                }
                else
                    possible++;

             }
             else
               possible++;
          }
        }
        cout<<"Case #"<<c+1<<": ";

        cout<< possible <<endl;
        ++c;
    }
    return 0;
}
