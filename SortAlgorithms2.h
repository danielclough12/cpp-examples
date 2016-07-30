#ifndef SORTALGO_H
#define SORTALGO_H


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template <class T>

void iSort( T a[],  int sz ) {
    T val;
    for ( int i = 1; i < sz; i ++ ) {
	val = a[i];
	int j = i ;
	while ( j > 0 ) { 
	   if ( a[j-1] <  val )  break ;
	   else { 
	   	a[j] = a[j-1];
	   	j --;
	   }
	}
	a[j] = val;
    }
}

template <class T>
int split( T a[],  int start, int end) {
    int i = start + 1, j = end; 
    while ( i <= j ) {
       for ( ;  a[j] > a[start];  j-- ) ;
       for ( ;  a[i] <= a[start]; i++ );
       if ( i <  j ) swap( a[i], a[j] );
    }
    swap( a[start], a[j]);
    return j;
}

template <class T>
void qSort( T a[],  int start, int end) {
    if ( start >= end ) return;
    int mid = split( a, start, end );

    qSort(a, start, mid - 1);
    qSort(a, mid + 1, end);
}

template <class T>
void qSort( T a[],  int sz ) {
    qSort( a, 0, sz - 1 );
}

// Find a child which is the bigger biger child of 1 child or 2 children
// of the parent located at startIdx. -1 is return if no such child.
template <class T>
int findLargerChild ( T a[],  int parent, int endIdx ) {
    int rChild = (parent + 1) * 2;
    int lChild = rChild - 1;
    if (parent >= endIdx || lChild > endIdx ) return -1;
    if ( lChild == endIdx )
	return ( a[lChild] > a[parent] ? lChild : -1 );
    int largerOne = a[lChild] >= a[rChild] ? lChild : rChild;
    return ( a[largerOne] > a[parent] ? largerOne : -1 );
}


template <class T>
void heapDown( T a[],  int startIdx, int endIdx ) {
    if ( startIdx >= endIdx ) return;

    // Find a child which is the bigger biger child of 1 child or 2 children
    // of the parent located at startIdx. -1 is return if no such child.
    int lgChild = findLargerChild( a, startIdx, endIdx );

   if ( lgChild < 0 ) return;
   swap ( a[startIdx], a[lgChild]);
   heapDown(a, lgChild, endIdx );
}

template <class T>
void buildHeap( T a[],  int sz ) {
    for ( int i = sz / 2 - 1; i >= 0 ; i -- ) 
	heapDown(a,  i, sz - 1);
}

template <typename T>
void heapSort(T a[], int sz) {

    buildHeap( a, sz);
    while ( sz > 0 ) {
    	sz--;
	swap( a[0], a[sz] );
	heapDown(a, 0, sz - 1);
    }
} 

template <typename T>
void displayOneLevel (T *a, int levels, int level,
			int lb, int ub ) {
   int skip = int(pow(2.0, levels - level) - 1);
   for ( int i = lb; i <= ub; i ++ ) 
	cout << setw(skip) << " " << setw(2) << a[i] << setw(skip) << " ";
   cout << endl << endl;
}

template <typename T>
void showHeap (T a[], int sz) {
   int  rowLength, lb(0), ub(0), size(sz),
	levels = (int)(ceil(log((float)sz )/log(2.0)));

    cout << endl;
    for (int level = 0; level <= levels; level++ ) {
	displayOneLevel(a, levels, level, lb, ub );
	rowLength = ub - lb + 1;
	lb = ub + 1;
	ub = min( ub + 2 * rowLength, sz - 1);
   }
}

#endif
