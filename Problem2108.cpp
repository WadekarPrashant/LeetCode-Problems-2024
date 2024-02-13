class Solution {
 public:
  string firstPalindrome(vector<string>& words) {
      for (auto word : words)  // iterate all the string 
      if (isPalindrome(word)) // check palindrome if true 
        return word;      // return the palindrome
    return "";
  }

 private:
  bool isPalindrome(string& s) {  // palindrome function to check
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
      if (s[i++] != s[j--]){
        return false;
      }
    return true;
  }
};
