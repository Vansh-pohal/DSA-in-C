#include<stdio.h>


void merge(int arr[],int low,int m, int high){
    int size=high - low + 1;
    int mm=m+1;
    int l=low;
    int h=high;
    int temp[size];
    int k=0;
    while(l<=m && mm<=h){
    if(arr[l]<=arr[mm]){
        temp[k]=arr[l];
        l++;
    }
    else{
        temp[k]=arr[mm];
        mm++;
    }
    k++;
}
    while(l<=m){
        temp[k]=arr[l];
        k++;l++;
    }
    while(mm<=h){
        temp[k]=arr[mm];
        k++;mm++;
    }
int x=low;
    for(int i=0;i<high-low+1;i++){
        arr[x]=temp[i];
        x++;
        
    }
}



void ms(int arr[],int low,int high){
    int m=(low+high)/2;
    if(low!=high){
    ms(arr,low,m);
    ms(arr,m+1,high);
    merge(arr,low,m,high);
}
}



int main(){
    int arr[]={5,6,8,42,7,8,12,8,23,7};
    int low=0;
    int high=(sizeof(arr)/sizeof(int))-1;
    ms(arr,low,high);
    for(int i=0;i<high+1;i++){
        printf("%d  ",arr[i]);
    }
}