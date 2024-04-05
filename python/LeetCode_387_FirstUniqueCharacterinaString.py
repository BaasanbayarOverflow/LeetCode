"""
def firstUniqChar(self, s: str) -> int:
    count = collections.Counter(s)
    
    for idx, ch in enumerate(s):
        if count[ch] == 1:
            return idx     
    return -1
"""


def firstUniqChar(s: str) -> int:
    for i, letter in enumerate(s):
        if s.count(letter) == 1:
            return i
    return -1