#include <cstdio>
#include <cstring>

int tc,t;
char a[10][10];
char b[100];
int i,j,k,n;
char res;
bool done;
char temp;




char check(int d,int pos){
    char c,n=0;    
    if(d==1){ // across
        int j = 0;
        c = a[pos][0];            
        if(c=='T'){
            c = a[pos][1];    
        }
        for(;j<4;j++){
            if(a[pos][j]=='.') return a[pos][j];
            if(a[pos][j]==c || a[pos][j]=='T') n++;    
        }
        if(n==4) return c;
        else return '.';
    }else if(d==0){ //down
        int i = 0;
        c = a[0][pos];            
        if(c=='T'){
            c = a[1][pos];    
        }
        for(;i<4;i++){
            if(a[i][pos]=='.') return a[i][pos];
            if(a[i][pos]==c || a[i][pos]=='T') n++;    
        }
        if(n==4) return c;
        else return '.';
    }
}


int main(){
    gets(b);
    sscanf(b,"%d",&tc);
    for(t=1;t<=tc;t++){
        if(t>1) gets(b);
        for(i=0;i<4;i++)
            gets(a[i]);  

        done = false;
        for(i=0;i<4;i++){
            res = check(1,i);
            if(res!='.'){ done = true; break;}
        }
        if(!done){
            for(j=0;j<4;j++){
                res = check(0,j);    
                if(res!='.'){ done = true; break;}  
            }         
        }
        if(!done){
            n = 0;
            temp = a[0][0];            
            if(temp=='T'){
                temp = a[1][1];    
            }
            for(i=0,j=0;i<4;i++,j++){
                if(a[i][j]=='.') break;
                if(a[i][j]==temp || a[i][j]=='T') n++;    
            }
            if(n==4){ res = temp; done = true;}
            else res = '.';
        }
        if(!done){
            n = 0;
            temp = a[0][3];            
            if(temp=='T'){
                temp = a[1][2];    
            }
            for(i=0,j=3;i<4;i++,j--){
                if(a[i][j]=='.') break;
                if(a[i][j]==temp || a[i][j]=='T') n++;    
            }
            if(n==4){ res = temp; done = true;}
            else res = '.';
        }
        
        if(done){
            printf("Case #%d: %c won\n",t,res);    
        } else{
            for(i=0;i<4;i++){
                if(done) break;
                for(j=0;j<4;j++)
                    if(a[i][j]=='.'){
                        done = true; 
                        break;    
                    }    
            }    
            if(done)
                printf("Case #%d: Game has not completed\n",t);
            else
                printf("Case #%d: Draw\n",t);
        }
    }
    
    return 0;
}
