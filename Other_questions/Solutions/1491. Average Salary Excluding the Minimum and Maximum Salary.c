int cmp(const void*a,const void *b) {
    return (*(int*)a) - (*(int*)b);
}

double average(int* salary, int salarySize){
    qsort(salary,salarySize,sizeof(int),cmp);
    double res = 0;
    for(int i=1;i<salarySize-1;i++) {
        res+=salary[i];
    }
    res /= (salarySize-2);
    return res;
}