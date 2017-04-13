#include<stdio.h>

char output[3100];
int j = 0;
void add_case(int cur_line) {
int tens;
output[j++] = 'C';
output[j++] = 'a';
output[j++] = 's';
output[j++] = 'e';
output[j++] = ' ';
output[j++] = '#';
if(cur_line<=9)
output[j++] = 48+cur_line;
else
{
tens = cur_line/10;
output[j++]=48+tens;
cur_line=cur_line%10;
output[j++]= 48+cur_line;
}
output[j++] = ':';
output[j++] = ' ';
}

int main(int argc, char * argv[]) {

char english[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z',
't','n','w','j','p','f','m','a','q'};


FILE * fd1 = fopen(argv[1],"rw");
FILE * fd2 = fopen(argv[2],"w+");
char temp;

int size=0,i;
int count = 0;
char test = 'c';
int cur_line = 1;
int tot_line = 0;
char tot_linec;
fread(&tot_linec,1,1,fd1);
tot_line = tot_linec-48;
fread(&tot_linec,1,1,fd1);
if(tot_linec != '\n') 
{
	tot_line = tot_line*10+tot_linec-48;
	fread(&tot_linec,1,1,fd1);
}
printf("total lines %d\n",tot_line);
add_case(cur_line);
count += 10;
while(size = fread(&temp,1,1,fd1) ) 
{      // printf("%c %d \n",temp,size);
	if(temp == '\n' && (cur_line < tot_line))
	{
		cur_line++;
		output[j++]=temp;
		add_case(cur_line);
		count +=10;
	}
	else if( temp < 97 || temp > 122 )
	{
		output[j++] = temp ;
		//fwrite(&temp,1,1,fd2);
		count++;
	}
	else 
	{
		i = temp - 97;
		output[j++] = english[i];
		//fwrite(&english[i],1,1,fd2);
		count++;
	}
}
output[j++] = 12;
	j = 0;
	while(output[j] != 12) {
	printf("%c",output[j++]);
	}
	fwrite(output,1,j,fd2);
//	fwrite(&test,1,1,fd2);
	fclose(fd1);
	fclose(fd2);
	return 0;
}
