#include "Bot.h"


bool Bot::move( bool canpush){
	if (next<position)
	{
		moveLeft();
		return false;
	}
	else if (next > position)
	{
		moveRight();
		return false;
	}
	else if (next == position && canpush)
	{
		push();
		return true;
	}
	else
	{
		stay();
		return false;
	}
}

Bot::Bot(){
	next = 1;
	position = 1;
	whoami="";
}

void Bot::moveLeft(){
	//cout<< "    " << whoami << " move left from " << position << endl;
	--position;
}

void Bot::moveRight(){
	//cout<< "    " << whoami << " move right from " << position << endl;
	++position;
}

void Bot::stay(){
	//cout<< "    " << whoami << " stay at " << position << endl;
	return;
}

void Bot::push(){
	//cout<< "    " << whoami << " push button at " << position << endl;
	return;
}
void Bot::setname(string name){
	whoami = name;
}