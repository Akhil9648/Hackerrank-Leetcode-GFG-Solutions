# Write your MySQL query statement below
SELECT score,dense_rank() over (ORDER BY score DESC) as 'rank'
FROM scores