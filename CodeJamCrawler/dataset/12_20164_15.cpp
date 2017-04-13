#include <iostream>

using namespace std;

char data_c(char c)
{ 
     if (c == 'a')
      return 'y';
     else if (c == 'b')
      return 'h';
     else if (c == 'c')
      return 'e';
     else if (c == 'd')
      return 's';
     else if (c == 'e')
      return 'o';
     else if (c == 'f')
      return 'c';
     else if (c == 'g')
      return 'v';
     else if (c == 'h')
      return 'x';
     else if (c == 'i')
      return 'd';
     else if (c == 'j')
      return 'u';
     else if (c == 'k')
      return 'i';
     else if (c == 'l')
      return 'g';
     else if (c == 'm')
      return 'l';
     else if (c == 'n')
      return 'b';
     else if (c == 'o')
      return 'k';
     else if (c == 'p')
      return 'r';
     else if (c == 'q')
      return 'z';
     else if (c == 'r')
      return 't';
     else if (c == 's')
      return 'n';
     else if (c == 't')
      return 'w';
     else if (c == 'u')
      return 'j';
     else if (c == 'v')
      return 'p';
     else if (c == 'w')
      return 'f';
     else if (c == 'x')
      return 'm';
     else if (c == 'y')
      return 'a';
     else if (c == 'z')
      return 'q';
     else
      return ' ';
}

int N;

char temp_c;

int main() {
    
    FILE *fp1 = freopen("A-small-attempt8.in","rt",stdin);
	FILE *fp2 = freopen("A-small-attempt8.out","wt",stdout);
	
	cin >> N;
	int i = 1;
	//cout << "Output";
	while (!feof(fp1))
	{
         temp_c = fgetc(fp1); 
         if (temp_c != 10)
         {
          cout << data_c(temp_c);
       // cout << temp_c;
       // cout << " ";
         }
         else
         {
             if (i == 1)
             {
             cout << "Case #";
             cout << i ;
             cout << ": ";
             i++;
             }
             else if (i<=N)
             {
                  cout << "\nCase #";
                  cout << i ;
                  cout << ": ";
                  i++;
             }
             else
             {
                 cout << "\n";
             }
         }   
    }
	return 0;
}
