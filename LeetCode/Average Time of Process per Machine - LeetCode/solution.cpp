# Write your MySQL query statement below
SELECT a1.machine_id,
ROUND((SUM(a2.timestamp) - SUM(a1.timestamp)) / COUNT(*)
,3)
as processing_time
FROM 
(
    SELECT * FROM Activity
    WHERE activity_type = 'start'
    ORDER BY machine_id , process_id
) as a1
LEFT JOIN
(
    SELECT * FROM Activity
    WHERE activity_type = 'end'
    ORDER BY machine_id , process_id 
) as a2
ON a1.machine_id = a2.machine_id
AND a1.process_id = a2.process_id
GROUP BY machine_id