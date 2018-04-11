/*
Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if
needle is not part of haystack.
*/

class Solution {
public:
  int strStr(string haystack, string needle) {
      int m = haystack.length(), n = needle.length();
    int i;
    for(i = 0; i <= m - n; i++) {
      int j = 0;
      for (; j < n; j++) {
        if (needle[j] != haystack[j + i])
          break;
      }
      if (j == n)
        return i;
    }
    return -1;
  }
};
