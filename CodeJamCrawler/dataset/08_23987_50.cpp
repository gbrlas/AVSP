#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 100
#define Q 1000

int clear (int *arr) {
	int iter;
	for (iter = 0; iter < S; iter ++)
		arr[iter] = 0;
	return 0;
}

int get_match (char Server_List[][512], int Number_Of_Servers, char Query[]) {
	int iter;
	for (iter = 0; iter < Number_Of_Servers; iter ++) {
		if (! strcmp (Server_List[iter], Query))
			return iter;
	}
	return -1;
}
int findOptimal (char Server_List[][512], char Query_List[][512], int NS, int NQ, int index, char Current_Server[]) {
	int val, check [S], count = 0, iter;
	clear (check);
	for (iter = index; iter < NQ; iter ++) {
		val = get_match (Server_List, NS, Query_List[iter]);
		if (check[val] == 0 && count < NS - 1) {
			check [val] = 1; count ++;
		}
	}
	for (iter = 0; iter < NS; iter ++) 
		if (check[iter] == 0) {
			strcpy (Current_Server, Server_List[iter]);
			return iter;
		}
}
int find_switch (char Server_List[][512], char Query_List[][512], \
			int Number_Of_Servers, int Number_Of_Queries)  {
	int query, switch_count = 0;
	char Current_Server [512];
	findOptimal (Server_List, Query_List, Number_Of_Servers, Number_Of_Queries, query, Current_Server);
//	printf ("Current Server: %s \n", Current_Server);
  	for ( query = 0; query < Number_Of_Queries; query ++) {
		if ( !strcmp (Query_List[query], Current_Server)) {
			switch_count ++;
			findOptimal (Server_List, Query_List, Number_Of_Servers, Number_Of_Queries, 
									query, Current_Server);
// 			printf ("Current Server: %s", Current_Server);
		}
	}
	return switch_count;
}

int SaveUniverse (char *filename) {
	FILE *fpIn, *fpOut;
	char Server_List[S][512], Query_List[Q][512];
	int Number_Of_Inputs, Number_Of_Servers, Number_Of_Queries, iter, server, query;
	fpIn = fopen (filename, "r"); fpOut = fopen ("Output", "w");
	fscanf (fpIn, "%d", &Number_Of_Inputs);
	for (iter = 0; iter < Number_Of_Inputs; iter ++) {
		fscanf (fpIn, "%d\n", &Number_Of_Servers);
		for (server = 0; server < Number_Of_Servers; server ++) {
			fgets (Server_List [server], 512, fpIn);
		}
		fscanf (fpIn, "%d\n", &Number_Of_Queries);
		for (query = 0; query < Number_Of_Queries; query ++) {
			fgets (Query_List [query], 512, fpIn);
		}
		// implementing optimal scheduling
		fprintf (fpOut, "Case #%d: %d\n",iter + 1, find_switch (Server_List, Query_List, \
								Number_Of_Servers, Number_Of_Queries));
	}
	return 0;
}
int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf ("Invalid arguments .... \n usage SavingUniverse <Input File>\n");
		exit (1);
	}
	else SaveUniverse (argv[1]);
	return 0;
}