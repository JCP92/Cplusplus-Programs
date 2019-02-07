// Joshua C. Peckham and Mandan 
// 2/17/2016
// CS1
// vq6934
// Program 1

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main() {
	int range1 = 0;
	cout << "Please insert the numbers you want to find the Prime numbers to: " << endl;
	cin >> range1;// select range

	bool flag = true;
	int n;
	for (int i = 2; i <= range1; i++) { //Loop through number
		flag = true;
		for (n = 2; n < i; n++) { //Test for prime number
			if ((i % n) == 0) {
				flag = false;
			}
		}
		if (flag) {//Display prime
			cout << "Prime: " << i << endl;
		}
	}
	return 0;
}