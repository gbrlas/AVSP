#include <iostream>

int abs(int a){
	if(a<0)
		return a*(-1);
	return a;
}

int main(){
	int t,n,curr,currO,currB,seg,segO,segB;
	char bot;

	std::cin>>t;
	for (int i = 0; i < t; i++) {
		std::cin>>n;
		currB=currO=1;
		seg=segO=segB=0;
		for (int j = 0; j < n; j++) {
			std::cin>>bot;
			if (bot=='O'){
				std::cin>>curr;
				segO+=abs(curr-currO)+1;
				if(segO>seg){
					seg=segO;
				}else{
					seg++;
					segO=seg;
				}
				currO=curr;
			}else{
				std::cin>>curr;
				segB+=abs(curr-currB)+1;
				if(segB>seg){
					seg=segB;
				}else{
					seg++;
					segB=seg;
				}
				currB=curr;
			}
		}
		std::cout<<"Case #"<<i+1<<": "<<seg<<std::endl;
	}
}
