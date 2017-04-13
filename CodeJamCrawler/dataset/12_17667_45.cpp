#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]){
	FILE* fileIn,*fileOut;
	int numCases=0;
	char mapping[27];
	char str[102];
	char strOut[102];

	mapping['a'-'a']='y';
	mapping['b'-'a']='h';
	mapping['c'-'a']='e';
	mapping['d'-'a']='s';
	mapping['e'-'a']='o';
	mapping['f'-'a']='c';
	mapping['g'-'a']='v';
	mapping['h'-'a']='x';
	mapping['i'-'a']='d';
	mapping['j'-'a']='u';
	mapping['k'-'a']='i';
	mapping['l'-'a']='g';
	mapping['m'-'a']='l';
	mapping['n'-'a']='b';
	mapping['o'-'a']='k';
	mapping['p'-'a']='r';
	mapping['q'-'a']='z';
	mapping['r'-'a']='t';
	mapping['s'-'a']='n';
	mapping['t'-'a']='w';
	mapping['u'-'a']='j';
	mapping['v'-'a']='p';
	mapping['w'-'a']='f';
	mapping['x'-'a']='m';
	mapping['y'-'a']='a';
	mapping['z'-'a']='q';
	
		
	//mapping['q'-'a']='z';
	

	fileIn=fopen("input.dat","r");
	fileOut=fopen("output.dat","w");
	fscanf(fileIn,"%d",&numCases);
	fscanf(fileIn,"%c",&str[0]);
	for(int i=0;i<numCases;++i){
		strOut[0]='\0';
		str[0]='\0';
		fgets(str,sizeof(str),fileIn);
		
		for(int j=0;j<strlen(str);++j){
			strOut[j]=(str[j]-'a'<0 || str[j]-'a'>26)?str[j]:mapping[str[j]-'a'];
			if(strOut[j]=='\n'){
				strOut[j]='\0';
				break;
			}
		}
		fprintf(fileOut,"Case #%d: %s\n",i+1,strOut);
	
	}

	fclose(fileIn);
	fclose(fileOut);
	return 0;
}