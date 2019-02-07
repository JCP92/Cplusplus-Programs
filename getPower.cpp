// Joshua C. Peckham and Mandan 
// 2/17/2016
// CS1
// vq6934
// Program 5

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main() {
	int val1, val2, i = 0, n = 0;
	cout << "Insert two numbers that you would like to find the power of: " << endl;
	cin >> val1 >> val2;
	
	i = val1;
	n = val2;
	for (n; 1 < n; n--) { // loop for val1 ^ val2
		i *= val1;
	}
	cout << "The " << val1 << "^(" << val2 << ")" << " = " << i << endl;

	i = val2;
	n = val1;
	for (n; 1 < n; n--) { // Loop for val2 ^ val1
		i*= val2;
		}
	cout << "The " << val2 << "^(" << val1 << ")" << " = " << i << endl;

	return 0;
}