// --- Save the Universe Problem ---
// Google Code Jam
// Name: David Allan Finch
// Date: Thursday 17th July 2008
// Email: david.allan@finch.org

#include <iostream>

using namespace std;

template <typename TYPE>
TYPE popTop( TYPE& top )
    {
    if( ! top ) return 0;
    TYPE tmp = top;
    top = top->next;
    return tmp;
    }

// ----------------------------------------------------------------------

struct IO
    {
    FILE* in;
	FILE* out;
	FILE* err;
    };

// ----------------------------------------------------------------------

int getInt( IO& io )
    {
    static char tbuff[200];
    memset( tbuff, 0, sizeof(tbuff) );
	return atoi( fgets( tbuff, sizeof(tbuff), io.in ) );
    }

// ----------------------------------------------------------------------

char* getStr( IO& io )
    {
    static char tbuff[200];
    memset( tbuff, 0, sizeof( tbuff ) );
    fgets( tbuff, sizeof(tbuff), io.in );
    tbuff[ strlen(tbuff)-1 ] = 0;
    return strdup( tbuff );
    }

// ----------------------------------------------------------------------

template <typename TYPE>
struct Array
    {
    Array( int len ) : length( len )
        {
        array = (TYPE*)(malloc(sizeof(TYPE)*length ));
        }

    ~Array() { free( array ); }

    int     length;
    TYPE*   array;
    };

// ----------------------------------------------------------------------

Array<char*>* getList( IO& io )
    {
    const int total = getInt(io);
    Array<char*>* array = new Array<char*>( total );

    for( int cnt = 0; cnt < total; cnt++ )
        {
        array->array[cnt] = getStr(io);
        }

    return array;
    }

Array<int>* getList( IO& io, Array<char*>* servers )
    {
    const int total = getInt(io);
    Array<int>* array = new Array<int>( total );

    for( int cnt = 0; cnt < total; cnt++ )
        {
        char* q = getStr(io);

        for( int x = 0; x < servers->length; x++ )
            {
            if( ! strcmp( servers->array[x], q ) )
                {
                array->array[cnt] = x;
                break;
                }
            }

        free(q);
        }

    return array;
    }

void doResult( IO& io, int case_cnt, int value )
    {
    fprintf( io.out, "Case #%d: %d\n", case_cnt+1, value );
    }

// ----------------------------------------------------------------------
// breath first solutions

struct SolutionState
    {
    SolutionState( int d, int s, int p ): next(0), depth(d), server(s), pos(p) { max++; count++; }

    ~SolutionState() { count--; }

    SolutionState*  next;
    int             depth;
    int            server;
    int             pos;
    // - data

    static int count;
    static int max;

    bool operator == ( SolutionState& s ) { return ( (s.depth==depth)&&(s.server==server)&&(s.pos==pos) ); }
    };

int SolutionState::count = 0;
int SolutionState::max = 0;

struct SolutionList
    {
    SolutionList( int d ) : next(0), depth(d), list(0) {}
    SolutionList() { while( list ) { delete popTop( list ); } }
    SolutionList* next;

    int             depth;
    SolutionState* list;
    };

struct SolutionDepth
    {
    SolutionDepth() : list(0) {}
    ~SolutionDepth()
        {
        while( list ) { delete popTop( list ); }
        }

    SolutionList* list;
    };

SolutionState* getNextSolutionToTry( SolutionState* solutions )
    {
    return 0;
    }



template <typename TYPE>
void addBack( TYPE& top, TYPE& add )
    {
    add->next = top;
    top = add;
    /*
    for( TYPE t = top; t; t = t->next )
        {
        if( ! t->next ) { t->next = add; add->next = 0; return; }
        }
    top = add;
    add->next = 0;
    */
    }

SolutionState* getNextSolutionToTry( SolutionDepth* solutions )
    {
    SolutionList* nextList = solutions->list;
    SolutionState* nextState = 0;

    while( nextList && ! nextState )
        {
        nextState = nextList->list ? popTop( nextList->list ) : 0;

        if( ! nextList->list )
            {
            SolutionList* tmp = nextList;
            nextList = solutions->list ? popTop( solutions->list ) : 0;
            delete tmp;
            }
        }

    return nextState;
    }

bool addAnotherState( SolutionList*& nextList, SolutionState* state )
    {
    if( ! nextList ) nextList = new SolutionList( state->depth );

    if( state->depth == nextList->depth )
        {
        bool found = false;
        for( SolutionState* x = nextList->list; x; x = x = x->next )
            {
            if( *x == *state ) { found = true; break; }
            }

        if( ! found ) addBack( nextList->list, state );

        return true;
        }

    if( state->depth >= nextList->depth )
        {
        if( addAnotherState( nextList->next, state ) )
            return true;
        }

    SolutionList* a = new SolutionList( state->depth );
    SolutionList* b = nextList->next;
    a->next = b;
    nextList->next = a;

    addAnotherState( nextList->next, state );

    return true;
    }

int addAnotherState( SolutionDepth*& solutions, SolutionState* state )
    {
    if( ! solutions ) solutions = new SolutionDepth();
    SolutionList*& nextList = solutions->list;
    return addAnotherState( nextList, state );
    }

// ----------------------------------------------------------------------
int main( int argc, const char* argv[] )
{
    IO io;

	io.in = stdin;
	io.out = stdout;
	io.err = stderr;

	if( argc > 1 ) io.in = fopen( argv[1], "r" ); else io.in = fopen( "test1.txt", "r" );
	if( argc > 2 ) io.out = fopen( argv[2], "w" );
	if( argc > 3 ) io.err = fopen( argv[3], "w" );

	int case_total = getInt(io);

	for( int cc = 0; cc < case_total; cc++ )
		{
        // case CNT
        int result = 9999;

        Array<char*>* search = getList(io);
        Array<int>* queries = getList(io,search);

        SolutionDepth* holder = 0;

        for( int sc = 0; sc < search->length; sc++ )
            {
            if( queries->array[0] != sc )
                {
                int depth = 0;
                SolutionState* curr = new SolutionState( depth, sc, 0 );
                addAnotherState( holder, curr );
                }
            }

        while( SolutionState* state = getNextSolutionToTry( holder ) )
            {
            //printf( "handle case=%d pos=%d depth=%d server=%d\n", cc, state->pos, state->depth, state->server );

            int pos = state->pos;

            while( pos < queries->length )
                {
                if( queries->array[pos] != state->server )
                    pos++;
                else
                    break;
                }

            //printf( "%d: %d\n", pos, state->depth );

            if( pos == queries->length )
                {
                result = state->depth;
                //printf( "SOLUTION: %d\n", state->depth );
                break;
                }
            else
                {
                int depth = state->depth + 1;

                for( int sc = 0; sc < search->length; sc++ )
                    {
                    if( queries->array[pos] != sc )
                        {
                        SolutionState* curr = new SolutionState( depth, sc, pos );
                        addAnotherState( holder, curr );
                        //printf( "--- %d: %d %d: %d\n", cc, curr->server, curr->pos, curr->depth );
                        }
                    }

                delete state; //printf( "SolutionState( %d %d )\n", SolutionState::count, SolutionState::max );
                }
            }

        doResult( io, cc, result );

        delete holder;
        delete search;
        delete queries;
        //printf( "SolutionState( %d %d )\n", SolutionState::count, SolutionState::max );
		}

	if( argc > 3 ) fclose( io.err );
	if( argc > 2 ) fclose( io.out );
	if( argc > 1 ) fclose( io.in );

	return 0;

}
