#include <iostream>
#include <vector>

using namespace std;

bool okrow(int N,int index,vector<bool> v){
    for(int j=index+1;j<N;j++)
        if(v.at(j))
	    return false;
    return true;
}

bool ok(int N, vector<vector<bool> > m){
    for(int i = 0; i <N; i++){
	if(!okrow(N,i,m.at(i)))
	    return false;
    }
    return true;
}


int main(){
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t++) {
	int N;
	cin >> N;
	vector<vector<bool> > v;
	for(int i = 0;i <N; i++){
	    vector<bool> sor;
	    for(int j =0;j<N;j++) {
		char c;
		cin >> c;
		sor.push_back(c - '0');
	    }
	    v.push_back(sor);
	}
	
/*	for(int i = 0; i <N; i++){
	    for(int j=0;j<N;j++){
		cout << v.at(i).at(j);
	    }
	    cout << endl;
	}*/
	
	int changes=0;
	
	int pp=0;
	for(int i = N-1; i >-1;i--) {
	    bool c = true;
	    for(int k=0;k<N;k++)
		if(v.at(k).at(i)) {
		    c=false;
		}
	    if(!c)
		break;
	    else pp++;
	}
	
	int sN=N, oszN=N;
	
	for(int aktsor=0;aktsor<N;aktsor++) {
	    if(ok(N,v))
		break;
	    int bestS=-1, en=N+1;
	
	    for(int sor=aktsor;sor<sN;sor++) {
		if(okrow(oszN,aktsor,v.at(sor))){
//		    cout << "jo sor: " << sor << endl;
		    int egy=0;
		    for(int i=0;i<oszN;i++)
			if(v.at(sor).at(i))
			    egy++;
		    if(egy<en){
			bestS=sor;
			en=egy;
		    }
		}
	    }
	    
//	    cout << "legjobb sor " << aktsor << ". sornak: " << bestS <<endl;
	    
	    for(int i=0;i<bestS-aktsor;i++) {
		v.at(bestS-1-i).swap(v.at(bestS-i));
		changes++;
	    }
	}
	
	cout << "Case #" << t << ": " << changes << endl;
    }
    return 0;
}
