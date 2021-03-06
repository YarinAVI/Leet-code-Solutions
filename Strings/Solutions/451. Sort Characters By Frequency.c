
// this function will sort the characters by the amount the appear in decreasing order.
char * frequencySort(char * s){
    int map[126] = {0};
    int i,mem_size=0;
    for(i=0;s[i];i++) map[s[i]-' ']++;
    for(i=0;i<126;i++) mem_size+=map[i];
    char *res = (char*)calloc(mem_size+1,sizeof(char));
    int index;
    int w=0;
    while(mem_size) {
    int max = 1;
    for(i=0;i<126;i++) if(map[i]>=max) index=i,max=map[i];
    map[index]=0;
    while(max) res[w] = index+' ',mem_size--,max--,w++;
    }
    return res;
}