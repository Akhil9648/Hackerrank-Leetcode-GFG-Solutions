# Write your MySQL query statement below
SELECT 
    CASE
        WHEN id=(SELECT MAX(id) from Seat) AND MOD(id,2)=1 THEN id
        WHEN MOD(id,2)=1 THEN id+1
        ELSE id-1
    END id,student FROM Seat
    ORDER BY id