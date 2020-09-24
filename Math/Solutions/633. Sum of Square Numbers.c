//https://leetcode.com/problems/sum-of-square-numbers/submissions/
bool judgeSquareSum(int c){
   // a^2 = c - b^2;
   // a = sqrt( c - b^2 ) b will be a static number 
    
    
    for(long long b=0;b*b<=c;b++){
        double a = sqrt(c-(b*b)); 
        if((int)a == a){
            return true;
        }
    }
    return false;
    
}