-- Write your PostgreSQL query statement below
SELECT tb1.employee_id FROM
Employees as tb1 LEFT JOIN Employees as tb2
ON tb1.manager_id = tb2.employee_id
WHERE tb1.manager_id IS NOT NULL AND
tb2.employee_id IS NULL
AND tb1.salary < 30000
ORDER BY tb1.employee_id