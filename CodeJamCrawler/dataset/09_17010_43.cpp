//gcj a

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int L,D,N;
 
vector<string> vs,input;
string ss[15];

int pro( string s )
{
    int res = 0;
    int curi, i;
    curi = i = 0;
    for( int i = 0; i < 15; i++ )
    {
         ss[i] = "";
    }
    while( i < s.length() )
    {
        if( s[i] == '(' )
        {
            i++;
            while( i < s.length() && s[i] != ')' )
            {
                   ss[curi] += s[i];        
                   i++;
            }
            curi++;
        }
        else
        {
            ss[curi] += s[i];
            curi++;
        }                
        i++;
    }
    
    for( int i = 0; i < vs.size(); i++ )
    {
         string ts = vs[i];
         bool ok = true;
         for( int j = 0; j < L; j++ )
         {
              bool match = false;
              for( int k = 0; k < ss[j].length(); k++ )
              {
                   if( ts[j] == ss[j][k] ) 
                   {
                       match = true;
                       break;
                   }
              }
              ok = match;
              if( !ok ) break;
         }
         if( ok ) 
             res++;
    }
    /*
    for( int i = 0; i < 15; i++ )
    {
         cout << ss[i] << endl;
    }
    */
    return res;
}

int main()
{
    string line;
    
    freopen("A-small-attempt0.in","r",stdin);
    freopen("smalla.out","w",stdout);
    scanf("%d %d %d\n",&L,&D,&N);
    for( int i = 0; i < D; i++ )
    {
         getline( cin, line );
         //cout << line << endl;
         vs.push_back( line );
    }
    
    for( int i = 0; i < N; i++ )
    {
         getline( cin, line );
         //cout << line << endl;
         input.push_back( line ); 
    }
    
    for( int i = 0; i < input.size(); i++ )
    {
         int ans =  pro( input[i] );
         cout << "Case #" << i+1 << ": " << ans << endl;
    }

    return 0;
}
