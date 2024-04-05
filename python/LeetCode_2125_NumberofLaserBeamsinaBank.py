def numberOfBeams(bank) -> int:
    prev = 0
    devs = 1
    result = 0
    for floor in bank:
        devs = floor.count('1')
        if (devs == 0):
            continue
        
        result += (devs * prev)
        prev = devs

    return result 


numberOfBeams(["000","111","000"])