class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size() == 0) return -1;
        
        vector<int> start(26), count(26);
        int ans = INT_MAX;
        
        for(int i = 0; i < s.size(); i++){
            int cix = s[i] - 'a';
            if(count[cix]==0){
                start[cix] = i;
                count[cix] = 1;
            }else{
                count[cix] += 1;
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(count[i] == 1){
                ans = min(ans, start[i]);
            }
        }
        
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};
