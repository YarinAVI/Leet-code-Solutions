int minOperations(char ** logs, int logsSize){
    int res =0;
    for(int i=0;i<logsSize;i++) {
        if(logs[i][0] == '.' && logs[i][1] =='.' && res) res--;
        else if(logs[i] == '.') continue;
        else if(logs[i][0]!='.') res++;
    }
    return res;
}