-- Write your PostgreSQL query statement below
SELECT product_name,unit FROM Products
LEFT JOIN 
(
    SELECT product_id,SUM(unit) as unit FROM Orders
    WHERE EXTRACT(YEAR FROM order_date) = 2020 AND EXTRACT(MONTH FROM order_date) = 2
    GROUP BY product_id
) AS tb
ON Products.product_id = tb.product_id
WHERE tb.unit >= 100