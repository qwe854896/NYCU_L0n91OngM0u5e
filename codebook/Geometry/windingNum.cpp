int n;
Poly poly;

bool checkPointOnSeg(const Point& p, const Point& A, const Point& B) {
    return cross(p, A, B) == 0 && dot(p, A, B) <= 0;
}
 
int boundaryCheck(const Point& p) {
    for (int i = 0; i < n; ++i)
        if (checkPointOnSeg(p, poly[i], poly[i + 1]))
            return cout << "BOUNDARY\n", 1;
    
    ll windingNumber = 0;
    for (int i = 0; i < n; ++i) {
        if (poly[i].Y <= p.Y) {
            if (poly[i + 1].Y > p.Y)
                if (cross(p, poly[i], poly[i + 1]) > 0)
                    ++windingNumber;
        }
        else {
            if (poly[i + 1].Y <= p.Y)
                if (cross(p, poly[i], poly[i + 1]) < 0)
                    --windingNumber;
        }
    }
    
    if (windingNumber)
        return cout << "INSIDE\n", 2;
    return cout << "OUTSIDE\n", 0;
}
 