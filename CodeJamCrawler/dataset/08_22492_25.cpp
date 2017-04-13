#include <iostream>
#include <string>
#include <fstream>
#include <list>

using std::list;
using std::string;

typedef list< string > StringList;

static const int DEBUG = 0;

struct TestCase {
    StringList searchEngines;
    StringList queries;
};

typedef list< TestCase > TestCaseList;

int getNSwitches( const TestCase& );

int main( int argc, char* argv[] ) {
    using std::cout;
    using std::endl;

    if ( argc != 3 ) {
        cout << "Usage: " << argv[ 0 ] << " <input-file> <output-file>" << endl;
        return -1;
    }
    ifstream inFile( argv[ 1 ] );
    char currString[ 1024 ];

    int nTestCases;
    inFile.getline( currString, 1024 );
    nTestCases = atoi( currString );
    TestCaseList testCases;
    TestCase currTestCase;

    int nSearchEngines, nQueries;
    int i, j;
    for ( i = 0; i < nTestCases; ++i ) {
        inFile.getline( currString, 1024 );
        nSearchEngines = atoi( currString );
        for ( j = 0; j < nSearchEngines; ++j ) {
            inFile.getline( currString, 1024 );
            currTestCase.searchEngines.push_back( currString );
        }
        inFile.getline( currString, 1024 );
        nQueries = atoi( currString );
        for ( j = 0; j < nQueries; ++j ) {
            inFile.getline( currString, 1024 );
            currTestCase.queries.push_back( currString );
        }
        testCases.push_back( currTestCase );
        currTestCase.searchEngines.clear();
        currTestCase.queries.clear();
    }
    
    i = 1;
    for ( TestCaseList::iterator iter = testCases.begin(); iter != testCases.end(); ++iter, ++i ) {
        cout << "Case #" << i << ": " << getNSwitches( *iter ) << endl;
    }
    return 0;
}

string getNextSearchEngine( const StringList&, const StringList::const_iterator &, 
                            const StringList::const_iterator& );

int getNSwitches( const TestCase& testCase ) {
    string currSearchEngine = getNextSearchEngine( testCase.searchEngines, testCase.queries.begin(), 
                                                   testCase.queries.end() );
    int nSwitches = 0;
    
    if ( DEBUG ) { 
        cout << "Starting with " << currSearchEngine << endl;
    }

    for ( StringList::const_iterator listIter = testCase.queries.begin(); 
          listIter != testCase.queries.end(); ++listIter ) {
        if ( currSearchEngine == *listIter ) {         // need to switch
            currSearchEngine = getNextSearchEngine( testCase.searchEngines, listIter, testCase.queries.end() );
            ++nSwitches;
            if ( DEBUG ) { 
                cout << "Switching to " << currSearchEngine << endl;
            }
        }
    }
    return nSwitches;
}

string getNextSearchEngine( const StringList& searchEngines, const StringList::const_iterator& queryIterStart,
                            const StringList::const_iterator& queryIterEnd ) {
    if ( DEBUG ) {
        cout << "getNextSearchEngine called!" << endl;
    }
    
    StringList::const_iterator nameIter, queryIter;
    int maxDistance = 0, distance;
    string retval = "";
    for ( nameIter = searchEngines.begin(); nameIter != searchEngines.end(); ++nameIter ) {
        distance = 0;
        for ( queryIter = queryIterStart; queryIter != queryIterEnd; ++queryIter, ++distance ) {
            if ( *nameIter == *queryIter ) {
                break;
            }
        }
        if ( DEBUG ) {
            cout << "Distance of " << *nameIter << " is " << distance << endl;
        }
        if ( distance > maxDistance ) {
            maxDistance = distance;
            retval = *nameIter;
        }
    }

    if ( DEBUG ) {
        cout << "Returning " << retval << endl;
    }

    return retval;
}
