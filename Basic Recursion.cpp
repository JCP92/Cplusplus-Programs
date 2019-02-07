//
//  main.cpp
//  as
//
//  Created by Joshua Peckham on 11/12/16.
//  Copyright © 2016 Joshua Peckham. All rights reserved.
//

#include <iostream>
using namespace std;

int recursive(int ar[], int i);

int main() {
    const int SIZE = 5;
    int nav = SIZE;
    int ar[SIZE] = { 1, 2, 3, 4, 5 };
    cout << "The Sum of the Array is: " << recursive(ar, (nav-1)) << endl;
    return 0;
}

int recursive(int ar[], int i) {
    if (i == 0) {
        return ar[i];
    }
    else {
        return ar[i] + recursive(ar, (i-1));
    }
}
