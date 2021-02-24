drop database if exists zadacha2;
create database zadacha2;
use zadacha2;

# CREATE TABLES
create table students(
    id int unsigned auto_increment primary key,
    name char(100) not null,
    age tinyint unsigned not null
);

create table grades(
    id int unsigned auto_increment primary key,
    student_id int unsigned not null references students(id),
    grade_name enum('BEL', 'MAT', 'SUBD') not null,
    grade tinyint unsigned check ( grade between 2 and 6) default 2
);

# INSERTS
insert into students(name, age) values
('Alex', 17),
('Kris', 17),
('Stefi', 17),
('Stela', 17),
('Misho', 22),
('Gosho', 18),
('Nqkoj', 16),
('Toj', 12),
('Narkoman', 100),
('Typanar', 69);

insert into grades(student_id, grade_name, grade) values
(1, 'BEL', 2),
(1, 'BEL', 3),
(2, 'BEL', 4),
(2, 'BEL', 5),
(3, 'BEL', 5),
(1, 'MAT', 4),
(1, 'MAT', 3),
(2, 'MAT', 5),
(3, 'MAT', 3),
(3, 'MAT', 4),
(1, 'SUBD', 6),
(1, 'SUBD', 4),
(1, 'SUBD', 5),
(2, 'SUBD', 3),
(3, 'SUBD', 5);

# CHECK DATA
select * from students;
select * from grades;

# AVERAGE FROM ALL
select avg(grade) as 'Average from ALL' from grades;

# AVERAGE FOR STUDENT WITH id=1
select avg(grade) as 'Average from ALL' from grades
where student_id = 1;

select distinct s.name from grades as g
left join students as s on g.student_id = s.id
where grade_name = 'SUBD'and g.grade between 4 and 6;