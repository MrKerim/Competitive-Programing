-- Write your PostgreSQL query statement below
SELECT *, 
CASE
    WHEN 
    (x + y + z)  > 2*GREATEST(x,y,z)
    THEN 'Yes'ELSE 'No' 
    END AS triangle
FROM Triangle