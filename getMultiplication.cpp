// Joshua C. Peckham and Mandan 
// 2/17/2016
// CS1
// vq6934
// Program 7

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main() {
	int i = 0, n, multiTable;
	cout << "Please insert the number you would like the multiplication table to: " << endl;
	cin >> multiTable;

	for (i; i <= multiTable; i++) { // display multiple table 
		n = multiTable*i;
		cout << multiTable << " * " << i << " = " << n << endl;
	}


	return 0;
}
