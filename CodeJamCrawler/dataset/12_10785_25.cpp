#include<stdio.h>

char output[3100];
int j = 0;
int A,B;
int n,m;

void get_recycle(FILE *fd2) {
int digits = 0,cur_digit=0;
int temp = A;
int n_tail,m_head,n_head;
int recycle= 0;
int power = 0;
int antipower;
int t_antipower;
int error;
char tempc;
while(temp) {
digits++;
temp = temp/10;
}
temp = digits;
antipower=1;
while(temp--) {
antipower *= 10;
}
//printf("antipower = %d\n",antipower);
printf("digits = %d\n",digits);
printf("A=%d,B=%d\n",A,B);
for(n = A,error=1;n<=B;n++) {
//printf("n = %d\n",n);
for(cur_digit=1,power=10,t_antipower=antipower/10;cur_digit<digits;cur_digit++,power *= 10,t_antipower /= 10) {
n_tail = n % power;
n_head = n / power;
//printf("n_head=%d,n_tail=%d\n",n_head,n_tail);
if( n_tail >= (power/10 ))
{
m = n_tail * t_antipower + n_head;
if( ( m >= A) && ( m <=B) && (m!=n) )
{ recycle++;
//printf("recycle numbers n=%d,m=%d\n",n,m);
error++;
}

}

}
if(error>3)
printf("error num = %d\n",n);
if(error>4)
printf("error num 4 = %d\n",n);
error=1;
}
recycle=recycle/2;
printf("recycle_count = %d\n",recycle);
temp = recycle;
digits = 0;
if(!temp) digits++;
while(temp) {
digits++;
temp = temp/10;
}
temp = digits;
antipower=1;
while(temp--) {
antipower *= 10;
}
t_antipower = antipower/10;
antipower = 1;

while(antipower <= digits) {

tempc = recycle / t_antipower;
temp = tempc+48;
output[j++]=temp;
recycle = recycle % t_antipower;
t_antipower = t_antipower/10;
antipower++;
}


}
void get_num(FILE *fd1) {
char temp;
A = 0;
B = 0;
fread(&temp,1,1,fd1);
while(temp != ' ')
{
	A = A * 10 + temp-48;
	fread(&temp,1,1,fd1);
}

fread(&temp,1,1,fd1);
while(temp != '\n')
{
	B = B * 10 + temp-48;
	fread(&temp,1,1,fd1);
}
printf("A = %d B= %d\n",A,B);
}

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

FILE * fd1 = fopen(argv[1],"rw");
FILE * fd2 = fopen(argv[2],"w+");
int totalcase,cur_case = 1;	
char totalcasec;
fread(&totalcasec,1,1,fd1);
totalcase = totalcasec-48;
fread(&totalcasec,1,1,fd1);
if(totalcasec != '\n')
{
	totalcase = totalcase*10+totalcasec-48;
	fread(&totalcasec,1,1,fd1);
}
printf("total_case=%d\n",totalcase);

while(cur_case <= totalcase) 
{
	get_num(fd1);
	add_case(cur_case);
	get_recycle(fd2);	
	cur_case++;
	output[j++]='\n';
}
totalcase = 0;
printf("j= %d\n",j);
while(totalcase <= j) 
{
printf("%c",output[totalcase++]);
}
fwrite(output,1,j,fd2);
	fclose(fd1);
	fclose(fd2);
	return 0;
}
