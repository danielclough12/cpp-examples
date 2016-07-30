#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

template <class T>
void insertSort(T a[], int size) {
    T val;
    for (int i = 1; i<size; i++) {
        val = a[i];
        int j = i-1;
        while(j>0) {
            if (val>a[j-1])
                break;
            else {
                a[j+1] = a[j];
                if (j==0)
                    break;
                j--; }}
         a[j] = val; }
}
#endif
