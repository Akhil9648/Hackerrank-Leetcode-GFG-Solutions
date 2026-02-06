SELECT W2.id from Weather as W1
JOIN Weather as W2 ON DATEDIFF(W2.recordDate,W1.recordDate)=1
WHERE W2.temperature>W1.temperature