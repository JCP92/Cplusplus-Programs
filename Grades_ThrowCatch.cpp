//  Joshua C. Peckham
//  main.cpp
//  CompScitIII: Hw16
//
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class TestScores{
private:
    float scores[];
public:
    class OutsideParameters{};
    TestScores(int n){
        scores[n] = {0};
    }
    void setScore(int n){
        for(int i = 0; i < n ; i++){
            cout << "Grade " << (i+1) << "?:" << endl;
            cin >> scores[i];
            if( (scores[i] < 0) || (scores[i] > 100) ) {
                throw scores[i];
            }
        }
    }
    void viewScores(int n)const{
        cout << "Scores: " << endl;
        for(int i = 0; i < n ; i++){
            cout << setw(7) << scores[i] << endl;;
        }
    }
    float Average(int n){
        float sum = 0;
        for(int i = 0; i < n ; i++) {
            sum += scores[i];
        }
        return (sum/n);
    }

};

int main() {
    int n = 0;
    TestScores l(n);
    cout << "How many grades will be input today?" << endl;
    cin >> n;
        try {
            l.setScore(n);
            l.viewScores(n);
            cout << "The Average is: " << l.Average(n);
            }
        catch (float a){
            cout << "Error: Invalid Number" << endl;
        }
    cout << "End of program" << endl;
    return 0;
}
