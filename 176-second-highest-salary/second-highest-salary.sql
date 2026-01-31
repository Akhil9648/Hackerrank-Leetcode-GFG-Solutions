# Write your MySQL query statement below
SELECT(
    SELECT MAX(Salary) from Employee 
    WHERE Salary<(Select MAX(Salary) from Employee)
) as SecondHighestSalary