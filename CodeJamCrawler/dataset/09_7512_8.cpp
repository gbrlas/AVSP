#include<iostream>
#include<string>
#include<vector>
#include<fstream>


using namespace std;

int find_ind(const vector<char>& vec, char a){
	for(int i=0;i<vec.size();++i)
		if(a==vec[i]) return i;
	return -1;


}

int main(){
	ofstream save("base.out");
	int T;
	cin >> T;
	for(int t=0;t<T;++t){
		string number;
		cin >> number;
		vector<char> vec;
		vector<int> store;
		vector<int>::iterator iter;
		int count=0, ind;
		for(int i=0;i<number.size();++i){
			if((ind=find_ind(vec,number[i]))==-1){
				vec.push_back(number[i]);
				if(count==0) store.push_back(1);
				else if(count==1) store.push_back(0);
				else store.push_back(count);
				++count;
			}
			else {
				if(ind==0) store.push_back(1);
				else if(ind==1) store.push_back(0);
				else store.push_back(ind);
			}
		}
		count=(count<=1)?2:count;
		int sum=0;
		for(int i=0;i<store.size();++i)
			sum=store[i]+count*sum;

		save << "Case #" << t+1 <<": " << sum << endl;
	}

	return 0;


}



