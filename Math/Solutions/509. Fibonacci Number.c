int fib(int N){
    if(N==1) return 1;
    int t1=0,t2=1,t3=0;
    int i;
    for(i=1;i<N;i++) {
        t3=t1+t2;
        t1=t2;
        t2=t3;
    }
    return t3;
}