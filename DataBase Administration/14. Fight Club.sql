drop database if exists fight_club;
create database fight_club;
use fight_club;

create table club (
    id int primary key auto_increment not null,
    name char(255) unique not null
);

create table person (
    id int primary key auto_increment not null,
    name char(255) unique not null,
    age int not null check ( age > 0 ),
    club_id int not null,
    foreign key (club_id) references club(id)
);

create table fight (
    id int primary key auto_increment not null,
    fight_date datetime not null default NOW(),
    winner int not null references person(id),
    looser int not null references person(id)
);

INSERT INTO club(name) VALUES('club 1');
INSERT INTO club(name) VALUES('club 2');
INSERT INTO club(name) VALUES('club 3');

INSERT INTO person(name, club_id, age) VALUES('Misho', 1, 20);
INSERT INTO person(name, club_id, age) VALUES('Nasko', 1, 20);
INSERT INTO person(name, club_id, age) VALUES('Mitko', 1, 20);
INSERT INTO person(name, club_id, age) VALUES('Georgi', 2, 20);
# INSERT INTO person(name, club_id, age) VALUES('Mimi', 2, -1);

INSERT INTO fight(winner, looser) VALUES(1,2);
INSERT INTO fight(winner, looser) VALUES(1,4);
# INSERT INTO fight(winner, looser) VALUES(3,3);
INSERT INTO fight(winner, looser) VALUES(4,2);
INSERT INTO fight(winner, looser) VALUES(1,2);
INSERT INTO fight(winner, looser) VALUES(1,1);

select p.name, f.fight_date from person p
left join fight f on p.id = f.winner;

select p.name, f.fight_date from person p
left join fight f on p.id = f.looser;

select p.name as winner, p2.name as looser from fight f
left join person p on p.id = f.winner
left join person p2 on p2.id = f.looser;

select c.name as 'Winning Club', c2.name as 'Loosing Club' from fight f
left join person p on p.id = f.winner
left join person p2 on p2.id = f.looser
left join club c on c.id = p.club_id
left join club c2 on c2.id = p2.club_id;

select p.name as 'People without wins' from fight
right join person p on p.id = fight.winner
where fight.id is null;

select p.name as 'People without looses' from fight
right join person p on p.id = fight.looser
where fight.id is null;

select p.name as 'People not fought' from person p
left join fight f on p.id = f.looser
left join fight f2 on p.id = f2.winner
where f.id is null and f2.id is null