// balancing algorithm... straight forward solution.
int minAddToMakeValid(char * S){
    int i=0;
    int open=0;
    int res=0;
    while(S[i]) {
        if(S[i]=='(') {
            open++;
        }
        else {
            if(open) open--;
            else res++;
        }
        i++;
    }
    return open+res;
}