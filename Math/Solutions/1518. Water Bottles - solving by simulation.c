int numWaterBottles(int numBottles, int numExchange){
    int res = 0;
    int empty=numBottles;
    while (numBottles) {
        res += numBottles;
        numBottles = empty / numExchange;
        empty = (empty - (numBottles * numExchange)) + numBottles;

        //printf("%d %d\n", empty, numBottles);

    }
    return res;
}