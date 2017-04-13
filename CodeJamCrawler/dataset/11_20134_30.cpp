#include "Controller.h"

Controller::Controller(){
	currentstep = 1;
	red.setname("orange");
	blue.setname("blue");
}
void Controller::addAction(int bt,int bid){
	Action * a = new Action(bt,bid,currentstep++);
	addAction(a);
}
void Controller::addAction(Action* act){
	if (act->botid == 1)
	{
		reds.push_back( act );
	}
	else 
	{
		blues.push_back( act);
	}
}

int Controller::start(){
	currentstep = 1;
	ri = reds.begin();
	bi = blues.begin();
	int counter = 0;
	if(ri != reds.end()) red.next = (*ri)->button;
	if(bi != blues.end()) blue.next = (*bi)->button;
	while (ri != reds.end() || bi != blues.end()){
		if (bi != blues.end() && currentstep == (*bi)->sequence)
		{
			if(blue.move(true))
			{
				++currentstep;
				++bi;
				if(bi != blues.end()) blue.next = (*bi)->button;
			}
			if(ri != reds.end())
			{
				red.move(false);
			}
		}
		else if (ri != reds.end())
		{
			if(bi != blues.end())
			{
				blue.move(false);
			}
			if(red.move(true))
			{
				++currentstep;
				++ri;
				if(ri != reds.end()) red.next = (*ri)->button;
			}
		}
		++counter;
	}
	return counter;
}