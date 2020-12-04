drop database if exists parking;
create database parking;
use parking;

create table Person
(
    id int primary key not null auto_increment,
    name varchar(50) not null unique,
    number_of_parked_cars tinyint not null default 0
);

create table Car
(
    id int primary key not null auto_increment,
    plate varchar(10) unique,
    person_id int references Person(id)
);

create table ParkingPlace
(
    id int primary key not null auto_increment,
    name varchar(3) not null unique,
    car_id int references Car(id)
);

create trigger after_insert_parking_place
    after insert on ParkingPlace
    for each row
    update Person
        set number_of_parked_cars = number_of_parked_cars + 1
        where id in
        (select person_id from Car where Car.id = new.car_id);

create trigger before_update_num_parking_place
    before update on ParkingPlace
    for each row
    update Person
        set number_of_parked_cars = number_of_parked_cars - 1
        where id in
        (select person_id from Car where Car.id = old.car_id);

create trigger after_update_num_parking_place
    after update on ParkingPlace
    for each row
    update Person
        set number_of_parked_cars = number_of_parked_cars + 1
        where id in
        (select person_id from Car where Car.id = new.car_id);

create trigger after_delete_num_parking_place
    after delete on ParkingPlace
    for each row
    update Person
        set number_of_parked_cars = number_of_parked_cars - 1
        where id in
        (select person_id from Car where Car.id = old.car_id);

insert into Person(name) values
    ("Alex"),
    ("Kris"),
    ("Joro"),
    ("Stefi"),
    ("Misho"),
    ("Gandalf"),
    ("Niki Milchev");

insert into Car(plate, person_id) values
    ("CO1234AC", 1),
    ("CA7698OO", 2),
    ("CO4398PP", 3),
    ("PA8745MP", 4),
    ("CO9467OP", 5),
    ("PK6587BB", 6),
    ("CA8734PO", 7),
    ("CO2947BO", 7),
    ("PK6969CC", 7),
    ("MICUBAHA", 7);

insert into ParkingPlace(name, car_id) values
    ("B73", 1),
    ("G04", 2),
    ("D63", 3),
    ("K38", 4),
    ("J38", 5),
    ("E28", 6),
    ("A96", 7),
    ("N46", 8);

select Person.name as name
from ParkingPlace
inner join Car on ParkingPlace.car_id = Car.id
inner join Person on Car.person_id = Person.id
group by Person.name;

select ParkingPlace.name as Place, Car.plate as Plate
from ParkingPlace
inner join Car on ParkingPlace.car_id = Car.id
where ParkingPlace.name like "G%";
