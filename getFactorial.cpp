// Joshua C. Peckham and Mandan 
// 2/17/2016
// CS1
// vq6934
// Program 4

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main() {
	int original = 0;
	cout << "Please put in the number you want to calculate the factorial for: " << endl;
	cin >> original;

	int factorial = original;

	for (int i = 1; i <= original; i++) { // Loop to calculate factorial
		if (factorial % i == 0){
			cout << i << endl; 
		}
	}

	return 0;
}