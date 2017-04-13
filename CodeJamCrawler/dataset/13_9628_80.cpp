#include<stdio.h>
int main()
{
	FILE *fp=NULL,*op;
	fp=fopen("A-large.in","r");
	op=fopen("output4","w");
	int t,count=0;
	int a_count,o_count,a_num,o_num,i,j,result,t_num;
	bool flag;
	char a[4][5];
	fscanf(fp,"%d",&t);
	while(count<t){
	
		flag=false;
		for(i=0;i<4;i++)
			fscanf(fp,"%s",a[i]);

		//vertical*4
		a_num=0;
		o_num=0;
		t_num=0;
		for(i=0;i<4;i++){
			a_count=0;
			o_count=0;
			for(j=0;j<4;j++)
			{
				if(a[i][j]=='X'){
					a_count++;
					a_num++;
				}
				else if(a[i][j]=='O'){
					o_count++;
					o_num++;
				}
				else if(a[i][j]=='T')
				{
					
					a_count++;
					o_count++;
					t_num++;
				}

			}
			if(a_count==4)
			{
				flag=true;
				result=1;
				break;
			}
			else if(o_count==4)
			{
				flag=true;
				result=2;
				break;
			}
		}
			
		//horizontal
		if(!flag)
			for(j=0;j<4;j++){
				a_count=0;
				o_count=0;
				for(i=0;i<4;i++)
				{
					if(a[i][j]=='X'){
						a_count++;
					}
					else if(a[i][j]=='O'){
						o_count++;
					}
					else if(a[i][j]=='T')
					{
						a_count++;
						o_count++;
					}

				}
				if(a_count==4)
				{
					flag=true;
					result=1;
					break;
				}
				else if(o_count==4)
				{
					flag=true;				
					result=2;
					break;
				}
			}
			// '\'
			if(!flag){
				a_count=0;
				o_count=0;
				for(i=0;i<4;i++)
				{
					if(a[i][i]=='X'){
						a_count++;
					}
					else if(a[i][i]=='O'){
						o_count++;
					}
					else if(a[i][i]=='T')
					{
						a_count++;
						o_count++;
					}

				}
				if(a_count==4)
				{
					flag=true;
					result=1;
	
				}
				else if(o_count==4)
				{
					flag=true;				
					result=2;
				}
			}
			// '/'
			if(!flag){
				a_count=0;
				o_count=0;
				for(i=0;i<4;i++)
				{
					if(a[3-i][i]=='X'){
						a_count++;
					}
					else if(a[3-i][i]=='O'){
						o_count++;
					}
					else if(a[3-i][i]=='T')
					{
						a_count++;
						o_count++;
					}

				}
				if(a_count==4)
				{
					flag=true;
					result=1;
				}
				else if(o_count==4)
				{
					flag=true;				
					result=2;
				}
			}
			if(flag)
			{
				switch(result)
				{
				case 1:fprintf(op,"Case #%d: X won\n",count+1);
					break;
				case 2:fprintf(op,"Case #%d: O won\n",count+1);
					break;
				}
			}else if(a_num+o_num+t_num<16){
				fprintf(op,"Case #%d: Game has not completed\n",count+1);
			}else if(a_num+o_num+t_num==16)
			{
				fprintf(op,"Case #%d: Draw\n",count+1);
			}

		count++;
	}
	return 0;
}