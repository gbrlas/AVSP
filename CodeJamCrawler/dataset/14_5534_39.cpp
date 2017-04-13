#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

# define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;
void get(FILE *,FILE *);
void s_sort(double* array);


int main(){
    FILE *nm,*out;
    //D-small-attempt0
    nm=fopen("D-small-attempt1.in","r+");
    out=fopen("output.out","w+");

    int num=0;

    fscanf(nm,"%d",&num);

    for(int i=1;i<=num;i++){
            fprintf(out,"Case #%d: ",i);
            printf("Case #%d: ",i);
    get(nm,out);


    }


    return 0;
}
int a=1;

double reaction(double told,double  left[]);
double find_min_num(double num,double list[]);
void lower_B(double list_a[],double list_b[],int & war_d,int i);
void upper_B(double list_a[],double list_b[],int & war_d,int i);
int get_min_position(double list[]){
    s_sort(list);
    for(int i=0;i<a;i++)
        if(list[i]>0)
        return i;
    return a-1;
}
void get(FILE * nm,FILE *out)
{

    fscanf(nm,"%d",&a);
    double list_a[a],list_b[a],copy_b[a];


    for(int i=0;i<a;i++){
        fscanf(nm,"%lf",&list_a[i]);

    }
    for(int i=0;i<a;i++){
        fscanf(nm,"%lf",&list_b[i]);
        copy_b[i]=list_b[i];
    }

    int war=0,war_d=a;

    s_sort(list_a);
    s_sort(list_b);

    for(int i=a-1;i>=0;i--){
            double a1,a2;
    a1=list_a[i];
    a2=reaction(list_a[i],copy_b);
        if(a1>a2)
            war++;
    }

    for(int i=0;i<a;i++){
        s_sort(list_b);
        if(list_a[i]<list_b[get_min_position(list_b)]||(list_a[a-1]<list_b[a-1])){
               lower_B(list_a,list_b,war_d,i);
        }
        else{
                upper_B(list_a,list_b,war_d,i);
        }


    }

    fprintf(out,"%d %d\n",war_d,war);
    printf("%d %d\n",war_d,war);
}
void lower_B(double list_a[],double list_b[],int & war_d,int i){

          double a1,a2;
          a1=list_a[i];
          a2=reaction((list_b[a-1]+MAX(list_b[a-2],find_min_num(list_b[a-1],list_a)))/2,list_b);
          list_a[i]=0;
          //cout<<a1<<" a "<<a2<<"  "<<""<<endl;
        if(a1<a2)
        war_d--;
}

void upper_B(double list_a[],double list_b[],int & war_d,int i){

          double a1,a2;
          a1=list_a[i];
          a2=reaction(list_b[a-1]+1,list_b);
          list_a[i]=0;
          //cout<<a1<<" a "<<a2<<"  "<<""<<endl;
        if(a1<a2)
        war_d--;
}
double find_min_num(double num,double list[]){
    for(int i=a-1;i>=0;i--)
    if(list[i]<num)
    return list[i];

        return 0;
}



double reaction(double told,double  left[]){
    s_sort(left);

    for(int i=0;i<a;i++){

        if(left[i]>told){
            double temp=left[i];
            left[i]=0;
            s_sort(left);
            return temp;
        }
    }
    double temp=left[get_min_position(left)];
    left[get_min_position(left)]=0;
    s_sort(left);
    return temp;
}

void swap(double*x,double*y)
{
    double a;
    a=*x;
    *x=*y;
    *y=a;
}

void s_sort(double* array)
{
    int array_size=a;
    int a,b,min_position;
    double min;
    for(a=0;a<array_size;a++)
    {
        for(b=a;b<array_size;b++)
        {
            if(b==a)
            {
                min=array[b];
                min_position=b;
            }
            else
            if(array[b]<min)
            {
                min=array[b];
                min_position=b;
            }
        }
        swap(array+a,array+min_position);

    }
}
