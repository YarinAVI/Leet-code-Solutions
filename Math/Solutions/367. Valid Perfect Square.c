//https://leetcode.com/problems/valid-perfect-square/
bool isPerfectSquare(int num){
    unsigned long long i=1;
    for(i=1;i<=num;i++) {
        if(i*i==num) return true;
        else if(i*i>num) return false;
    }
    return false;
}