CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        SELECT DISTINCT salary from Employee as Emp1
        WHERE N-1=(SELECT count(DISTINCT salary) FROM Employee as Emp2
        WHERE emp2.salary>emp1.salary)
  );
END