

int subtractProductAndSum(int n){
    int temp = n;
    int p = 1,s =0;
    while(temp) p*=temp%10,temp/=10;
    temp = n;
    while(temp) s+=temp%10,temp/=10;
    return p-s;
}