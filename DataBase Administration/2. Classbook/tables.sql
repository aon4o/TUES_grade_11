drop database if exists Classbook;
create database Classbook;
use Classbook;

create table Students
(
    id int unsigned not null auto_increment primary key,
    name char(100) not null,
    age tinyint unsigned not null
);
create table Grades
(
    id int unsigned not null auto_increment primary key,
    grade_name enum('Bel', 'Math', 'Subd') not null,
    grade tinyint not null check (grade = 2 or grade = 6) default 2,
    student_id int unsigned references Students(id)
);
