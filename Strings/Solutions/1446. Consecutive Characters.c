

int maxPower(char * s){
    int res = INT_MIN;
    int size = strlen(s);
    for(int i=0;s[i];i++) {
        int counter = 1;
        while(i<size-1 && s[i] == s[i+1]) counter++,i++;
        if(counter > res) res = counter;
    }
    return res;
}