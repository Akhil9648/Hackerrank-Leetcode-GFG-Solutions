# Write your MySQL query statement below
SELECT D1.name as Department, E1.name as Employee,Salary FROM Employee as E1 JOIN 
Department as D1 on E1.departmentId=D1.id WHERE E1.salary =(SELECT max(salary) from Employee E2
    WHERE E1.departmentId=E2.departmentId )