class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


class Solution:
    def getImportance(self, employees, id: int) -> int:
        id_to_index = {employees[i].id: i for i in range(len(employees))}

        @cache
        def solve(i: int):
            for child in employees[i].subordinates:
                employees[i].importance += solve(id_to_index[child])
            return employees[i].importance

        return solve(id_to_index[id])
    

"""
class Solution:
    def getImportance(self, employees, id: int) -> int:
        if not employees: return 0

        self.total = 0

        tmp = None
        inx = 0
        for emp in employees:
            if emp.id == id:
                tmp = emp
                break
            inx += 1

        def traverse(worker, inx):
            if not worker: return None

            self.total += worker.importance
            if worker.subordinates:
                tmp = worker.subordinates
                for t in tmp:
                    i = 0
                    while (i < len(employees)):
                        if employees[i].id == t:
                            traverse(employees[i], i)
                        i += 1
        
        if tmp:
            traverse(tmp, inx)

        return self.total
"""