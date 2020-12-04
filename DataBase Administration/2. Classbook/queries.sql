select avg(grade) as "Average from all Grades" from Grades;

select avg(grade) as "Average for Student with id = 1" from Grades
    where student_id = 1;

select grade_name as "Subject", avg(grade) as "Average Grade" from Grades
group by grade_name;

select Students.name as "Name", grade_name as "Subject", grade as "Grade"
from Grades
left join Students on Grades.student_id = Students.id
order by Grades.student_id;
