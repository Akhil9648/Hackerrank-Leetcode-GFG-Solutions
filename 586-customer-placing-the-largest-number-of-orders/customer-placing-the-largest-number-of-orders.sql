# Write your MySQL query statement below
SELECT customer_number FROM (SELECT COUNT(*) as cnt,customer_number FROM Orders
GROUP BY customer_number  ORDER BY cnt DESC LIMIT 1) as ptr