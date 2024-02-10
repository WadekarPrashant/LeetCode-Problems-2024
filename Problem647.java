public class Solution {
    public int countSubstrings(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += count(i, i, s);
            if(i > 0 && s.charAt(i) == s.charAt(i - 1)){
                count += count(i - 1, i, s);
            }
        }
        return count;
    }
    private int count(int l, int r, String s){
        int count = 0;
        while (l >= 0 && r < s.length()){
            if(s.charAt(l) == s.charAt(r)){
                count++;
            }else break;
            l--;
            r++;
        }
        return count;
    }
}
