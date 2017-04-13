
#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<vector>
using namespace std;


#define Len 52


class BitInt
{
public:
	string s;
public:
	BitInt(){}
	BitInt(string st):s(st){}
	BitInt(int * arr);
	friend ostream & operator<<(ostream & os,const BitInt & t);
	BitInt operator-(const BitInt & t)const;
	BitInt operator+(const BitInt & t)const;
	friend BitInt operator*(int n,BitInt & t);
	BitInt operator*(int n)const;
	BitInt operator/(int n)const;
	bool operator<(const BitInt & t)const;
};

BitInt::BitInt(int * arr)
{
	int j=Len-1;
	while( j>=0 && arr[j]==0 )
		j--;
	s.clear();
	if(j==-1)
	{
		s[0]='0';
		return;
	}
	s.resize(j+1);
    for(int i=j;i>=0;i--)
		s[j-i]=arr[i]+'0';
}

BitInt BitInt::operator+(const BitInt & t)const
{
	int *add=new int[Len];
	for(int i=0;i<Len;i++)
		add[i]=0;
	int *data1=new int[Len];
	int *data2=new int[Len];
	for(int i=0;i<Len;i++)
	{
		data1[i]=0;
		data2[i]=0;
	}
	int m1=(*this).s.size();
	int m2=t.s.size();
	for(int i=(m1-1);i>=0;i--)
	{
		data1[m1-1-i]=(*this).s[i]-'0';
	}
	for(int i=(m2-1);i>=0;i--)
	{
		data2[m2-1-i]=t.s[i]-'0';
	}
	for(int i=0;i<Len;i++)
	{
		add[i]=data1[i]+data2[i];
	}
	int j=Len-1;
	while(add[j]==0)
	{
		j--;
	}
    for (int i=0;i<=j;i++)
    {
        if(add[i]>9)
		{
            int temp=add[i]/10;
			add[i]%=10;
			add[i+1]+=temp;
 		}
    }
	BitInt b(add);
	delete []data2;
	delete []data1;
	delete []add;
	return b;
     
}

bool BitInt::operator<(const BitInt & t)const
{
    if((*this).s.size()<t.s.size())
		return true;
	if((*this).s.size()==t.s.size() && (*this).s<t.s)
		    return true;
	return false;
}

BitInt operator*(int n,BitInt & t)
{
    return t*n;
}

BitInt BitInt::operator *(int n)const
{
	if(n==2)
	{
		int *arr=new int[Len];
        for(int i=0;i<Len;i++)
		    arr[i]=0;
		int m1=(*this).s.size();
	    for(int i=(m1-1);i>=0;i--)
	    {
		    arr[m1-1-i]=(*this).s[i]-'0';
	    }

		int *result=new int[Len];
		for(int i=0;i<Len;i++)
			result[i]=0;
		for(int i=0;i<Len;i++)
		{
			result[i]=arr[i]*2;
	     }
		int j=Len-1;
	    while(result[j]==0)
	    {
		    j--;
	    }
        for (int i=0;i<=j;i++)
        {
            if(result[i]>9)
		    {
                 int temp=result[i]/10;
			     result[i]%=10;
			      result[i+1]+=temp;
 	      	 }  
		}
		BitInt b(result);
		delete []arr;
		delete []result;
		return b;
	}
}

BitInt BitInt::operator/(int n)const
{
    if(n==2)
	{
		int *arr=new int[Len];
        for(int i=0;i<Len;i++)
		    arr[i]=0;
		int m1=(*this).s.size();
	    for(int i=(m1-1);i>=0;i--)
	    {
		    arr[m1-1-i]=(*this).s[i]-'0';
	    }

		int *result=new int[Len];
		for(int i=0;i<Len;i++)
			result[i]=0;
		int k=Len-1;
		while(arr[k]==0)
			k--;
		int temp=arr[k];
		for(;k>=0;k--)
		{
			result[k]=temp/2;
            if(k==0)
				break;
			else
			{
				temp=(temp-(temp/2)*2)*10+arr[k-1];
			}
	    }
		int j=Len-1;
	    while(result[j]==0)
	    {
		    j--;
	    }
        
		BitInt b;
		b.s.resize(j+1);
		for(int r=j;r>=0;r--)
			b.s[j-r]=result[r]+'0';
		delete []arr;
		delete []result;
		return b;
	}
}

BitInt BitInt::operator -(const BitInt & t)const
{
	int *sub=new int[Len];
	for(int i=0;i<Len;i++)
		sub[i]=0;
	if((*this).s.size()<t.s.size())
		return t-(*this);
	if((*this).s.size()==t.s.size() && (*this).s<t.s)
		    return t-(*this);
	int *data1=new int[Len];
	int *data2=new int[Len];
	for(int i=0;i<Len;i++)
	{
		data1[i]=0;
		data2[i]=0;
	}
	int m1=(*this).s.size();
	int m2=t.s.size();
	for(int i=(m1-1);i>=0;i--)
	{
		data1[m1-1-i]=(*this).s[i]-'0';
	}
	for(int i=(m2-1);i>=0;i--)
	{
		data2[m2-1-i]=t.s[i]-'0';
	}
	int carry=0;
	for(int i=0;i<m1;i++)
	{
		if((data1[i]-carry)>=data2[i])
		{
		    sub[i]=data1[i]-carry-data2[i];
			carry=0;
		}
		else
		{
			sub[i]=(data1[i]-carry+10)-data2[i];
			carry=1;
		}
	}
	BitInt b(sub);
	delete []data2;
	delete []data1;
	delete []sub;
	return b;
}

ostream & operator<<(ostream & os,const BitInt & t)
{
	os<<t.s;
	return os;
}


vector<BitInt> ivec;

BitInt gcd(BitInt x,BitInt y)
{
	if(x<y)
		return gcd(y,x);
	bool flag=false;
	int size1=x.s.size();
	int size2=y.s.size();
	for(int i=y.s.size()-1;i>=0;i--)
	{
		if(y.s[i]!=0)
		{
			flag=true;
			break;
		}
	}
	if(!flag)
		return x;
	
	else
	{
		if((x.s[size1-1]-'0')%2==0)
		{
			if((y.s[size2-1]-'0')%2==0)
				return  gcd(x/2,y/2)*2;
			else
				return gcd(x/2,y);
		}
		else
		{
            if((y.s[size2-1]-'0')%2==0)
				return  gcd(x,y/2);
			else
				return gcd(y,x-y);
		}
	}
}

BitInt Gcd(vector<BitInt> & ivec,vector<BitInt>::size_type  length)
{
	if(length==2)
		return ivec[1]-ivec[0];
	return gcd(ivec[length-1]-ivec[length-2],Gcd(ivec,length-1));
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fin("B-small-attempt1.in");
	ofstream fout("B-small-attempt1.out");
	int C,N;
	fin>>C;
	for(int i=0;i<C;i++)
	{
		fin>>N;
		ivec.clear();
		for(int j=0;j<N;j++)
		{
			BitInt bit1;
	        string st1;
	        fin>>st1;
	        bit1=st1;
			ivec.push_back(bit1);
		}
		vector<BitInt>::size_type length=ivec.size();
		BitInt div=Gcd(ivec,length);
		int t=1;
		BitInt temp=div;
		while(div<ivec[0])
		{
			div=div+temp;
		}
		BitInt residual=div-ivec[0];
		if(residual.s.size()==0)
		{
			 fout<<"Case #"<<(i+1)<<": "<<0<<endl;
			 continue;
		}
		fout<<"Case #"<<(i+1)<<": "<<residual<<endl;
	}
	return 0;
}

