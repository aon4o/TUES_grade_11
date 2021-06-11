drop database if exists office_bulding;
create database office_bulding;
use office_bulding;

create table Office (
    id int primary key auto_increment not null,
    name char(255) unique not null
);

create table Person (
    id int primary key auto_increment not null,
    name char(255) unique not null,
    age int not null check ( age > 0 ),
    office_id int not null,
    foreign key (office_id) references Office(id)
);

create table Entered (
    id int primary key auto_increment not null,
    person_id int not null,
    date_of_entering datetime not null default NOW(),
    foreign key (person_id) references Person(id)
);

INSERT INTO Office(name) VALUES("Robopartans");
INSERT INTO Office(name) VALUES("Work and Share");
INSERT INTO Office(name) VALUES("Deliveroo");

INSERT INTO Person(name, age, office_id) VALUES("Misho", 25, 1);
INSERT INTO Person(name, age, office_id) VALUES("Ivan", 28, 1);
INSERT INTO Person(name, age, office_id) VALUES("Kiko", 35, 1);
INSERT INTO Person(name, age, office_id) VALUES("Georgi", 25, 2);
INSERT INTO Person(name, age, office_id) VALUES("Alex", 25, 2);

INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-02", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-03", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-04", 1);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-01", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-03", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-04", 2);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-03-03", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-04", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-01", 3);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-01-01", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-02-02", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-03-03", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-01", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-04", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-30", 4);
INSERT INTO Entered(date_of_entering, person_id) VALUES("2020-04-05", 4);


select E.date_of_entering as 'Date of Entering', O.name as 'Office' from Entered E
left join Person P on P.id = E.person_id
left join Office O on O.id = P.office_id;

select count(date_of_entering) as 'Times of Georgi entering' from Person
left join Entered E on Person.id = E.person_id
where name = 'Georgi';

select P.name as 'Person', count(E.date_of_entering) as 'Times Entered' from Entered E
left join Person P on P.id = E.person_id
where date_of_entering like '2020-04-%'
group by P.name
order by count(E.date_of_entering) desc
limit 1;

select O.name as 'Office', count(E.date_of_entering) as 'Times Entered' from Office O
left join Person P on O.id = P.office_id
left join Entered E on P.id = E.person_id
group by O.name;

select O.name as `Ofice without People` from Office O
left join Person P on O.id = P.office_id
where P.id IS NULL;

select P.name from Entered E
right join Person P on P.id = E.person_id
where E.date_of_entering is not null
group by P.name;
