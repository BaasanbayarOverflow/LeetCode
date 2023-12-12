def reverseVowels(s: str) -> str:
    low = 0
    high = len(s) - 1
    arr = list(s)

    vowels = 'aeiou'
    while (low <= high):
        isLowVowel = arr[low] in vowels
        isHighVowel = arr[high] in vowels 
        if not (isLowVowel):
            low += 1

        if not (isHighVowel):
            high -= 1

        if (isLowVowel and isHighVowel):
            arr[low], arr[high] = arr[high], arr[low]
            low += 1
            high -= 1
        
        
    return ''.join(arr)
    

print(reverseVowels('LeetCode'))