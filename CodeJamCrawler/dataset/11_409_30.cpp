#include <iostream>
#include <fstream>
#include <list>
#include <cmath>


using namespace std;

struct Goal{
	int destination;
	char robot;
};

list<Goal> sequence;

list<Goal>::iterator getFirstOrange(){
	list<Goal>::iterator z;
	for(z=sequence.begin(); z != sequence.end(); ++z){
		if ((*z).robot == 'O'){
			return z;
		}

	}
	return sequence.end();
}

list<Goal>::iterator getFirstBlue(){
	list<Goal>::iterator z;
	for(z=sequence.begin(); z != sequence.end(); ++z){
		if ((*z).robot == 'B'){
			return z;
		}

	}
	return sequence.end();
}

int main(){

	int Blue = 1;
	int Orange = 1;
	int steps = 0;
	int col;
	int rows;
	list<Goal>::iterator orangeDest;
	list<Goal>::iterator blueDest;




	ofstream outputFile;
	ifstream inputFile;

	inputFile.open("in.txt");
	outputFile.open("out.txt");


	if (inputFile.is_open())
	{
		inputFile >> rows;
		for (int i = 0; i < rows; i++){
			steps = 0;
			inputFile >> col;

			for (int k = 0; k < col; k++){
				struct Goal temp;
				inputFile>>temp.robot;
				inputFile>>temp.destination;
				sequence.push_back(temp);
			}
			for (int h = 0; h<col; h++){
				if(sequence.begin()->robot == 'B'){
					orangeDest = getFirstOrange();
					blueDest = sequence.begin();
					steps += abs(blueDest->destination - Blue)+1;
					if(orangeDest != sequence.end()){
						if (abs(orangeDest->destination - Orange) <= (abs(blueDest->destination - Blue)+1)){
							Orange = orangeDest->destination;
						} else if (Orange > orangeDest->destination) {
							Orange-= abs(blueDest->destination - Blue)+1;
						} else if(Orange < orangeDest->destination){
							Orange+= abs(blueDest->destination - Blue)+1;
						} else {
							//do nothing
						}
					}
					Blue = blueDest->destination;
				} else if(sequence.begin()->robot == 'O'){
					blueDest = getFirstBlue();
					orangeDest = sequence.begin();
					steps += abs(orangeDest->destination - Orange)+1;
					if(blueDest != sequence.end()){
						if (abs(blueDest->destination - Blue) <= (abs(orangeDest->destination - Orange)+1)){
							Blue = blueDest->destination;
						} else if (Blue > blueDest->destination) {
							Blue-= abs(orangeDest->destination - Orange)+1;
						} else if(Blue < blueDest->destination){
							Blue+= abs(orangeDest->destination - Orange)+1;
						} else {
							//do nothing
						}
					}
					Orange = orangeDest->destination;
				}
				sequence.pop_front();
			}
			sequence.clear();
			Orange = 1;
			Blue = 1;
			outputFile<<"Case #"<<i+1<<": "<<steps<<endl;
			//cout<<"STEPS: "<<steps<<endl;


		}

		inputFile.close();
		outputFile.close();
	}
	std::cout<<"Finished!!!\n";


	return 0;
}
