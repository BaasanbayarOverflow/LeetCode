class Solution:
    def timeRequiredToBuy(self, tickets, k: int) -> int:
        counter = 0

        inx = 0
        while (tickets[k] != 0):
            if (len(tickets) == inx): inx = 0

            if (tickets[inx] == 0):
                tickets.pop(inx)
                if inx < k:
                    k -= 1
                continue
            
            tickets[inx] -= 1
            counter += 1
            inx += 1

        return counter