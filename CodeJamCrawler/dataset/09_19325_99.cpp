#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct node {
  node* link[26];
  int ex;

  node() {
    for( int i = 0; i < 26; ++i )
      link[i] = NULL;
    ex = 0;
  }
};

struct trie {
  node* head;

  trie() {
    head = new node();
  }

  void insert( string word ) {
    node *p = head;

    for( int i = 0; i < (int)word.size(); ++i ) {
      int c = word[i]-'a';
      if( p->link[c] == NULL ) {
	p->link[c] = new node();
      }
      p = p->link[c];
    }

    p->ex = 1;
  }

  bool find( string word ) {
    node *p = head;

    for( int i = 0; i < (int)word.size(); ++i ) {
      int c = word[i]-'a';
      if( p->link[c] == NULL ) {
	return false;
      }
      p = p->link[c];
    }

    return p->ex;
  }
};

trie T;
vector<string> poss;
int l, d, n;
int sol;

void load() {
  char tmp[20];

  scanf( "%d%d%d", &l, &d, &n );
  for( int i = 0; i < d; ++i ) {
    scanf( "%s", tmp );
    T.insert( string( tmp ) );
  }
}

void init() {
  poss = vector<string>( l );
  char tmp[1000];
  scanf( "%s", tmp );

  int n = (int)string(tmp).size();
  int open = 0, pok = 0;

  for( int i = 0; i < n; ++i ) {
    if( tmp[i] == '(' )
      open = 1;
    else if( tmp[i] == ')' ) {
      open = 0;
      pok++;
    } else if( open ) {
      poss[pok] += tmp[i];
    } else {
      poss[pok] += tmp[i];
      pok++;
    }
  }
}

void solve( node* cvor, int p ) {
  if( p == l ) {
    ++sol;
    return;
  }

  for( int i = 0; i < (int)poss[p].size(); ++i ) {
    int c = poss[p][i]-'a';
    if( cvor->link[c] != NULL )
      solve( cvor->link[c], p+1 );
  }
}
  

int main() {
  load();
  for( int i = 0; i < n; ++i ) {
    init();
    sol = 0;
    solve( T.head, 0 );
    printf( "Case #%d: %d\n", i+1, sol );
  }


  
  return 0;
}
