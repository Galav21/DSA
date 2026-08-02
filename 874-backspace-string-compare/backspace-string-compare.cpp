class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        
        int skipS = 0;
        int skipT = 0;

        while (i >= 0 || j >= 0) {
            // Find the index of the next valid character in string 's'
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break; // Found a valid character
                }
            }

            // Find the index of the next valid character in string 't'
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break; // Found a valid character
                }
            }

            // Compare the valid characters
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            } else if ((i >= 0) != (j >= 0)) {
                // One string has remaining valid characters while the other doesn't
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};