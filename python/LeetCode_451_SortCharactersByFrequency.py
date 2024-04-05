from collections import Counter


def frequencySort(s: str) -> str:
    result = ''
    letters = Counter(s).most_common()
    for letter in letters:
        result += letter[0] * letter[1]
    return result

print(frequencySort("treeE"))