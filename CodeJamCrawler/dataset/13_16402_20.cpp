#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Lawn {
public:
	Lawn(int width, int length){
		w = width;
		l = length;
		lawn = new vector<vector<int> >(width);
		crossed = new vector<vector<bool> >(width);

		for(int i=0; i<width; i++){
			vector<int> x(length);
			vector<bool> y(length);
			lawn->at(i) = x;
			crossed->at(i) = y;
		}		
	};

	~Lawn(){};

	void setHeight(int x, int y, int height){
		lawn->at(x)[y] = height;
	};

	int getHeight(int x, int y){
		return lawn->at(x)[y];
	};

	void print(){
		for(int i=0; i<w; i++){
			for(int j=0; j<l; j++){
				cout<<getHeight(i,j)<<" ";
			}
			cout<<endl;
		}
	};

	bool canDoPattern();

private:
	vector<vector<int> >* lawn;
	vector<vector<bool> >* crossed;
	int w;
	int l;
	void update_marked(int h);
	bool checkRow(int rowNum, int h);
	bool checkColumn(int colNum, int h);
	bool checkBoard();
};

struct block {
	int x;
	int y;
	int height;
};

bool sortBlock(const block& a, const block& b){
	return a.height < b.height;
}

void Lawn::update_marked(int height){
	for(int i=0; i<w; i++){
		for(int j=0; j<l; j++){
			if(crossed->at(i)[j]==true){
				setHeight(i, j, height);
				crossed->at(i)[j]= false;
			}
		}
	}
}

bool Lawn::checkRow(int rowNum, int h){
	for(int i=0; i<l; i++){
		if(getHeight(rowNum,i)!=h)
			return false;
	}
	for(int i=0; i<l; i++){
		crossed->at(rowNum)[i]=true;
	}
	return true;
};

bool Lawn::checkColumn(int colNum, int h){
	for(int i=0; i<w; i++){
		if(getHeight(i,colNum)!=h)
			return false;
	}
	for(int i=0; i<w; i++){
		crossed->at(i)[colNum]=true;
	}
	return true;
};

bool Lawn::checkBoard(){
	int h = getHeight(0,0);
	for(int i=0; i<w; i++){
		for(int j=0; j<l; j++){
			if(getHeight(i,j)!=h){
				return false;
			}
		}
	}
	return true;
};

bool Lawn::canDoPattern(){
	vector<block> border(w+l-1); 
	block bl;
	for(int i=0; i<w; i++){
		bl.x = i;
		bl.y = 0;
		bl.height = getHeight(i,0);
		border[i] = bl;
	}

	for(int i=1; i<l; i++){
		bl.x = 0;
		bl.y = i;
		bl.height = getHeight(0,i);
		border[i+w-1] = bl;
	}
	sort(border.begin(), border.end(), sortBlock);
	//for(int i=0; i< border.size(); i++){
	//	cout<<border[i].x<<" "<<border[i].y<<" "<<border[i].height<<endl;
	//}

	vector<block> rankHeight(w*l); 
	for(int i=0; i<w; i++){
		for(int j=0; j<l; j++){
			rankHeight[i*l+j].height = getHeight(i,j);
			rankHeight[i*l+j].x = i;
			rankHeight[i*l+j].y = j;
		}
	}
	sort(rankHeight.begin(),rankHeight.end(), sortBlock);
	sort(border.begin(), border.end(), sortBlock);
	//for(int i=0; i< border.size(); i++){
	//	cout<<border[i].x<<" "<<border[i].y<<" "<<border[i].height<<endl;
	//}
	for(int i=0; i< rankHeight.size(); i++){
		cout<<rankHeight[i].height<<endl;
	}
	int lastHeight = border[0].height;
	int maxHeight = border[border.size()-1].height;
	int current = 0;
	while(1){
		while(border[0].height!=border[border.size()-1].height || border[border.size()-1].height!=rankHeight[rankHeight.size()-1].height){
			if(current >= border.size()){
				break;
			}
			if(border[current].height!=lastHeight){
				update_marked(border[current].height);
				//update border structure
				for(int i=0; i<current; i++){
					border[i].height = getHeight(border[i].x, border[i].y);
				}
				current = 0;
				lastHeight = border[0].height;
			} else {
				bool rowCheck = checkRow(border[current].x, lastHeight);
				bool colCheck = checkColumn(border[current].y, lastHeight);
				if( rowCheck || colCheck ){
					current++;
				} else {
					return false;
				}
			}
		}
		if(border[0].height==border[border.size()-1].height){
			for(int i=0; i<rankHeight.size(); i++){
				rankHeight[i].height = getHeight(rankHeight[i].x, rankHeight[i].y);
			}
			for(int k=0; k<rankHeight.size(); k++){
				if(border[0].height > rankHeight[k].height){
					return false;
				} 
				if(rankHeight[k].height>lastHeight)
				{
					update_marked(rankHeight[k].height);
					//update border structure
					for(int i=0; i<border.size(); i++){
						border[i].height = rankHeight[k].height;
					}
					//update rankHeight
					for(int i=0; i<rankHeight.size(); i++){
						rankHeight[i].height = getHeight(rankHeight[i].x, rankHeight[i].y);
					}
					current = 0;
					lastHeight = border[0].height;
					break;
				}
			}
		}
		if(rankHeight[rankHeight.size()-1].height == rankHeight[0].height){
			break;
		}
	}
	return checkBoard();
}

int main() {
	ifstream input("B-small-attempt0.in");
	ofstream output("output.out");
	string inputLine;

	if(input.is_open()&&output.is_open()){
		getline(input, inputLine);
		int size = atoi(inputLine.c_str());
		int width, length;
		for(int i=0; i<size; i++){
			getline(input, inputLine,' ');
			width = atoi(inputLine.c_str());
			getline(input, inputLine,'\n');
			length = atoi(inputLine.c_str());
			Lawn* l = new Lawn(width, length);
			for(int k=0; k<width; k++){
				for(int j=0; j<length; j++){
					if(j!=length-1){
						getline(input, inputLine,' ');
					} else {
						getline(input, inputLine,'\n');
					}
					l->setHeight(k,j,atoi(inputLine.c_str()));
				}			
			}
			l->print();
			if(l->canDoPattern()){
				output <<  "Case #"; output << i+1; output << ": YES\n";
			} else {
				output <<  "Case #"; output << i+1; output << ": NO\n";
			}

		}
	}
	system("PAUSE");
}