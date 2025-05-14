# Write your MySQL query statement below

SELECT r.contest_id,
ROUND(
SUM(r.user_id = u.user_id) /
COUNT(DISTINCT u.user_id) * 100
,2) AS percentage
FROM Register r
CROSS JOIN Users u
GROUP BY r.contest_id
ORDER BY percentage DESC,r.contest_id;