int* replaceElements(int* arr, int arrSize, int* returnSize){
    *returnSize=arrSize;
    int i,max=INT_MIN,temp;
    for(i=arrSize-2;i>=0;i--) {
        if(arr[i+1]>max) {
            temp=arr[i];
            arr[i]=arr[i+1];
            if(temp>arr[i+1]) max=temp;
            else max=arr[i];
        }
        else {
            temp=arr[i];
            arr[i]=max;
            if(temp>max) max=temp;
        }
    }
    arr[arrSize-1]=-1;
    return arr;
}