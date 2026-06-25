#include <iostream>
#include "circle.h"
#include "point.h"
using namespace std;

int main() {
    Circle c;
    Point p;
    
    while (cin >> c.centre.x >> c.centre.y >> c.radius >> p.x >> p.y) {
        double d = distance(&c, &p);
        double diff = d - c.radius;
        cout << CheckPointInCircle(diff) << endl;
    }
    return 0;
}