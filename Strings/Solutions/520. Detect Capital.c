//https://leetcode.com/problems/detect-capital/
bool detectCapitalUse(char * word){
        if(*word>=65 && *word<=90) {
            word++;
            if(*word>=97 && *word<=122) {
                word++;
                while(*word) {
                    if(*word<97) return false;
                        word++;
                }
                return true;
            }
            else {
                
                while(*word) {
                    if(*word>=97 && *word<=122) return false;
                    word++;
                }
                return true;
            }
        }
        else if(*word) {
            word++;
            while(*word) {
                if(*word<97) return false;
                word++;
            }
            return true;
        }
        return false;
}