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
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

int main(int argc, char **argv)
{
	ifstream file;
	file.open ("A-small-attempt0.in");
	ofstream out;
	out.open("a.out");
	int cases,cas=1;
	file>>cases;
	while(cases){
		int ans1,ans2;
		file>>ans1;
		set<int> arr1,arr2;
		for(unsigned int i=1;i<=4;i++){
			int card;			
			for(int j=0;j<4;j++){
				file>>card;
				if(i==ans1){
					arr1.insert(card);
				}
			}
		}
	

		file>>ans2;
		for(unsigned int i=1;i<=4;i++){
			int card;			
			for(int j=0;j<4;j++){
				file>>card;
				if(i==ans2){
					arr2.insert(card);
				}
			}
		}		
		
		set<int> intersect;
		
		std::set_intersection( arr1.begin(), arr1.end(), arr2.begin(), arr2.end(),std::insert_iterator< std::set<int> >( intersect, intersect.begin() ) );
		

		out<<"Case #"<<cas<<": ";
		
		switch(intersect.size()){
			case 0:
				out<<"Volunteer cheated!";
				break;
			case 1:
				out<<(*intersect.begin());
				break;
			default:
				out<<"Bad magician!";
				break;
			
		}
		out<<endl;
		
		cases--;
		cas++;
	}
	
	return 0;
}
