#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>

struct Data{
	int r;
	int c;
	std::vector<char> data;
};

std::string trial(const Data& in){
	std::vector<char> large((in.r+2)*(in.c+2),'.');
	std::vector<char> result=in.data;
	bool impossible=false;

	for(int y=0;y<in.r;y++){
		for(int x=0;x<in.c;x++){
			std::cerr << in.data[y*in.c+x] << " ";
		}
		std::cerr << std::endl;
	}

	for(int y=0;y<in.r+2;y++){
		if(y==0 || y==in.r+1)continue;
		for(int x=0;x<in.c+2;x++){
			if(x==0 || x==in.c+1) continue;
			large[y*(in.c+2)+x]=in.data[(y-1)*in.c+(x-1)];
		}
	}

	std::cerr << "-- large --" << std::endl;
	for(int y=0;y<in.r+2;y++){
		for(int x=0;x<in.c+2;x++){
			std::cerr << large[y*(in.c+2)+x] << " ";
		}
		std::cerr << std::endl;
	}

	std::cerr << "-- end --" << std::endl;

	int height=in.r+2;
	int width=in.c+2;
	for(int y=0;y<height;y++){
		if(y==0 || y==in.r+1)continue;
		for(int x=0;x<width;x++){
			if(x==0 || x==in.c+1) continue;
			if(large[y*width+x]!='#')continue;
			if(large[(y-1)*width+x-1]!='.')continue;
			if(large[(y-1)*width+x]!='.')continue;
			if(large[y*width+x-1]!='.')continue;
			
			if(large[(y+1)*width+x+1]!='#'){impossible=true;break;}
			if(large[(y+1)*width+x]!='#'){impossible=true;break;}
			if(large[y*width+x+1]!='#'){impossible=true;break;}
			
			
			large[y*width+x]='.';
			large[(y+1)*width+x+1]='.';
			large[(y+1)*width+x]='.';
			large[y*width+x+1]='.';

			result[(y-1)*in.c+(x-1)]='/';
			result[y*in.c+(x-1)]='\\';
			result[(y-1)*in.c+x]='\\';
			result[y*in.c+x]='/';
		}
		if(impossible)break;
	}

	for(int y=0;y<in.r;y++){
		for(int x=0;x<in.c;x++){
			if(result[y*in.c+x]=='#'){
				impossible=true;break;
			}
		}
	}

	std::ostringstream oss;
	oss << std::endl;
	
	if(impossible){
		oss << "Impossible" << std::endl;
	}else{
		for(int y=0;y<in.r;y++){
			for(int x=0;x<in.c;x++){
				oss << result[y*in.c+x];
			}
			oss << std::endl;
		}
	}
	return oss.str();
}

int main(int argc, char **argv){
	std::string str;
	int t;

	std::cin >> t;
	std::vector<Data> query(t);
	for(int i=0;i<t;i++){
		std::cin >> query[i].r;
		std::cin >> query[i].c;
		int size=query[i].r*query[i].c;
		char c;
		query[i].data.resize(size);
		for(int j=0;j<size;j++){
			std::cin >> c;
			query[i].data[j]=c;
		}
	}

	std::vector<std::string> result(t);
#ifdef _OPENMP
#pragma omp parallel for
#endif
	for(int i=0;i<t;i++){
		result[i]=trial(query[i]);
	}

	for(int i=0;i<t;i++){
		std::cout << "Case #" << i+1 << ":" << result[i];
	}
	return 0;
}
