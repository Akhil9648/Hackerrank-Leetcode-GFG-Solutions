# Write your MySQL query statement below
SELECT player_id,min(event_date) as first_login FROM Activity
Group By player_id
ORDER BY player_id,event_date