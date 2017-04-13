#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
string doubleToString(double val)
{
    ostringstream out;
    out << val;
    return out.str();
}
string convertInt(int number)
{
   stringstream ss;
   ss << number;
   return ss.str();
}
bool palindrom(string s)
{
    int n = s.length();
    if(n < 2)
        return true;
    for(int i=0; i<(n/2); i++)
    {
        if(s[i] != s[(n-1)-i])
            return false;
    }
    return true;
}
bool square(int x)
{
    double y = sqrt(x);
    return (y - floor(y)) == 0;
}
int Problem_C(int A,int B)
{
    int result = 0;
    for(int i=A; i<=B; i++)
    {
        if(palindrom(convertInt(i)) && square(i) && palindrom(doubleToString(sqrt(i))))
            result++;
    }
    return result;
}
int main()
{
    char arr[4][4];
    int N , numb = 1;
    int A,B;
    ifstream infile("C-small-attempt0.in");
    ofstream outfile("C-small-attempt0.out");
    infile>>N;
    while(N != 0)
    {
        infile>>A;
        infile>>B;
        outfile << "Case #" << numb << ": " << Problem_C(A,B) << endl;
        N--;
        numb++;
    }
    infile.close();
    outfile.close();
    return 0;
}
