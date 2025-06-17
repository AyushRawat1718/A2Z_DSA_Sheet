// Problem Statement: Given an array, we have to find the largest element in the array.

#include<bits/stdc++.h>
using namespace std;

// Sort the array, and return the last element
void approach_1(vector<int> arr){
    sort(arr.begin(), arr.end());
    cout<<"Largest element is => "<<arr[arr.size()-1]<<endl;
}

// Keeping a max variable and traversing in the whole array
void approach_2(vector<int> arr){
    int max = arr[0];
    for(int i=1; i<arr.size(); i++){
        if (arr[i] > max) max = arr[i];
    }
    cout<<"Largest element is => "<<max<<endl;
}

int main(){
    vector<int> arr = {2,5,1,3,0};
    approach_1(arr);
    approach_2(arr);
      
    return 0;
}
