#include <fstream>

using namespace std;

class seng
{
public:
	char name[101];
	bool check;
};

int cases,nr,inputs;

seng lista[101];
seng q[1001];

bool areCEqual(char a[101],char b[101])
{
	int la,lb;
	la=strlen(a);
	lb=strlen(b);
	if(la==lb)
	{
		for(int i=0;i<la;i++)
		{
			if(a[i]!=b[i])
				return false;
		}
		return true;
	} else {
		return false;
	}
}

bool checkList(char name[101])
{
	for(int i=0;i<nr;i++)
	{
		if(areCEqual(lista[i].name,name))
		{
			if(lista[i].check==false)
			{
				lista[i].check=true;
				return true;
			}
		}
	}
	return false;
}

int check2()
{
	int ct=0,rez;
	for(int i=0;i<nr;i++)
	{
		if(lista[i].check==false)
		{
			ct++;
			rez=i;
		}
	}
	if(ct==1)
	{
		return rez;
	} else {
		if(ct==0)
			return -2;
		else
			return -1;
	}
}

int main()
{
	ifstream f("A-small.in");
	ofstream f2("output.out");

	f>>cases;

	char iname[101];

	int i,mrez,final=0;

	for(int ca=0;ca<cases;ca++)
	{
		f>>nr;
		f.getline(iname,1);
		for(i=0;i<nr;i++)
		{
			f.getline(lista[i].name,101);
			//f>>lista[i].name;
			lista[i].check=false;
		}
		f>>inputs;
		f.getline(iname,1);
		int evit=-1;
		bool checked;
		for(i=0;i<inputs;i++)
		{
			//f>>iname;
			f.getline(iname,101);
			
			checked=checkList(iname);
			mrez=check2();
			if(mrez>=0)
			{
				evit=mrez;
			}
			if(mrez==-2 && checked)
			{
				final++;
				for(int h=0;h<nr;h++)
					lista[h].check=false;
				lista[evit].check=true;
				for(int h=0;h<nr;h++)
					if(lista[h].check==false)
						evit=h;
			}
		}
		f2<<"Case #"<<ca+1<<": "<<final<<endl;
		final=0;
	}

	f.close();
	f2.close();
	return 0;
}