

//   compiled on ubuntu using     code block's
#include <iostream>
#include<fstream>
# include<string.h>

using namespace std;

int main()
{
   long int n,i,o,j,x,r,k,g,d,tmp,t,money=0,f=0,z,tripmoney=0,st;
    ifstream fin("C-small-attempt5.in");

     fin.seekg(0);
    fin>>t;
    long int out[t];
    for(g=1;g<=t;++g)
    {

                                                 //main loop
          money=0;

            fin>>r;
            fin>>k;
            fin>>n;

            long int q[n+1];
            //<<<<<<<<<<<<<<<<<<<<<<     GETTING VALUES   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


            for(j=0;j<n;j++)
            {
                fin>>tmp;
                q[j]=tmp;

                          }


            //<<<<<<<<<<<<<<<<<<<<<   VALUES IMPORTED  >>>>>>>>>>>>>>>>>>>>>

            //<<<<<<<<<<<<<<<<<<<<<  FINDING  COST >>>>>>>>>>>>>>>>>>>>>>>>>

            //<<<<<<<<<<<<<<<<<<<<<MULTIPLE TRIP SIMULATION>>>>>>>>>>>>>>>>
            for( i=0;i<r;i++)
            {

               x=0;tripmoney=0; tmp=0;st=1;
                //<<<<<<<<<<<<<<<<<<<<<<SIMULATION STARTS  >>>>>>>>>>>>>>>
                //<<<<<<<<<<<<<<<<<<<<<  CALCULATING PERTRIP REVENUE   >>>>>>>>>>>>

           do{
               ++tmp;
               if(q[0]+tripmoney<=k && tmp<=n)
               {
                   x=q[0];
                   tripmoney=tripmoney+q[0];
             for(z=0;z<n-1;++z)
                   {
                        q[z]=q[z+1];
                     } q[n-1]=x;
               }
               else
               break;


                       }while(st=1);
             //   <<<<<<<<<<<<<     one day's trips run    >>>>>>>>>>>>>>>>>>>>><<<<<<<<    heading to next   >>>>>>>>>>>
money+=tripmoney;}
            cout<<"\ncase #"<<g<<":"<<money;
out[g]=money;


}
fin.close();


ofstream a_file ( "outcr.txt" );
a_file.seekp(0);
for(i=1;i<=t;++i)
{
  // Outputs to example.txt through a_file
  a_file<<"Case #";
  a_file<<i;
  a_file<<": ";
  a_file<<out[i];
  a_file<<"\n";
    // Close the file stream explicitly

} a_file.close();

cin.get();
}
