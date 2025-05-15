# Write your MySQL query statement below

SELECT 
ROUND(SUM(t1.order_date = t1.customer_pref_delivery_date)
/COUNT(DISTINCT t1.customer_id) * 100,2)
AS immediate_percentage
FROM Delivery t1
WHERE t1.order_date = (SELECT MIN(t2.order_date)
                        FROM Delivery t2
                        WHERE t2.customer_id = t1.customer_id
                        )