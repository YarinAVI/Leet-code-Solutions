

int hammingDistance(int x, int y){
if (x==y) return 0;
    x=x^y; // we xor here, you can look on their example and understand why using xor
    y=0;
    int i;
    for(i=0;i<=31;i++) if((x>>i)&1 == 1) y++;
    return y;
}