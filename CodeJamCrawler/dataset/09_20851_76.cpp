#include <vector>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;
class UnionFind {
	struct Node {
		int data;
		int index;
		Node *parent;
	};
	vector< Node * > nodes;
	int numElements;
	int numSets;
public:
	UnionFind(int count) {
		numElements = 0;
		numSets = 0;
		addElements(count);
	}
	int findSet(int elementId) {
		Node *currentNode = nodes[elementId];
		while (currentNode->parent != NULL)
			currentNode = currentNode->parent;
		return currentNode->index;
	}
	void unite(int elementId0, int elementId1) {
		int setId0 = findSet(elementId0);
		int setId1 = findSet(elementId1);
		if (setId0 == setId1)
			return;
		Node *set0 = nodes[setId0];
		Node *set1 = nodes[setId1];
		set1->parent = set0;
		numSets--;
	}
	void addElements(int count) {
		nodes.insert(nodes.end(), count, (Node *)NULL);
		for (int i = numElements; i < numElements + count; i++) {
			nodes[i] = new Node();
			nodes[i]->index = i;
			nodes[i]->parent = NULL;
		}
		numElements += count;
		numSets += count;
	}
	int getNumSets(void) {
		return numSets;
	}
	int getNumElements(void) {
		return numElements;
	}
	int getParentIndex(int elementId) {
		int setId = findSet(elementId);
		Node *set = nodes[setId];
		return set->index;
	}
};
int main(int argc, char **argv) {
	int T;
	ifstream fin(argv[1]);
	fin >> T;
	for (int t = 0; t < T; t++) {
		int H, W;
		fin >> H >> W;
		vector< int > altitudes(H*W);
		for (int h = 0; h < H; h++)
			for (int w = 0; w < W; w++)
				fin >> altitudes[h*W+w];

		UnionFind uf(H*W);
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				int min = altitudes[h*W+w];
				int downTo = -1;
				for (int i = h-1; i <= h+1; i++) {
					if (i < 0 or i >= H)
						continue;
					for (int j = w-1; j <= w+1; j++) {
						if (j < 0 or j >= W)
							continue;
						if (i != h and j != w)
							continue;
						if (min > altitudes[i*W+j]) {
							min = altitudes[i*W+j];
							downTo = i*W+j;
						}
					}
				}
				if (downTo != -1) {
					int x = (h*W+w < downTo) ? h*W+w : downTo;
					int y = (h*W+w < downTo) ? downTo : h*W+w;
					uf.unite(x, y);
				}
			}
		}

		cout << "Case #" << t+1 << ":" << endl;
		map< int, char > table;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				int basin = uf.getParentIndex(h*W+w);
				if (table.find(basin) == table.end())
					table[basin] = 'a' + (char)table.size();
				cout << table[basin] << ((w+1 < W) ? " " : "");
			}
			cout << endl;
		}
	}
	return 0;
}
