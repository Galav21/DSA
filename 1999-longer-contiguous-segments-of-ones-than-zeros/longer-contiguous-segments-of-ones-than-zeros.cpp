class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOne = 0, currOne = 0;
        int maxZero = 0, currZero = 0;

        for(char c : s){
            if(c == '1'){
                currOne++;
                currZero = 0;
                maxOne = max(maxOne, currOne);
            }else{
                currZero++;
                currOne = 0;
                maxZero = max(maxZero, currZero);
            }
        } 
        return maxOne > maxZero;
    }
};