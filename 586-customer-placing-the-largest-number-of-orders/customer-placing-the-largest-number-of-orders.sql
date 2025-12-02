# Write your MySQL query statement below
WITH cte as (SELECT customer_number,COUNT(order_number) AS NumOrd FROM Orders
GROUP BY customer_number )
SELECT customer_number from cte
WHERE NumOrd=(SELECT max(NumOrd) from cte)