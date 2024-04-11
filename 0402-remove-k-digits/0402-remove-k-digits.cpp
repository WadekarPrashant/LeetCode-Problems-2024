
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k>=num.length())
            return "0";

        stack<char> st;

        for (char c : num) {
            // k keeps track of how many characters we can remove
            // if the previous character in stk is larger than the current one
            // then removing it will get a smaller number
            // but we can only do so when k is larger than 0
            while (k>0 && !st.empty() && st.top()>c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // edge cases like "1111", "12345"
        while (k-->0) st.pop();

        string res="";
        while (!st.empty()) {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        // remove leading zeros if any (coonsider case num="100", k=1)
        auto idx = res.length()-1;
        for (int i=0; i<res.length(); i++) {
            if (res[i]=='0') continue;
            idx=i;
            break;
        }
        res = res.substr(idx);

        return res;
    }
};