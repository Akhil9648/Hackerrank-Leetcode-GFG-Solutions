SELECT 
    stu.student_id,stu.student_name,sub.subject_name,
    COUNT(ex.subject_name) AS attended_exams
FROM  
    STUDENTS stu
CROSS JOIN Subjects sub
LEFT JOIN 
    Examinations ex 
    ON stu.student_id = ex.student_id AND sub.subject_name = ex.subject_name
GROUP BY stu.student_id, stu.student_name, sub.subject_name
ORDER BY stu.student_id, sub.subject_name;