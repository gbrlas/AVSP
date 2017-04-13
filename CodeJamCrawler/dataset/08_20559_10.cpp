#include <fstream>
#include <iomanip>

using namespace std;

int n;
double c_min=100000000;
double cx,cy,cz;
double sumX=0,sumY=0,sumZ=0;

class pos
{
public:
	int x,y,z;
	int p;
};

pos ship[1001];

double pozitiv(double A)
{
	if(A<0)
		return -A;
	else
		return A;
}

double calculate(int x,int y,int z,int P)
{
	//return ((a + b + c) / P);
	return 0;
}

double calculateMax()
{
	double valmax=0,temp;
	for(int i=0;i<n;i++)
	{
		double a,b,c;
		a=cx-ship[i].x;
		b=cy-ship[i].y;
		c=cz-ship[i].z;
		if(a<0) a=-a;
		if(b<0) b=-b;
		if(c<0) c=-c;
		temp=((a + b + c) / ship[i].p);
		if(temp>valmax)
		{
			valmax=temp;
		}
	}
	return valmax;
	//return 0;
}

double error=1;
double m_error=0.0000001;

bool get_better()
{
	bool found=false;
	bool dx=false,dy=false,dz=false;
	bool gx=false,gy=false,gz=false;
while(error>m_error)
{
	found=false;
	//+X
	cx+=error;
	double cu=calculateMax();
	if(cu<c_min)
	{
		found=true;
		c_min=cu;
		//get_better();
		dx=true;
	}
	else
		cx-=error;

	//-X
	if(!dx)
	{
	cx-=error;
	cu=calculateMax();
	if(cu<c_min)
	{
		found=true;
		c_min=cu;
		//get_better();
	}
	else
		cx+=error;
	} else
	{
		dx=false;
	}

	//+Z
	cz+=error;
	cu=calculateMax();
	if(cu<c_min)
	{
		found=true;
		c_min=cu;
		//get_better();
		dz=true;
	}
	else
		cz-=error;

	//-Z
	if(!dz){
	cz-=error;
	cu=calculateMax();
	if(cu<c_min)
	{
		found=true;
		c_min=cu;
		//get_better();
	}
	else
		cz+=error;
	} else {
		dz=false;
	}

	//+Y
	cy+=error;
	cu=calculateMax();
	if(cu<c_min)
	{
		found=true;
		c_min=cu;
		//get_better();
		dy=true;
	}
	else
		cy-=error;

	//-Y
	if(!dy){
	cy-=error;
	cu=calculateMax();
	if(cu<c_min)
	{
		found=true;
		c_min=cu;
		//get_better();
	}
	else
		cy+=error;
	} else {
		dy=false;
	}

	if(!found)
	{
		error/=10;
	}

}

	

	return true;
}

int main()
{
	ifstream f("input.in");
	ofstream f2("output.out");

	sumY=0;sumX=0;sumZ=0;
	int T;

	f>>T;

	f2.setf(ios::fixed, ios::floatfield);
	f2.precision(6);

	for(int X=0;X<T;X++)
	{
		f>>n;
		for(int i=0;i<n;i++)
		{
			f>>ship[i].x>>ship[i].y>>ship[i].z>>ship[i].p;
			sumX+=ship[i].x;
			sumY+=ship[i].y;
			sumZ+=ship[i].z;
		}
		error=0.1;
		cx=sumX/n;
		cy=sumY/n;
		cz=sumZ/n;
		if(n>1)
		{
		c_min=calculateMax();
		get_better();
		} else {
			c_min=0;
		}
		f2<<"Case #"<<X+1<<": "<<c_min<<endl;
	}

	f.close();
	f2.close();
	return 0;
}