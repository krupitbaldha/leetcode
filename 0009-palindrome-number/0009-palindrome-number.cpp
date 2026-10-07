class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n = s.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            if(s[a]!=s[b])return false;
            a++;
            b--;
        }
 return true;
    }
};