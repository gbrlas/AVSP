// program1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afx.h>

int main(int argc, char* argv[])
{
	FILE *ofile;
	char ch[100];
	char *p = ch;
	//	p=(char *)(LPCTSTR)filename;
	//p=;
	CString filename;
//	p=filename.GetBuffer(filename.GetLength());
//	if ((ofile = fopen("A-small-attempt0", "rt")) != NULL)
//	{

		CStdioFile f,SaveDataFile;
//		char buf[100];
		if (f.Open("A-small-attempt0", CFile::modeRead) == TRUE)
		{
			if (SaveDataFile.Open("result", CFile::modeCreate | CFile::modeWrite) != TRUE)
			{   
				return 1;
			}
//		printf("open OK!\n");
		CString temp;
		if(f.ReadString(temp) != false)
		{
			printf("%s", temp.GetBuffer(10));
		}
		int count = atoi(temp);
//		printf("count=%d\n", count);

		for(int k=0; k<count; k++)//总循环
		{
		int result=0;
		f.ReadString(temp);
		int count2 = atoi(temp);
		int eng_num= count2;
		const int ALL=100;
		CString eng[ALL];
		int eng_count[ALL];
		CString search[ALL];
		for(int j=0; j<ALL; j++)
		{
			eng_count[j]=0;
		}

		for(int i=0; i< count2; i++)//name of engine
		{
			f.ReadString(eng[i]);
//			printf("engine #%d: %s\n", i, eng[i].GetBuffer(0));
		}

		f.ReadString(temp);
		count2 = atoi(temp);
//		printf("count2=%d\n", count2);


		if(count2 == 0) result =0;
		else
		{
			int toOne=0;//由0变1的个数，当为eng_num时，就是最后一个出现的，就先用那个engine
			while(count2>0)//for(i=0; i< count2; i++)
			{
				CString se;//search name
				f.ReadString(se);
//				printf("%s\n", se.GetBuffer(0));
				int toOneNum=0;//最后一个eng_count变成1的那个engine序号
				for(j = 0; j < eng_num; j++)
				{
					if (se == eng[j])
					{
						if (eng_count[j] ==0) 
						{
							toOne++;
							toOneNum=j;
						}
						eng_count[j]++;
					}
				}
				if (toOne == eng_num) 
				{
					result++;
					for(j = 0; j < eng_num; j++)//清空
					{
						eng_count[j] =0;
					}
					toOne = 1;
					eng_count[toOneNum]++;//已经有一个这个查询词了
//					printf("toOneNum=%d\n", toOneNum);
				}
				count2--;
			}
		}
		printf("Case #%d: %d\n", k+1, result);
		char ch1[50];
		sprintf(ch1, "Case #%d: %d\n", k+1, result);
		SaveDataFile.WriteString(ch1);
		
		}		
		}
/*		int i,j;
		for(i=0;i<row;i++)
		{ 
			for(j=0;j<col;j++)
			{
				//fwrite (&data[i*col+j], sizeof (data[i*col+j]), 1, ofile);
				if ((j==0) && (i ==0)) printf("%d\n",data[i*col+j]);
				fwrite (&data[i*col+j], sizeof (data[i*col+j]), 1, ofile);		
			}
		}
*/		
//		fclose (ofile);
//	}	
//	printf("Hello World!\n");
		f.Close();
		SaveDataFile.Close();
	return 0;
}

