#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
int i=0,j=0,k=0;
int temp[nums1Size];
while(i<m && j<n) {
    if(nums1[i]<nums2[j]) temp[k++]=nums1[i++];
    else temp[k++]=nums2[j++];
}

while(i<m) temp[k++]=nums1[i++];
while(j<n) temp[k++]=nums2[j++];
for(i=0;i<n+m;i++) nums1[i]=temp[i];
}


int main () {

int nums1[17] = {1,2,2,4,4,5,6,6,7,8,10,20,30,50,100,105,123};
int nums2[3] = {2,5,6};
int m = 17,n = 3,i=0;
int nums1Size=sizeof(nums1)/sizeof(nums1[0]);
int nums2Size=sizeof(nums2)/sizeof(nums2[0]);
merge(nums1,nums1Size,m,nums2,nums2Size,n);
for(i=0;i<n+m;i++) printf("%d ",nums1[i]);
}
