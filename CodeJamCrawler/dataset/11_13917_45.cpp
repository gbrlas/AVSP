#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

struct instruction {
	char robot;
	int button;

	instruction(int robot, int button) {
		this->robot = robot;
		this->button = button;
	}

	
};

int main() {
	ifstream in("in.txt");
	FILE *out = fopen ("out.txt", "w");

	if (in == NULL || out == NULL) {
		return EXIT_FAILURE;
	}

	int n;
	in >> n;

	for (int z = 0; z < n; z++) {
		int n2;
		in >> n2;
		printf("Instructions: %d\n", n2);

		vector<instruction> instructions;

		for (int y = 0; y < n2; y++) {
			char robotType;
			int button;

			in >> robotType >> button;

			int robot = (robotType == 'O' ? 0 : 1);
			printf("Move %c to %d\n", robotType, button);

			instructions.push_back(instruction(robot, button));	
		}
		
		long int steps = 0;
		int mover = 0; // robot O
		int locations[2] = { 1, 1 }; // store where they are
		int startTurn = -1;
		int turn = -1;

		for (int i = 0; i < instructions.size(); i++) {
			int mover = instructions[i].robot;
			
			int lol;
			// get next robot move (if exists)
			for (int b = i; b < instructions.size(); b++) {
			   if (mover != instructions[b].robot) {
			      lol = b;
			      break;
			   }
			}
			

			
			if (turn == -1) {
				startTurn = mover;
				turn = mover;
			}

bool end = true;
			while (end) {
				// if button is at destination
		//		if (turn == startTurn) {
					steps++;
				//	printf(" -- TURN!\n");
	//			}

				if (instructions[i].button == locations[mover]) {
				//	printf("FOUND!\n");
//			      turn = (turn + 1) % 2;
			      
end = false;
				} else if (instructions[i].button < locations[mover]) {
				//	printf("Moving Back\n");
					locations[mover] --; // move back
				} else if (instructions[i].button > locations[mover]) {
				//	printf("Moving Forward\n");
					locations[mover] ++; // move forward
				}
					
				
				if (instructions[lol].button == locations[(mover + 1) % 2]) {
				//	printf("FOUND! But staying.\n");
				} else if (instructions[lol].button < locations[(mover + 1) % 2]) {
				//	printf("Moving Back\n");
					locations[(mover + 1) % 2] --; // move back
				} else if (instructions[lol].button > locations[(mover + 1) % 2]) {
				//	printf("Moving Forward\n");
					locations[(mover + 1) % 2] ++; // move forward
			   }
				

				//turn = (turn + 1) % 2;
			}
		}

		fprintf(out, "Case #%d: %ld\n", z + 1, steps);
	}

	fclose(out);

//	system("PAUSE");

	return EXIT_SUCCESS;
}