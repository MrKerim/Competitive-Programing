# Write your MySQL query statement below
WITH tb AS (
SELECT id,country,state,amount,
DATE_FORMAT(trans_date,'%Y-%m')
AS trans_date
FROM Transactions t
)
SELECT tb.trans_date AS month,
tb.country,
COUNT(*)
AS trans_count,
SUM(tb.state = 'approved')
AS approved_count,
SUM(amount)
AS trans_total_amount,
SUM( amount*(state = 'approved') )
AS approved_total_amount
FROM tb
GROUP BY
tb.trans_date,tb.country