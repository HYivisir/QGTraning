#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include"../inc/qgsort.h"

// 打印
void PrintArr(int *a,int size){
    for(int i = 0;i<size;i++){
        printf("%d->",a[i]);
    };
    printf("\n");
}
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

// 归并排序（合并数组）
void MergeArray(int *a,int begin,int mid,int end,int *temp){
    int left = begin;
    int t = left;
    int right = mid + 1;
	while (left <= mid && right <= end){
		if (a[left] < a[right]){
			temp[t++] = a[left++];
		}
		else{
			temp[t++] = a[right++];
		};
	}
	while (left <= mid){
		temp[t++] = a[left++];
	};
	while (right <= end){
		temp[t++] = a[right++];
    };
    memcpy(a + begin, temp + begin, sizeof(int)*(end-begin+1));
}

// 归并排序
void MergeSort(int *a,int begin,int end,int *temp){
    int middle = 0;
    if(begin < end){
        middle = (begin+end)/2;
        MergeSort(a,begin,middle,temp);
        MergeSort(a,middle + 1,end,temp);
        MergeArray(a,begin,middle,end,temp);
        
    }
}

// 快速排序（递归版）
void QuickSort_Recursion(int *a, int begin, int end){
    if(begin < end){
        int left = begin;
        int right = end;
        int temp = a[left];
        while(left<right){
            // 从右开始，找到比temp小的值，放在左边
            while(left<right && a[right] >= temp){
                right--;
            };
            if(left<right){
                a[left++] = a[right];
            };

            // 从左开始，找到比temp大的值，放在右边
            while(left < right && a[left] <temp){
                left++;
            };
            if(left<right){
                a[right--] = a[left];
            };
        }
        a[right--] = temp;
        // 左右分开排序
        QuickSort_Recursion(a,begin,left - 1);
        QuickSort_Recursion(a,left + 1,end);
    }

}


// 计数排序
void CountSort(int *a, int size){
    int max = a[0],min = a[0];
    int i,j=0;
    for(i=0;i<size;i++){
        if(a[i]>max){
            max = a[i];
        };
        if(a[i]<min){
            min = a[i];
        };
    };

    int length = max - min + 1;
    int *temp = (int*)calloc(length,sizeof(int));
    for(i = 0;i<size;i++){
        temp[a[i] - min]+=1;
    };

    for(i=0;i<length;i++){
        while(temp[i]--){
            a[j] = i + min;
            j++;
        }
    };

    free((void*)temp);
}

// 桶排序
void BucketSort(int *a,int size){
    int max = a[0];
    int i,j;
    for(i=0;i<size;i++){
        if(a[i]>max){
            max = a[i];
        };
    };
    int length = max + 1;
    int *temp = (int*)calloc(length,sizeof(int));
    // 装桶
    for(i=0;i<size;i++){
        temp[a[i]]++;
    };

    // 出桶
    for(i=0,j=0;i<length;i++){
        while(temp[i]!=0){
            a[j] = i;
            j++;
            temp[i]--;
        }
    };
    free((void*)temp);
};

// 基数排序
void RadixCountSort(int *a,int size){
    int *temp = (int*)calloc(size,sizeof(int));
	int rad = 1;
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	while (max / rad > 0)
	{
		int* count = (int*)calloc(10,sizeof(int));
		int key;
		//统计当前位数出现次数
		for (int i = 0; i < size; i++)
		{
			//统计个数
			key = a[i] / rad % 10;
			count[key]++;
		}
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		for (int i = size - 1; i >= 0; i--)
		{
			//位数对应的数字
			key = a[i] / rad % 10;
			temp[--count[key]] = a[i];
		}
		//将temp复制给a
		for (int i = 0; i < size; i++)
		{
			a[i] = temp[i];
		}
		rad *= 10;
	}
}
// 颜色排序
void ColorSort(int *a,int size){
    int left = 0;
    int right = size-1;
    int temp;
    for(int i=0;i<size;i++){
        if(a[i]<a[left]){
            temp = a[left];
            a[left++] = a[i];
            a[i] = temp;
        };
        if(a[i]>a[right]){
            temp  = a[right];
            a[right++] = a[i];
            a[i] = temp;
        };
    };
    
}
// 查询第几小
int researchKey(int* a,int size,int key){
    BucketSort(a,size);
    return a[key];
}
// 打印菜单
void menu(){
    printf("-----------------------------------------\n\
-----------*欢迎进入排序管理系统*--------\n\
-----------------------------------------\n\
--------------*请选择以下功能*-----------\n\
-----------------------------------------\n\
||     1      ||-------->||插入排序      ||\n\
||     2      ||-------->||归并排序      ||\n\
||     3      ||-------->||快速排序(递归)||\n\
||     4      ||-------->||计数排序      ||\n\
||     5      ||-------->||基数排序      ||\n\
||     6      ||-------->||颜色排序      ||\n\
||     7      ||-------->||寻找第k小值   ||\n\
||     8      ||-------->||退出系统      ||\n\
-----------------------------------------\n\
请选择功能(以第一个字符为标准):");
}

void bignum(){
    printf("-----------------------------------------\n\
-----------*欢迎进入排序时间测试*--------\n\
-----------------------------------------\n\
--------------*请选择以下量级*-----------\n\
-----------------------------------------\n\
||     1      ||-------->||10000         ||\n\
||     2      ||-------->||50000         ||\n\
||     3      ||-------->||200000        ||\n\
||     4      ||-------->||100*100k      ||\n\
||     5      ||-------->||退出系统      ||\n\
-----------------------------------------\n\
请选择功能(以第一个字符为标准):");
}
