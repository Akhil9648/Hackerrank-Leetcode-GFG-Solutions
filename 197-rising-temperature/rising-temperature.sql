# Write your MySQL query statement below
SELECT w1.id from Weather as w1,Weather as w2
WHERE datediff(w1.RecordDate,w2.RecordDate)=1 and
w1.temperature>w2.temperature