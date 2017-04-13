// #include<stdio.h>
// #include<iostream>
// #include<string>
// #include <math.h>
// using namespace std;
// 
// struct point{
// 	float x,y;
// }p[2002], pp[500001];
// 
// point inters(float k1, float b1, float k2, float b2){
// 
// 	point a;
// 	a.x = (b2-b1)/(k1-k2);
// 	a.y = k1*a.x + b1;
// 	return a;
// }
// 
// int main(){
// 
// 	 	freopen("D:\\My Documents\\Downloads\\A-large.in", "r", stdin);
// 	 	freopen("D:\\My Documents\\Downloads\\out.txt", "w", stdout);
// 	int num=0;
// 	int t,index,i,j,n;
// 
// 	float k[1001];
// 	float b[1001]; // y=kx+b
// 	memset(b, 0, sizeof(b));
// 	cin>>t;
// 
// 	for (index=0;index<t;index++)
// 	{
// 		num=0;
// 		cin>>n;
// 		for (i=0;i<n;i++)
// 		{
// 			point t1, t2;
// 			t1.x = 0;
// 			t2.x = 1;
// 			cin>>t1.y>>t2.y;
// 			p[2*i] = t1, p[2*i+1] = t2;	
// 			k[i] = (t1.y - t2.y)/ (t1.x - t2.x);			
// 			b[i] = (float)(t1.y - k[i] * t1.x);	
// 			//cout<<t1.y<<"::"<<t2.y<<k[i]<<"x+"<<b[i]<<endl;	
// 
// 		}
// 		for (i=0;i<n-1;i++)
// 			for (j=i+1;j<n;j++)
// 			{
// 				if (k[i] != k[j])
// 				{
// 					point tmp = inters(k[i],b[i],k[j],b[j]);
// 					if (tmp.x>=0 && tmp.x<=1)
// 					{
// 						num++;
// 						//cout<<tmp.x<<"in:"<<k[i]<<"x+"<<b[i]<<"::"<<k[j]<<"x+"<<b[j]<<endl;
// 					}			
// 					//else cout<<tmp.x<<" not in:"<<k[i]<<"x+"<<b[i]<<"::"<<k[j]<<"x+"<<b[j]<<endl;
// 				}
// 				//else cout<<"not in:"<<k[i]<<"x+"<<b[i]<<"::"<<k[j]<<"x+"<<b[j]<<endl;
// 			}
// 
// 		cout<<"Case #"<<index+1<<": "<<num<<endl;
// 		
// 	}
// 
// 
// }