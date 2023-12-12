def largestOddNumber(num: str) -> str:
    n = len(num)
    for i in range(n):
        number = num[(n - 1) - i]
        if (number % 2 == 1):
            return num[0 : (n - i)]        
    
    return ''
    

print(largestOddNumber("35427"))