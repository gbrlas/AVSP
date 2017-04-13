#include<iostream>
using namespace std;
#include<string>

int main(){
int n,i,j,k,o,x,v,p;
string str[4];

cin>>n;

for(k=0;k<n;k++){

	for(j=0;j<4;j++){
		cin>>str[j];
					}
				
		x=0;
		o=0;
		v=0;
		p=0;
		for(j=0;j<4;j++){
			if(str[0+j][0+j]=='X')
			x++;
			else if(str[0+j][0+j]=='O')
			o++;
			else if(str[0+j][0+j]=='T'){
			o++;
			x++;
			}
			else 
			p++;
		}
		if(x==4) v=1;
		else if(o==4) v=1;

		if(v!=1)
		{
		x=0;
		o=0;
		for(j=0;j<4;j++){
			if(str[0+j][3-j]=='X')
			x++;
			else if(str[0+j][3-j]=='O')
			o++;
			else if(str[0+j][3-j]=='T'){
			o++;
			x++;
			}
			else 
			p++;
		}
		if(x==4) v=1;
		else if(o==4) v=1;
		}
			if(v!=1)
		{
		x=0;
		o=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
			if(str[i][0+j]=='X')
			x++;
			else if(str[i][0+j]=='O')
			o++;
			else if(str[i][0+j]=='T'){
			o++;
			x++;
			}
			else
			p++;
			}
			if(x==4||o==4) {v=1; break;}
			
			else {x=0; o=0;}
			}
		}
			if(v!=1)
		{
		x=0;
		o=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
			if(str[0+j][i]=='X')
			x++;
			else if(str[0+j][i]=='O')
			o++;
			else if(str[0+j][i]=='T'){
			o++;
			x++;
			}
			else
			p++;
			}
			if(x==4||o==4) {v=1; break;}
			
			else {x=0; o=0;}
			}
		}
		if(x==4) cout<<"Case #"<<k+1<<": X won"<<endl;
		else if(o==4)  cout<<"Case #"<<k+1<<": O won"<<endl;
		else if(p) cout<<"Case #"<<k+1<<": Game has not completed"<<endl;
		else cout<<"Case #"<<k+1<<": Draw"<<endl;
		}
		
		return 0;
		
		}
	
		
				
			
	