bool hasAlternatingBits(int n){
    bool a = false;
    bool b = false;
    while(n) {
        a = n & 1;
         n = n >> 1;
        if(n)  {
            b = n & 1;
            if(a==b) return false;
        }
        
    }
    return true;
}