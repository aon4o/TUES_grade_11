# database
drop database if exists school;
create database school;
use school;

# tables
create table student(
id int unsigned primary key not null auto_increment,
name varchar(100) not null
);

create table textbook(
id int unsigned primary key not null auto_increment,
subject varchar(30) not null,
publisher varchar(30) not null
);

create table student_textbook(
id int unsigned primary key not null auto_increment,
student_id int unsigned not null references student(id),
textbook_id int unsigned not null references textbook(id),
constraint uc_textbook unique (textbook_id)
);

# inserts
insert into student(name) values
('Misho'),
('Mimi');

insert into textbook(subject, publisher) values
('Math', 'Anubis'),
('Bulgarian', 'Prosveta');

insert into student_textbook(student_id, textbook_id) values
(1, 1),
(2, 2),
(2, 1);






