drop database if exists zadacha3;
create database zadacha3;
use zadacha3;

# CREATE TABLES
create table person(
    id int unsigned auto_increment primary key,
    name char(100) not null,
    age tinyint unsigned not null,
    gender enum('M', 'F') not null
);

create table weight_data(
    id int unsigned auto_increment primary key,
    person_id int unsigned not null references person(id),
    created_at timestamp not null default now(),
    weight float unsigned not null check (weight > 0)
);

# INSERTS
insert into person(name, age, gender) values
('Alex', 17, 'M'),
('Kris', 17, 'M'),
('Stefi', 17, 'F'),
('Stela', 17, 'F'),
('Misho', 22, 'M'),
('Gosho', 18, 'M'),
('Nqkoj', 16, 'M'),
('Toj', 12, 'F'),
('Narkoman', 100, 'M'),
('Typanar', 69, 'F');

insert into weight_data(person_id, weight) values
(1, 50),
(1, 55),
(2, 52.3),
(2, 54.9),
(3, 50),
(1, 58.75),
(1, 49),
(2, 61),
(3, 46),
(3, 74.1250),
(1, 65),
(1, 57.9),
(1, 60),
(2, 49),
(3, 53);

insert into weight_data(person_id, created_at, weight) values
(1, '2019-02-5', 50),
(1, '2019-02-15', 60),
(1, '2019-02-28', 60);

# SELECT AVERAGE WEIGHT
select avg(weight) as 'Average weight for person with id=1' from weight_data
where person_id = 1
and created_at like '2019-02-%';

# AVERAGE WEIGHT OF ALL WOMEN
select avg(weight) as 'Average weight for all women' from weight_data
left join person on person.id = weight_data.person_id
where gender = 'F';

# HEAVIEST MAN
select name as 'Heaviest man' from weight_data
left join person on person.id = weight_data.person_id
where created_at between '2021-03-01' and '2021-04-01'
and gender = 'M'
order by weight desc limit 1;

# GENDER COUNT
select gender, count(gender) as 'count' from person
group by gender;

# AVERAGE FOR EVERYBODY
select name as 'Name', avg(weight) as 'Average weight' from weight_data
left join person on person.id = weight_data.person_id
group by name;

# 7ma
select @start := weight from weight_data
left join person on person.id = weight_data.person_id
where created_at like '2019-%'
order by created_at limit 1;

select @end := weight from weight_data
left join person on person.id = weight_data.person_id
where created_at like '2019-%'
order by created_at desc limit 1;

select @start - @end;