#define forward(a, b) Vector(b.X - a.X, b.Y - a.Y)
 
using Point = pii;
using Vec = pii;
 
ll cross(const Vec& u, const Vec& v) {
  return u.X * v.Y - u.Y * v.X;
}
 
ll cross(const Point& O, const Point& A, const Point& B) {
  return cross(Vec(A.X - O.X, A.Y - O.Y), Vec(B.X - O.X, B.Y - O.Y));
}
 
ll dot(const Vec& u, const Vec& v) {
  return u.X * v.X + u.Y * v.Y;
}
 
ll dot(const Point& O, const Point& A, const Point& B) {
  return dot(Vec(A.X - O.X, A.Y - O.Y), Vec(B.X - O.X, B.Y - O.Y));
}
 