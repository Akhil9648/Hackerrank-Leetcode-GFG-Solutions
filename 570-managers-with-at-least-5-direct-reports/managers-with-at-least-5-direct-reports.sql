# Write your MySQL query statement below
SELECT name FROM Employee
WHERE id IN (SELECT managerId From Employee
    Group BY managerId 
    Having count(*)>=5)