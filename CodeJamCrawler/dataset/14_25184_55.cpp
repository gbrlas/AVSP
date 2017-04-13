#include<iostream>
#include<fstream>

using namespace std;
int magic(int array[16],int array1[16],int r1,int r2);
int value;
main()
{
	fstream fin1,fin2;		//opening file
	fin1.open("A-small-attempt0.in",ios::in);
	fin2.open("out.txt",ios::out);
int testc;
int r1,r2,t1;
int n1,n2,n3,n4;
int array[16],array1[16];
	fin1>>testc;
	int k=1,flag;
	for(k;k<=testc;k++)
	{
		fin1>>r1;
		int i=0;
		int j=0;
		for(i;i<=3;i++)
		{
			fin1>>n1>>n2>>n3>>n4;
			array[j]=n1;
			array[j+1]=n2;
			array[j+2]=n3;
			array[j+3]=n4;
			j=j+4;
		}
		fin1>>r2;
		j=0;
		for(i=0;i<=3;i++)
		{
			fin1>>n1>>n2>>n3>>n4;
			array1[j]=n1;
			array1[j+1]=n2;
			array1[j+2]=n3;
			array1[j+3]=n4;
			j=j+4;
		}
	flag=magic(array,array1,r1,r2);
	if(flag==0)
	fin2<<"Case #"<<k<<": Volunteer cheated!"<<"\n";
	else if(flag==1)
	fin2<<"Case #"<<k<<": "<<value<<"\n";
	else
	fin2<<"Case #"<<k<<": Bad magician!"<<"\n";
		
	}
	fin1.close();
	fin2.close();
return 0;	
}

int magic(int array[16],int array1[16],int r1,int r2)
{
int i=0,j=0,m=0,ele=0;
r1=r1-1;
r2=r2-1;
int det[]={0,0,0,0};
	for(i;i<=3;i++)
	{
		
		for(j=0;j<=3;j++)
		{
			if(array[(4*r1)+m]==array1[(4*r2)+j])
			{
			det[ele]=array[(4*r1)+m];
			ele=ele+1;
			}
		}
	m++; 
	}
int flag=0;
	for(i=0;i<=3;i++)
	{
		if(det[i]!=0)
		flag++;
		else
		continue;
	}
value=det[0];
return flag;
}
