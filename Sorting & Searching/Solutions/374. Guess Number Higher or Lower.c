/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
	int right = n;
    int left =1;
    int m;
    while(left<=right) {
        m=left+(right-left)/2;
        //printf("%d %d %d %d\n",left,right,m,guess(m));
        if(guess(m)==0) return m;
        else if(guess(m)==1) left=m+1;
        else if(guess(m)==-1) right =m-1;
        //printf("%d %d %d\n",left,right,m);
    }
   // printf("%d %d %d",left,right,m);
    return -1;
}