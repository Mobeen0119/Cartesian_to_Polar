A C++ program that approximates double integrals in polar coordinates using the midpoint rule numerical method.

**What it does**

This program computes an approximation of integrals of the form:

∬f(x,y)dxdy

by converting them into polar coordinates:

∫
θ
	​

∫
r
	​

**f(rcosθ,rsinθ)⋅rdrdθ**

It then evaluates the integral using a grid-based numerical approximation.

 Current Function Being Integrated

**By default:**

f(x, y) = sin(x) + cos(y) + 1

You can modify this inside the code to test different functions.

** Method Used**
Polar coordinate transformation
Midpoint Rule (numerical integration)
Uniform grid sampling
Jacobian correction (r factor)
User Input

**The program takes:**

Lower & upper limit of r
Lower & upper limit of θ
Number of steps (resolution)

**Example:**

r: 0 → 1  
θ: 0 → π/2  
steps: 100
**Output**
Approximated value of the double integral
Based on discretized summation over polar grid

**Example output:**

**Calculated Integral Value: 0.41827**
 How it works (simplified)
Convert polar coordinates → Cartesian
Evaluate function at each grid point
Multiply by Jacobian (r)
Sum contributions over all small

** Limitations**
No symbolic integration (numerical only)
Accuracy depends on number of steps
Function must be hardcoded in source code
Not suitable for discontinuous functions without care

**Possible Future Improvements**
User-defined function parser (expression engine)
Adaptive step size integration
Monte Carlo integration mode
Error estimation vs exact solutions
Visualization of integration grid
