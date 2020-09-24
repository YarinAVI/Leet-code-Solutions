int reverse(int x){
int temp=x;
    long check=0;
    int res=0;
    int i=0;
    for(i=0;temp!=0;i++) temp/=10;
    printf("%d",i);
    for(;i>=0;i--) check+=x%10*pow(10,i-1), x/=10;
    if(check>INT_MAX || check<INT_MIN) return 0;
    else res=check;
    return res;
}