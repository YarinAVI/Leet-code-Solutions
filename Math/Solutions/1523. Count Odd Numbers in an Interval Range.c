

int countOdds(int low, int high){
    if(high==low && low%2==0) return 0;
    else if(high==low && low%2!=0) return 1;
    if(low == 0 )return high/2 + high%2;
    
    if(low%2==0 && high%2==0) return (((high-low)-1) / 2 ) + ((high-low)-1) % 2;
    else if(low%2!=0 && high%2==0) return (((high-low)) / 2 )+ ((high-low)) % 2;
    else if(low%2==0 && high%2!=0) return (((high-low)-1) / 2 ) + ((high-low)) % 2;
    else if(low%2!=0 && high%2!=0) return ((high-low) /2 )+1;
    return 0;
}