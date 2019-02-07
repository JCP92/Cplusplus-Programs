//  Joshua C. Peckham
//  main.cpp
//  CompScitIII: Hw16
//
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <typename t>
float minimum(t val1, t val2) {
    if(val1 > val2){
        return val2;
    }
    else if (val1 < val2){
        return val1;
    }
    else{
        return val1;
    }
}

template <typename t>
float maximum(t val1, t val2) {
    if(val1 > val2){
        return val1;
    }
    else if (val1 < val2){
        return val2;
    }
    else{
        return val1;
    }
}

int main() {
    float float1 = 3.1,float2 = 5.9;
    char char1 = 'A', char2 = 'D';
    int int1 = 0, int2 = 5;
    
    cout << setw(10) <<"Value A" << setw(10) << "Value B"<< setw(10) << "Minimum"<< setw(10)<< "Maximum"<< endl;
    cout << setw(10) << int1 << setw(10) << int2 << setw(10) << minimum(int1,int2) << setw(10) << maximum(int1,int2)<< endl;
    cout << setw(10) << float1 << setw(10) << float2 << setw(10) << minimum(float1,float2) << setw(10) << maximum(float1,float2)<< endl;
    cout << setw(10) << char1 << setw(10) << char2 << setw(10) << static_cast<char>(minimum(char1,char2)) << setw(10) << static_cast<char>(maximum(char1,char2))<< endl;
    
    
    return 0;
}
