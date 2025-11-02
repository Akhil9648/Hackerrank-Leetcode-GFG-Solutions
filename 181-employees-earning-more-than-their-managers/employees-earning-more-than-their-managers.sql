# Write your MySQL query statement below
SELECT E.name as Employee from Employee as E
JOIN Employee as M on E.managerID=M.id
WHERE E.salary>M.salary