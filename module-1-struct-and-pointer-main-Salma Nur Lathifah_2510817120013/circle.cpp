#include "circle.h"
#include <cmath>
#include <string>
using namespace std;

double distance(const Circle * c, const Point * p) {
    double dx = p->x - c->centre.x;
    double dy = p->y - c->centre.y;
    return sqrt(dx * dx + dy * dy); 
}

string CheckPointInCircle(double distance_val) {
    if (abs(distance_val) < EPSILON) {
        return "On Circle";
    } else if (distance_val < 0) {
        return "Inside";
    } else {
        return "Outside";
    }
}