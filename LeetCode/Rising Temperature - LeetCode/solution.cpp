# Write your MySQL query statement below
SELECT w2.id AS Id
FROM Weather w1 INNER JOIN
(
    SELECT * FROM Weather
    WHERE recordDate <> 
    (
        SELECT MIN(recordDate) FROM Weather
    )
) as w2
ON DATE_ADD(w1.recordDate, INTERVAL 1 DAY) = w2.recordDate
WHERE w2.temperature > w1.temperature