#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;


class timeVig
{
      public:
             int hour;
             int minutes;
             int operator>=(timeVig);
             timeVig operator+(int);
             timeVig(int,int);
             timeVig();
            
};

timeVig ::  timeVig(int a,int b)
{
                      hour = a;
                      minutes = b;
}

timeVig :: timeVig()
{
}

int timeVig :: operator>=(timeVig t)
{
    if(hour> t.hour || (hour == t.hour && minutes >= t.minutes ))
             return(1);
    return(0);
}

timeVig timeVig :: operator+(int t)
{
     timeVig temp;
     temp.minutes = minutes+t;
     temp.hour = hour;
     while(temp.minutes>=60)
     {
          temp.minutes -= 60;
          temp.hour++;
     }
     return temp;
}          
             

class station
{
      vector<timeVig> ArratS;
      vector<timeVig> DepatS;
      int ArrTable[26][62];
      int DepTable[26][62];
      
      public:
             int calcTrains(int);
             void initVectors();
             friend void setTableVal(int,station &A,station &B,int,int,int,int);
             void display();
             station();
};

void station :: display()
{
     
     for(int i = 0;i<24;i++)
     {
             for(int j = 0;j<60;j++)
             {
                     if(DepTable[i][j])
                     {    cout<<i<<","<<j<<"      ";
                          cin.get();
                     }
              }
     }
}

station :: station()
{
        memset(ArrTable,0,sizeof(ArrTable));
        memset(DepTable,0,sizeof(DepTable));
}

void setTableVal(int flag,station & A,station & B,int i1,int j1,int i2,int j2)
{
     if(flag == 1)
     {
             B.DepTable[i1][j1]++;
             A.ArrTable[i2][j2]++;
     }
     else
     {
             A.DepTable[i1][j1]++;
             B.ArrTable[i2][j2]++;
     }
}
     

void  station :: initVectors()
{
     for(int i = 0;i<24;i++)
     {
           for(int j = 0;j<60;j++)
           {
                   if(ArrTable[i][j]>0)
                   {       
                           timeVig temp(i,j);
                           for(int count = 1;count<=ArrTable[i][j];count++)
                                   ArratS.push_back(temp);
                   }
                   if(DepTable[i][j]>0)
                   {
                          timeVig temp(i,j);
                           for(int count = 1;count<=DepTable[i][j];count++)
                                   DepatS.push_back(temp);
                   }
           }
     }
}
                                     


int station :: calcTrains(int turntimeVig)
{
    int numTrains = 0;
    int SIZE1 = DepatS.size();
       
    for(int i = 0;i<SIZE1;i++)
    {
            if(ArratS.size() == 0)
                             numTrains++;
            else
            {
                timeVig temp;
                temp = ArratS[0]+turntimeVig;
                if(DepatS[i]>= temp)
                {
                           vector<timeVig> :: iterator p = ArratS.begin();
                           ArratS.erase(p);
                }
                else
                    numTrains++;
            }
    }
    return numTrains;
}

int main()
{
    int turntimeVig,tripsA,tripsB,cases,count;
    vector<int> outputA,outputB;
    int num1,num2,num3,num4;
    int i;
    ifstream ifile("c:\\abc.in");
    ofstream ofile("c:\\abc.out");
    if(!ifile)
    {
              cout<<"Error!!!";
              cin.get();
              cin.get();
              exit(0);
    }
    ifile>>cases;
    for(count = 1;count<=cases;count++)
    {
            station A,B;
            string s1,s2;
            string c(" ");
            ifile>>turntimeVig;
            ifile>>tripsA>>tripsB;
            for(i = 1;i<=tripsA;i++)
            {
                  ifile>>s1;
                  s1.replace(2,1,c); //to be checked
                  istringstream in1(s1); 
                  ifile>>s2;
                  s2.replace(2,1,c); // to be checked
                  istringstream  in2(s2);
                  if(in1>>num1 && in1>>num2 && in2>>num3 && in2>>num4)
                            setTableVal(0,A,B,num1,num2,num3,num4); 
                  
            }
            for(i = 1;i<=tripsB;i++)
            {
                  ifile>>s1;
                  s1.replace(2,1,c); //to be checked
                  istringstream in1(s1); 
                  ifile>>s2;
                  s2.replace(2,1,c); // to be checked
                  istringstream  in2(s2);
                  if(in1>>num1 && in1>>num2 && in2>>num3 && in2>>num4)
                              setTableVal(1,A,B,num1,num2,num3,num4);  
            }
            A.initVectors();
            B.initVectors();
            int x = A.calcTrains(turntimeVig);
            int y = B.calcTrains(turntimeVig);
            outputA.push_back(x);
            outputB.push_back(y);
    }
    for(count = 0;count<outputA.size();count++)
            ofile<<"Case #"<<count+1<<": "<<outputA[count]<<" "<<outputB[count]<<"\n";
    ifile.close();
    ofile.close();
    cin.get();
    return(0);
}
                  
    
                        
                        
