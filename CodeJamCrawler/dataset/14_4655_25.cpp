/**
 * Tournament: Google Code Jam 2014 - Round 1
 * Task: B - short
 * Author: Vasil Sarafov
 * 12.04.2014, Varna, Bulgaria
 * **/
 #include <iostream>
 #include <cstdio>
 #include <fstream>
 #include <iomanip>
 #define space " "
 #define ln "\n"
 using namespace std;
 
 const double EPS = 1e-6;
 
 int testCases;
 double c, f, x;
 
 int main(int argc, char **argv)
 {
	 freopen("B-short.in", "rt", stdin);
	 freopen("B-short.out", "wt", stdout);
	 
	 cin >> testCases;
	 for(int test = 1; test <= testCases; test++)
	 {
		 cin >> c >> f >> x;
		 
		 double rate = 2, best = 0;
		 double firstCondition, secondCondition;
		 
		 while(true)
		 {
			firstCondition = (x / rate);
			secondCondition = ( (c / rate) + (x / (rate + f)) );
			
			if(firstCondition > secondCondition)
			{
				best += (c / rate);
				rate += f;
			}
			else
			{
				cout << "Case #" << test << ": ";
				cout << fixed << setprecision(7);
				cout << best + firstCondition << ln;
				break;
			}  
		 }
	 }
	 
	 return 0;
 }
