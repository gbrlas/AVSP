
 # include <cstdio>
 # include <iostream>
 # include <fstream>
 # include <list>
 
 using namespace std ;
 
 list<int> L ;
 
 void initList(int *array,int size) {
 if(L.empty()==false) {L.clear();}
 for(int i=0;i<size;++i) {
  L.push_back(array[i]) ; }     
 }
 
 int main() {
     
     int T ;
     int R ;
     int K ;
     int N ;
     int euros = 0 ;
//     int flagPos = 0 ;
     int *array     ;

     ifstream is("C-small-attempt3.in") ;
     ofstream os("C-small-attempt3.out") ;
     
     is>>T ;

     for(int loop = 1 ; loop<=T ; ++loop) {               
     is>>R>>K>>N ;               
     array =(int *)new int[N] ;
     for(int r=0;r<N;++r) {is>>array[r];}
     initList(array,N) ;          
     for(int i=1 ; i<=R; ++i) {
     int sum = 0 ;             
     for( list<int>::size_type j = 0; j<L.size() ; ++j ) {          
     
     int Front = L.front() ;
     
//     flagPos = (flagPos-1==0)?L.size():flagPos-1;
     sum += Front ; 
          
     if(sum==K) { L.pop_front();L.push_back(Front);break ;}
     else if(sum<K) { L.pop_front();L.push_back(Front);}  
     else { sum -= Front;
//     flagPos = (flagPos==L.size())?1:flagPos+1;
     break ;}     
     
     }
     
/*     if(i==1) {flagPos = L.size() ;}
     else if( i>1 && flagPos==L.size() && i!=R) {
     euros = (euros*R)/(i-1);break; }*/
          
     euros += sum ;                              
     
     }     

     os<<"Case #"<<loop<<": "<<euros<<endl ;
     euros = 0 ;
     R=K=N=0;
//     flagPos=0 ;
     delete(array) ;
     
     }
     
     is.close();
     os.close();

 
     return 0 ;
 }
 


