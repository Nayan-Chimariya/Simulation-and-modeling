#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
const int NUM_STATES = 2;

int main ()
{
    double transitionMatrix[20][NUM_STATES];
    double present_state[20][20], days;

    int i, j;

    cout<< "Create Transition Matrix\n\n";
    for(i=1;i<=NUM_STATES;i++)
    {
        for(j=1; j<=NUM_STATES; j++)
        {
            cout<< "Enter transition probability from state "<<i <<" --> " <<j <<" : ";
            cin>>transitionMatrix[i][j];
        }
    }

    cout<<"\nEnter present state : ";
    cin>> present_state[1][1] >>present_state[1][2];

    cout<<"\nSimulation how many days? : ";
    cin>>days;

    cout<<endl;
    for(i=0; i<days; i++)
    {
        present_state[1][1] = present_state[1][1]*transitionMatrix[1][1]
                            + present_state[1][2]*transitionMatrix[2][1];

        present_state[1][2] = present_state[1][1]*transitionMatrix[1][2]
                            + present_state[1][2]*transitionMatrix[2][2];

        cout<< "[ " <<setprecision(3)<<present_state[1][1] <<"  "
                    <<setprecision(3)<<present_state[1][2] <<" ]\n";
    }

    return 0;
}


