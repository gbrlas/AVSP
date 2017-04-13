#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define all(v) v.begin(), v.end()
#define forint(i, a, b) for (int i = a; i != b; ++i)
#define foreach(i, v) typedef typeof(v) i##_##c;\
  for (i##_##c::iterator i = v.begin(); i != v.end(); ++i)

struct Node;

struct Node {
  map<string, Node*> children;
};

int addPath(Node *node, string& path) {
  int additions = 0, left = 1, right;
  do {
    right = path.find('/', left);
    if (right == string::npos)
      right = path.length();
    string s = path.substr(left, right - left);
    map<string, Node*>::iterator i = node->children.find(s);
    if (i == node->children.end()) {
      Node *child = new Node();
      node->children[s] = child;
      node = child;
      ++additions;
    } else {
      node = i->second;
    }
    left = right + 1;
  } while (left < path.length());
  return additions;
}

int commands(vector<string>& exists, vector<string>& create) {
  Node *root = new Node();
  foreach(s, exists)
    addPath(root, *s);
  int additions = 0;
  foreach(s, create)
    additions += addPath(root, *s);
  return additions;
}

int main() {
  int t, n, m;
  cin >> t;
  for(int i = 0; i != t; ++i) {
    cin >> n >> m;
    vector<string> exists, create;
    string s;
    for(int j = 0; j != n; ++j) {
      cin >> s;
      exists.push_back(s);
    }
    for(int j = 0; j != m; ++j) {
      cin >> s;
      create.push_back(s);
    }
    cout << "Case #" << (i+1) << ": " << commands(exists, create) << endl;
  }
}
