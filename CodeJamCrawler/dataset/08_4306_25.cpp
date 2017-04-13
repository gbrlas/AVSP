#include<iostream>
#include<vector>
#include<fstream>
#include<cstdio>

using namespace std;


struct Time {
	int sttime;
	int ettime;
};


bool cmp( Time a, Time b )
{
	return a.sttime < b.sttime;
	
};			

int main()
{

//FILE * fin = fopen("data.in","r");
FILE * fin = fopen("B-small-attempt1.in","r");
ofstream cout("data.out");

int notc;
fscanf( fin , "%d", &notc );

int counta=0, countb=0;

for( int z=1;z<=notc; z++ ){
	

	int t=0;
	int na=0, nb=0;
	int i=0, t1=0, t2=0, t3=0, t4=0;
	Time tm;

	fscanf( fin, "%d",&t);
	fscanf( fin, "%d %d",&na,&nb ); 

	vector<Time> atob ;
	vector<Time> btoa;
	

	for( i=0; i<na; i++ ) {
		
		fscanf( fin, "%d:%d %d:%d",&t1,&t2,&t3,&t4); 
		tm.sttime = 60*t1 + t2;
		tm.ettime = 60*t3 + t4;
		atob.push_back(tm);
	}

	
	for( i=0; i<nb; i++ ) {
		
		fscanf(fin, "%d:%d %d:%d",&t1,&t2,&t3,&t4); 
		tm.sttime = 60*t1 + t2;
		tm.ettime = 60*t3 + t4;
		btoa.push_back(tm);
	}
/*
	if( na == 0 )
 	{
		counta=0 ; countb = btoa.size();
		 goto enda;
	 }
	else if( nb == 0 )
	{
		counta= atob.size(); 
		countb=0; 
		goto enda;
	 }

	cout<<"\n\n";
	for( int o2=0; o2 < atob.size(); o2++ )
  	 cout<<"\n"<<atob[o2].sttime<<" "<<atob[o2].ettime;
	cout<<"\n\n";
	for( int o2=0; o2 < btoa.size(); o2++ )
  	 cout<<"\n"<<btoa[o2].sttime<<" "<<btoa[o2].ettime;
*/
	
	sort( atob.begin(), atob.end(),  cmp );
	sort( btoa.begin(), btoa.end(),  cmp );
/*

	cout<<"\n\n";
	for( int o2=0; o2 < atob.size(); o2++ )
  	 cout<<"\n"<<atob[o2].sttime<<" "<<atob[o2].ettime;

	cout<<"\n\n";
	for( int o2=0; o2 < btoa.size(); o2++ )
  	 cout<<"\n"<<btoa[o2].sttime<<" "<<btoa[o2].ettime;
	cout<<"\n\n Size : "<<atob.size()<<" "<<btoa.size()<<"\n";


//	cout<<"data : "<<atob.begin()->sttime;
*/
	int turn =0 , avbat=0;	
	counta=0 , countb=0;
	i=0;

	while( atob.size() > 0 && btoa.size() > 0 ) {	
//	  cout<<"\nEntered outside";	
	   if( atob[0].sttime <= btoa[0].sttime ) {
 		 avbat = atob[0].ettime + t;
		 turn = 2;
		 counta++;
		 atob.erase(atob.begin());
		}
		else 
		{
		 avbat = btoa[0].ettime + t;
		 turn = 1;
		 countb++;
		 btoa.erase(btoa.begin());
		}
		
	   while(1) {
//		cout<<"\n Entered inside ";
		vector<Time> :: iterator starta = atob.begin();
		vector<Time> :: iterator startb = btoa.begin();
		if( turn == 2 ) {
			if( avbat > btoa[btoa.size()-1].sttime || btoa.size() == 0 ) break;
			 else {
			 for( i=0; i < btoa.size(); i++ )
			 if( btoa[i].sttime >= avbat ) {
			  avbat = btoa[i].ettime + t;
			  btoa.erase(startb+i);
			  turn = 1;	
			  break;
			 }		  
	  		}
		}
		else if( turn == 1 ) {
			if( avbat > atob[atob.size()-1].sttime || atob.size() == 0 ) break;
			for( i=0; i< atob.size(); i++ ) 
			if( atob[i].sttime >= avbat ) {
			  avbat = atob[i].ettime + t;
			  atob.erase(starta +i);
			  turn = 2;
			  break;
			}		
		}
	}	
	 
/*	  
	cout<<"\n\n";
	for( int o2=0; o2 < atob.size(); o2++ )
  	 cout<<"\n"<<atob[o2].sttime<<" "<<atob[o2].ettime;

	cout<<"\n\n";
	for( int o2=0; o2 < btoa.size(); o2++ )
  	 cout<<"\n"<<btoa[o2].sttime<<" "<<btoa[o2].ettime;
	cout<<"\n\n Size : "<<atob.size()<<" "<<btoa.size()<<"\n";
	
cout<<"\nCount a : "<<counta<<"  b "<<countb;
*/
	}	

	counta+= atob.size();
	countb+= btoa.size();
 
cout<<"Case #"<<z<<": "<<counta<<" "<<countb<<"\n";
}


return 0;
}
