class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int half_len = n/2;
        
        // Take the first half
        string half = s.substr(0, half_len);

        // Sort it to get the lexicographically smallest order
        sort(half.begin(),half.end()); 
        
        // Construct the full palindrome
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());

        if(n%2 == 1){
            return half + s[half_len] + rev_half;
        }else{
            return half + rev_half;
        }
    }
};