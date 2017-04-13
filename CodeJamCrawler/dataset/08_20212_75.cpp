/*
 * Google Code Jam 2008
 * Qualification Round
 * Problem C: Fly Swatter
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <cassert>
#include <cstdio>
#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

/* Four cases for upper right quadrant:

 CASE 1:

   (xL,yH)   (xA,yH)=(xA,yA)
        +----*
        |     \
        |      *(xH,yB)=(xB,yB)
        |      |
        +------+
   (xL,yL)      (xH,yL)

   Area = (xA-xL)*(yH-yL)
        + (xH-xA)*(yB-yL)
        + (xH-xA)*(yH-yB)/2
        + area between chord and circle


 CASE 2:

   (xL,yA)=(xA,yA)
        *-----\     
        |      *(xH,yB)=(xB,yB)
        |      |
        +------+
   (xL,yL)      (xH,yL)

   Area = (xH-xL)*(yB-yL)
        + (xH-xL)*(yA-yB)/2
        + area between chord and circle


 CASE 3:

   (xL,yH)  (xA,yH)=(xA,yA)
        +---*
        |    \ 
        |     | 
        |     |
        +-----*
   (xL,yL)    (xB,yL)=(xB,yB)


   Area = (xA-xL)*(yH-yL)
        + (xB-xA)*(yH-yL)/2
        + area between chord and circle


 CASE 4:

   (xL,yA)=(xA,yA)
        *----\     
        |     \
        +-----*
   (xL,yL)    (xB,yL)=(xB,yB)

   Area = (xB-xL)*(yA-yL)/2
        + area between chord and circle

*/

double norm(const double x, const double y)
{
  return sqrt(x*x + y*y);
}

double chordArea(const double x1,
                 const double y1,
                 const double x2,
                 const double y2,
                 const double radius,
		 const int memo = -1)
{
  assert (fabs(norm(x1,y1)-radius) < 1.0e-9);
  assert (fabs(norm(x2,y2)-radius) < 1.0e-9);
  const double dotProduct   = x1*x2 + y1*y2;
  const double crossProduct = x1*y2 - x2*y1;
  const double centralAngle = acos(dotProduct / (radius * radius));
  const double triangleArea = fabs(crossProduct) / 2;
  const double pieSliceArea = fabs(radius * radius * centralAngle / 2);
  return pieSliceArea - triangleArea;
}

double hitProbability(const double f,
                      const double R,
                      const double t,
                      const double r,
                      const double g)
{
  if (2*f >= g)
    return 1.0;

  double safeArea = 0.0;
  const int H = int(R / (2*r + g)) + 3;
  const double radius = R - t - f;
  for (int j = H-1; j >= 0; j--) {
    for (int i = 0; i < H; i++) {
      const double xL = r + (i * (g + (2*r))) + f;
      const double xH = r + (i * (g + (2*r))) + g - f;
      const double yL = r + (j * (g + (2*r))) + f;
      const double yH = r + (j * (g + (2*r))) + g - f;
      const bool xLyL_in = norm(xL,yL) < (R-t-f);
      const bool xLyH_in = norm(xL,yH) < (R-t-f);
      const bool xHyL_in = norm(xH,yL) < (R-t-f);
      const bool xHyH_in = norm(xH,yH) < (R-t-f);

      if (! xLyL_in) {
        // entirely outside
        ;

      } else if (xHyH_in) {
        // entirely inside
        safeArea += (g - (2*f)) * (g - (2*f));

      } else if (xLyH_in && xHyL_in) {
        // Case 1
        const double xA = sqrt(radius*radius - yH*yH);
        const double yB = sqrt(radius*radius - xH*xH);
        assert ((xL <= xA) && (xA <= xH));
        assert ((yL <= yB) && (yB <= yH));
        safeArea += (xA-xL)*(yH-yL);
        safeArea += (xH-xA)*(yB-yL);
        safeArea += (xH-xA)*(yH-yB)/2;
        safeArea += chordArea(xA, yH, xH, yB, R-t-f, 1);

      } else if ((!xLyH_in) && xHyL_in) {
        // Case 2
        const double yA = sqrt(radius*radius - xL*xL);
        const double yB = sqrt(radius*radius - xH*xH);
        assert ((yL <= yA) && (yA <= yH));
        assert ((yL <= yB) && (yB <= yH));
        safeArea += (xH-xL)*(yB-yL);
        safeArea += (xH-xL)*(yA-yB)/2;
        safeArea += chordArea(xL, yA, xH, yB, R-t-f, 2);

      } else if (xLyH_in && (!xHyL_in)) {
        // Case 3 
        const double xA = sqrt(radius*radius - yH*yH);
        const double xB = sqrt(radius*radius - yL*yL);
        assert ((xL <= xA) && (xA <= xH));
        assert ((xL <= xB) && (xB <= xH));
        safeArea += (xA-xL)*(yH-yL);
        safeArea += (xB-xA)*(yH-yL)/2;
        safeArea += chordArea(xA, yH, xB, yL, R-t-f, 3);

      } else if ((!xLyH_in) && (!xHyL_in)) {
        // Case 4
        const double yA = sqrt(radius*radius - xL*xL);
        const double xB = sqrt(radius*radius - yL*yL);
        assert ((yL <= yA) && (yA <= yH));
        assert ((xL <= xB) && (xB <= xH));
        safeArea += (xB-xL)*(yA-yL)/2;
        safeArea += chordArea(xL, yA, xB, yL, R-t-f, 4);

      } else {
        assert (false);
      }
    } //next j
  } //next i
  safeArea *= 4;
  const double fullArea = PI * R * R;
  return 1.0 - (safeArea / fullArea);
}
  
int main(int argc, char *argv[])
{
  int N;
  cin >> N;
  for (int tc = 1; tc <= N; tc++) {
    double f, R, t, r, g;
    cin >> f >> R >> t >> r >> g;
    double prob = hitProbability(f, R, t, r, g);
    printf("Case #%d: %.6f\n", tc, prob);
  }
  return 0;
}
  




