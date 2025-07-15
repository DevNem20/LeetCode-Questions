class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false;
        bool isVowel = false;
        bool isConst = false;
        for(char ch: word) {
            ch = tolower(ch);
            if(ch == '@' || ch == '#' || ch == '$') return false;
            else if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') isVowel = true;
            else if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || 
                ch == '6' || ch == '7' || ch == '8' || ch == '9') continue;
            else isConst = true;
        }
        return isConst && isVowel;
    }
};