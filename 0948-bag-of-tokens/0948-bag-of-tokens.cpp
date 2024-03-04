class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j,score=0,res=0;
        j=tokens.size()-1;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i];
                i++;
            }
            else if(score>0)
            {
                score--;
                power+=tokens[j];
                j--;
            }
            else
            {
                break;
            }
            res=max(res,score);
        }
        return res;
    }
};