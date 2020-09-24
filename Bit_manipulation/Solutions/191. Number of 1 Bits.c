int hammingWeight(uint32_t n) {
      int i,res=0;
    for(i=31;i>=0;i--) if((n>>i)&1 == 1 ) res++;
    return res;
}