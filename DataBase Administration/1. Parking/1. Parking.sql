drop database if exists parking;
create database parking;
use parking;

create table park (
	id int primary key not null auto_increment,
	car char(10) not null,
	place int not null
);

insert into park(car, place) values
('EB9565PA', 1),
('PK3860OB', 2),
('BT1996PA', 3),
('B746654', 4),
('PA1996CM', 5),
('CB911113', 6),
('A5378EB', 7),
('CM8972B', 8),
('OB2672CH', 9),
('X8942T', 10),
('M21996P', 11),
('KH1996CA', 12),
('BP647932', 13),
('CC446526', 14),
('PB7707CO', 15),
('H3977M', 16),
('CH1996TH', 17),
('BT4932PK', 18),
('CA619881', 19),
('K124344OB', 20);

select count(*) from park;
select * from park where car like '%1996%';