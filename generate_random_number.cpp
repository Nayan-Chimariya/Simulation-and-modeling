#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

// Linear congruent  method
//------------------------//

long long a = 1664525;
long long c = 1013904223;
long long m = 4294967296;


long long liner_generateRandomNumber(long long & previousRand, long long _min, long long _max)
{
    previousRand = (a * previousRand + c) % m;

    long long range = _max - _min + 1;
    return _min + (previousRand % range);
}

long long mid_generateRandomNumber(long long seed, int numDigits)
{
    long long squared = seed * seed;
    long long middleDigits = (squared / static_cast<long long>(pow(10, (numDigits / 2)))) % static_cast<long long>(pow(10, numDigits));
    return middleDigits;
}



int main()
{
    long long seed = static_cast<long long>(time(nullptr));
    long long previousRand  = seed;
    long long currentSeed = seed;
    int numDigits = 4;

    long long _min, _max;
    int numRandomNumbers;

    cout<< "Enter start range and end range: ";
    cin>> _min >>_max;

    cout<< "How many random numbers do you want to generate? : ";
    cin>> numRandomNumbers;

    cout << "\nGenerated using Linear congruent method" << endl;

    for (int i = 0; i < numRandomNumbers; i++)
    {
        long long randNum = liner_generateRandomNumber(previousRand, _min, _max);
        cout << randNum << " ";
    }
    cout<<"\n";

    cout << "\nGenerated using Mid Square method" << endl;
    for (int i = 0; i < numRandomNumbers; i++)
    {
        long long randNum = mid_generateRandomNumber(currentSeed, numDigits);

        randNum = _min + (randNum % (_max - _min + 1));

        cout << randNum <<" ";

        currentSeed = randNum;
    }
    cout<<"\n";



    return 0;
}

/*//mid square method

#include <iostream>

#include <ctime>

// Function to generate a random number using the mid-square method


int main()
{
    const  // Fixed number of digits for each random number
    long long seed = static_cast<long long>(time(nullptr));
    long long _min, _max;
    int numRandomNumbers;




    long long currentSeed = seed;


    return 0;
}*/
