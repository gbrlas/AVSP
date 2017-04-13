#include<iostream>
#define S 4
using namespace std;

int main(){
        int t;
        cin >> t;
        char ar[S][S];
        char p[S],s[S];
        int i,j;
	int tot=t;
        while(t--){
		cout << "Case #" << tot-t << ": " ;
                int c=1;
                int bb=0;
                char tt;
                char pp=';',ss=';';
		char k=';';


		for(i=0;i<S;i++) for(j=0;j<S;j++) cin >> ar[i][j];
			
		
                for(i=0;i<S;i++){
			k=';';
                        for(j=0;j<S;j++){
                                tt=ar[i][j];
                                if(i==j){
                                        if(tt!='T')
                                                pp==';' || pp==tt ?pp=tt:pp='n';
                                }
                                if((S-1-j)==i){
                                        if(tt!='T')
                                                ss==';' || ss==tt ?ss=tt:ss='n';
                                }
                                if(tt!='T')
                                        k==';' || k==tt ?k=tt:k='n';
                                if(tt=='.'){
                                        c=0;
                                }
                        }
                        if(k=='X' || k=='O'){
                                cout << k << " won" << endl;
                                bb=1;
                                break;
                        }
			
                }
                if(bb) continue;
		//		cout << ss << ";;" << pp << endl;
                if(ss=='X' || ss=='O'){
                        cout << ss << " won" << endl;
			continue;
		}
                if(pp=='X' || pp=='O'){
                        cout << pp << " won" << endl;
			continue;
		}
                bb=0;
                for(i=0;i<S;i++){
                        k=';';
                        for(j=0;j<S;j++){
                                tt=ar[j][i];
                                if(tt!='T')
                                        k==';' || k==tt ?k=tt:k='n';
                        }
                        if(k=='X' || k=='O'){
                                cout << k << " won" << endl;
                                bb=1;
                                break;
                        }
                }
                if(bb) continue;
                if(!c) cout << "Game has not completed" << endl;
                else
                        cout << "Draw" << endl;

        }
        return 0;
}
