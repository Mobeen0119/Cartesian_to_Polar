#include <iostream>
#include <cmath>
using namespace std;

double cartesion(double x, double y)
{

    return (x * x) + (y + y);
}

double polar_side(double r, double theta)
{
    double x = r * cos(theta);
    double y = r * sin(theta);

    return r * cartesion(x, y);
}
int main()
{
    return 0;
}