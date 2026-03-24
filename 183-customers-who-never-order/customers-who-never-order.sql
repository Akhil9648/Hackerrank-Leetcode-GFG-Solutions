# Write your MySQL query statement below
SELECT C.name as customers FROM Customers as C
LEFT JOIN Orders as O ON C.id=O.customerId
WHERE O.customerId IS NULL