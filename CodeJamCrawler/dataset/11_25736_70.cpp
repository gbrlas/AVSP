#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>

const int STAY=0;
const int MOVE_F=1;
const int MOVE_B=-1;
const int PUSH=2;

const int ORANGE=0;
const int BLUE=1;

int compactionA(std::vector<int>& action, int zerostartpos, int zeroendpos){
	int zeropos=zerostartpos;
	int ret;
	for(int i=zeroendpos;action[i]==MOVE_F||action[i]==MOVE_B;i++){
		action[zeropos]=action[i];
		action[i]=STAY;
		zeropos++;
		ret=i;
	}
	return ret;
}

void compactionB(std::vector<int>& action,const std::vector<int>& oaction,int pushpos){
	for(int targetpos=pushpos; targetpos > 0 ; targetpos--){
		if(oaction[targetpos-1] == PUSH){
			action[targetpos]=PUSH;
			if(targetpos!=pushpos) action[pushpos]=STAY;
			break;
		}else if(action[targetpos-1] != STAY){
			action[targetpos]=PUSH;
			if(targetpos!=pushpos) action[pushpos]=STAY;
			break;
		}
	}
}

int trial(const std::string& input){
	std::istringstream iss(input);
	int num;
	int target;
	std::vector<int> robots;
	std::vector<int> targets;
	int currentpos[2]={1,1};

	iss >> num;
	for(int i=0;i<num;i++){
		char robot;
		iss >> robot;
		if(robot=='O') robots.push_back(ORANGE);
		else if(robot=='B') robots.push_back(BLUE);
		iss >> target;
		targets.push_back(target);
	}

	std::vector<std::vector<int> > actions(2,std::vector<int>());
	for(int i=0;i<num;i++){
		if(targets[i] > currentpos[robots[i]]){
			for(int j=0;j<targets[i]-currentpos[robots[i]];j++){
				actions[robots[i]].push_back(MOVE_F);
				actions[(robots[i]+1)%2].push_back(STAY);
			}
		}else{
			for(int j=0;j<currentpos[robots[i]]-targets[i];j++){
				actions[robots[i]].push_back(MOVE_B);
				actions[(robots[i]+1)%2].push_back(STAY);
			}
		}
		currentpos[robots[i]]=targets[i];
		actions[robots[i]].push_back(PUSH);
		actions[(robots[i]+1)%2].push_back(STAY);
	}

	int size=actions[robots[0]].size();
	std::vector<std::vector<int> > prevactions;

	while(prevactions!=actions){
		prevactions=actions;
		{// 0の後ろに1がある場合詰める
			for(int robot=0;robot<2;robot++){
				bool iszerocont=false;
				int zerocount=0;
				int zerostartpos=0;

				for(int i=0;i<size;i++){
					if(actions[robot][i]==STAY){
						if(iszerocont==false){
							zerostartpos=i;
						}
						iszerocont=true;
					}else if(iszerocont==true){
						if(actions[robot][i]!=PUSH)
							i=compactionA(actions[robot], zerostartpos, i);
						iszerocont=false;
					}
				}
			}
		}
		{// 0の後ろに2がある場合詰める
				int ppos=-1;
				for(int i=size-1;i>=0;i--){
					for(int robot=0;robot<2;robot++){
						if(actions[robot][i]==PUSH)
							compactionB(actions[robot],actions[(robot+1)%2],i);
					}
				}
		}
	}

	int count=0;
	for(int i=0;i<size;i++){
		if(actions[0][i]==0 && actions[1][i]==0) break;
		count++;
	}
	return count;
}

int main(int argc, char **argv){
	std::string str;
	int n;
	std::getline(std::cin,str);
	n=std::atoi(str.c_str());
	std::vector<std::string> query;
	for(int i=0;i<n;i++){
		std::getline(std::cin,str);
		query.push_back(str);
	}

#ifdef _OPENMP
#pragma omp parallel for
#endif
	for(int i=0;i<n;i++){
		std::cout << "Case #" << i+1 << ": " << trial(query[i]) << std::endl;
	}
	return 0;
}
