class Solution {
public:
    string intToRoman(int num) {
        // Include standard symbols AND the 6 subtractive pairs (13 total)
        const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";

        for (int i = 0; i < 13; ++i) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};