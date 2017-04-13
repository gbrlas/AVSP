#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

struct node {
  double prob;
  string feature;
  node *left, *right;
};

void build(node **pn, vector<string> &tokens, int &current) {
  *pn = new node;

  /* Skip opening bracket */
  ++current;

  stringstream ss(tokens[current]);
  ss >> (**pn).prob;
  ++current;

  if (tokens[current] != ")") {
    (**pn).feature = tokens[current++];
    build(&(**pn).left, tokens, current);
    build(&(**pn).right, tokens, current);
  }

  /* Skip closing bracket */
  ++current;
}

int main() {
  int z;
  scanf("%d", &z);

  for (int zz = 1; zz <= z; ++zz) {
    int lines;
    scanf("%d", &lines);
    char line[1000];
    gets(line);
    vector<string> tokens;
    node *root;

    for (int i = 0; i < lines; ++i) {
      gets(line);

      stringstream ss(line);

      while (1) {
        string token;
        ss >> token;
        if (token == "")
          break;

        int leading = 0;

        while (leading < token.size() && token[leading] == '(')
          ++leading;

        int trailing = 0;

        while (trailing < token.size() && token[token.size() - trailing - 1] == ')')
          ++trailing;

        for (int j = 0; j < leading; ++j)
          tokens.push_back("(");

        if (leading + trailing < token.size())
          tokens.push_back(token.substr(leading, token.size() - leading - trailing));

        for (int j = 0; j < trailing; ++j)
          tokens.push_back(")");
      }
    }

//    for (int i = 0; i < tokens.size(); ++i)
//      printf("%s\n", tokens[i].c_str());

    int c = 0;
    build(&root, tokens, c);

    printf("Case #%d:\n", zz);

    scanf("%d", &c);

    for (int i = 0; i < c; ++i) {
      set<string> features;
      int number;

      scanf("%*s%d", &number);

      for (int j = 0; j < number; ++j) {
        scanf("%s", line);
        features.insert(line);
      }

      node *cur = root;
      double prob = 1;

      while (1) {
        prob *= cur->prob;
        if (cur->feature == "")
          break;
        if (features.find(cur->feature) != features.end())
          cur = cur->left;
        else
          cur = cur->right;
      }

      printf("%f\n", prob);
    }
  }

  return 0;
}
