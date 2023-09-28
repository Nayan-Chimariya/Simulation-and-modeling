#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int NUM_GROUPS = 3;
const int NUM_TRIALS = 1000;

void pokerTest(int data[], int dataSize)
{
    if (dataSize % NUM_GROUPS != 0) {
        cerr << "Error: Data size must be divisible by " << NUM_GROUPS << endl;
        return;
    }

    int counts[NUM_GROUPS] = {0};
    int groupSize = dataSize / NUM_GROUPS;

    for (int i = 0; i < dataSize; i += groupSize)
    {
        int group[groupSize];
        copy(data + i, data + i + groupSize, group);
        sort(group, group + groupSize);
        int uniqueCount = unique(group, group + groupSize) - group;
        counts[uniqueCount - 1]++;
    }

    double chiSquared = 0.0;

    for (int i = 0; i < NUM_GROUPS; i++)
        chiSquared += pow(counts[i] - (dataSize / NUM_GROUPS), 2) / (dataSize / NUM_GROUPS);


    double criticalValue = 9.488;

    cout << "\nChi-Squared Value: " << chiSquared << endl;
    cout << "\nCritical Value: " << criticalValue << endl;

    if (chiSquared <= criticalValue)
        cout << "\nThe sequence appears to be random (passes Poker Test).\n";
    else
        cout << "\nThe sequence does not appear to be random (fails Poker Test).\n";

}

int main()
{
    int data[NUM_TRIALS], n;

    cout << "Enter the number of data points: ";
    cin >> n;

    cout<<endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data point [" <<i+1 <<"] : ";
        cin >> data[i];
    }


    pokerTest(data, n);

    return 0;
}

