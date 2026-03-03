# Write your MySQL query statement below
SELECT max(num) as num FROM(
    SELECT num FROM MyNumbers
    GROUP BY num
    HAVING count(num)=1
) as ans