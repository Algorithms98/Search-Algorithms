//
// Created by PRINCE NDHLOVU on 9/14/20.
//The source code for the 3 algorithms was sourced from Geek for Geeks
// https://www.geeksforgeeks.org/
//

#include "SortingAlgos.h"


void SortingAlgos::bubbleSort(vector<int>& nums) {

    int i,j, temp;

    for(i = 0; i < nums.size() - 1; i++){
        for(j = 0; j < nums.size() - i - 1; j++)
            if(nums[j] > nums[j+1]){
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
    }

}

void SortingAlgos::insertionSort(vector<int>& nums) {

    int i, j, temp;

    for(i = 1; i < nums.size(); i++){

        temp = nums[i];
        j = i-1;

        while(j >= 0 && nums[j] > temp){

            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = temp;
    }

}

void SortingAlgos::merge(vector<int> & nums, int left, int mid, int right) {

    int i, j, k;

    int lower = mid - left + 1;
    int upper = right - mid;

    int Left[lower];
    int Right[upper];

    for(i = 0; i < lower; i++){
        Left[i] = nums[left + i];
    }

    for(j = 0; j < upper; j++){
        Right[j] = nums[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < lower && j < upper){

        if(Left[i] <= Right[j]){
            nums[k] = Left[i];
            i++;
        }
        else{
            nums[k] =  Right[j];
            j++;
        }
        k++;

    }

    while (i < lower){

        nums[k] = Left[i];
        i++;
        k++;
    }

    while(j < upper){
        nums[k] = Right[j];
        j++;
        k++;
    }

}

void SortingAlgos::mergeSorter(vector<int> & nums, int left, int right) {

    if(left < right){
        int mid = (right + left) / 2;
        mergeSorter(nums, left, mid);
        mergeSorter(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

}
void SortingAlgos::mergeSort(vector<int>& nums) {

    mergeSorter(nums, 0, nums.size() - 1);

}
