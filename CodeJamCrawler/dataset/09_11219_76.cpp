#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>



using namespace std;



struct harf{
 
  int sira;
  char value;
  char onceki;
  char ikionceki;
  int pc;
};


int main()
{

FILE *f;

f = fopen("C-small-attempt2.in","r");

int adet;

fscanf(f,"%d",&adet);


vector<char> tut;


char x;
int i,count;

fgetc(f);

string jam = "welcome to code jam";

int howmany,temp; 


queue<struct harf> liste;



for(count = 1;count<=adet;count++)
{
  
  tut.clear();
  while(!liste.empty())liste.pop();
  
  howmany = 0;
  
  while(1)
  {
    x = fgetc(f);
  
    if(x == '\n')break;
    if(feof(f))break;
  
    tut.push_back(x);   
  }
  
  
  
  for(i=0;i<tut.size();i++)
  {
    if(tut[i] == 'w')
    {
	struct harf temp;
	temp.sira = i;
	temp.value = 'w'; 
	
	liste.push(temp);
	
    }
    
  }
  
  while(1)
  {
    if(liste.empty())break;
    
    struct harf poped = liste.front();
    liste.pop();
    
    i = poped.sira;
    char deger = poped.value;
    char once = poped.onceki;
    char ikionceki = poped.ikionceki;
    char aranacak;
    char topu;
    int pc;
    int turn;
    
     
    
    if(deger == 'w')aranacak = 'e';
    else if(deger == 'e' && once == 'w'){aranacak = 'l';}
    else if(deger == 'l'){aranacak = 'c';topu = 'w';}
    else if(deger == 'c' && once == 'l'){aranacak = 'o';topu = 'e';}
    else if(deger == 'o'&& once == 'c' && ikionceki == 'e'){aranacak = 'm';topu = 'l';}
    else if(deger == 'm'){aranacak = 'e';topu = 'c';}
    else if(deger == 'e'&& once == 'm'){aranacak = ' ';topu = 'o';pc=1;}
    else if(deger == ' '&& once == 'e' && ikionceki == 'o' && pc == 1){aranacak = 't';topu = 'm';}
    else if(deger == 't'){aranacak = 'o';topu = 'e';pc=4;}
    else if(deger == 'o' && once == 't' && pc==4){aranacak = ' ';topu = ' ';pc=3;}
    else if(deger == ' ' && pc==3){aranacak = 'c';topu = 't';}
    else if(deger == 'c'&& once == ' '){aranacak = 'o';topu = 'o';}
    else if(deger == 'o'&& once == 'c' && ikionceki == 'o'){aranacak = 'd';topu = ' ';}
    else if(deger == 'd'){aranacak = 'e';topu = 'c';}
    else if(deger == 'e'&& once == 'd'){aranacak = ' ';topu = 'o';pc=2;}
    else if(deger == ' '&& once == 'e' && ikionceki == 'o' && pc == 2){aranacak = 'j';topu = 'd';}
    else if(deger == 'j'){aranacak = 'a';topu = 'e';}
    else if(deger == 'a'){aranacak = 'm';topu = 'j';}
    
//    printf("%c %d %c\n",deger,i,aranacak);
    if(aranacak == 'm' && deger == 'a')
    {
      for(turn = i;turn<tut.size();turn++)
      {
	if(tut[turn] == aranacak)
	{
	  howmany++;
	}
      }
      
     
      continue;
    }
    
     
    
    
    for(turn = i;turn<tut.size();turn++)
    {
	if(tut[turn] == aranacak)
	{
	  struct harf temp;
	  temp.value = aranacak;
	  temp.sira = turn;
	  temp.onceki = deger;
	  temp.ikionceki = topu;
	   temp.pc = pc;
	  liste.push(temp);
    
	}
    }
    
    
  }
  
printf("Case #%d: ",count);
int num = howmany % 10000;
int sifir;
if(num>1000)sifir = 0;
if(num<1000 && num>=100)sifir = 1;
if(num<100 && num>=10)sifir = 2;
if(num<10 && num>=1)sifir = 3;
if(num== 0)sifir = 3;

int g;
for(g=0;g<sifir;g++)
{
  printf("0");
}
printf("%d",num);

if(count != adet)cout<<endl;




}




return 0;
} 
