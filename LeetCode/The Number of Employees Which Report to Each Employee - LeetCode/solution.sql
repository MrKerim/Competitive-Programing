-- Write your PostgreSQL query statement below
SELECT employee_id, name, reports_count, average_age FROM 
Employees LEFT JOIN (
    SELECT reports_to, COUNT(*) AS reports_count, 
   ROUND(SUM(age)/COUNT(*)::numeric)  AS average_age 
    from Employees
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to
) AS tb1
ON Employees.employee_id = tb1.reports_to
WHERE reports_count IS NOT NULL
ORDER BY employee_id