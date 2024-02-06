#include <iostream>
#include <cstdlib>

#include "fisher_yates.h"
#include "prefix_sum.cpp"
using namespace std;

int main() {
    srand(time(NULL));
    string n_string;
    string trials_string;
    cout << "Enter the number of parens: " << endl;
    cin >> n_string;
    cout << "Enter the number of trials: " << endl;
    cin >> trials_string;
    int n;
    int trials;

    n = stoi(n_string);
    trials = stoi(trials_string);

    int arrayValues[n*2];

    for (int i=0; i<2*n; i++) { 
        arrayValues[i] = 1;
    }

    for (int i=0; i<n; i++) {
        arrayValues[i+n] = -1;
    }

    cout << "Testing..." << endl;

    int s = 0;

    for(int i = 0; i < trials; i++){
        fisher_yates(arrayValues, n*2, std::rand);
        print_array(arrayValues, n*2);
        if (check_validity(arrayValues, n*2)){
            s++;
            cout << "Sequence above is valid!" << endl;
        }
    }

    cout << s << " out of " << trials << " trials were valid." << endl;

}