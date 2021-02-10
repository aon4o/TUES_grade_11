drop database if exists classbook;
create database classbook;
use classbook;

create table student(
    id int primary key not null auto_increment,
    name varchar(40) not null unique,
    age int unsigned not null check(age > 0)
);

create table grades(
    id int primary key not null auto_increment,
    student_id int unsigned unique references student(id),
    grade_bg tinyint not null check(grade_bg between 2 and 6) default 2,
    grade_math tinyint not null check(grade_math between 2 and 6) default 2,
    grade_subd tinyint not null check(grade_subd between 2 and 6) default 2
);

# Exercise 1
insert into student(name, age) values
('ALEX', 17),
('Stefi', 17),
('Gosho', 18),
('Kris', 17),
('Dankata', 18),
('Nqkoj', 45),
('Nqkoj drug', 35),
('Oshte nqkoj', 40),
('Ne znam', 29),
('Pak ne znam', 36);

insert into grades (student_id, grade_bg, grade_math, grade_subd) values
(1, 2, 3, 6),
(2, 5, 4, 6),
(3, 6, 6, 6),
(4, 4, 6, 6),
(5, 6, 6, 6);

# Exercise 2
select s.name, s.age, g.grade_bg as bg, g.grade_math as math, g.grade_subd as subd
from student as s
left join grades as g on s.id = g.student_id
where name = 'ALEX';

# Exercise 3
select s.name, s.age, g.grade_bg as bg, g.grade_math as math, g.grade_subd as subd
from student as s
left join grades as g on s.id = g.student_id
where name like '%a%';

# Exercise 4
select s.name, s.age, g.grade_bg as bg, g.grade_math as math, g.grade_subd as subd
from grades as g
left join student as s on g.student_id = s.id
where ((g.grade_bg + g.grade_math + g.grade_subd) / 3) > 5;

# Exercise 5
select s.name, s.age, g.grade_bg as bg, g.grade_math as math, g.grade_subd as subd
from grades as g
left join student as s on g.student_id = s.id
where ((g.grade_bg + g.grade_math) / 2) > 5;