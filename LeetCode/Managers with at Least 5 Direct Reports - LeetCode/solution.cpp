# Write your MySQL query statement below

SELECT e.name
FROM
(
    SELECT e.managerId as Id
    FROM Employee e
    WHERE e.managerId IS NOT NULL
    GROUP BY e.managerId
    HAVING COUNT(*) >= 5
) as id_table
INNER JOIN Employee e
ON id_table.Id = e.id