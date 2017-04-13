#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct node
{
  double p;
  string f;
  node *l, *r;
};

bool get_next_lbracket ()
{
  string s;
  cin >> s;
  if (s[0] != '(')
  {
    for (int i = s.size () - 1; i >= 0; --i)
      cin.putback (s[i]);
    return false;
  }

  if (s.size () > 1)
  {
    for (int i = s.size () - 1; i >= 1; --i){
      cin.putback (s[i]);
    }
    return true;
  }
  return true;
}

bool get_next_rbracket ()
{
  string s;
  cin >> s;
  if (s[0] != ')')
  {
    for (int i = s.size () - 1; i >= 0; --i)
      cin.putback (s[i]);
    return false;
  } 

  if (s.size () > 1)
  {
    for (int i = s.size () - 1; i >= 1; --i)
      cin.putback (s[i]);
    return true;
  }
  return true;
}

double get_next_prob ()
{
  double d;
  string s;
  cin >> s;;

  int i = 0;
  while (i < s.size () && s[i] != ')')
    ++i;
  for (int j = s.size () - 1; j >= i; --j)
    cin.putback (s[j]);
  s = s.substr (0, i);
  stringstream ss;
  ss << s ;
  ss >> d;
  return d;
}

string get_next_feature ()
{
  string s;
  cin >> s;
  int i = 0;
  while (i < s.size () && s[i] != ')')
    ++i;
  for (int j = s.size () - 1; j >= i; --j)
    cin.putback (s[j]);
  s = s.substr (0, i); 
  return s;
}

void build (node *r)
{
  get_next_lbracket ();
  r->p = get_next_prob ();
  if (!get_next_rbracket ())
  {
    r->f = get_next_feature ();
    r->l = new node ();
    r->r = new node ();
    build (r->l);
    build (r->r);
    get_next_rbracket ();
    return;
  }
  r->l = r->r = 0;
}


void do_test (int no)
{
  int L;
  cin >> L;

  node *root = new node;
  build (root);

  int A;
  cin >> A;
  for (int i = 0; i < A; ++i)
  {
    string animal;
    cin >> animal;
    int n;
    cin >> n;
    set<string> animal_f;
    for (int j = 0; j < n; ++j)
    {
      string cur_f;
      cin >> cur_f;
      animal_f.insert (cur_f);
    }
    
    node *cur = root;
    double p = 1.0;
    while (cur != NULL)
    {
      p *= cur->p;
      if (animal_f.find (cur->f) != animal_f.end ())
        cur = cur->l; 
      else
        cur = cur->r;
    }
    cout << fixed << setprecision(6) << p << endl;

  }
}


int main ()
{
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i)
  {
    cout << "Case #" << i << ": \n";
    do_test (i);
  }
}


