
//https://leetcode.com/problems/palindrome-number/
bool isPalindrome(int x){
if(x<0) return false;
    // check how many digits the number have :
    int i,check=x,ndigits=0,g,b;
    while(x) x/=10,ndigits++;
    x=check,b=check,check=0;
    while(x) {
        g=x%10;
        x/=10;
        check+=g*pow(10,ndigits-1);
        ndigits--;
    }
    if(check==b) return true;
    else return false;
}