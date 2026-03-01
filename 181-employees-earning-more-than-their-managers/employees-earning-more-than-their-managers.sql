# Write your MySQL query statement below
SELECT name as Employee FROM Employee E
WHERE Salary>(Select salary FROM Employee as E1
            WHERE E1.id=E.managerId)