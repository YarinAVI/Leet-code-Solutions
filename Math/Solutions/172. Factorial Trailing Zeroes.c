//https://leetcode.com/problems/factorial-trailing-zeroes/submissions/
// we need to return the amount of zeros for given N! number, we can see that every 5 number in N! adds another 0 but when it //turns to be 26 its 5 zeros +1 and this has to be connected to the power of 5 so all the numbers below are powers of 5 to limit
// INT MAX
int trailingZeroes(int n){
return n/5 +n/25 +n/125 +n/625 +n/3125 +n/15625 +n/78125 +n/390625 +n/1953125 +n/9765625 +n/48828125 +n/244140625 +n/1220703125 +n/6103515625;
}