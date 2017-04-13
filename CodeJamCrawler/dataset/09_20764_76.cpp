

int okes(char * word,char * pattern)
{
/*
ok (a:word) (b:pattern)
	|b=='('=if (elem a $ takeWhile (/=')') pattern) then ( ok word (tail $ dropWhile (/=')') pattern ) )
	|True=if (b==a) then (ok word pattern) else False

*/
//printf("%c %s\n",word[0],pattern);
if (strlen(word)==0 ) return 1;
if (pattern[0]=='(')
	{
	int j=0;
	int talalat=0;
	for (j=0;pattern[j]!=')';j++)
		if (pattern[j]==word[0] )talalat=1;
	if (talalat==0) return 0;
	return okes(word+1,pattern+j+1);	
	
	}
	else
	{
	if (pattern[0]==word[0] ) return okes(word+1,pattern+1);else return 0;
	
	}
}

int main()
{
//printf("%d\n",okes ("abc","(ab)(bc)(ca)") );
int len,words,patterns;
scanf("%d %d %d",&len,&words,&patterns);
char ** word_ar=malloc (words*(sizeof(char * ) ));
int i;
for (i=0;i<words;i++)
	word_ar[i]=malloc(len*sizeof(char) );

char ** pat_ar=malloc (patterns*(sizeof(char * ) ));
for (i=0;i<patterns;i++)
	pat_ar[i]=malloc(1500*sizeof(char) );
for (i=0;i<words;i++)
	scanf("%s",word_ar[i]);
for (i=0;i<words;i++)
	scanf("%s",pat_ar[i] );
int iii;
for (iii=0;iii<patterns;iii++)
	{
	int solut=0;
	int i2;
//printf("kkk:%d\n",okes("bca","(abc)(abc)(abc)"));
//printf("%s\n",pat_ar[iii] );
	for (i2=0;i2<words;i2++)
		if (okes(word_ar[i2],pat_ar[iii] ) ==1) solut++;
	printf("Case #%d: %d\n",iii+1,solut);	
	}	
	
	
}
