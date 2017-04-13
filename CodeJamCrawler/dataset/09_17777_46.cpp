#include <iostream>
#include <fstream>

using namespace std;

static const int MAX_ANIMALS = 100;
static const int MAX_FEATURES = 100;

struct Node
{
	double p;
	char feature[32];
	Node * left;
	Node * right;

	Node() :
	p(0),
	left(NULL),
	right(NULL)
	{
	}
};

int numCases;
int treeLines;
int numAnimals;
int numFeatures;
char features[MAX_FEATURES][32];
char animal[32];

Node * root = NULL;

void printTree(Node * tree, int level)
{
	for ( int i = 0; i < level; i ++ )
	{
		cout << "  ";
	}
	cout << tree->p << " " << tree->feature << endl;
	if ( tree->left )
	{
		printTree(tree->left, level + 1);
	}
	if ( tree->right )
	{
		printTree(tree->right, level + 1);
	}
}

void cleanTree(Node ** tree)
{
	if ( (*tree)->left )
	{
		cleanTree(&((*tree)->left));
	}
	if ( (*tree)->right )
	{
		cleanTree(&((*tree)->right));
	}
	
	delete(*tree);
	*tree = NULL;
}

void extractNode(ifstream & fileIn, Node ** node)
{
	char c;
	fileIn >> c;
	if ( c == '(' )
	{
		*node = new Node();
		fileIn >> (*node)->p;
		fileIn >> c;
		if ( c == ')' )
		{	// Leaf node. 
		} else
		{	// Non-leaf.
			(*node)->feature[0] = c;
			char a = fileIn.peek();
			if ( isspace(a) || a == '(' )
			{
				(*node)->feature[1] = 0;
			} else
			{
				fileIn >> &((*node)->feature[1]);
			}
			extractNode(fileIn, &((*node)->left));
			extractNode(fileIn, &((*node)->right));
			
			fileIn >> c;	// matching ')'
		}
	}
}

void extractTree(ifstream & fileIn)
{
	fileIn >> treeLines;
	extractNode(fileIn, &root);
}

double process(Node * node, double x)
{
	if ( node )
	{
		if ( node->left )
		{	// Not leaf.
			bool match = false;
			for ( int i = 0; i < numFeatures; i++ )
			{
				if ( strcmp(node->feature, features[i]) == 0 )
				{
					match = true;
					break;
				}
			}
			if ( match )
			{
				return node->p * process(node->left, x);
			} else
			{
				return node-> p * process(node->right, x);
			}
		} else
		{
			return x * node->p;
		}
	} else
	{
		return x;
	}
}

int main (int argc, char * const argv[]) 
{
	if ( argc != 2 ) return -1;
	
	ifstream fileIn(argv[1], ifstream::in);
	
	if ( fileIn.good() == false ) return -1;
	
	fileIn >> numCases;
	for ( int caseIndex = 0; caseIndex < numCases; caseIndex++ )
	{
		cout << "Case #" << caseIndex + 1 << ": " << endl;
		extractTree(fileIn);
//		printTree(root, 0);
		
		fileIn >> numAnimals;
		for ( int animalIndex = 0; animalIndex < numAnimals; animalIndex++ )
		{
			fileIn >> animal >> numFeatures;
			for ( int featureIndex = 0; featureIndex < numFeatures; featureIndex++ )
			{
				fileIn >> features[featureIndex];
			}
			
			cout << process(root, 1.0) << endl;
		}
		
		cleanTree(&root);
	}
	
	fileIn.close();
	return 0;
}


