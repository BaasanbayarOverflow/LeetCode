# Optimal Solution

"""
def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    for i in set(ransomNote):
        if magazine.count(i) < ransomNote.count(i):
            return False
    else:
        return True
"""


def canConstruct(ransomNote: str, magazine: str) -> bool:
    hash = [0] * 26
    for letter in magazine:
        hash[ord(letter) - 97] += 1

    for letter in ransomNote:
        hash[ord(letter) - 97] -= 1
        if (hash[ord(letter) - 97] < 0): return False

    return True 


canConstruct('aa', 'aab')
