/*
 * credit.cxx
 * 
 * Copyright 2014 Santiago <santiago@santiago-XPS-L412Z>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip> 
using namespace std;

int main(int argc, char **argv)
{
	ifstream file;
	file.open ("B-large.in");
	ofstream out;
	out.open("b.out");
	int cases,cas=1;
	file>>cases;
	
	
	while(cases){		
		
		long double c,x,f;
		file>>c>>f>>x;
		long double rate=2;		
		long double time=0;
		bool salir=false;		
		
		while(!salir){
			
			long double auxtime=c/rate;			
			long double time1=(x)/(rate+f);			
			long double time2=(x-c)/(rate);
						
			if(time1 <= time2){				
				rate+=f;											
			}else{				
				salir=true;
				time+=time2;				
			}
			
			
			time+=auxtime;
			
		}
		
		out<<"Case #"<<cas<<": "<<std::setprecision(9)<<time<<endl;
		
		cases--;
		cas++;
	}	
	return 0;
}

