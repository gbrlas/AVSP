#include <fstream>
#include <string>
using namespace std;

struct node
{  
	char ch;
	node *parent;
	node *sibling;
	node *child;	// point to the left most child
};

void addWord (node*, int, string);
int searchWord (node*, string);

int main ()
{

	// Generic file instantiations
	ifstream input;
	ofstream output;
	
	string inputname, outputname;
	
	inputname = "alien_input.in";
	outputname = "alien_output.out";
	input.open (inputname.c_str ());
	output.open (outputname.c_str ());
	
	// Input read
	int L, D, N; // L: word length, D: dictionary length, N: number of test cases
	
	input >> L >> D >> N;

	// Create Tree	
	node* header = new node;
	header->ch = ' '; header->child = NULL; header->parent = NULL; header->sibling = NULL;
	
	string str;

	for(int i = 0; i < D; i++)
	{
		input >> str;
		addWord(header, L, str);
	}

	// Search Test Cases
	for(int j = 1; j <= N; j++)
	{
		input >> str;
		output << "Case #" << j << ": " << searchWord(header->child, str) << endl;
	}

	input.close();
	output.close();
	return 0;
}

void addWord (node* header, int word_length, string word)
{
	node* current_node;
	current_node = header;

	bool exist;

	for(int i = 0; i < word_length; i++)
	{
		if (current_node->child == NULL)
		{
			current_node->child = new node;
			current_node->child->ch = word[i];
			current_node->child->parent = current_node;
			current_node->child->sibling = NULL;
			current_node->child->child = NULL;

			current_node = current_node->child;
		}
		else
		{
			exist = false;

			current_node = current_node->child;

			while(!exist)
			{
				if (current_node->ch == word[i])
				{
					exist = true;
				}
				else if (current_node->sibling != NULL)
				{
					current_node = current_node->sibling;
				}
				else
				{
					current_node->sibling = new node;
					current_node->sibling->ch = word[i];
					current_node->sibling->parent = current_node->parent;
					current_node->sibling->sibling = NULL;
					current_node->sibling->child = NULL;

					current_node = current_node->sibling;

					exist = true;
				}
			}
		}
	}
}

int searchWord (node* header, string sequence)
{
	int start_pos = 0, current_pos, end_pos = 0;
	int totalFound = 0;

	node* current_node;
	current_node = header;

	bool end_reached = false;

	if (sequence[0] == '(') // end & current positions are kept at 0 if condition not met
	{
		int i = 3;
		while (end_pos == 0)
		{
			if (sequence[i] == ')')
			{
				end_pos = i;
			}
			i++;
		}

		start_pos = 1;
	}

	while (!end_reached)
	{
		current_pos = start_pos;
		do
		{
			if (current_node->ch == sequence[current_pos])
			{
				if (current_node->child != NULL)
				{
					totalFound = totalFound + searchWord(current_node->child, sequence.substr(end_pos+1));
				}
				else
				{
					totalFound++;
				}
			}
			current_pos++;
		} while (current_pos < end_pos);
			
		if (current_node->sibling != NULL)
		{
			current_node = current_node->sibling;
		}
		else
		{
			end_reached = true;
		}
	}

	return totalFound;
}


