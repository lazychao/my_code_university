def isPalindrome(s):
    l=list(s)
    l.reverse()
    S=''.join(l)
    return S==s

print(isPalindrome('asdfdsa1'))
