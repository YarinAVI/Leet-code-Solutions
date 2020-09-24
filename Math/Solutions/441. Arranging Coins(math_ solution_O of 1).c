
int arrangeCoins(int n){
    //calculate first root, if it equals 2n return it, if its less return its floor value(int)
    // we calculate the first root using the famous formula -b +-sqrt(b^2-4ac) /2a
    // intution to form this formula comes from the fact that if we add another stair
    // it basically creates series of numbers... then you come up with the formula
    // x^2 +x -2n = 0, where N is given.
    double k = 2 * (double)n;
    printf("%lf ",k);
    double res =(-1 + sqrt(1+4*k) );
    printf("%lf",res);
    res /=2;
    return res;
}