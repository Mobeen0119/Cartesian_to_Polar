#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y)
{
    return sin(x) + cos(y);
}

double polar_side(double r, double theta)
{
    double x = r * cos(theta);
    double y = r * sin(theta);

    return r * f(x, y); // Jacobian
}

double integrate(
    double r_hi, double r_lo, double r_steps,
    double theta_hi, double theta_lo, double theta_steps)
{

    if (r_steps <= 0 && theta_steps <= 0)
    {
        cout << "\n\t\t-----Invalid Interval....Dobara enter kro------\n";
        return 0.0;
    }

    if (r_hi < r_lo)
        swap(r_hi, r_lo);
    if (theta_hi < theta_lo)
        swap(theta_hi, theta_lo);

    double dr = (r_hi - r_lo) / r_steps;
    double dt = (theta_hi - theta_lo) / theta_steps;
    double integral = 0.0;

    for (int i = 0; i < theta_steps; i++)
    {
        double t = theta_lo + (i + 0.5) * dt;

        for (int j = 0; j < r_steps; j++)
        {
            double r = r_lo + (j + 0.5) * dr;

            if (r < __DBL_EPSILON__ && r_lo == 0)
                ;

            integral += polar_side(r, t) * dr * dt;
        }
    }
    return integral;
}
int main()
{
    int steps;
    double r_start, r_end, theta_start, theta_end;

    cout << "Enter the lower limit for r : ";
    cin >> r_start;
    cout << "\nEnter the upper limit for r : ";
    cin >> r_end;
    cout << "\nEnter the lower limit for theta : ";
    cin >> theta_start;
    cout << "\nEnter the upper limit for theta : ";
    cin >> theta_end;

    cout << "\nEnter the intervals  for integral : ";
    cin >> steps;

    cout << "\n========== POLAR DOUBLE INTEGRATION ==========\n";

    cout << "Function: f(x,y) = x^2 + y^2\n";

    cout << "Region:\n";
    cout << "r     ∈ [" << r_start << ", " << r_end << "]\n";
    cout << "theta ∈ [" << theta_start << ", " << theta_end << "]\n";

    cout << "Steps: " << steps << " x " << steps << "\n";

    cout << "\nComputing...\n\n";
    double result = integrate(r_end, r_start, steps, theta_end, theta_start, steps);

    cout << "\n\t\tApproximate integration of f(x,y)  : " << result;
    return 0;
}