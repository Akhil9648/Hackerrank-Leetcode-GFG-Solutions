# Write your MySQL query statement below
SELECT C.name as Customers from Customers as C
LEFT JOIN Orders as O ON C.id=O.customerId
WHERE customerId IS NULL