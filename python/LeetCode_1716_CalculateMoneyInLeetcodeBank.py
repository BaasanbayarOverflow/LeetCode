def totalMoney(n):
    total = 0
    adder = 0
    for i in range(n):
        if i % 7 == 0: adder += 1
        total += (adder + (i % 7)) 
    return total     


print(totalMoney(10))