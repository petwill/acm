#include <iostream>
#include <complex>
#include <cmath>
using namespace std;
const double pi = 2 * asin(1);
main() {
  std::complex<double> z4 = 1 + 2i, z5 = 1 - 2i; // conjugates
  std::cout << "(1+2i)*(1-2i) = " << z4*z5 << '\n';
  complex<double> i, a;
  i = -1; i = sqrt(i);
  a = exp(2*pi*i);
  cout << "i is " << i << "and Euler was right: e(i pi) = " << a << endl;
}
