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
	int num, i, revised, val1; //Initialize variable
	int total = 0, sizeOfnum = 0, o = 1; //Initialize variable

										
	for (num = 1; num <= 500; num++) { // loop through desiginated number groop
		sizeOfnum = num;
		for (o; sizeOfnum > 0; o++) { //Count the size of the number
			sizeOfnum /= 10;
		}
		revised = num; // allows original number to be modified to complete for loop
		for (i = 1; i < o; i++) { // loop to create create variable check for armstrong number
			val1 = revised % 10;
			revised /= 10;
			total += (pow(val1, 3));
		}
		if (num == total) { //Determine if amrstrong number
			cout << num << endl;
			total = 0;
		}
		else {
			total = 0; // return value to run again
		}
	}
	return 0;
}