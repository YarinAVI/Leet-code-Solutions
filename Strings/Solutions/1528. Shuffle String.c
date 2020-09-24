char * restoreString(char * s, int* indices, int indicesSize){
    char * res = (char*)calloc(indicesSize+1,sizeof(char));
    int i;
    for(i=0;i<indicesSize;i++) {
        res[indices[i]] = s[i];
    }
    return res;
}