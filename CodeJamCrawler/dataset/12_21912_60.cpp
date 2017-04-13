#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char* map = "yhesocvxduiglbkrztnwjpfmaq";
    char buf[101];
    char ans[101];
    
    ifstream fileIn("in.txt");
    ofstream fileOut("out.txt");
    
    int N = 0;
    fileIn >> N;
    fileIn.getline(buf, 101);
    
    for(int i=0; i<N; ++i)
    {  
        ans[0] = 0;  
        fileIn.getline(buf, 101);
        int j=0;
        char cur;
        while(cur = buf[j])
        {
            if(cur == ' ')
                ans[j] = ' ';
            else
                ans[j] = map[cur-'a'];
            ++j;
        }
        ans[j] = 0;
        fileOut<<"Case #" << i+1 << ": " << ans<<endl;
    }
    return 0;
}
