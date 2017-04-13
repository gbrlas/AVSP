#include <iostream>

using namespace std;

#define REPEAT(i,n) for( int i(1), _##n(n); i <= _##n; i++ )
#define FOR(i,n) for( int i(0), _##n(n); i < _##n; i++ )

typedef __int64 LLU;

template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}

//#define DEBUG
#ifdef DEBUG
#define D fprintf
#else
#define D debug
inline void debug( ... ) {}
#endif

// -----------------------------------------------------------------------------------

template <typename PTR>
void safe_delete( PTR& ptr )
    {
    if( ptr )
        {
        delete ptr;
        ptr = 0;
        }
    }

// -----------------------------------------------------------------------------------

class RAII
    {
    public:

        RAII( void* p ) : ptr(p) {}

    protected:
        void* ptr;
    };

template <typename PTR>
class Ptr : public RAII
    {
    public:
        Ptr( PTR* p = 0 ) : RAII(p) {}
        void operator = ( PTR* p ) { safe_delete( ptr ); ptr = p; }
        operator PTR () { return ptr; }
        virtual ~Ptr() { safe_delete( ptr ); }
    };

// -----------------------------------------------------------------------------------

template <typename DATA>
class Array
    {
    public:

        Array( int s = 16 ) :
            size(s), array( new DATA* [ size ] ), len(0)
            { memset( array, 0, sizeof(DATA*)*size ); }

        ~Array()
            {
            for( int i = 0; i < size; i++ )
                safe_delete( array[i] );
            delete [] array;
            }

        DATA& operator [] ( int i )
            {
            resize( i );

            if( i > len ) len = i;

            if( ! array[i] )
                array[i] = new DATA;
            return *array[i];
            }

        int noof() { return len; }

    protected:

        void resize( int new_size )
            {
            if( new_size > size )
                {
                new_size *= 2;
                DATA** tmp = new DATA* [new_size];
                memcpy( tmp, array, sizeof(DATA*)*size );
                memset( &tmp[size], 0, sizeof(DATA*)*(new_size-size) );
                delete [] array;
                array = tmp;
                size = new_size;
                }
            }

        int size;
        DATA** array;
        int len;

    };

// -----------------------------------------------------------------------------------

template <typename DATA>
class Stack : protected Array<DATA>
    {
    public:

        void operator += ( const DATA& val ) { push( val ); }

        void push( const DATA& val )
            {
            Array<DATA>::operator[](Array<DATA>::len) = val;
            }

        DATA* operator -- () { return pop(); }

        DATA* pop()
            {
            int top = Array<DATA>::len-1;
            DATA* val = Array<DATA>::array[top];
            return val;
            }

    };

// -----------------------------------------------------------------------------------

typedef char const * const CStr;

class String
    {
    public:

        String( int s = 16 ): size(s), data( new char[size] ), len(0)
            { *data = 0; }

        String( char* str ) : size(strlen(str)), data( new char[size] ), len(size)
            { strcpy(data,str); }

        String( CStr str ) :
            size(0), data((char*)str), len(sizeof(str))
            {}

        String( const String& str ) : size(str.size), data( new char[size] ), len(str.len)
            { strcpy(data,str.data); }

        ~String() { delete [] data; }

        inline void set( int val )
            {
            int l = sprintf( 0, "%d", val );
            resize( l, false );
            sprintf( data, "%d", val );
            len = l;
            }

        inline void set( bool val )
            {
            int l = val ? 4 : 5;
            resize( l, false );
            strcpy( data, ( val ? "true" : "false" ) );
            len = l;
            }

        inline void set( float val )
            {
            int l = sprintf( 0, "%g", val );
            resize( l, false );
            sprintf( data, "%g", val );
            len = l;
            }

        inline void set( const String& str )
            {
            resize( str.size, false );
            strcpy( data, str );
            len = str.len;
            }

        inline void set( CStr str )
            {
            int l = strlen( str );
            resize( l, false );
            strcpy( data, str );
            len = l;
            }

        inline void operator = ( bool val ) { set( val ); }
        inline void operator = ( float val ) { set( val ); }
        inline void operator = ( int val ) { set( val ); }
        inline void operator = ( CStr val )  { set( val ); }
        inline void operator = ( const String& val )   { set( val ); }

        inline void add( const String& str )
            {
            resize( len+str.len, true );
            strcpy( &data[len], str );
            len += str.len;
            }

        inline void add( CStr str )
            {
            int l = strlen( str ) + len;
            resize( l, true );
            strcpy( &data[len], str );
            len = l;
            }

        inline void add( int val )
            {
            int l = len + sprintf( 0, "%d", val );
            resize( l, true );
            sprintf( &data[len], "%d", val );
            len = l;
            }

        inline void add( float val )
            {
            int l = len + sprintf( 0, "%g", val );
            resize( l, true );
            sprintf( &data[len], "%g", val );
            len = l;
            }

        inline void add( bool val )
            {
            int l = len + (val ? 4 : 5);
            resize( l, false );
            strcpy( &data[len], ( val ? "true" : "false" ) );
            len = l;
            }

        inline operator int () const { return ::atoi(data); }
        inline operator float () const { return ::atof(data); }
        inline operator bool () const { return !::strcmp(data,"true"); }
        inline operator CStr () const { return data; }

        inline int strcmp( const String& str ) const { return ::strcmp( data, str ); }
        inline bool greater( const String& str ) const { return ::strcmp( data, str ) > 0; }
        inline bool lesser( const String& str ) const { return ::strcmp( data, str ) < 0; }
        inline bool equal( const String& str ) const { return !::strcmp( data, str ); }

    private:

        int size;
        char* data;
        int len;

        void resize( int new_size, bool copy )
            {
            if( new_size > size )
                {
                new_size *= 2;
                char* tmp = new char[ new_size ];
                if( copy ) strncpy( tmp, data, len );
                if( size ) delete [] data;
                size = new_size;
                data = tmp;
                }
            }
    };

inline bool operator > ( const String& s1, const String& s2  ) { return s1.greater(s2); }
inline bool operator <= ( const String& s1, const String& s2  ) { return !s1.greater(s2); }
inline bool operator < ( const String& s1, const String& s2  ) { return s1.lesser(s2); }
inline bool operator >= ( const String& s1, const String& s2  ) { return !s1.lesser(s2); }
inline bool operator == ( const String& s1, const String& s2  ) { return s1.equal(s2); }
inline bool operator != ( const String& s1, const String& s2  ) { return !s1.equal(s2); }

inline void operator += ( String& s1, bool val ) { s1.add( val ); }
inline void operator += ( String& s1, float val ) { s1.add( val ); }
inline void operator += ( String& s1, int val ) { s1.add( val ); }
inline void operator += ( String& s1, CStr val )  { s1.add( val ); }
inline void operator += ( String& s1, const String& val )   { s1.add( val ); }

// -----------------------------------------------------------------------------------

inline void join( Array<String>& array, const String& sep, String& res )
    {
    res += "sfsdffdf"; //array.noof();
    res += sep;

    for( int i = 0, l = array.noof(); i < l; i++ )
        {
        //res += array[i];
        //res += sep;
        }

    printf( "jfhsdjfh %s\n", (CStr)sep );
    }

inline Array<String> split( String& string, const String& pat )
    {
    Array<String> res;

    return res;
    }

// -----------------------------------------------------------------------------------

        struct BotInst
            {
            char bot[2];
            int button;
            };

int main()
{
    //freopen( "test.txt", "r", stdin );
    //freopen( "small0.txt", "r", stdin );
    freopen( "large0.txt", "r", stdin );

    freopen( "output.txt", "w", stdout );
    freopen( "error.txt", "w", stderr );

    int noofCases = 0;
    scanf( "%d\n", &noofCases );

    REPEAT( caseNo, noofCases )
        {
        int result = 0;
        int noofInsts = 0;
        scanf( "%d", &noofInsts );

        Array<BotInst> inst( noofInsts );

        FOR( instNo, noofInsts )
            {
            BotInst& i = inst[instNo];

            scanf( "%s %d", i.bot, &i.button );
            //D( stderr, "%d %d %s %d\n", caseNo, instNo, i.bot, i.button );
            }

        enum BotType { pO = 0, pB = 1 };

        struct BotState
            {
            int next;
            int curr;
            char name;
            }
        bots[2] =
            {
                { 0, 1, 'O' },
                { 0, 1, 'B' }
            };

        FOR( instNo, noofInsts )
            {
            BotInst& i = inst[instNo];
            D( stderr, "%d %d %s %d\n", caseNo, instNo, i.bot, i.button );

            if( ! bots[pO].next )
                for( int j = instNo; j < noofInsts; j++ )
                    if( *inst[j].bot == bots[pO].name )
                        {
                        bots[pO].next = inst[j].button;
                        break;
                        }

            if( ! bots[pB].next )
                for( int j = instNo; j < noofInsts; j++ )
                    if( *inst[j].bot == bots[pB].name )
                        {
                        bots[pB].next = inst[j].button;
                        break;
                        }

            D( stderr, "\tB %d %d, O %d %d\n", bots[pB].curr, bots[pB].next, bots[pO].curr, bots[pO].next );

            BotType bT = ( *i.bot == 'B' ) ? pB : pO;
            BotType oT = ( *i.bot == 'B' ) ? pO : pB;

            D( stderr, "\t\t%c do\n", bots[bT].name );

            while( bots[bT].curr != bots[bT].next )
                {
                result++;

                if( bots[bT].curr > bots[bT].next )
                    {
                    bots[bT].curr--;
                    }
                else if( bots[bT].next > bots[bT].curr )
                    {
                    bots[bT].curr++;
                    }

                if( bots[oT].curr > bots[oT].next )
                    {
                    bots[oT].curr--;
                    }
                else if( bots[oT].next > bots[oT].curr )
                    {
                    bots[oT].curr++;
                    }

                D( stderr, "\t\t\t %d B %d %d, O %d %d\n", result, bots[pB].curr, bots[pB].next, bots[pO].curr, bots[pO].next );
                }

            result++;

            if( bots[bT].next != 0 && bots[bT].curr == bots[bT].next )
                {
                D( stderr, "\t\t\t%c press %d\n", bots[bT].name, result );
                bots[bT].next = 0;
                }

            if( bots[oT].curr > bots[oT].next )
                {
                bots[oT].curr--;
                }
            else if( bots[oT].next > bots[oT].curr )
                {
                bots[oT].curr++;
                }
            }

        printf( "Case #%d: %d\n", caseNo, result );
        }

    return 0;
}
