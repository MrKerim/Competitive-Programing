-- Write your PostgreSQL query statement below

SELECT product_id, year AS first_year, quantity, price FROM Sales
WHERE year = (
    SELECT MIN(year) FROM Sales AS s2
    WHERE s2.product_id = Sales.product_id         
)
ORDER BY product_id;