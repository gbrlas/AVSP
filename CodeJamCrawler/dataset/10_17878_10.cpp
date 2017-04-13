#include <iostream>
#include <vector>
using namespace std;

int getNewIndex( const int& max,  const vector<int>& groups ){
    int sum =0;
    int idx =0;
    
    while(true){
      if( idx >= groups.size() ) break;
      sum += groups[idx];
      if( sum > max ) break;
      ++idx;
    }
    
    return idx;
}

vector<int> makeGroup( const vector<int>& groups, const int& index ){
  vector< int > result;
  // shuffle gorups
  for( int i = index; i < groups.size(); ++i ){
    result.push_back( groups[i] );
  }
  for( int i = 0; i < index; ++i ){
    result.push_back( groups[i] );
  }

  return result;
}

int main()
{
  int T;
  cin >> T;
  const int MAX_TIMES = T;
  
  int R; // time for running
  int k; // the size of corster
  int N; // the size of group
  
  while( T-- ){
    vector<int> groups;
    int temp;
    
    // input header data
    cin >> R >> k >> N;
    for( int i =0; i < N; ++i ){
      cin >> temp;
      groups.push_back( temp );
    }
    
    unsigned long int sum = 0;
    while( R-- ){
      // get new index;
      int index = getNewIndex( k, groups );
      // calc money
      for( int i =0; i < index; ++i ){
        sum += groups[i];
      }
      // make new groups
      vector<int> t_groups = makeGroup( groups, index );
      groups = t_groups;

    }

    cout << "Case #" << MAX_TIMES - T << ": " <<sum <<  endl;

    
  }

  
  return 0;
}


