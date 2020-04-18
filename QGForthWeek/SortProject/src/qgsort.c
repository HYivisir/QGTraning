#include<stdio.h>
#include<stdlib.h>
#include"../inc/qgsort.h"

// 插入排序
void insertSort(int *a,int n){
    int temp;
    int i;
    for(i=1;i<n;i++){
        if(a[i] < a[i-1]){
            int j = i-1;
            temp = a[i];
            while (j>-1 && temp <= a[j])
            {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = temp;
        }
    }
}

// 归并排序
void MergeArray(int *a,int begin,int mid,int end,int *temp){
    
}

int main(){
    int a[] = {5,5,2,4,9,8};
    insertSort(a,6);
    for(int i = 0;i<6;i++){
        printf("%d,",a[i]);
    }
}