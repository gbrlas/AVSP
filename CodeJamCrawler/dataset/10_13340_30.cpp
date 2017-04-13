// ****************************************************************************
// File: main.cc
// Author: Nigel Struble (ASCII)
// Date: 7/05/2010
// Purpose: 	The main() for the snapper problem
// ****************************************************************************

#include "snapper.h"
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

struct Case{
	size_t number_of_snappers;
	size_t number_of_snaps;
};

int main(int args, char *argv[]){
	size_t number_of_cases = 0;
	if (args != 2){
		cout << "wrong number of arguments" << endl;
		return 1;
	}
	ifstream ifs(argv[1]);
	if (ifs.fail()){
		cout << "cannot open file" << endl;
		return 1;
	}
	ifs >> number_of_cases;
	Case input[number_of_cases];
	//Case *input = in + sizeof(Case);
	
	for(size_t i = 0; i < number_of_cases; ++i){
		ifs >> input[i].number_of_snappers;
		ifs >> input[i].number_of_snaps;
	}
	/*for(size_t i = 0; i < number_of_cases; ++i){
		cout << "snappers = " << input[i].number_of_snappers << endl;
		cout << "snaps = " <<input[i].number_of_snaps << endl << endl;
	}*/
	for(size_t case_number = 0; case_number < number_of_cases; ++case_number){
		list<gadget*> snappers;
		snappers.push_back(new light());
		for(size_t i = 0; i < input[case_number].number_of_snappers; ++i){
			snappers.push_front(new snapper());	
		}
		snappers.push_front(new socket());
		for(size_t snap = 0; snap < input[case_number].number_of_snaps; ++snap){
			list<gadget*>::iterator p = snappers.begin();
			//for(++p; p != snappers.end(); ++p){
			bool have_power = true;
			while(p != snappers.end()){
				if(have_power){
					if(!(*p)->is_on())
						have_power = false;
					(*p)->set_power(true);
				}else{
					(*p)->set_power(false);
				}
				++p;
			}

			p = snappers.begin();
			while(p != snappers.end()){
				if((*p)->is_powered())
					(*p)->toggle();
				else
					break;
				++p;
			}
		}
		cout << "Case #" << case_number + 1 << ": ";
		//list<gadget*>::iterator p = snappers.rbegin();
		list<gadget*>::reverse_iterator pr = snappers.rbegin();
		list<gadget*>::iterator p = snappers.begin();
		bool have_power = true;
		while(p != snappers.end()){
			if(have_power){
				if(!(*p)->is_on())
					have_power = false;
				(*p)->set_power(true);
			}else{
				(*p)->set_power(false);
			}
			++p;
		}
		if((*pr)->is_powered())
			cout << "ON" << endl;
		else
			cout << "OFF" << endl;
		for(list<gadget*>::iterator p = snappers.begin(); p!=snappers.end();p = snappers.begin()){
			delete *p;
			snappers.pop_front();

		}
	
	}
}
