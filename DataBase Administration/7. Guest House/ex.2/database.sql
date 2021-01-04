drop database if exists guest_house;
create database guest_house;
use guest_house;

create table room(
    id int unsigned not null auto_increment primary key,
    name varchar(3) not null unique,
    capacity int unsigned not null,
    price_per_person float not null
);

create table person(
    id int unsigned not null auto_increment primary key,
    name varchar(100) not null unique,
    age int unsigned not null
);

create table reception(
    id int unsigned not null auto_increment primary key,
    person_id int unsigned not null references person(id),
    room_id int unsigned not null references room(id),
    sleep_date date not null default (DATE_FORMAT(NOW(), '%Y-%m-%d'))
#     constraint uc_person_date unique (person_id, sleep_date)
)