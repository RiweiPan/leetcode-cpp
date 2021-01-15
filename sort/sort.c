#include <iostream>
#include "../utils/utils.h"

using namespace std;

void insertion_sort(int *A, int num)
{
    for(int j = 1; j < num; j++) {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
}


int main() {
    const int num = 10;
    int *data = new int[num];
    init_rand(data, num, 50);

    insertion_sort(data, num);

    for (int i = 0; i < num; i++) {
        cout << data[i] << endl;
    }
    

    delete [] data;
    return 0;
}