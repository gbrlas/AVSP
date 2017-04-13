#include <fstream>
#include <string>
#include <bitset>
using namespace std;

#define CHECKO(arg)								( (arg) == 0xaa || (arg) == 0xea || (arg) == 0xba || (arg) == 0xae || (arg) == 0xab )
#define CHECKX(arg)								( (arg) == 0x55 || (arg) == 0xd5 || (arg) == 0x75 || (arg) == 0x5d || (arg) == 0x57 )
#define BYTENUM(arg1,arg2,arg3,arg4)			( (0xc0&(arg1))|(0x30&(arg2))|(0x0c&(arg3))|(0x03&(arg4)) )
#define CREATENUM(val,arg1,arg2,arg3,arg4)		BYTENUM( ( (val)>>(arg1) ), ( (val)>>(arg2) ), ( (val)>>(arg3) ), ( (val)>>(arg4) ) )

bool check00(unsigned v)
{
	//check whether 00 exists anywhere
	for(size_t i=0;i<16;i++)
	{
		unsigned char tmp=0x03&(v>>(i*2));
		if(tmp == 0)
			return true;
	}
	return false;
}

size_t checkBroad(unsigned v)
{
	size_t f=4;
	for(size_t i=0;i<4;i++)
	{
		unsigned char tmp=v>>(i*8);
		if(CHECKO(tmp)) return 3;
		if(CHECKX(tmp)) return 0;
	}

	unsigned char tmp=CREATENUM(v,24,16,8,0);
	if(CHECKO(tmp)) return 3;
	if(CHECKX(tmp)) return 0;

	//
	for(size_t i=0;i<4;i++)
	{
		int delta=2*i;
		unsigned char tmp=CREATENUM(v,24-delta,16+2-delta,8+4-delta,0+6-delta);
		if(CHECKO(tmp)) return 3;
		if(CHECKX(tmp)) return 0;
	}

	tmp=CREATENUM(v,18,14,10,6);
	if(CHECKO(tmp)) return 3;
	if(CHECKX(tmp)) return 0;

	if(check00(v)) return 2;
	else return 1;
}

int main()
{
	fstream readfile("theIn.txt");
	fstream writefile("theOut.txt",ios::out) ;
	if(!readfile || !writefile)
		return -1;
	string status[4]={"X won\n","Draw\n","Game has not completed\n","O won\n"};
	//00	.
	//11	T
	//01	X
	//10	O
	//a board can be represented by 32bits in INT
	size_t c=0;
	readfile>>c;
	for(size_t i=0;i<c;i++)
	{
		string str;
		bitset<32> v(0);
		for(size_t j=0;j<5;j++)
		{
			string tmp;
			getline(readfile,tmp);
			str+=tmp;
		}
		for(size_t j=0;j<16;j++)
		{
			if(str[j] == 'X')
			{v[30-2*j]=1,v[31-2*j]=0;}
			else if(str[j] == 'T')
			{v[30-2*j]=1,v[31-2*j]=1;}
			else if(str[j] == 'O')
			{v[30-2*j]=0,v[31-2*j]=1;}
			else{}
		}
		size_t index=checkBroad(v.to_ulong());
		writefile<<"Case #"<<i+1<<": "<<status[index];
	}
	writefile.close();
	readfile.close();
}