/* atan2 example */
#include <stdio.h>      /* printf */
#include <cmath>       /* atan2 */
#include <iostream>
using namespace std;
#define PI 3.14159265

int main () {
  double x, y, result;
  for(int i =1;i<=360;i++)  {
      x = cos(i*PI/180);
      y = sin(i*PI/180);
      result = atan2 (y,x) * 180 / PI;
      printf ("The arc tangent for (x=%f, y=%f) is %f degrees\n", x, y, result );
  }
  return 0;
}
