//
//  main.cpp
//  google_jam
//
//  Created by Maciej Partyka on 13.04.2013.
//  Copyright (c) 2013 Maciej Partyka. All rights reserved.
//

#include<iostream>

#define TDOT 1
#define TX 2
#define TO 3
#define TT 4
#define TDRAW 5
#define TXWIN 6
#define TYWIN 7
#define TNOTCOMPLETED 8
int CheckGame(FILE* f);
int main(int argc, const char * argv[])
{
	const char*filename="/Users/maciejpartyka/Desktop/GG/input.in";
	FILE*f= fopen(filename,"r");
	int qty=0;
	char buf[20];
	std::string ff;
	do{
		fread(buf,1,1,f);
		if(strcmp(buf,"\n")==0){
			break;
		}
		ff+=buf;
	}while(1);
	
	qty=atoi(ff.c_str());
	//std::cout<<qty;
	for(int i=1;i<=qty;++i){
		char buf[256];
		switch(CheckGame(f)){
			case TX:
				sprintf(buf,"Case #%d: X won",i);
				break;
			case TO:
				sprintf(buf,"Case #%d: O won",i);
				break;
			case TDRAW:
				sprintf(buf,"Case #%d: Draw",i);
				break;
			case TNOTCOMPLETED:
				sprintf(buf,"Case #%d: Game has not completed",i);
				break;
		}
		std::cout<<buf<<std::endl;
	}
    return 0;
}


int CheckGame(FILE* f){
	int tab[16];//row-prime
	int cx=0,co=0,cdot=0,ct=0;;
	int gc=0;
	int signs[]={TX,TO,TT};
	for(int i=0;i<16;++i){
		char buf[256];
		fread(buf,1,1,f);
		buf[1]='\0';
		if(strcmp(buf,".")==0){
			tab[i]=TDOT;
			++cdot;
		}else if(strcmp(buf,"X")==0){
			tab[i]=TX;
			++cx;
		}else if(strcmp(buf,"O")==0){
			tab[i]=TO;
			++co;
		}else if(strcmp(buf,"T")==0){
			tab[i]=TT;

			++ct;
			continue;
		}else{
			--i;
		}
	}
	char rzut[]={'+','.','X','O','T'};
	for(int i=0;i<4;++i){
		for(int x=0;x<4;++x){
	//		std::cout<<rzut[tab[x+i*4]];
		}
	//	std::cout<<"\n";
	}
	bool win[]={1,0,0,0,
				0,1,0,0,
				0,0,1,0,
				0,0,0,1};
	
	bool win_win[]={0,0,0,1,
					0,0,1,0,
					0,1,0,0,
					1,0,0,0};
	bool *po_skosie[2]={win,win_win};
	for(int sign=0;sign<3;++sign){
		int count=0;
		int s=signs[sign];
		//po skosie
		for(int w=0;w<2;++w){
			bool *win=po_skosie[w];
			count=0;
			for(int i=0;i<16;++i){
				//po win
				if(win[i]==0)
					continue;
				if((s==tab[i]||tab[i]==TT)){
					++count;
				}else
					break;
			}
			if(count==4){
				//WIN 'S'
				return s;
			}
		}
		//wzdluz osi
		for(int x=0;x<4;++x){
			count=0;
			for(int y=0;y<4;++y){
				if((s==tab[x+y*4]||tab[x+y*4]==TT)){
					++count;
				}else
					break;
			}
			if(count==4){
				//WIN 'S'
				return s;
			}
		}
		
		
		//wzdluz osi
		for(int y=0;y<4;++y){
			count=0;
			for(int x=0;x<4;++x){
				if((s==tab[x+y*4]||tab[x+y*4]==TT)){
					++count;
				}else
					break;
			}
			
			if(count==4){
				//WIN 'S'
				return s;
			}
		}
		
		
	}
	if(cdot==0)
		return TDRAW;
	//wzdluz osi
	return TNOTCOMPLETED;
}