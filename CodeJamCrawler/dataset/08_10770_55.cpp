#include <stdio.h>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <assert.h>
#include <math.h>

#define FLOATTYPE double

#define PI 3.1415926535897
#define SQRT2 1.4142135623
using namespace std;

typedef struct {
    FLOATTYPE x,y;
}Coord2D;

FLOATTYPE ComputeChordShape( FLOATTYPE R, Coord2D & src, Coord2D & dst )
{
    FLOATTYPE angle,halfChord;
    halfChord = 0.5 * sqrtl((src.x-dst.x)*(src.x-dst.x) + (src.y-dst.y)*(src.y-dst.y));
    angle = 2*asinl(halfChord/R);
    return 0.5 * R * R *( angle - sinl(angle) );
}

FLOATTYPE ComputeOverLap( FLOATTYPE R, FLOATTYPE inLen, FLOATTYPE outLen, int x, int y )
{
    Coord2D start;
    FLOATTYPE minDist;
    FLOATTYPE maxDist;
    FLOATTYPE upLeftDist;
    FLOATTYPE downRightDist;
    FLOATTYPE RSquare = R * R;
    FLOATTYPE inLenSquare = inLen * inLen;
    int jumpIndex = 0;
    start.x = outLen * (FLOATTYPE) x + (outLen - inLen) * 0.5;
    start.y = outLen * (FLOATTYPE) y + (outLen - inLen) * 0.5;
    minDist = start.x * start.x + start.y * start.y;
    if ( minDist >= RSquare ) {
        return 0.;
    }
    maxDist = (start.x + inLen)*(start.x + inLen) + 
        (start.y + inLen)*((start.y + inLen));
    if ( maxDist <= RSquare ) {
        return inLenSquare;
    }
    // JumpIndex:
    //  0 bit: downLeft point is out of the square.
    //  1 bit: downRight point is out of the square.
    //  2 bit: upRight point is out of the square.
    //  3 bit: upLeft point is out of the square.
    jumpIndex = 0;
    upLeftDist = minDist + 2 * start.y * inLen + inLenSquare;
    downRightDist = minDist + 2 * start.x * inLen + inLenSquare;
    if ( upLeftDist <= RSquare ) {
        jumpIndex |= 0x1;
    }
    if ( downRightDist <= RSquare ) {
        jumpIndex |= 0x2;
    }
    
    switch ( jumpIndex )
    {
    case 0:
        {
            Coord2D src,dst;
            src.x = start.x;
            src.y = sqrtl(RSquare - start.x * start.x);
            dst.y = start.y;
            dst.x = sqrtl(RSquare - start.y * start.y);
            return ComputeChordShape(R,src,dst) + 
                (src.y  - start.y) * ( dst.x - start.x ) * 0.5;
        }
    case 1:
        {
            Coord2D src,dst;
            src.y = start.y + inLen;
            src.x = sqrtl(RSquare - src.y * src.y);
            dst.y = start.y;
            dst.x = sqrtl(RSquare - dst.y * dst.y);
            return ComputeChordShape(R,src,dst) + 
                (src.x + dst.x - 2 * start.x) * inLen * 0.5;
        }
    case 2:
        {
            Coord2D src,dst;
            src.x = start.x;
            src.y = sqrtl(RSquare - start.x * start.x);
            dst.x = start.x + inLen;
            dst.y = sqrtl(RSquare - dst.x * dst.x);
            return ComputeChordShape(R,src,dst) + 
                (src.y + dst.y - 2 * start.y) * inLen * 0.5;
        }
    case 3:
        {
            Coord2D src,dst;
            src.y = start.y + inLen;
            src.x = sqrtl(RSquare - src.y * src.y);
            dst.x = start.x + inLen;
            dst.y = sqrtl(RSquare - dst.x * dst.x);
            return ComputeChordShape(R,src,dst) + inLen * inLen -
                (inLen - (src.x - start.x)) * ( inLen - (dst.y - start.y) ) * 0.5;
        }
    }
}

int main()
{
    int i,j,n,caseCnt = 0;
    FLOATTYPE f,R,r,t,g,p,squareSize,whole,escape;
    cin>>n;
    while( n-- ){
        cin>>f>>R>>t>>r>>g;
        squareSize = g - 2*f;
        if ( squareSize <= 0.f ) {
            p = 1.f;
        } else {
            int innerSize,outSize;
            escape;
            whole = R*R*PI;
            R = R - t;

            innerSize = (int)(R/(SQRT2*(2*r+g)));
            escape = innerSize * innerSize * squareSize * squareSize;
            outSize = (int)(R/(2*r+g));
            outSize++;
            assert(outSize<30);
            for ( i = 0; i < outSize; i++ ) {
                for ( j = 0 ; j < outSize; j++ ) {
                    if ( i < innerSize && j < innerSize ) {
                        continue;
                    }
                    escape += ComputeOverLap(R - f,squareSize,2*r+g,i,j);
                }
            }
            p = 1. - escape * 4. / whole;
        }
        printf("Case #%d: %0.6f\n",++caseCnt,p);
    }
    return 0;
}