# Write your MySQL query statement below
Select name as Customers from Customers C WHERE C.id NOT IN(
    SELECT customerId from Orders
) 