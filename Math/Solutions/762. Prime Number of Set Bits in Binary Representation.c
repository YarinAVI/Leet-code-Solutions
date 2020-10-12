bool is_prime(int n) {
    if(n==2) return true;
    else if(n%2 == 0 || n == 1) return false;
    for(int i = 3 ; i<n ; i+=2) {
        if( (n%i) == 0) return false;
    }
    return true;
}

int countPrimeSetBits(int L, int R){
    int res = 0;
    for(int i=L;i<=R;i++) {
        int x = __builtin_popcount(i);
        if(is_prime(x)) res++;
    }
    return res;
}