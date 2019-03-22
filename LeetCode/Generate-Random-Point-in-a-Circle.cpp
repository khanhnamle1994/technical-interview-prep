/* Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.

Example 1:
Input:
["Solution","randPoint","randPoint","randPoint"]
[[1,0,0],[],[],[]]
Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],[-0.83119,-0.19803]]

Example 2:
Input:
["Solution","randPoint","randPoint","randPoint"]
[[10,5,-7.5],[],[],[]]
Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],[11.13430,-12.42337]]

Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has three arguments, the radius, x-position of the center, and y-position of the center of the circle. randPoint has no arguments. Arguments are always wrapped with a list, even if there aren't any. */

double r, xc, yc;

Solution(double radius, double x_center, double y_center) {
    r = radius;
    xc = x_center;
    yc = y_center;
}

vector<double> randPoint() {
    double ra = (double)rand()/RAND_MAX;
    double len = sqrt(ra)*r;
    ra = (double)rand()/RAND_MAX;
    double deg = ra*M_PI*2;
    double nx = xc + len*cos(deg), ny = yc + len*sin(deg);
    return {nx, ny};
}
