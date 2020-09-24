int maxNumberOfBalloons(char * text){
    int i,min=INT_MAX;
    int *map = (int*)calloc(26,sizeof(int));
    for(i=0;text[i]!='\0';i++) map[text[i]-'a']++;
    
    if(min>map['a'-'a']) min = map['a'-'a'];
    if(min>map['b'-'a']) min = map['b'-'a'];
    if(min>map['l'-'a']/2) min=map['l'-'a']/2;
    if(min>map['o'-'a']/2) min=map['o'-'a']/2;
    if(min>map['n'-'a']) min=map['n'-'a'];
    free(map);
    return min;
}