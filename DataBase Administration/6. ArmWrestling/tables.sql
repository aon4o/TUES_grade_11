create table person(
    id int primary key not null auto_increment,
    name varchar(40) unique
);

create table battle(
    id int primary key not null auto_increment,
    winner_id int references person(id),
    looser_id int references person(id),
    constraint CHK_Person check (winner_id != looser_id)
);
