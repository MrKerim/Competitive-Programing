# Write your MySQL query statement below


SELECT tb1.student_id, tb1.student_name,tb1.subject_name,
COALESCE(tb2.attended_exams, 0) AS attended_exams
FROM
(
    SELECT *
    FROM Students
    CROSS JOIN Subjects
) as tb1
LEFT JOIN 
(
    SELECT e.student_id,e.subject_name,
    COUNT(*) AS attended_exams
    FROM Examinations e
    GROUP BY e.student_id, e.subject_name
) as tb2
ON tb1.student_id = tb2.student_id AND
tb1.subject_name = tb2.subject_name
ORDER BY tb1.student_id,tb1.subject_name;