#include <iostream>
#include <limits.h>
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

/*
    选择排序: 先找出A中最小的元素，跟A[0]交换，然后再找未排序元素中的最小的元素根A[1]交换，如此类推
 */
void selection_sort(int *A, int num)
{
    int tmp;
    int i, j;
    for (i = 0; i < num - 1; i++) {
        int min = A[i], minpos = i;
        for (j = i; j < num; j++) {
            if(A[j] < min) {
                minpos = j;
                min = A[j];
            }
        }

        // swap
        tmp = A[minpos];
        A[minpos] = A[i];
        A[i] = tmp;
    }
    
}


/**
 * 归并排序，将数组分为两堆，每一次比较两个堆的最顶的值，取最小值出来放到输出堆中，直到两个堆比较完毕
 * 前提，要保证分成的两个堆已经排好序，因此这是整个归并排序的一部分，整个部分可以细化为两个最基本两个元素合并形成有序的子列，然后子列再合并逐渐合并为一个排序的完整序列
 */
void merge(int *A, int p, int q, int r)
{
    // 分成两堆
    int i, j;
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1 + 1]; // +1的原因是设置哨兵观察是否当前堆为空
    int *R = new int[n2 + 1];

    for (i = 0; i < n1; i++) {
        L[i] = A[p+i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = A[q+j+1];
    }    

    L[i] = INT_MAX; // 假设我们知道数组都是正整数，使用负数做哨兵
    R[j] = INT_MAX;

    i = 0;
    j = 0;
    for (int k = p; k <= r; k++) {     // k=p到r就是遍历了全部A
        if (L[i] <= R[j]) { // 分别从两个堆的顶部取两个值比较，注意这里INT_MAX的使用，两个堆肯定会先有一个遍历完，那么意味着剩下的堆的尺寸都是大于另外一个堆的，因此只需要对这个堆进行排序
            A[k] = L[i];
            i = i + 1;
        } else {
            A[k] = R[j];
            j = j + 1;
        }
        
    }

    delete [] R;
    delete [] L;
}

/**
 * merge_sort的思想是分治法，将一段无序的序列切割为最小只包含两个元素的小序列，然后两个元素通过比较生成有序的小序列。
 * 只有两个元素的小序列和其他小序列，合并生成4个元素的有序小序列，再合并生成8个元素的有序小序列，最后将所有元素完成排序
 */
void merge_sort(int *A, int p, int r)
{
    if(p < r) { // 只剩下两个元素就没必要继续分割了
        int q = (p + r) / 2;
        merge_sort(A, p, q); // 通过递归的方式完成排序
        merge_sort(A, q+1, r);
        merge(A, p, q, r); // 这里的作用是合并两个子序列
    }
}

/**
 * 冒泡排序的作用是每一次遍历，就两两交换，将最大值放到左边
 */
void bubble_sort(int *A, int num)
{
    int i, j;
    for(i = 0; i < num; i++) {
        // j循环是冒泡的过程
        int curpos = 0;
        for(j = 0; j < num - i - 1; j++) { // num - i - 1的意思是每经历一次循环，最大值就放到了左边，因此就不用比较左边已经排好序的序列
            if(A[curpos] > A[curpos+1]) {
                int tmp = A[curpos];
                A[curpos] = A[curpos+1];
                A[curpos+1] = tmp;
            }
            curpos = curpos + 1;
        }
    }
}


int main() {
    const int num = 10;
    int *data = new int[num];
    init_rand(data, num, 100);

    
    bubble_sort(data, num);

    for (int i = 0; i < num; i++) {
        cout << data[i] << endl;
    }
    
    delete [] data;
    return 0;
}