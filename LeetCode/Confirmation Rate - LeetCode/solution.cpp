# Write your MySQL query statement below

SELECT s.user_id as user_id,
ROUND(COALESCE(SUM(action = 'confirmed')/
COUNT(*),0),2 )
AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id