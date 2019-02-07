//
//  main.cpp
//  Assignment 2
//
//  Created by Joshua Peckham on 7/11/17.
//  Copyright © 2017 Joshua Peckham. All rights reserved.
//

/*
 ** MY ASSIGNMENT **
 the way that this operates is based off of the array itself. Where each element is a specific job and the integer value inside is how long the job will take.
 The two methods I am comparing are:
 1.) First Come First Serve (fcfs)
 2.) Shortest Job First (sjf)
 The Sorting algorithm is bubble sort, the speed of the sorting algorithm is not the main focus of it. If you look inside it has a +2 processing time for the organization peice. Any time it must exchange any of the numbers it that time back into it.
 The runs in 3 different scenerios.
 1.)Where the first one is already in decending order, which is conter productive for both of the CPU Scheduling options, but more so for Shorest Job first.
 2.)The Second one is i just randomely disordered. This doesn't really give either the benefit of the doubt allowing for equal footing for the most part.
 3.)The final order is in ascending order. This actually benefits both of them.
 
 
 */



#include <iostream>
using namespace std;

const int SIZE = 10;
static int p1time, p2time, ab = 0;

void fcfs( int a[]);
void sjf(int a[]);
void printArray(int a[]);
void InsertionSort( int num[]);


void BubbleSort( int &num );

int main(int argc, const char * argv[]) {
    p1time = p2time = 0;
    int process1[SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int process2[SIZE] = { 3, 2, 5, 6, 7, 8, 3, 1, 3, 10 };
    int process3[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int process4[SIZE] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int process5[SIZE] = { 3, 2, 5, 6, 7, 8, 3, 1, 3, 10 };
    int process6[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    
    cout << "********TEST 1********" << endl;
    printArray(process1);
    fcfs(process1);
    cout << "___Bubble Sort___" << endl;
    sjf(process1);
    cout << endl << endl;
    p1time = p2time = 0;
    
    cout << "___Selection Sort___" << endl;
    sjf(process4);
    cout << endl << endl;
    p1time = p2time = 0;
    
    cout << "********TEST 2********" << endl;
    printArray(process2);
    fcfs(process2);
    cout << "___Bubble Sort___" << endl;
    sjf(process2);
    cout << endl << endl;
    p1time = p2time = 0;
    cout << "___Selection Sort___" << endl;
    sjf(process5);
    cout << endl << endl;
    p1time = p2time = 0;
    
    cout << "********TEST 3********" << endl;
    printArray(process3);
    fcfs(process3);
    cout << "___Bubble Sort___" << endl;
    sjf(process3);
    cout << endl << endl;
    p1time = p2time = 0;
    cout << "___Selection Sort___" << endl;
    sjf(process6);
    cout << endl << endl;

    
    return 0;
}
void printArray(int a[]){
    for (int i = 0; i < SIZE; i++){
        cout<< a[i] << " ";
    }
    cout << endl;
}
void InsertionSort( int num[])
{
    int i, j, key;
    for(j = 1; j < SIZE; j++)    // Start with 1 (not 0)
    {
        key = num[j];
        for(i = j - 1; (i >= 0) && (num[i] < key); i--)   // Smaller values move up
        {
            num[i+1] = num[i];
            p2time += 2;
        }
        num[i+1] = key;    //Put key into its proper location
    }
    return;
}
void BubbleSort(int num[])
{
    int i, j, flag = 1;    // set flag to 1 to start first pass
    int temp;             // holding variable
    int numLength = SIZE;
    for(i = 1; (i <= numLength) && flag; i++)
    {
        flag = 0;
        for (j=0; j < (numLength -1); j++)
        {
            if (num[j+1] < num[j])      // ascending order simply changes to <
            {
                temp = num[j];             // swap elements
                num[j] = num[j+1];
                num[j+1] = temp;
                flag = 1;               // indicates that a swap occurred.
                p2time += 2;
            }
        }
    }
    return;   //arrays are passed to functions by address; nothing is returned
}
void fcfs( int a[]){
    cout << "________First Come First Serve________" << endl;
    int b[SIZE];
    for (int i = 0; i < SIZE; i++){
        b[i] = a[i];
    }
    for (int i = 0; i < SIZE; i++){
        p1time += b[i];
    }
    cout << "Array completed in this order: ";
    printArray(b);
    cout << endl;
    cout << "Amount of Time to complete: " << p1time;
    cout << "\nAverge Wait Time: " << (p1time - b[9])/10 << endl;
    cout << "Burst Lengths: " << endl;
    cout << "p0: " << 0 << endl;
    for (int i = 1; i < SIZE - 1; i++){
        cout << "p" << i << ": " << b[i] + b[i-1] << endl;
    }
}
void sjf(int a[]){
    
    cout << "________Shortest Job First________" << endl;
    int b[SIZE];
    for (int i = 0; i < SIZE; i++){
        b[i] = a[i];
    }
    if (ab % 2 == 0)
        BubbleSort(b);
    else
        InsertionSort(b);
    cout << "PTIME " << p2time << endl;
    for (int i = 0; i < SIZE; i++){
        p2time += b[i];
    }
    cout << "Array completed in this order: ";
    printArray(b);
    cout << endl;
    cout << "Amount of Time to complete: " << p2time;
    cout << "\nAverge Wait Time: " << (p2time - b[9])/10 << endl;
    cout << "Burst Lengths: " << endl;
    cout << "p0: " << 0 << endl;
    for (int i = 1; i < SIZE - 1; i++){
        cout << "p" << i << ": " << b[i] + b[i-1] << endl;
    }
}

