#include <cassert>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    double weight;
    string feature;
    vector<Node*> children;

    Node *parent;

    Node() { weight = 0.0; parent = 0; }
    ~Node() { for (int i = 0; i < children.size(); ++i) delete children[i]; }
};


Node* readTree()
{
    int l;
    cin >> l;
    char dummyNewLine;
    cin.get(dummyNewLine);

    Node *root = 0, *node = 0;
    for (int i = 0; i < l; ++i) {
        bool readWeight = false;
        string weightBuffer;
        string featureBuffer;
        weightBuffer.reserve(1024);
        while (1) {
            char ch;
            cin.get(ch);
            if (ch == '\n' || ch == '\r') {
                if (node && readWeight && weightBuffer.empty() == false) {
                    istringstream stream(weightBuffer);
                    stream >> node->weight;
                    weightBuffer.clear();
                    readWeight = false;
                } else if (node && !featureBuffer.empty()) {
                    node->feature = featureBuffer;
                    featureBuffer.clear();
                }
                break;
            }

            if (ch == '(') {
                Node *n = new Node();
                n->parent = node;
                if (!node) {
                    root = n;
                } else {
                    node->children.push_back(n);
                }

                node = n;
                readWeight = true;
                assert(weightBuffer.empty());
                assert(featureBuffer.empty());
            } else if (ch == ')') {
                if (readWeight) {
                    assert(node != 0);
                    assert(!weightBuffer.empty());
                    istringstream stream(weightBuffer);
                    stream >> node->weight;
                    readWeight = false;
                    weightBuffer.clear();
                } else if (!featureBuffer.empty()) {
                    node->feature = featureBuffer;
                    featureBuffer.clear();
                }
                node = node->parent;
            } else if (ch == ' ') {
                if (node && readWeight && weightBuffer.empty() == false) {
                    istringstream stream(weightBuffer);
                    stream >> node->weight;
                    weightBuffer.clear();
                    readWeight = false;
                } else if (node && !featureBuffer.empty()) {
                    node->feature = featureBuffer;
                    featureBuffer.clear();
                }
            } else {
                if (readWeight) {
                    weightBuffer.insert(weightBuffer.end(), ch);
                } else {
                    featureBuffer.insert(featureBuffer.end(), ch);
                }
            }
        }
    }
    return root;
}

typedef vector<pair<string, set<string> > > AnimalData;
void readAnimalData(AnimalData &data)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string animal;
        cin >> animal;

        int k; cin >> k;

        set<string> features;
        while (k--) {
            string f;
            cin >> f;
            features.insert(f);
        }

        data.push_back(make_pair(animal, features));
    }
}

void findAndPrintCuteness(Node *tree, const AnimalData &data)
{
    for (int i = 0; i < data.size(); ++i) {
        Node *parent = 0, *node = tree;
        double prob = 1.0;

        while (node) {
            prob *= node->weight;

            if (data[i].second.find(node->feature) != data[i].second.end()) {
                parent = node;
                if (node->children.empty() == false) {
                    node = node->children[0];
                } else {
                    node = 0;
                }
            } else {
                parent = node;
                if (node->children.size() >= 2) {
                    node = node->children[1];
                } else {
                    node = 0;
                }
            }
        }

        cout << fixed << setprecision(7) << prob << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        Node *tree = readTree();
        AnimalData data;
        readAnimalData(data);
        cout << "Case #" << i << ":" << endl;
        findAndPrintCuteness(tree, data);
        delete tree;
    }
    return 0;
}

