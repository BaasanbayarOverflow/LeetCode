def buyChoco(prices, money: int) -> int:
    pricess = sorted(prices)
    summ = pricess[0] + pricess[1]
    return money - summ if money >= summ else money


def buyChoco(prices, money: int) -> int:
    min_m = 100000
    min_m_m = min_m
    for n in prices:    
        if (min_m > n):
            min_m_m = min_m
            min_m = n
        
        elif (min_m <= n and min_m_m > n):
            min_m_m = n

    summ = min_m_m + min_m
    return money if money < summ else money - summ


buyChoco([1,2,2], 3)