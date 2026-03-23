class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=s.lower()
        temp=""
        for i in s:
            if i.isalnum():
                temp+=i
        r=temp[::-1]
        if r==temp:
            return True
        return False
        