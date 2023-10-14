#ifndef __SORTING_ALGORITHMS__
#define __SORTING_ALGORITHMS__

#include <functional>

using std::function;

template<class T>
class SortingAlgorithms {
public:
    SortingAlgorithms() = delete;
    SortingAlgorithms(SortingAlgorithms& other) = delete;
    SortingAlgorithms(SortingAlgorithms&& other) = delete;

    static void quickSelect(int l, int r, int& p, T* arr, function<bool(T,T)> isLowerThan) {
        while(l < r) {
            while(isLowerThan(arr[l], arr[p])) ++l;
            while(isLowerThan(arr[p], arr[r])) --r;
            swap(arr[l],arr[r]);
            if(l == p){
                p = r;
                ++r;
            }
            else if(r == p) {
                p = l;
                --l;
            }
            ++l;
            --r;
        }
    }
    static void quicksort(int i, int f, T* arr, function<bool(T,T)> isLowerThan) {
        recursiveQuickSort(i, f, arr, isLowerThan);
    }
private:
    static void recursiveQuickSort(int i, int f, T* arr, function<bool(T,T)> isLowerThan) {
        if(i >= f) return;
        int pivot = (i + f) / 2;
        quickSelect(i,f,pivot,arr,isLowerThan);
        recursiveQuickSort(i, pivot -1, arr, isLowerThan);
        recursiveQuickSort(pivot + 1, f, arr, isLowerThan);
    }
    static void swap(T& a, T& b) {
        T c = a;
        a = b;
        b = c;
    }
};


#endif