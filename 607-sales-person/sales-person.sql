# Write your MySQL query statement below
SELECT name FROM SalesPerson
WHERE sales_id NOT IN(
    SELECT O.sales_id FROM Orders O
    JOIN Company as C ON O.com_id=C.com_id 
    WHERE C.name="RED"
)