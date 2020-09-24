bool checkIfExist(int* arr, int arrSize){
    float d[arrSize];
    int i,j,Zcounter=0;
    for(i=0;i<arrSize;i++) {
        d[i]=(float)arr[i]/2;
        if((float)arr[i]/2==0) Zcounter++;
    }
    if(Zcounter>=2) return true;
    for(i=0;i<arrSize;i++) printf("%f ",d[i]);
    for(j=0;j<arrSize;j++) {
        while(d[j]-(int)d[j]!=0 && j<arrSize-1) j++;
        for(i=0;i<arrSize;i++) {
            if(d[j]==arr[i] && arr[i]!=0) return true;
        }
    }
    
    return false;
}