#include<iostream.h>
#include<conio.h>
#include<fstream.h>



Q_shift(int grps_on_ride,int no_grps,int arr[])
{
int arr1[12];
int no=no_grps-1;
for(int i=grps_on_ride;i<no_grps;i++)
{
	arr1[i-grps_on_ride]=arr[i];
}

for(i=(grps_on_ride-1);i>=0;i--,no--)
{
arr1[no]=arr[i];
}

for(i=0;i<no_grps;i++)
	arr[i]=arr1[i];


}


int calcGrpPossible(int no_grps,int arr[],int max_ride)
{
//cout<<" "<<no_grps<<" "<<max_ride;
int poss_grps=0;
int ride_left=max_ride;
int flag;
int i=0;
do
{       flag=0;
	if(arr[i]<=ride_left)
		{	ride_left=(ride_left-arr[i]);
			poss_grps=poss_grps+1;
			flag=1;
		}
	i++;// cout<<"\t "<<poss_grps;
}while((flag==1)&&(i<no_grps));

cout<<poss_grps;
return poss_grps;
}


main()
{
clrscr();
fstream f1,f2;
f1.open("inp.in",ios::in);
f2.open("outp.out",ios::out);

int num;
f1>>num;
unsigned long money;
int no_poss;
int no_grps;
int max_ride;
int arr[12];

for(int h=0;h<num;h++)
{
money=0;
no_poss=0;
no_grps=0;
max_ride=0;
int no_of_times;

f1>>no_of_times;
f1>>max_ride;
f1>>no_grps;

//cout<<" "<<no_of_times<<" "<<max_ride<<" "<<no_grps<<" money"<<money;


for(int f=0;f<no_grps;f++)
	f1>>arr[f];
for(f=0;f<no_grps;f++)
	cout<<arr[f];

//beginning of coster loop
for(int c=0;c<no_of_times;c++)
{


no_poss=calcGrpPossible (no_grps,arr,max_ride);
//cout<<"\n\n\t"<<money;

for(int m=0;m<no_poss;m++)
	money=money+arr[m];

//cout<<"\t"<<money;
//cout<<"\t"<<no_poss;
Q_shift(no_poss,no_grps,arr);


//cout<<"\n";
/*for(int k=0;k<no_grps;k++)
	cout<<" "<<arr[k];
getch();
*/
}

f2<<"\nCase #"<<h+1<<": "<<money;

}

f1.close();
f2.close();
}