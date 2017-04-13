#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cmath>

using namespace std;
#define LIM 1002
int data[LIM];
bool visited[LIM];

int d;
vector<int> digits;
vector<int> temp;
void exec(int i){
	temp.clear();
	digits.clear();
	while(i!=0){
		d=i%10;
		temp.push_back(d);
		i=i/10;
		}
	for(int j=temp.size()-1; j>=0; j--){ digits.push_back(temp[j]);};
	//for(int i=0; i<digits.size(); i++) cout<<digits[i]<<" ";
	}

void gen(int& count, int a, int b, int n){
	d=digits.size();
	int p=d, num=0, o;
	bool unique=0;
	o=digits[0];
	for(int i=1;i<digits.size(); i++){if (digits[i]!=o) unique=1;}
	if (unique){
        //cout<<"for "<<n<<endl;
	for(int i=1; i<d; i++){
		num=0;
		for(int j=0; j<d; j++){
			num+=(int)pow(10, p-1-j)*digits[(i+j)%d];
			}
		int size_of_num=0, k=num;
		while(k!=0){ k=k/10; size_of_num++;}
		if (size_of_num==d){
		//cout<<num<<endl;
            if (num>n and num>=a and num<=b) {count++;
            //cout<<"count now is"<<count<<endl;
            }
		}
	}
	}

	/*
	if (!visited[num]){
	for(int i=num; i<LIM; i++){
		num[i]+=1;
		}
	}*/
}


int main(){
	int t, a, b,count=0;
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
	scanf("%d %d", &a, &b);
    count=0;
    for(int j=a; j<=b; j++){
		
		//if (j%10!=0){
		//cout<<endl<<"for <<"<<j<<endl;
		exec(j);
		gen(count, a, b, j);
    }
    printf("Case #%d: %d\n", i, count);
    }
    
	
	return 0;

	}

