#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double chiSquareTest(vector<double>& randomNumbers, int numBins)
{
    double minNumber = *std::min_element(randomNumbers.begin(), randomNumbers.end());
    double maxNumber = *std::max_element(randomNumbers.begin(), randomNumbers.end());

    //divide by 0 exception
    if (randomNumbers.front() == randomNumbers.back())
        return 99999; // any max value

    double binWidth = (maxNumber - minNumber) / numBins;
    vector<int> observedCounts(numBins, 0);

    for (const double& number : randomNumbers)
    {
        int bin = static_cast<int>((number - minNumber) / binWidth);
        observedCounts[bin]++;
    }

    double chiSquare = 0.0;
    double expectedCount = static_cast<double>(randomNumbers.size()) / numBins;

    for (int i = 0; i < numBins; i++)
        chiSquare += pow(observedCounts[i] - expectedCount, 2) / expectedCount;

    return chiSquare;
}

double kolmogorovSmirnovTest(vector<double>& randomNumbers)
 {
    vector<double> sortedNumbers = randomNumbers;
    sort(sortedNumbers.begin(), sortedNumbers.end());

    double maxD = 0.0;

    // divide by 0 exception
    if (sortedNumbers.front() == sortedNumbers.back())
        return 99999; // any max value

    for (size_t i = 0; i < sortedNumbers.size(); i++) {
        double empiricalCDF = static_cast<double>(i + 1) / sortedNumbers.size();
        double theoreticalCDF = (sortedNumbers[i] - sortedNumbers.front() + 1.0) / (sortedNumbers.back() - sortedNumbers.front() + 1.0);

        double diff = abs(empiricalCDF - theoreticalCDF);
        if (diff > maxD) {
            maxD = diff;
        }
    }

    return maxD;
}

int main()
{
    //--------------------Chi-Square-test------------------//

    vector<double> randomNumbers;
    double random;
    int numBins = 5, i, n;

    int degreesOfFreedom = numBins - 1;
    double alpha = 0.05;
    double criticalValue = 11.07; // Critical value for alpha = 0.05 and degrees of freedom = 4

    cout<<"How many random numbers do you want to enter? : ";
    cin>> n;

    for(i=0; i<n; i++)
    {
        cout<<"Enter number " <<i+1 <<" : ";
        cin>> random;
        randomNumbers.push_back(random);
    }

    double chiSquareStatistic = chiSquareTest(randomNumbers, numBins);

    cout<<"\nChi-Square test\n";

    if (chiSquareStatistic <= criticalValue)
        cout << "The random numbers follow a uniform distribution" <<endl;
    else
        cout << "The random numbers do not follow a uniform distribution" <<endl;


    //--------------------K-S_test------------------//

    double ksCriticalValue = 1.36 / sqrt(randomNumbers.size()); // Approximation for alpha = 0.05

    double ksStatistic = kolmogorovSmirnovTest(randomNumbers);

    cout<<"\nK-S test\n";

    if (ksStatistic <= ksCriticalValue)
        cout << "The random numbers follow a uniform distribution" <<endl;
    else
        cout << "The random numbers do not follow a uniform distribution" <<endl;

    return 0;
}
