//
//  main.cpp
//  CSIII_HW_2
//
//  Created by Joshua Peckham on 9/28/16.
//  Copyright © 2016 Joshua Peckham. All rights reserved.
/*  Create class NumDays - Represent number of work hours and convert them to days
    constructor that accepts numbers of hours
    Member Functions for storing and retrieving hours and days
    addition operator
    subtraction operator
    prefix and postfix increment operators
    prefix and postfix decrement operator
    */

#include <iostream>
#include <iomanip>
using namespace std;


class NumDays{
private:
    double* hours;
    double* days;

public:
    NumDays (){
        hours = new double(0);
        days = new double(0);
    }
    NumDays (double &hours){
        this->hours = new double(hours);
        this->days = new double(hours/8);

    }
    NumDays ( const NumDays& u ){
        hours = new double( u.getHours() );
        days = new double( u.getDays() );

    }
    void set (double &n){
        *(this->hours) = n;
        *(this->days) = n/8;
    }
    double getHours() const{
        return *(this->hours);
    }
    double getDays() const{
        return (*(this->days));
    }
    
    // Overriders
    NumDays operator+(NumDays &m){
        double temp = ( *hours + m.getHours() );
        return temp;
    }
    NumDays operator-(NumDays &m){
        double temp = ( *hours - m.getHours() );
        return temp;
    }
    // Prefix
    NumDays operator++(){
        ( *hours )++;
        set(*hours);
        return *this;
    }
    
    // Postfix
    NumDays operator++( int ){
        NumDays temp( *hours );
        ( *hours )++;
        set(*hours);
        return temp;
    }
    
    // Prefix
    NumDays operator--(){
        ( *hours )--;
        set(*hours);
        return *this;
    }
    
    // Postfix
    NumDays operator--( int ){
        NumDays temp( *hours );
        ( *hours )--;
        set(*hours);
        return temp;
    }
    
    
};


int main(){
    double hours;
    
    cout << "How many Hours where worked in week one?" << endl;
    cin >> hours;
    NumDays one(hours);
    
    cout << "How many Hours where worked in week two?" << endl;
    cin >> hours;
    NumDays two(hours), mod;
    
    cout << fixed << setprecision(2) << "Week one Hours: " << one.getHours() << endl;
    cout << fixed << setprecision(2) <<"Week one Days: " << one.getDays() << endl;

    cout << fixed << setprecision(2) <<"Week two Hours: " << two.getHours() << endl;
    cout << fixed << setprecision(2) <<"Week two Days: " << two.getDays() << endl;
    
    mod = one + two;
    cout << fixed << setprecision(2) << "Week one plus week two = " << mod.getHours() << endl;
    
    mod = one - two;
    cout << fixed << setprecision(2) <<"Week one minus week two = " << mod.getHours() << endl;
    
    one++;
    cout << fixed << setprecision(2) <<"one++ = " << one.getHours() << ", " << one.getDays() << endl;
    
    ++one;
    cout << fixed << setprecision(2) << "++one = " << one.getHours() << ", " << one.getDays() << endl;
    
    two++;
    cout << fixed << setprecision(2) <<"two++ = " << two.getHours() << ", " << two.getDays() << endl;
    
    ++two;
    cout << fixed << setprecision(2) << "++two = " << two.getHours() << ", " << two.getDays() << endl;
    
    
    
    return 0;
}
