# database
drop database if exists school;
create database school;
use school;

# tables
create table student(
id int unsigned primary key not null auto_increment,
name varchar(100) not null
);

create table computer(
id int unsigned primary key not null auto_increment
);

create table computer_student(
id int unsigned primary key not null auto_increment,
computer_id int unsigned not null references computer(id),
student_id int unsigned not null references student(id)
);

# inserts
insert into student(name) values
('Misho'),
('Mimi');

insert into computer() values
(),(),();

insert into computer_student(computer_id, student_id) values
(1, 1),
(1, 1),
(2, 2),
(2, 1),
(3, 2),
(3, 1);