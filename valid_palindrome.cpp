class Solution {
public:
    bool isPalindrome(string s) {
int i=0;
int n=s.length()-1;
while(i<n)
{
  while(i<n&&!isalnum(s[i]))
  {
    i++;
  }
  while(i<n&&!isalnum(s[n]))
  {
    n--;
  }
  if(tolower(s[i])!=tolower(s[n]))
  {

  return false;
  }
  i++;
    n--;
  }
  return true;
 }
};
