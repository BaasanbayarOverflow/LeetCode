from collections import Counter


class Solution:
    def groupAnagrams(self, strs):
        hash = {}
        for word in strs:
            tmp = ''.join(sorted(word))

            if tmp not in hash:
                hash[tmp] = []
            hash[tmp].append(word)
        return list(hash.values())


def groupAnagrams(strs):
    length = len(strs)
    
    result = []
    i = 0
    while (i < length):
        word_I = strs[i]

        j = i + 1
        tmpList = []
        tmpList.append(word_I)
        while (j < length):
            word_II = strs[j]

            if (len(word_I) != len(word_II)):
                j += 1
                continue
            
            c_1 = Counter(word_I)
            c_2 = Counter(word_II)
            if (c_1 == c_2):
                tmpList.append(word_II)
                strs.pop(j)
                j -= 1
                length -= 1

            j += 1

        i += 1
        result.append(tmpList)
    return result

    
groupAnagrams(["", "b"])