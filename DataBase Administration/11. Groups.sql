drop database if exists zadacha4;
create database zadacha4;
use zadacha4;

# CREATE TABLES
create table person(
    id int unsigned auto_increment primary key,
    name char(100) not null,
    type enum('student', 'teacher') not null
);

create table `group`
(
    id int unsigned auto_increment primary key,
    name char(100) not null,
    first_meet timestamp not null default current_timestamp
);

create table group_person(
    id int unsigned auto_increment primary key,
    group_id int unsigned not null references `group`(id),
    person_id int unsigned not null references person(id)
);


# INSERTS
insert into person(name, type) values
('Alex', 'student'),
('Kris', 'student'),
('Stefi', 'student'),
('Stela', 'teacher'),
('Misho', 'teacher'),
('Gosho', 'teacher'),
('Nqkoj', 'student'),
('Toj', 'teacher'),
('Narkoman', 'student'),
('Typanar', 'teacher');

insert into `group`(name, first_meet) values
('Group 1', date('2011-04-20 04:20:00'));

insert into `group`(name) values
('Group 2'),
('Group 3');

insert into group_person(group_id, person_id) values
(1, 1),
(1, 2),
(1, 5),
(2, 4);


# SELECT ALL
select g.name as 'Group name', p.name as 'Person name', p.type as 'Type'
from `group` as g
left join group_person as gp on g.id = gp.group_id
left join person p on gp.person_id = p.id;

# PEOPLE IN GROUP
select g.name as 'Group name', count(gp.person_id) as 'People in the group'
from `group` as g
left join group_person as gp on g.id = gp.group_id
group by g.name;

# STUDENTS IN GROUP todo
select g.name as 'Group name', count(p.id) as 'Students in the group'
from `group` as g
left join group_person as gp on g.id = gp.group_id
left join person p on gp.person_id = p.id
where p.type = 'student'
group by g.name;

# TEACHERS IN GROUP todo
select g.name as 'Group name', count(gp.person_id) as 'People in the group'
from `group` as g
left join group_person as gp on g.id = gp.group_id
inner join person p on gp.person_id = p.id
where p.type = 'teacher'
group by g.name;

# GROUPS BETWEEN GIVEN DATES
select g.name as 'Group name', g.first_meet as "Date of first meet"
from `group` as g
where first_meet between '2010-10-10 00:00:00' and '2011-11-11 23:49:59';