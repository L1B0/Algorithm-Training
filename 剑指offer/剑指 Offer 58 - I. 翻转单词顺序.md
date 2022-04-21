```
class Solution {
public:
    string reverseWords(string s) {
        int len = s.length(), l = len-1, r = len-1;
        string result = "", t = "";

        while(l >= 0){
            while(l >= 0 && s[l] == ' ') l--;
            while(l >= 0 && s[l] != ' ') t += s[l--];
            if(t.length() > 0){
                if(result.length() != 0) t += " ";
                reverse(t.begin(), t.end());
                result += t;
                t = "";
            }
        }

        return result;
    }
};
```