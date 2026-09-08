#include<stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}



int partition(int arr[],int low,int high){
    
    int pivot = arr[low];
    int pivotPosition = low;
    while(low<high){
        while(low <= high && arr[low] <= pivot){
            low++;
        }
        while(high >= low && arr[high] > pivot){
            high--;
        }
        if(low<high){
            
            swap(&arr[low], &arr[high]);
            
        }
        
    }
    swap(&arr[pivotPosition], &arr[high]);
    return high;
}



void QS(int arr[],int low,int high){
    if(low<high){
        int pivotindex=partition(arr,low,high);
        QS(arr,low,pivotindex-1);
        QS(arr,pivotindex+1,high);
    }
}


int main(){
    int arr[]={7,8,2,3,6};
    int low=0,high=(sizeof(arr)/sizeof(int))-1;
    QS(arr,low,high);
    for(int i=0;i<=high+1;i++){
        printf("%d ",arr[i]);
    }
}