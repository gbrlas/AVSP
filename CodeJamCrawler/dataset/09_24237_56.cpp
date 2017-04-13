#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

char st[20000];
struct Tree
{
   double num;
   int l,r;
   char name[100];
   bool b;       
}t[100000];
double ans;
int len,n;
char tz[100][100];    

int mark_tree( int l , int mark )
{
     t[mark].b=false;
     t[mark].l=0;
     t[mark].r=0;
     while( st[l]==' ' ) l++;
     t[mark].num=0;
     while( st[l]<='9'&&st[l]>='0' )
     {
          t[mark].num=t[mark].num*10+st[l]-'0';
          l++;
     }
     double q=0.1;
     if( st[l]=='.' ){
       l++;
	   while( st[l]<='9'&&st[l]>='0' )
       {
            t[mark].num=t[mark].num+(st[l]-'0')*q;
            l++;q=q*0.1;
       }
	 }
     while( st[l]==' ' ) l++;
     int k=0;
     while( st[l]>='a'&&st[l]<='z' ) t[mark].name[k++]=st[l++];
     t[mark].name[k]='\0';
     while( st[l]==' ' ) l++;
     if( st[l]==')' ) { t[mark].b=true; l++; while(st[l]==' ') l++; return( l ); }
     if( st[l]=='(' )
     {
        t[mark].l=len; 
        l=mark_tree( l+1 , len++ );
     }
     if( st[l]==')' ) {l++; while(st[l]==' ') l++;return( l );}
     if( st[l]=='(' )
     {
        t[mark].r=len; 
        l=mark_tree( l+1 , len++ );
     }
     if( st[l]==')' ) {l++; while(st[l]==' ') l++;return( l );}
}

void init()
{
    int i, n;
    char tmp[100];
    scanf( "%d", &n );gets( tmp );
    for( i = 0; i < n; i++ ){
        gets( tmp );
        if( i == 0 ) strcpy( st, tmp );
        else strcat( st, tmp );    
    }
}

void doit( int mark )
{
   int i;
   if( mark==0 ) return;
   ans*=t[mark].num;
   if( t[mark].b ) return;
   for( i=1 ; i<=n ; i++ )
    if( strcmp( tz[i] , t[mark].name )==0 )
     { doit( t[mark].l);return;}
   doit( t[mark].r );
}

void search()
{
    int Cas2,i;
    scanf("%d",&Cas2);
    while( Cas2-- )
    {
       ans=1;
       scanf("%s%d",&tz[0],&n);
       for( i=1 ; i<=n ; i++ )
        scanf("%s",&tz[i]);
       ans=1;
       doit( 1  ) ;
/*
       mark=1;
       while( 1 )
       {
          ans*=t[mark].num;
          if( t[mark].b ) break;
          int mark1=mark;
          mark=mark*2+1;
          for( i=1 ; i<=n ; i++ )
           if( strcmp( tz[i] , t[mark1].name )==0 ) 
            { mark--; break; }
          //  printf("%d\n",mark);
       }*/
       printf("%.7lf\n",ans);
    }   
}

int main()
{
    freopen( "A-small-attempt1.in", "r", stdin );
    freopen( "A-small-attempt1.out", "w", stdout );    
    int Cas=0,Cas1,i,j;
    scanf("%d",&Cas1);
    while( Cas++<Cas1 )
    {
       init();
       i=0;
       while( st[i]!='(' ) i++;
       len=2;
       mark_tree( i+1 , 1 );
       printf("Case #%d:\n",Cas);       
       search();    
    }
    return(0);
}
