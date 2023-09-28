#include <iostream>
using namespace std;

const int MAX_DATA_POINTS = 1000;

double calculateMean(int data[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += data[i];
    return sum / n;
}

double calculateAutocorrelation(int data[], int n, int lag)
 {
    double mean = calculateMean(data, n);
    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i < n - lag; i++)
        numerator += (data[i] - mean) * (data[i + lag] - mean);

    for (int i = 0; i < n; i++)
        denominator += (data[i] - mean) * (data[i] - mean);

    return numerator / denominator;
}

int main()
{
    int n;
    int data[MAX_DATA_POINTS];
    int range;

    cout << "Enter the number of data points: ";
    cin >> n;

    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data point [" <<i+1 <<"] : ";
        cin >> data[i];
    }

    int lag;

    cout << "\nEnter the time lag for autocorrelation: ";
    cin >> lag;

    cout<<"\nEnter the range of coefficient: ";
    cin >> range;

    if (lag < 0 || lag >= n)
        cout << "\nInvalid time lag. It should be >= 0 and < " << n << endl;
    else
    {
        double autocorrelation = calculateAutocorrelation(data, n, lag);
        cout << "\nAutocorrelation coefficient at lag " << lag << ": " << autocorrelation << endl;

        if(autocorrelation >=-range && autocorrelation <=range)
            cout<<"\nThe data is independent\n";
        else
            cout<<"\nThe data is dependent\n";
    }

    return 0;
}

