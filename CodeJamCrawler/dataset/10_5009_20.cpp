
 #include <iostream>
 #include <stdio.h>
 
 using namespace std;
 
 int main() {
    
    FILE* fp = fopen("c.in","r");  
    FILE* fp1 = fopen("c.out","w");
    
    int t1,t2,t3;
    int n;
    
    fscanf(fp,"%d\n",&n);
    
    for(int var=0;var<n;var++) 
    {    
    fscanf(fp,"%d %d %d\n",&t1,&t2,&t3);
    
    const int no_groups=t3,R=t1, K=t2;    
 
    int* groups; 
    
    groups = new int[no_groups];
    
    for(int gvar=0; gvar<no_groups; gvar++)
            fscanf(fp,"%d ",&groups[gvar]);     
                
    int pindex=0,euro_count = 0;
    
    int index;
    
    index=pindex;         
      
    for(int i=0;i<R;i++) {     
    
    int count=0, t; 
    while(true) {                        
       
       if( (t=count + groups[index]) <= K ) 
        count = t;        
       else {
        pindex = index;      
        break;     
       } 
       index = (index+1)%no_groups;      
       if(index==pindex) break;            
     }            
      euro_count += count;       
    }  
    
    delete[] groups;    
    
    fprintf(fp1,"Case #%d: %d\n",var+1, euro_count);
    
   // cout<<"\n Count is "<<euro_count;  
   //    cout<<"\n---------------"; 
}   
    
    
    fclose(fp);
    fclose(fp1);
    
    cout<<"\n Done ";
    
    char c;
    cin.get(c);     
      
    return 0;  
  }
