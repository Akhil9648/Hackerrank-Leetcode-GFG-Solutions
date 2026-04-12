# Write your MySQL query statement below
SELECT id,
CASE 
 WHEN (p_id is NULL) THEN 'Root'
 WHEN (p_id is NOT NULL AND id in (SELECT p_id from Tree)) THEN 'Inner'
 ELSE 'Leaf'
 END as type
FROM Tree