/**
 * Name: Huaqing Wang
 * Description:
 *
 * Date:
 * */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;


template <class T>
int  split ( T * a, int lb, int ub ) {

    int left ( lb + 1), right(ub);

    T  pivate = a[lb];

    while ( left <= right ) {
	while ( a[left] <=  pivate ) left++;
	while ( a[right] >  pivate ) right--;
    	if ( left < right) swap( a[left], a[right] );
    }
    swap( a[lb], a[right] );
    return right;
}    

template <class T>
void qsort( T * a, int lb, int ub ) {

    if ( lb >= ub ) return;

    int k = rand() % ( ub - lb + 1 ) + lb;

    swap( a[lb], a[k] );

    int mid = split ( a, lb , ub );

    qsort(a, lb, mid - 1);
    qsort(a, mid + 1, ub );

}

template <class T>
void qsort( T * a, int size ) {

    qsort( a, 0, size - 1);
}

void display(int *a, int sz ) {
    for ( int i = 0; i < sz; i ++ )
	cout << setw(5) << a[i] ;

    cout << endl;
}

int main( int argc, char * argv[] ) {

    srand( time (0) );

    int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 } ;
   
    //  for ( int i = 0; i < 10; i ++ ) a[i] = rand() % 100;

    display (a, 10);
    qsort( a, 10 ) ;
    display (a, 10);
    return 0;
}
