
/*
 * Class: CMSC140 CRN 20433_22867
 * Instructor: Grigoriy A. Grinberg
 * Homework 8
 * Description: write a program that calculates the occupancy rate
   and the total hotel income for one night and displays this
   information as well as some other information described below.
 * Due Date: 12/13/21
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Full Name here: Nadine Wetzler
*/

#include <iostream>
#include <cmath>
using namespace std;

void displayArray(int[], int);
void selectionSort(int[], int);
int findMax(int[], int);
int findMin(int[], int);
double findAvg(int[], int);

void swap(int &, int &); //swap function



int main()
{
    
    const int MIN_SCORE = 0, MAX_SCORE = 100;
    
    int num_of_scores, index, count;
    
    cout << "How many scores do you want to enter ? ";
    cin >>  num_of_scores;
    
    int scores[num_of_scores]; //scores array
    
    for (count = 1, index = 0 ; count <= num_of_scores; count++, index++)
    {
        cout << "Enter score #" << count << ": ";
        cin >> scores[index];
        while (scores[index] < MIN_SCORE || scores[index] > MAX_SCORE)
        {
            cout << "Sorry, scores can only be from 0 - 100." << endl;
            cout << "Enter score #" << count << ": ";
            cin >> scores[index];
        }
    }
    cout << "\nOriginal order scores are: ";
    displayArray(scores, num_of_scores);
    cout << endl;
    
    cout << "\nScores ordered high to low: ";
    selectionSort(scores, num_of_scores);
    cout << endl;
    
    cout << "\nHighest score: " << findMax(scores, num_of_scores) << endl;
    
    cout << "\nLowest score: " << findMin(scores, num_of_scores) << endl;
    
    cout << "\nAverage of scores: " << findAvg(scores, num_of_scores) << endl;
    cout <<  endl;
    
}
void displayArray(int array[], int size)
{
    
    for(int index = 0; index < size; index++)
        cout << array[index] << " ";
}
void selectionSort(int array[], int size)
{
    
    int maxIndex, maxValue;
    
    for(int start = 0; start < (size - 1); start++)
    {
        maxIndex = start;
        maxValue = array[start];
        for(int index = (start + 1); index < size; index++)
        {
            if(array[index] > maxValue)
            {
                maxValue = array[index];
                maxIndex = index;
            }
        }
        swap(array[maxIndex], array[start]);
    }
    
    for(int index = 0; index < size; index++)
        cout << array[index] << " ";
}
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int findMax(int array[], int size)
{
    int maxIndex, maxValue, index, start = 0;
    
        maxIndex = start;
        maxValue = array[start];
        
        for(index = (start + 1); index < size; index++)
        {
            if(array[index] > maxValue)
            {
                maxValue = array[index];
                maxIndex = index;
            }
        }
    return maxValue;
}


int findMin(int array[], int size)
{
    int minIndex, minValue;
    
    for(int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for(int index = (start + 1); index < size; index++)
        {
            if(array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
    }
    return minValue;
}
double findAvg(int array[], int size)
{
    int totalScores = 0;
    double avgScores;
    
    for(int index = 0; index < size; index++)
        totalScores += array[index];
    
    avgScores = (static_cast<double>(totalScores)) / (static_cast<double>(size));
    
    return avgScores;
}

