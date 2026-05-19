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

    return r * cartesion(x, y); // Jacobian
}

double integrate(double r_upper_limit, double r_lower_limit, double r_steps, double theta_upper_limit, double theta_lower_limit, double theta_steps)
{

    double dr = (r_upper_limit - r_lower_limit) / r_steps;
    double dt = (theta_upper_limit - theta_lower_limit) / theta_steps;
    double integral = 0.0;

    for (int i = 0; i < theta_steps; i++)
    {
        double t = theta_lower_limit + (i+0.5) * dt;

        for (int j = 0; j < r_steps; j++)
        {
            double r = r_lower_limit + (j+0.5) * dr;

            if (r < 1e-9 && r_lower_limit == 0)
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

    cout<<"\nEnter the intervals  for integral : ";
    cin>>steps;

   double result=integrate(r_end,r_start,steps,theta_end,theta_start,steps);

   

   cout << "Calculated Integral Value: " <<result;



    



    return 0;
}