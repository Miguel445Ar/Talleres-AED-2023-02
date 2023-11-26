#ifndef __SORTING_ALGORITHMS__
#define __SORTING_ALGORITHMS__

#include <functional>
#include <vector>

using std::function;
using std::vector;

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
    static void mergeSort(vector<T>& arr, function<bool(T,T)> isLowerThan) {
        recursiveMergeSort(0, arr.size() - 1, arr, isLowerThan);
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
    static void recursiveMergeSort(int i, int f, vector<T>& arr, function<bool(T,T)>& isLowerThan) {
        if(i == f) return;
        int medium = (i + f) / 2;
        recursiveMergeSort(i, medium, arr, isLowerThan);
        recursiveMergeSort(medium + 1, f, arr, isLowerThan);
        mergeHalfs(i, f, medium, arr, isLowerThan);
    }
    static void mergeHalfs(int i, int f, int medium, vector<T>& arr, function<bool(T,T)>& isLowerThan) {
        size_t size = (f - i) + 1;
        T* aux = new T[size];
        size_t l = i, r = medium + 1, k = 0;
        while(l <= medium && r <= f) {
            if(isLowerThan(arr[l],arr[r]))
                aux[k++] = arr[l++];
            else 
                aux[k++] = arr[r++];
        }
        while(l <= medium)
            aux[k++] = arr[l++];
        while(r <= f)
            aux[k++] = arr[r++];
        for(size_t j = 0; j < size; ++j)
            arr[i + j] = aux[j];
        delete[] aux;
    }
};


#endif