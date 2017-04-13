#include<iostream>
#include<stdio.h>
using namespace std;

char lastturn;
int TotalTime;
int ExtraTime;
int lastposo = 1;
int lastposb = 1;

void OrangeTurn(int pos)
{
    int travel = lastposo - pos;
    if( travel < 0 ){
        travel = travel * (-1);
    }
    if( lastturn == 'O' ){
        TotalTime = TotalTime + travel + 1;
        ExtraTime = ExtraTime + travel + 1;
    }
    else{
        if( ExtraTime >= travel ){
            TotalTime = TotalTime + 1;
            ExtraTime = 1;
            lastturn = 'O';
        }
        else{
            TotalTime = TotalTime + (travel - ExtraTime) + 1;
            ExtraTime = travel - ExtraTime + 1;
            lastturn = 'O';
        }
    }
    lastposo = pos;
}

void BlueTurn(int pos)
{
    int travel = lastposb - pos;
    if( travel < 0 ){
        travel = travel * (-1);
    }
    if( lastturn == 'B' ){
        TotalTime = TotalTime + travel + 1;
        ExtraTime = ExtraTime + travel + 1;
    }
    else{
        if( ExtraTime >= travel ){
            TotalTime = TotalTime + 1;
            ExtraTime = 1;
            lastturn = 'B';
        }
        else{
            TotalTime = TotalTime + (travel - ExtraTime) + 1;
            ExtraTime = travel - ExtraTime + 1;
            lastturn = 'B';
        }
    }
    lastposb = pos;
}

int main()
{
    int t,n,pos;
    char ch;
    int i,j;
    FILE *fd,*fout;
    fd = fopen("input","r");
    fout = fopen("output","w");
    fscanf(fd,"%d",&t);
    for( j=1 ; j<=t ; j++ ){
        TotalTime = 0;
        ExtraTime = 0;
        lastposo = 1;
        lastposb = 1;
        fscanf(fd,"%d",&n);
        for(i=0;i<n;i++)
        {
            fscanf(fd," %c ",&ch);
            fscanf(fd,"%d",&pos);
            if( i==0 ){
                 lastturn = ch;
             }    
             if(ch == 'O'){
                 OrangeTurn(pos);
             }
            else{
                 BlueTurn(pos);
            }
        }
        fprintf(fout,"Case #%d: %d\n",j,TotalTime);
     }
}
