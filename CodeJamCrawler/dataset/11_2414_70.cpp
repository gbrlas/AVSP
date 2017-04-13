#include <stdio.h>
#include <stdlib.h>

#define B	0
#define O	1

#define MAX(x,y) ((x > y) ? x : y)
#define MIN(x,y) ((x < y) ? x : y)

typedef struct command_s command_t;
typedef struct robot_s robot_t;

struct robot_s {
	int position;
	command_t *cmdlist;
	robot_t *oth;
};

struct command_s {
	int robot;
	int button;
	int n;
	
	command_t *next;
};

int main(int argc, char *argv[]) {
	FILE *in, *out;
	int lines;
	int commands;
	int n;
	robot_t robot[2];
	
	if(argc != 3) {
		return(1);
	}
	
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w+");
	
	if(!in || !out) {
		return(1);
	}
	
	fscanf(in, "%d", &lines);
	printf("%d lines\n", lines);
	for(n = 0; n < lines; n++) {
		command_t *c;
		int ttime, m;
		robot_t *rob;
		
		ttime = 0;
		rob = NULL;
		robot[O].cmdlist = NULL;
		robot[B].cmdlist = NULL;
		robot[O].position = 1;
		robot[B].position = 1;
		robot[O].oth = &robot[B];
		robot[B].oth = &robot[O];
		
		fscanf(in, "%d", &commands);
		printf("%d commands\n", commands);
		for(m = 0; m < commands; m++) {
			command_t *cmd;
			char r;
			
			cmd = malloc(sizeof(command_t));
			cmd->robot = -1;
			cmd->button = 0;
			cmd->n = m;
			cmd->next = NULL;
			
			fscanf(in, " %c %d", &r, &cmd->button);
			switch(r) {
				case 'O':
					cmd->robot = O;
					break;
				case 'B':
					cmd->robot = B;
					break;
				default:
					printf("Oops...\n");
			}
			if(robot[cmd->robot].cmdlist) {
				command_t *p = robot[cmd->robot].cmdlist;
				
				while(p->next) {
					p = p->next;
				}
				p->next = cmd;
			} else {
				robot[cmd->robot].cmdlist = cmd;
			}
			if(!rob) { /* this robot has the first command */
				rob = &robot[cmd->robot];
			}
		}
		m = 0;
		c = robot[O].cmdlist;
		while(c) { c = c->next; m++; }
		printf("Rob[O] has %d commands\n", m);
		m = 0;
		c = robot[B].cmdlist;
		while(c) { c = c->next; m++; }
		printf("Rob[B] has %d commands\n", m);
		m = 0;
		
		while(rob->cmdlist || rob->oth->cmdlist) {
			int btn_pressed = 0;
			
			if(rob->cmdlist) {
				if(rob->position < rob->cmdlist->button) {
					rob->position++;
				} else if(rob->position > rob->cmdlist->button) {
					rob->position--;
				} else {
					if(rob->cmdlist->n == m) {
						/* press button */
						command_t *cur;
						btn_pressed = 1;
					
						cur = rob->cmdlist;
						rob->cmdlist = rob->cmdlist->next;
						printf("Button %d pressed after %ds [Rob %d]\n", cur->button, ttime, cur->robot);
						free(cur);
					}
					/* else wait */
				}
			}
			if(rob->oth->cmdlist) {
				if(rob->oth->position < rob->oth->cmdlist->button) {
					rob->oth->position++;
				} else if(rob->oth->position > rob->oth->cmdlist->button) {
					rob->oth->position--;
				} else {
					if(rob->oth->cmdlist->n == m) {
						/* press button */
						command_t *cur;
						btn_pressed = 1;
					
						cur = rob->oth->cmdlist;
						rob->oth->cmdlist = rob->oth->cmdlist->next;
						printf("Button %d pressed after %ds [Rob %d]\n", cur->button, ttime, cur->robot);
						free(cur);
					}
					/* else wait */
				}
			}
			if(btn_pressed) {
				m++;
			}
			
			ttime++;
		}
		fprintf(out, "Case #%d: %d\n", n+1, ttime);
	}
	fclose(in);
	fclose(out);
	return(0);
}
