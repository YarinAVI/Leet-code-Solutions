bool isPowerOfThree(int n){
    if(n==1) return true;
    if(n<0) return false;
    if(n%2==0) return false;
    while(n>=3) {
        if(n%3!=0) return false;
        n=n/3;
    }
    return true;
}