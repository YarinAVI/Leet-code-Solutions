

int numberOfSteps (int num){
    long int res =0;
    while(num) {
        if(num%2==0) num >>=1;
        else num-=1;
        res++;
    }
    return res;
}