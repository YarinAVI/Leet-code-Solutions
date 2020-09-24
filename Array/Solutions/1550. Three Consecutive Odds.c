bool threeConsecutiveOdds(int* arr, int arrSize){
    int i,j,k;
    for(i=0,j=1,k=2;k<arrSize;k++,i++,j++) {
        if(arr[i]%2!=0 && arr[j]%2!=0 && arr[k]%2!=0) return true;
    }
    return false;
}