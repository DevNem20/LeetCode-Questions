class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        int n = s.length();
        result.push_back(s[0]);
        for(int i = 1; i<n; i++) {
            if(s[i] == s[i-1] && s[i] == s[i+1]) continue;
            result.push_back(s[i]);
            
        }
        return result;
    }
};