class Solution:
    def countStudents(self, students, sandwiches) -> int:
        inx = 0
        while (len(students) > inx):
            if students[0] == sandwiches[0]:
                students.pop(0)
                sandwiches.pop(0)
                inx = 0
                continue
            else:
                tmp = students.pop(0)
                students.append(tmp)

            inx += 1

        return len(students)