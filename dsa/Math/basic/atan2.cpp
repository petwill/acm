/* atan2 example */
#include <stdio.h>      /* printf */
#include <cmath>       /* atan2 */
#include <iostream>
using namespace std;
#define PI 3.14159265

int main () {
  double x, y, result;
  /**
  Returns the principal value of the arc tangent of y/x, expressed in radians.
  To compute the value, the function takes into account the sign of both arguments
  in order to determine the quadrant.
  **/
  for(int i =1;i<=360;i++)  {
      x = cos(i*PI/180);
      y = sin(i*PI/180);
      result = atan2 (y,x) * 180 / PI;
      printf ("The arc tangent for (x=%f, y=%f) is %f degrees\n", x, y, result );
  }
  puts("");
  for(int i =-10000;i<=10000;i+=1000)  {
      x = atan(i);
      printf ("The arc tan %d is %f degrees\n", i,x*180/PI  );
  }
  puts("");
  for(double i =-1;i<=1;i+=0.5)  {
      x = acos(i);
      printf ("The arc cos %f is %f degrees\n", i,x*180/PI  );
  }
  puts("");
   for(double i =-1;i<=1;i+=0.5)  {
      x = asin(i);
      printf ("The arc sin %f is %f degrees\n", i,x*180/PI  );
  }
  return 0;
}

