bool isPowerOfThree(int n){
    double f=n;
    if(n==1) return true;
    if(n<0) return false;
    if(n%2==0) return false;
    while(f>=3) {
        f=f/3;
    }
    if(f==1) return true;
    return false;
}