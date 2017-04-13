#include <cstdio>
#include <cstdlib>

typedef struct Bot_press{
	int but_press;
	int seq_num;
	bool next;
} next_move;

int main(int argc, char** argv){
	FILE* fi_ptr = fopen("A-large.in", "r");
	FILE* fo_ptr = fopen("output.txt", "w");
	char* line = new char[9000];
	fgets(line, 8999, fi_ptr);
	// get no of iterations/cases
	int num_iter = atoi(line);
	char value[100];
	for(int l=0; l < num_iter ; l++){
		// no. of button presses
		int pos = 0;
		fgets(line, 8999, fi_ptr);
		sscanf(line, "%s", value);
		pos++;
		for(int m=0; value[m] != '\0' ; m++, pos++);
		int n_butpress = atoi(value);
		next_move* orange = new next_move[n_butpress];
		next_move* blue = new next_move[n_butpress];
		int o_no = 0;
		int b_no = 0;
		for(int i=0 ; i < n_butpress ; i++){
			//int fp_pos=0;
			sscanf(line+pos, "%s", value);
			if(value[0] == 'O'){
				pos++;
				for(int m=0; value[m] != '\0' ; m++, pos++);
				sscanf(line+pos, "%s", value);
				orange[o_no].but_press = atoi(value);
				orange[o_no].seq_num = (i+1);
				orange[o_no].next = true;
				o_no++;
			}
			else if (value[0] == 'B'){
				pos++;
				for(int m=0; value[m] != '\0' ; m++, pos++);
				sscanf(line+pos, "%s", value);
				blue[b_no].but_press = atoi(value);
				blue[b_no].seq_num = (i+1);
				blue[b_no].next = true;
				b_no++;
			}
			pos++;
			for(int m=0; value[m] != '\0' ; m++, pos++);
		}
		if(b_no > 0)
			blue[b_no - 1].next = false;
		if(o_no > 0)
			orange[o_no - 1].next = false;
		
		/*for(int i=0 ; i < o_no ; i++){
			printf("O %d at seq %d   ", orange[i].but_press, orange[i].seq_num);
		}

		for(int i=0 ; i < b_no ; i++){
			printf("B %d at seq %d   ", blue[i].but_press, blue[i].seq_num);
		}
		printf("\n");*/
		int o_curr_loc = 1;
		int b_curr_loc = 1;
		int next_o_dest = 0;
		int next_b_dest = 0;
		int o_dest;
		if(o_no)
			o_dest = orange[next_o_dest].but_press;
		else
			o_dest = -1;
		int b_dest;
		if(b_no)
			b_dest = blue[next_b_dest].but_press;
		else
			b_dest = -1;
		bool b_press = true;
		int time = 0;
		if( o_no > 0 && orange[0].seq_num == 1)
			b_press = false;
		int curr_seq = 0;
		bool button_pressed = false;
		while(curr_seq < n_butpress && (b_dest > 0 || o_dest > 0) &&(orange[next_o_dest].seq_num <= n_butpress || blue[next_b_dest].seq_num <= n_butpress)){
			button_pressed = false;
			if(o_dest > 0 &&orange[next_o_dest].next)
				o_dest = orange[next_o_dest].but_press;
			if(b_dest > 0 && blue[next_b_dest].next)
				b_dest = blue[next_b_dest].but_press;
			if(o_dest > 0){
				if( (o_dest - o_curr_loc) != 0 )
					if( (o_dest - o_curr_loc) > 0)
						o_curr_loc++;
					else
						o_curr_loc--;
				else if( !b_press){
					curr_seq++;
					if(orange[next_o_dest].next)
						o_dest = orange[++next_o_dest].but_press;
					else{
						o_dest = -1;
						orange[next_o_dest].seq_num = n_butpress + 1;
					}
					if(b_no > 0 && orange[next_o_dest].seq_num > blue[next_b_dest].seq_num )
						b_press = true;
						button_pressed = true;
				}
			}
			if(b_dest > 0){
				if( (b_dest - b_curr_loc) != 0 )
					if( (b_dest - b_curr_loc) > 0)
						b_curr_loc++;
					else
						b_curr_loc--;
				else if( b_press && !button_pressed){
					curr_seq++;
					if(blue[next_b_dest].next)
						b_dest = blue[++next_b_dest].but_press;
					else{
						b_dest = -1;
						blue[next_b_dest].seq_num = n_butpress +1;
					}
					if(o_no > 0 && orange[next_o_dest].seq_num < blue[next_b_dest].seq_num )
						b_press = false;
				}
			}
			time++;
		}
		fprintf(fo_ptr, "Case #%d: %d\n", (l+1), time);
		if(orange)
		delete [] orange;
		if(blue)
		delete [] blue;
	}	
	//getchar();
	delete [] line;
	fclose(fi_ptr);
	fclose(fo_ptr);
	return 0;
}