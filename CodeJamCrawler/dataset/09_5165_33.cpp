/***************************************************************************
 * 
 * Copyright (c) 2009 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file a.cpp
 * @author xujing03(huanghaibin@baidu.com)
 * @date 2009/09/04 03:58:06
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int l,d,n;

string dic[5010];
bool f[5010];
bool ch[300];

int ans(string s)
{
		
	memset(f,true,sizeof(f));
	int i;
	int p=0;
	int len=s.length();
	for( i=0;i<l;i++)
	{
		memset(ch,false,sizeof(ch));
		
		if( p>=len ) 
		{
			return 0;
		}
		if( s[p]=='(')
		{
			p++;
			while ( p<len && s[p]!=')' )
			{
				if( s[p]<='z' && s[p]>='a' )
				{
					ch[s[p]]=true;
				}else
				{
					return 0;
				}
				p++;
			}
			if( p<len && s[p]==')' )
			{
				p++;
			}
		}else
		{
			if( s[p]<='z' && s[p]>='a' )
			{
				ch[s[p]]=true;
				p++;
			}else
			{
				return 0;
			}
		}
		int j;
		for( j=0;j<d;j++)
		{
			if( ! ch[dic[j][i]] )
			{
				f[j]=false;
			}
		}
	}
	
	int a=0;
	for( i=0;i<d;i++)
	{
		if( f[i] ) 
		{
			a++;
		}
	}
	return a;
}

int main()
{
	ifstream fin("in.txt");
	fin>>l>>d>>n;
	int i;
	for(i=0;i<d;i++)
	{
		fin>>dic[i];
		//cout<<dic[i]<<endl;
	}
	
	string s;
	for(i=1;i<=n;i++)
	{
		fin>>s;
		cout<<"Case #"<<i<<": "<<ans(s)<<endl;
	}
	
	fin.close();
	return 0;
}




















/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
