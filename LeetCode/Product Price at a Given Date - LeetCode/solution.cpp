-- Write your PostgreSQL query statement below

SELECT DISTINCT tb1.product_id, COALESCE(tb2.new_price,10) AS price  FROM

(SELECT DISTINCT product_id FROM Products)
AS tb1 LEFT JOIN
(
    SELECT p1.product_id, p1.new_price FROM Products AS p1
    WHERE change_date = (
        SELECT MAX(change_date) FROM Products AS p2
        WHERE p1.product_id = p2.product_id AND
        change_date <= DATE '2019-08-16'
    )
) AS tb2
ON tb1.product_id = tb2.product_id