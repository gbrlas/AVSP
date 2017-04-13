
#include <stdafx.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include <fstream>
using namespace std;
int gf=0,len,num,i1,istar;
char *str1,*str2;
char **st;
int *ar,top;
struct node{
	char *word;
	struct node *left;
	struct node *right;
};
struct node *root1;
struct node *star1,*star2;
void lbbin(struct node* root,char* str)
{
	
	if(root==NULL)return;
	int k=strcmp(str,root->word);
	if(k==0)
	{
		star1=root;
	}
	else if(k<0)
	{
		star1=root;
		lbbin(root->left,str);
	}
	else
	{
		lbbin(root->right,str);
	}
}
void ubbin(struct node* root,char* str)
{
	
	if(root==NULL)return;
	int k=strcmp(str,root->word);
	if(k==0)
	{
		star2=root;
	}
	else if(k>0)
	{
		star2=root;
		ubbin(root->right,str);
	}
	else
	{
		ubbin(root->left,str);
	}
}
void binary_tree_inorder(struct node *root,char* str)
{
	int k;
	if(root==NULL)
	{
		if(istar==0)	star1=NULL;
		else	star2=NULL;
		return;
	}
	

	k=strcmp(root->word,str);
	if(k<0)
	{
		binary_tree_inorder(root->right,str);
	}
	else
	{
		if(k>0)
		{	
			binary_tree_inorder(root->left,str);
		}
		star1=root;istar=1;
		star2=root;
		binary_tree_inorder(root->right,str);//..
	}
		
	//if(
	
	
  //	printf("%s\n",root->word);
	k=strcmp(root->word,str);
	


	if(k==0)
	{
		gf=1;
	}
	if(!gf)
	{
		if(k>0)
		binary_tree_inorder(root->left,str);
		else
		binary_tree_inorder(root->right,str);
	}
}
struct node* binary_search_tree(char **,int);
void call1(int);
int main()
{
	int L,N,D,ff,t;

	int n,i,j;
	char **s;
	char *str;

	ifstream fin("A-small-attempt2.in");
	ofstream fout("output.txt");
	str=(char*)malloc(100);

	root1=(struct node*)malloc(sizeof(struct node)*1);
 //	scanf("%d %d %d",&L,&D,&N);
	fin>>L>>D>>N;
//	scanf("%d",&n);

	str=(char*)malloc(sizeof(char)*20);
	s=(char**)malloc(sizeof(char*)*D);
	for(i=0;i<D;i++)
	{
	  //	scanf("%s",str);
		 fin>>str;
		s[i]=(char*)malloc((sizeof(char))*(strlen(str)+1));
		strcpy(s[i],str);
	}
	 root1=binary_search_tree(s,D);
	
	 free(str);
	 str1=(char*)malloc(600);
	 str2=(char*)malloc(20);
	 i1=1;
	 st=(char**)malloc(2*30);
	 ar=(int*)malloc(70);
	 for(i=0;i<30;i++)	st[i]=(char*)malloc(30);
	 while(i1<=N)
	 {
		// scanf("%s",str1);
		fin>>str1;
		 num=0;
		 len=strlen(str1);
		 /*for(i=0,j=0;i<len;i++,j++)
		 {
			 if(str1[i]!='(')
			 {
				str2[j]=str1[i];
			 }
			 else
			 {
				call(N,i,j);
				break;
			 }
		 } */
		 top=-1;ff=0;
		 for(i=0,j=0;i<len;i++)
		 {
			if(ff==0)
			{
				if(str1[i]!='(')
				{

					str2[j]=str1[i];
				}
				else
				{
					ff=1;t=-1;top++;ar[top]=j;str2[j]='-';
				}
				j++;
			}
			else
			{
				if(str1[i]!=')')
				{
					st[top][++t]=str1[i];
				}
				else
				{
					st[top][++t]='\0';
					ff=0;
				}
			}
		 }
		 str2[j]='\0';
			call1(0);

		 /*printf("%s",str2);
		 for(i=0;i<=top;i++)
			printf("\n%s",st[i]);*/

		//cout<<num;
		fout<<"Case #"<<i1<<": "<<num<<endl;
		i1++;
	 }
	 fin.close();
    fout.close();
    return 0;
}
void call1(int k)
{
	int len,i;
	char c,c1;
	if(k>top)
	{
		gf=0;
		binary_tree_inorder(root1,str2);
		num+=gf;
	}
	else
	{
		len=strlen(st[k]);
		for(i=0;i<len;i++)
		{
			
			str2[ ar[k] ] = st[k][i];
			c=str2[ar[k]+1];
			str2[ar[k]+1]='\0';
			star2=star1=NULL;
			lbbin(root1,str2);
			str2[ar[k]]++;
			ubbin(root1,str2);
			str2[ar[k]]--;
			str2[ar[k]+1]=c;
			if(star1==NULL||star2==NULL)
				continue;
			if(strcmp(star2->word ,star1->word)>=0)
				call1(k+1);
		}
	}
}




/*void call(int n,int a,int b)
{
	int i,j;
	char *c;
	c=(char*)malloc(30);
	for(i=a+1,j=0;str1[i]!=')';i++,j++)
	{
		c[j]=str1[i];
	}
	a=i+1;
	for(j--;j>=0;j--)
	{
		str2[++b]=c[j];
	  //	for(x=0;


   }

	if(str1[a]==')')
	{
	}
} */
struct node* binary_search_tree(char **str,int n)
{
	int len,j,i,flag;
	struct node *temp, *temp1,*root;
	temp=(struct node*)malloc(sizeof(struct node)*1);
	root=(struct node*)malloc(sizeof(struct node)*1);
	len=strlen(str[0]);
	temp->word=(char*)malloc(sizeof(char)*(len+1));
	root->word=str[0];
	root->left=NULL;
	root->right=NULL;


	for(i=1;i<n;i++)
	{
		len=strlen(str[i]);

		temp=root;
		while(1)
		{
			j=0;
			flag=0;
			while(1)
			{

				if(temp->word[j]=='\0'&&str[i][j]=='\0')
					{
						flag=1;
						break;
					}
				if(temp->word[j]<str[i][j]||temp->word[j]=='\0')
				{
					if(temp->right!=NULL)
					{
						temp=temp->right;
						break;
					}
					else
					{
						temp1=(struct node*)malloc(sizeof(struct node)*1);
						temp1->word=(char*)malloc(sizeof(char)*(len+1));
						strcpy(temp1->word,str[i]);
						temp1->left=NULL;
						temp1->right=NULL;
						temp->right=temp1;
						flag=1;
						break;
					}
				}
				else
				if(temp->word[j]==str[i][j])
				{
					j++;
				}
				else
				if(temp->word[j]>str[i][j]||str[i][j]=='\0')
				{
					if(temp->left!=NULL)
					{
						temp=temp->left;
						break;
					}
					else
					{
						temp1=(struct node*)malloc(sizeof(struct node)*1);
						temp1->word=(char*)malloc(sizeof(char)*(len+1));
						strcpy(temp1->word,str[i]);
						temp1->left=NULL;
						temp1->right=NULL;
						temp->left=temp1;
						flag=1;
						break;
					}

				}

			}
			if(flag==1)
			{
				break;
			}

		}

	}
	return root;
}