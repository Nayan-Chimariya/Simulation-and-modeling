#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


double exponentialRandom(double lambda)
{
    double u = rand() / (RAND_MAX + 1.0);
    return -log(1 - u) / lambda;
}

int main()
{
    srand(time(0));

    int numCustomers;
    double lambda = 0.5, mu = 1.0;

    cout<<"Enter number of Customers: ";
    cin>> numCustomers;

    cout<<"Enter Arrival Rate: ";
    cin>> lambda;

    cout<<"Enter Service Rate: ";
    cin>> mu;


    queue<double> arrivalTimes;
    double currentTime = 0.0;
    double totalWaitingTime = 0.0;
    double totalServiceTime = 0.0;

    for (int i = 0; i < numCustomers; ++i)
    {
        double interarrivalTime = exponentialRandom(lambda);
        double serviceTime = exponentialRandom(mu);

        if (i == 0)
            arrivalTimes.push(interarrivalTime);

        else
            arrivalTimes.push(arrivalTimes.back() + interarrivalTime);


        double waitTime = max(0.0, currentTime - arrivalTimes.front());
        totalWaitingTime += waitTime;
        totalServiceTime += serviceTime;

        currentTime = max(currentTime, arrivalTimes.front()) + serviceTime;

        arrivalTimes.pop();
    }

    double averageWaitingTime = totalWaitingTime / numCustomers;
    double averageServiceTime = totalServiceTime / numCustomers;

    cout << "\nAverage Waiting Time -> " << averageWaitingTime << endl;
    cout << "Average Service Time -> " << averageServiceTime << endl;

    return 0;
}

