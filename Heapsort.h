#include <iomanip>
#include <cstdlib>

using namespace std;

template <class T>
void BuildHeap (T a[], int size) {
    for (int i=(size/2)-1; i>=0; i--) {
        heapDown(a, size, i); } }

template <class T>
void heapDown (T a[], int size, int parent) {
    int largerChild = findLargerChild (a, size, parent);
    if (largerChild <=0)
        return;
    else
        swap (a[parent], a[largerChild]);
    heapDown (a, size, largerChild); }

template <class T>
int findLargerChild (T a[], int size, int parent) {
    int rightChild = (parent+1)*2;
    int leftChild = rightChild -1;
    int largerChild = (rightChild >= size) ? leftChild : (a[rightChild] >= a[leftChild]) ? rightChild : leftChild;
    if (leftChild>=size)
        return -1;
    return a[largerChild] > a[parent] ? largerChild : -1;}

template <class T>
void heapSort (T a[], int size) {
    buildHeap( a, size);
    for (int nextOne = size-1; nextOne > 0; nextOne--) {
        swap ( a[0], a[nextOne]);
        heapDown (a, nextOne, 0); }}
