// Joshua C. Peckham and Mandan 
// 2/17/2016
// CS1
// vq6934
// Program 1

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	// Initialize variables 
	int reverse=0, original, edited, i=1, tran;

	cout << "Please enter a number to determine if it is a palendrome: " << endl;
	cin >> original;

	// Deterimin size of original
	for (int sizeOfOrigin = original; sizeOfOrigin > 0; i++) {
		sizeOfOrigin /= 10; 
	}

	edited = original; // create reverse number
	for (int o = 1; o <= i; o++) {

		tran = edited % 10;
		reverse = (reverse * 10) + tran;
		edited /= 10;

		if (edited == 0)
			break;
	}
	if (original == reverse) { // check if palindrome
		cout << "This is a palendrome becuase the original amount is: " << original << endl; 
		cout << "and the reverse amount is: " << reverse << endl;
	}
	else {
		cout << "This is not a palendrome becuase the original amount is: " << original;
		cout << "and the reverse amount is: " << reverse << endl;
	}

	return 0;
}

