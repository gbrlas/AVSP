//
//  main.cpp
//  google_jam
//
//  Created by Maciej Partyka on 13.04.2013.
//  Copyright (c) 2013 Maciej Partyka. All rights reserved.
//

#include<iostream>
#include <list>
#include <math.h>
void GetNumber(FILE*f,int &qty){
	char buf[20];
	std::string ff;
	int count=0;
	do{
		if(fread(buf,1,1,f)!=1)
			break;
		buf[1]='\0';
		if(strcmp(buf,"\n")==0||strcmp(buf," ")==0){
			if(ff.length()>0)
				break;
		}
		ff+=buf;
		if(++count>10){
			//echo blad
			std::cout<<"PETLA"<<std::endl;
		}
	}while(1);
	
	qty=atoi(ff.c_str());
	//std::cout<<" "<<qty<<std::endl;;
}
bool poli(int n){
	int qty=(int)log10(n)+1;
	int *tab=new int[qty];
	int orig_n=n;
	for(int i=0;i<qty;++i){
		tab[i]=floor(n/(pow(10,qty-i-1)));
		n-=tab[i]*pow(10,qty-i-1);
	//	std::cout<<tab[i];
	}
	//std::cout<<std::endl;
	int srodek=floor((1+qty)/2.0);
	int s1=0,s2=0;
	if(srodek!=qty/2.0){
		s1=qty/2;
		s2=s1+1;
		s1-=1;
	}else{
		s1=s2=srodek;
		s1-=1;
		//s2+=1;
	}
	bool jest=true;
	while(s1>=0&&s2<qty){
		if(tab[s1]!=tab[s2]){
			return false;
		}
		s1-=1;
		s2+=1;
	}
	delete []tab;
	return true;
}
bool sq(int x){
	int xx=sqrt(x);
	if(xx!=sqrt(x))
		return false;
	return poli(xx);
}
int main(int argc, const char * argv[])
{
	const char*filename="/Users/maciejpartyka/Desktop/GG/fair.in";

	FILE*f= fopen(filename,"r");
	int mmin=1,mmax=1,qty=0;
	GetNumber(f,qty);
	for(int i=0;i<qty;++i){
		GetNumber(f,mmin);
		GetNumber(f,mmax);
		int count=0;
		for(int x=mmin;x<=mmax;++x){
			if(poli(x)==true&&sq(x)==true){
				count+=1;
			}
		}
		std::cout<<"Case #"<<i+1<<": "<<count<<std::endl;
	}
	return 0;
	std::cout<<(poli(11111)?"JEST":"NIE JEST")<<std::endl;
	std::cout<<(poli(1231)?"JEST":"NIE JEST")<<std::endl;
	std::cout<<(poli(1111)?"JEST":"NIE JEST")<<std::endl;

	return 0;
}