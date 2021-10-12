bool intersect(Point p, Point a, Point b) {
    return min(a.X, b.X) <= p.X && p.X <= max(a.X, b.X) && min(a.Y, b.Y) <= p.Y && p.Y <= max(a.Y, b.Y);
}
 
bool intersect(Point a, Point b, Point c, Point d) {
    int c1 = cross(a, b, c);
    int c2 = cross(a, b, d);
    int c3 = cross(c, d, a);
    int c4 = cross(c, d, b);

    if (c1 && c2 && c3 && c4 && ((c1 < 0) ^ (c2 < 0)) && ((c3 < 0) ^ (c4 < 0))) return true;
 
    if (!c1 && intersect(c, a, b)) return true;
    if (!c2 && intersect(d, a, b)) return true;
    if (!c3 && intersect(a, c, d)) return true;
    if (!c4 && intersect(b, c, d)) return true;
    return false;
}