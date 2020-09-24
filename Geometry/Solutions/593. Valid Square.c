int compare (const void * a, const void * b)
{
  if (*(double*)a > *(double*)b)
    return 1;
  else if (*(double*)a < *(double*)b)
    return -1;
  else
    return 0;  
}
int cmp1 (const void *a , const void *b) {
    return (*(int*)a-*(int *)b);
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
    int x[4] = {p1[0],p2[0],p3[0],p4[0]};
    int y[4] = {p1[1],p2[1],p3[1],p4[1]};
    int max_y=INT_MIN;
    int max_x,i,not,k;
    for(i=0;i<4;i++) {
        if(y[i]>max_y) max_y = y[i],max_x = x[i],not=i;
    }
    double d[3];
    for(k=0,i=0;i<4;i++) {
        if(i!=not) {
            d[k++] = sqrt(pow(max_x-x[i],2) +pow(max_y-y[i],2));
        }
    }
    //d[0] = sqrt(pow(max_x-x[1],2) +pow(max_y-y[1],2));
   // d[1] = sqrt(pow(max_x-x[2],2) +pow(max_y-y[2],2));
   // d[2] = sqrt(pow(max_x-x[3],2) +pow(max_y-y[3],2));
    qsort(&d[0],3,sizeof(double),compare);
    //printf("%f %f %f",d[0],d[1],d[2]);
    if(d[0]!=d[1] || d[0]==0 || d[1]==0 || d[2] == 0) return false;
    
    //printf("%f %f %f",d[0],d[1],d[2]);
    double c1 =  pow(d[0],2) + pow(d[1],2);
    double c2 = pow(d[2],2);
   // printf("%f %f\n",c1,c2);
   // printf("%u %u ",c1,c2);
    if((float)c1 != (float)c2) return false;
    
    qsort(&x[0],4,sizeof(int),cmp1);
    qsort(&y[0],4,sizeof(int),cmp1);
    
    if(x[0] == x[1] && x[0] == x[2]) return false;
    //printf("%d %d %d",y[0],y[1],y[2]);
    
    if (y[0] == y[1] && y[0]==y[2]) return false;

    
    return true;
}