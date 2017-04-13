#include<stdio.h>
#include<string.h>
#include<memory.h>

/*******************



********************/

#define LMAX 15
#define DMAX 5000
#define NMAX 500
#define AMAX 26

char dict[DMAX][LMAX+1]={0};
char list[LMAX][AMAX+1]={0};
char result_str[LMAX+1]={0};
FILE *fp;

int make_dir(int, int);
int make_list(int);
int insert_list(int);
int cmp(int,int,int,int);

int main()
{
	int L,D,N;
	int result;
	int nCycle=0;
	char tmp;

	fp = fopen("A-small-attempt3.in","r");

	fscanf(fp,"%d%d%d",&L,&D,&N);

	make_dir(L,D);

	while(N--)
	{
		nCycle++;
		memset(list,0,sizeof(list));
		memset(result_str,0,sizeof(result_str));
		fscanf(fp,"%c",&tmp);
		result = make_list(L);
		if(result != L)
		{
			result = 0;
		}
		else
		{
			result = cmp(L,D,0,0);
		}

		printf("Case #%d: %d\n",nCycle,result);
	}


	return 0;
}

int make_dir(int L, int D)
{
	int i;

	for(i=0;i<D;i++)
	{
		fscanf(fp,"%s",dict[i]);
	}

	return 0;
}

int make_list(int L)
{
	int idx;
	char input;

	for(idx=0;idx<L;idx++)
	{
		fscanf(fp,"%c",&input);
		if(input != '\n' || input != '\0')
		{
			if(input == '(')
			{
				insert_list(idx);
			}
			else
			{
				list[idx][0]=input;
			}
		}
		else
		{
			break;
		}
	}
	return idx;
}

int insert_list(int idx)
{
	char input;
	int i=0;
	while(fscanf(fp,"%c",&input)==1)
	{
		if(input==')')
			return 0;
		list[idx][i]=input;
		i++;
	}
}
int cmp(int L,int D,int idx,int iDict)
{
	int i,j;
	int dirLen;
	int result=0;
	int last_result;
	if(L==idx)
	{
		for(i=0;i<D;i++)
		{
			if(strncmp(result_str,dict[i],sizeof(char)*L) == 0)
				result++;

		}
		return result;

		//compare
	}
	else if(idx == 0)
	{
		dirLen = strlen(list[idx]);
		for(i=0;i<dirLen;i++)
		{
			result_str[idx] = list[idx][i];
			for(j=0;j<D;j++)
			{
//				if(strncmp(result_str,dict[j],sizeof(char)*(idx+1))==0)
				if(result_str[0]==dict[j][0])
					result += cmp(L,D,idx+1,j);	
			}
					
		}
		return result;

	}
	else
	{
		dirLen = strlen(list[idx]);
		for(i=0;i<dirLen;i++)
		{
			result_str[idx]=list[idx][i];
			if(result_str[idx] == dict[iDict][idx])
			{
				result += cmp(L,D,idx+1,iDict);
			}
			else
				result += 0;
		}
		return result;
	}
	
}