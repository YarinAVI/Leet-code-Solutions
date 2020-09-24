//https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/


int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime){
int counter=0,i=0,j=0;
    while(i<startTimeSize) {
        if(startTime[i]<= queryTime && endTime[i]>=queryTime) counter++,i++;
        else i++;
    }
    return counter;
}