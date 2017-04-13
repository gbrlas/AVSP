// Written by Robert L Szkutak II
// r0szsoft@gmail.com

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

//Returns true if s is a palindrome
bool is_Palindrome(string s)
{
     for(int i = 0; i < s.length(); i++)
     {
             if(s[i] != s[s.length()-1-i])
                 break;
             if(i == s.length()-1)
                 return true;
     }
     return false;
}

//Returns true if n has a whole number square root
bool is_Square(int n)
{
     double s = sqrt(n);
     if(floor(s) == s)
         return true;
     return false;
}

bool is_Fair_And_Square(string s)
{
     if(!is_Palindrome(s))
         return false;
     int n = atoi(s.c_str());
     if(!is_Square(n))
         return false;
     char buff[55];
     itoa((int)sqrt(n), buff, 10);
     if(!is_Palindrome(string(buff)))
         return false;
     
     return true;
     
}

int do_range(int min, int max)
{
    int counter = 0;
    for(int i = min; i <= max; i++)
    {
            char buff[55];
            itoa(i,buff,10);
            if(is_Fair_And_Square(string(buff)))
                counter++;
    } 
    return counter;
}

string test(string s)
{
       /*if(is_Palindrome(s))
           return s + ": True";
       else
           return s + ": False";*/
           
       if(is_Fair_And_Square(s))
           return s + ": True";
       else
           return s + ": False";
}

int main()
{
    ifstream myfile ("C-small-attempt0.in");
    string output, line;
    int cases = 0;
    if (myfile.is_open())
    {
     if ( myfile.good() )
     {
       getline (myfile,line);
       cases = atoi(line.c_str());
       int counter = 0;
       while(myfile.good() && counter < cases)
       {
              getline(myfile, line);
              int min = 0, max = 0;
              int p = line.find(" ");
              min = atoi(line.substr(0,p).c_str());
              max = atoi(line.substr(p+1).c_str());
              char buff[55];
              itoa(do_range(min, max),buff,10);
              output += "Case #" + string(itoa(counter+1, buff, 10)) + ": " + string(buff) + "\n";
              counter++;
       }
     }
     myfile.close();
    }
    else cout << "Unable to open file";
    
    ofstream outfile ("output.txt");
    if (outfile.is_open())
    {
        outfile << output;
        outfile.close();
    }
    else cout << "Unable to open file";
    
    return 0;
}
