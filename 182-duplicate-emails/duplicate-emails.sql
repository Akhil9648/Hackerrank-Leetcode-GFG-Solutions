# Write your MySQL query statement below
SELECT DISTINCT P1.email as Email FROM Person P1
JOIN Person P2 on P1.id!=P2.id
WHERE P1.email=P2.email