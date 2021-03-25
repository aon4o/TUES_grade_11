DROP DATABASE IF EXISTS Weights;
CREATE DATABASE Weights;
USE Weights;

CREATE TABLE Person(
id int primary key not null auto_increment,
name varchar(100),
age int not null,
gender ENUM('M', 'F')
);

CREATE TABLE WeightData(
id int primary key not null auto_increment,
created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
weight double not null,
name varchar(100),
person_id int,
FOREIGN KEY (person_id) references Person(id)
);

INSERT INTO Person(name, age, gender) VALUES('ALEX', 16, 'M');
INSERT INTO Person(name, age, gender) VALUES('Ivo', 18, 'F');
INSERT INTO Person(name, age, gender) VALUES('Petar', 19, 'F');
INSERT INTO Person(name, age, gender) VALUES('Ivan', 15, 'F');
INSERT INTO Person(name, age, gender) VALUES('Koko', 17, 'F');
INSERT INTO Person(name, age, gender) VALUES('Bobo', 14, 'M');

INSERT INTO Person(name, age, gender) VALUES('Iva', 17, 'F');
INSERT INTO Person(name, age, gender) VALUES('Bojidara', 15, 'F');
INSERT INTO Person(name, age, gender) VALUES('Kati', 19, 'F');
INSERT INTO Person(name, age, gender) VALUES('Ani', 17, 'F');

-- Решение: https://bit.ly/3rjQybr
INSERT INTO WeightData(person_id, weight) VALUES(1, 70);
INSERT INTO WeightData(person_id, weight) VALUES(1, 80);
INSERT INTO WeightData(person_id, weight) VALUES(1, 85);
INSERT INTO WeightData(person_id, weight, created_at) VALUES(1, 85, '2019-02-12 00:00:00');
INSERT INTO WeightData(person_id, weight, created_at) VALUES(1, 85, '2019-02-12 00:00:00');
INSERT INTO WeightData(person_id, weight) VALUES(2, 65);
INSERT INTO WeightData(person_id, weight) VALUES(3, 91);
INSERT INTO WeightData(person_id, weight) VALUES(4, 81);
INSERT INTO WeightData(person_id, weight) VALUES(5, 52);


# 2
update WeightData w, Person p
set w.name = p.name
where p.id = w.person_id;

# 3
alter table Person
drop column name;

# 4
alter table WeightData
add column gender ENUM('M', 'F');

# 5
update WeightData w, Person p
set w.gender = p.gender
where p.id = w.person_id;

# 6
alter table Person
drop column gender;

select * from Person
left join WeightData WD on Person.id = WD.person_id;
