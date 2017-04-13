#include <iostream>
#include <string>
#include <map>
using namespace std;
int n, s, q;
int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        int smallest = 0;
        cin >> s;
        char c;
        cin.get(c);
        map<string,int> names;
        for (int j=0;j<s;j++){
            char temp[100];
            cin.getline(temp, 100);
            string ts=string(temp);
            names[ts]=j;
        }
        cin >> q;
        cin.get(c);
        int table[s][q];
        for (int k=0;k<s;k++) table[k][0]=0;
        for (int j=1;j<q;j++)
            for (int k=0;k<s;k++)
                table[k][j]=-2;
        string queries[q];
        for (int j=0;j<q;j++){
            char temp[100];
            cin.getline(temp, 100);
            queries[j]=string(temp);
            table[names[queries[j]]][j] = -1;
        }
        for (int j=1;j<q;j++){
            int temp = -1;
            for (int k=0;k<s;k++){
                if (table[k][j]==-1) continue;
                if (table[k][j-1]>=0) table[k][j]=table[k][j-1];
                else table[k][j]=smallest+1;
                if (temp==-1||table[k][j]<temp) temp=table[k][j];
            }
            smallest=temp;
        }
        cout<<"Case #"<<(i+1)<<": "<<smallest<<endl;
    }
}
