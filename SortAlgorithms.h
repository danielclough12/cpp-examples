#ifndef SORTALGO_H
#define SORTALGO_H

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
#endif

