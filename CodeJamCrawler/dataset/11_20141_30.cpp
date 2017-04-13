#include "Magick.h"


Magick::Magick(){
	combines.clear();
	opposes.clear();
	elems.clear();
}

void Magick::addElem(char elem){
	bool add = true;
	list<char>::iterator elemit = elems.end();
	if ( elems.size() ==0)
	{
		elems.push_back(elem);
		return;
	}
	--elemit;
	list<Combo>::iterator comboit;
	char newelem = findCombo(*elemit,elem);
	if (elem != newelem)
	{
		*elemit = newelem;
		add = false;
	}
	for (comboit = opposes.begin(); comboit != opposes.end(); ++comboit)
	{
		for (elemit = elems.begin();elemit != elems.end();++elemit)
		{
			if (findOppose(*elemit,newelem))
			{
				elems.clear();
				return;
			}
		}
	}
	if (add)
		elems.push_back(elem);
	return;
}

char Magick::findCombo(char element1,char element2){
	char e1,e2;
	if(element1<element2)
	{
		e1=element1;
		e2=element2;
	}
	else
	{
		e1=element2;
		e2=element1;
	}
	list<Combo>::iterator lit = combines.begin();
	for (lit = combines.begin();lit != combines.end();++lit)
	{
		if(lit->elem1 == e1 && lit->elem2 == e2)
			return lit->result;
	}
	return element2;
}
bool Magick::findOppose(char element1,char element2){
	char e1,e2;
	if(element1<element2)
	{
		e1=element1;
		e2=element2;
	}
	else
	{
		e1=element2;
		e2=element1;
	}
	list<Combo>::iterator lit = opposes.begin();
	for (lit = opposes.begin();lit != opposes.end();++lit)
	{
		if(lit->elem1 == e1 && lit->elem2 == e2)
			return true;
	}
	return false;
}
string Magick::getElemList(){
	list<char>::iterator eit = elems.begin();
	string result="";
	//cout<<"["<<flush;
	result += "[";
	//print 1st
	if (elems.size() > 0)
	{
		//cout << *eit << flush;
		result += *eit;
	//print next
		while (++eit != elems.end())
		{
			//cout << ", "<< *eit<<flush;
			result += ", ";
			result += *eit;
		}
	}
	//print last
	//cout<<"]"<<flush;
	result += "]";
	return result;
}

void Magick::addCombo(char e1,char e2,char e3){
	Combo combo(e1,e2,e3);
	combines.push_back(combo);
}
void Magick::addOppose(char e1,char e2){
	Combo combo(e1,e2);
	opposes.push_back(combo);
}