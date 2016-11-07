vector<P> interCircle( P o1 , double r1 , P o2 , double r2 ){
  double d2 = ( o1 - o2 ) * ( o1 - o2 );
  double d = sqrt(d2);
	if( d > r1 + r2 ) return {};
  P u = (o1+o2)*0.5 + (o1-o2)*((r2*r2-r1*r1)/(2*d2));
  double A = sqrt((r1+r2+d)*(r1-r2+d)*(r1+r2-d)*(-r1+r2+d));
  P v = P( o1.y-o2.y , -o1.x + o2.x ) * A / (2*d2);
  return {u+v, u-v};
}

