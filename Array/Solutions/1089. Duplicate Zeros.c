

void duplicateZeros(int* arr, int arrSize){
    int i,j,zc=0;
    int temp,t;
    //for(i=0;i<arrSize;i++) 
    for(i=0;i<arrSize-1;i++) {
        if(arr[i]==0) {
            i++;
            temp = arr[i];
            arr[i] = 0;
            for(j=i+1;j<arrSize;j++) t=arr[j],arr[j]=temp ,temp=t;
        }
    }
}