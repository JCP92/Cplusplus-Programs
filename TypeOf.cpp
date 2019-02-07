//  Joshua C. Peckham
//  main.cpp
//  CompScitIII: Hw15
//
//

#include <iostream>
#include <string>

using namespace std;

class Ship{
private:
    string shipName;
    string builtYear;
public:
    Ship(){
        shipName = "Empty";
        builtYear = "Empty";
    }
    
    Ship(string n, string m){
        shipName = n;
        builtYear = m;
    }
    
    void setName(string n){
        shipName = n;
    }
    
    void setYear(string m){
        builtYear = m;
    }
    
    virtual string getName() const{
        return shipName;
    }
    
    string getYear() const{
        return builtYear;
    }
    virtual void printInfo() const{
        cout << "Ship Name: " << getName() << endl;
        cout << "Created in: " << getYear() << endl;
    }
};

class CruiseShip : public Ship{
private:
    int maxPass;
    
public:
    CruiseShip(){
        maxPass = 0;
    }
    CruiseShip(int a){
        maxPass = a;
    }
    CruiseShip(string n, int a){
        setPass(a);
        setName(n);
    }
    void setPass(int m){
        maxPass = m;
    }
    
    int getPass() const{
        return maxPass;
    }
    void printInfo()const{
        cout << "Cruise Name: " << getName() << endl;
        cout << "Number of Passengers: " << getPass() << endl;
    }
    
};

class CargoShip : public Ship{
private:
    int maxCargo;
    
public:
    CargoShip(){
        maxCargo = 0;
    }
    CargoShip(int a){
        maxCargo = a;
    }
    CargoShip(string n, int a){
        setCargo(a);
        setName(n);
    }
    void setCargo(int m){
        maxCargo = m;
    }
    
    int getCargo() const{
        return maxCargo;
    }
    void printInfo()const{
        cout << "Cargo Name: " << getName() << endl;
        cout << "Max Wieght: " << getCargo()<< endl;
    }
    
};


int main() {
    string name, year;
    int val;
    cout << "What is the name of the boat and when was it created?" << endl;
    cin >> name >> year;
    
    Ship newS(name, year);
    CruiseShip cruise;
    CargoShip cargo;
    
    cout << "The name of the ship is: \t" << newS.getName() << "\nThe year it was built is: " << newS.getYear() << endl;
    
    cout << "What is the name of the Cruise boat and how many passengers do they have?" << endl;
    cin >> name;
    cin >> val;
    cruise.setPass(val);
    cruise.setName(name);
    cout << "Cruise Name: \t" << cruise.getName() << "\nCruise Max Passanger: \t" << cruise.getPass() << endl;
    
    cout << "What is the name of the Cargo Ship and what is the max capacity?" << endl;
    cin >> name;
    cin >> val;
    cargo.setCargo(val);
    cargo.setName(name);
    cout << "Cargo Name: \t" << cargo.getName() << "\nCargo Max Weight: \t" << cruise.getPass() << endl;
    
    Ship* shipInfo[] =
    {
        new Ship("Ship1", "1992" ),
        new CruiseShip("Ship2", 300),
        new CargoShip("Ship3", 40000)
    };
    
    for (int i = 0; i < 3; i++){
        shipInfo[i]->printInfo();
    }
    
    for (int i = 0; i < 3; i++){
        delete shipInfo[i];
    }
    cout << endl;
    
    return 0;
}
