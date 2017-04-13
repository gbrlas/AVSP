# include <cstdio>
# include <cmath>
# include <iostream>
# include <fstream>
using namespace std ;

# define ON         "ON"
# define OFF        "OFF"

int main() {
    
long T ;
long N ;
long K ;
long power   ;
ifstream ifs("A-large.in") ;
ofstream ofs("A-large.out");

ifs>>T ;
for(long loop=1;loop<=T;++loop){
ifs>>N>>K ;
power = pow((double)2,(double)N)  ;

if ((K+1)%power==0)  ofs<<"Case "<<"#"<<loop<<": "<<ON<<endl ;
else               ofs<<"Case "<<"#"<<loop<<": "<<OFF<<endl ;

N=K=power=0; }

ifs.close() ;
ofs.close() ;    

return 0 ;
}
