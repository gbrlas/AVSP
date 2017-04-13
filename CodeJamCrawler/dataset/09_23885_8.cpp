#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

long long int calcTime(string num)
{
   int tempArr[36] = {0};
   for(int i=0; i<num.length();i++)
   {
      if(islower(num[i]))
         tempArr[num[i] - 'a' + 10] = 1;
      else
         tempArr[num[i] - '0'] = 1;
   }
   
   int base = 0;
   for(int i=0; i<36; i++)
     if(tempArr[i] == 1) base++;
     
   if (base == 1)
     base++;
   
   for(int i=0; i<36; i++)
      tempArr[i] = -1;
      
      if(islower(num[0]))
        tempArr[num[0] - 'a' + 10] = 1;
      else
      {
        cout << "pos = " << num[0] - '0' << endl;
        tempArr[num[0] - '0'] = 1;
      }     
   for(int i=1, cur = 0; i<num.length();i++)
   {
      if(cur == 1) cur++;
      if(islower(num[i]))
      {
         if(tempArr[num[i] - 'a' + 10] == -1)
         {
            cout<<"Modified pos " <<num[i] - 'a' + 10 << "with " <<cur <<endl;
            tempArr[num[i] - 'a' + 10] = cur;
            cur++;
         }
      }
      else
      {
         if(tempArr[num[i] - '0'] == -1)
         {
            cout<<"Modified pos " <<num[i] - '0' << "with " <<cur <<endl;
            tempArr[num[i] - '0'] = cur;
            cur++;
         }
      }
   }
   long long int result = 0;
   int mul = 1;
   
   for(int i=num.length()-1; i>=0; i--)
   {
      if(islower(num[i]))
      {
        result += tempArr[num[i] - 'a' + 10] * mul;
        mul *= base;
        cout << "Result = " << result << endl;
        cout << "Mul = " << mul << endl;
        cout << "num[i] = " << tempArr[num[i] - 'a' + 10] << endl;
      }
      else
      {
        result += tempArr[num[i] - '0'] * mul;
        mul *= base;
        cout << "Result = " << result << endl;
        cout << "Mul = " << mul << endl;
        cout << "num[i] = " << tempArr[num[i] - '0'] << endl;
      }
   }
   
   
   return result;
} 

main()
{
   int T, base;
   long long int time;
   fstream input_file("Input.txt",ios::in);
   fstream output_file("Output.txt",ios::out);
   
   input_file >> T;
   string num;
   
   for(int i=0; i<T; i++)
   {
      input_file >> num;
      //if(num.length() == 1) time = 0;
      //else
        time = calcTime(num);
      output_file << "Case #" << i+1 << ": " << time <<endl;
   }
}
