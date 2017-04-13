#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

unsigned long long int bourrin_magistral(vector <unsigned long long int> candies,unsigned long long int total1,unsigned long long int total2,unsigned long long int total3,int truc,bool modifie)
{
    if(total1==total2&&modifie)
        if(truc==candies.size())
            return total3;
        else
            return max(total3,max(bourrin_magistral(candies,total1^candies[truc],total2^candies[truc],total3-candies[truc],truc+1,true),bourrin_magistral(candies,total1,total2,total3,truc+1,modifie)));
    if(truc==candies.size())
        return 0;
    return max(bourrin_magistral(candies,total1^candies[truc],total2^candies[truc],total3-candies[truc],truc+1,true),bourrin_magistral(candies,total1,total2,total3,truc+1,modifie));
}


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int nb_cas;
    in>>nb_cas;
    for(int c=0;c<nb_cas;c++)
    {
        int nb_candies;
        in>>nb_candies;
        vector <unsigned long long int> candies;
        candies.resize(nb_candies);
        unsigned long long int total1=0,total3=0;
        for(int c2=0;c2<nb_candies;c2++)
        {
            in>>candies[c2];
            total1^=candies[c2];
            total3+=candies[c2];
        }
        sort(candies.begin(),candies.end());
        out<<"Case #"<<c+1<<": ";
        unsigned long long int machin=bourrin_magistral(candies,total1,0,total3,0,false);
        if(machin==0)
            out<<"NO"<<endl;
        else
            out<<machin<<endl;
    }
}
