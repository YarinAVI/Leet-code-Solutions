

bool isPowerOfTwo(int n){
    unsigned int t=2;
    if(n<1) return false;
if(n==1) return true;
else {
while(t<n) t=t<<1;
   }
    if(t==n) return true;
    else return false; 
}