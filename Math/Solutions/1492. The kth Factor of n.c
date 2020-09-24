int kthFactor(int n, int k){
    int counter = 0;
    int divider = n;
    int res;
    while(counter<k && divider >=1) {
        if(n%divider==0) counter++,res=n/divider;
        divider--;
    }
    if(counter!=k) return -1;
    return res;
}