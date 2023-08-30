#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x_cord, y_cord, distance, PI;
    int interval, circle_points = 0, square_points = 0;

    srand(time(NULL));

    cout<< "Run for? : ";
    cin>> interval;

    for (int i = 0; i < interval; i++)
    {
        x_cord = double(rand() % (interval + 1)) / interval;
        y_cord = double(rand() % (interval + 1)) / interval;

        distance = pow(x_cord,2) + pow(y_cord,2);

        if(distance<=1)
            circle_points ++;

        square_points ++;

        PI = double(4 * circle_points) / square_points;
    }

    cout<<"\nThe value of PI using " << interval <<" random points is : " << PI <<endl;

    return 0;
}
