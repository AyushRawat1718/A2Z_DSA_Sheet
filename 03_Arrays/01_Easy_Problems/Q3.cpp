// Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

// Note: Two consecutive equal values are considered to be sorted. That means every current element could either be greater or equal to the previous element.

#include<bits/stdc++.h>
using namespace std;

// Returning false whenever the previous element is greater than the current element 
bool approach_1(vector<int> arr){
    for (int i=1; i<arr.size(); i++){
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main(){
    vector<int> arr = {1, 6, 2, 3, 4, 5};
    (approach_1(arr)) ? cout<<"Sorted\n" : cout<<"Not Sorted\n";

    return 0;
}