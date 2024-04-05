def evalRPN(tokens) -> int:
    if (not tokens):
        return 0
    
    stack = []
    for num in tokens:
        if (num == "+"):
            A = stack.pop()
            B = stack.pop()
            stack.append(A + B)
        elif (num == "-"):
            A = stack.pop()
            B = stack.pop()
            stack.append(B - A)
        elif (num == "*"):
            A = stack.pop()
            B = stack.pop()
            stack.append(A * B)
        elif (num == "/"):
            A = stack.pop()
            B = stack.pop()
            stack.append(int(B / A))
        else:
            stack.append(int(num))
    
    return stack.pop()


print(evalRPN(["4","3","-"]))


# IT WORKS BUT SLOW 

"""
def checkIntegers(num):
    try:
        num = int(num)
    except:
        return False 
    else:
        return True 
       

def execute(a, b, sym):
    res = 0
    if (sym == '+'):
        res = int(a) + int(b)
    elif (sym == '-'):
        res = int(a) - int(b)
    elif (sym == '*'):
        res = int(a) * int(b)
    elif (sym == '/'):
        res = int(int(a) / int(b))
    
    return str(res)


def evalRPN(tokens) -> int:
    if (not tokens):
        return 0
    
    lngth = len(tokens)
    if (lngth <= 2):
        return 0
    
    for _ in range(lngth):
        inx = 0
        is_executed = False
        for i in range(0, lngth - 2):
            if (not is_executed):
                a = tokens[inx]
                b = tokens[inx + 1]
                sym = tokens[inx + 2]
                if (checkIntegers(a) and checkIntegers(b) and sym in "+-*/"):
                    tokens[inx] = execute(a, b, sym)
                    inx += 2
                    lngth -= 2
                    is_executed = True
            else:
                tokens[i] = tokens[inx]    

            inx += 1

    return tokens[0] if lngth == 1 else 0


print(evalRPN(["2","1","3","*"]))
"""