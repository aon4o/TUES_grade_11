drop database if exists scale;
create database scale;
use scale;

create table Person (
    id int primary key not null auto_increment,
    name varchar(100) not null,
    age tinyint not null,
    height int not null,
    gender enum('male','female') not null,
    average_weight float,
    weight_in_count int default 0
);

create table Weight (
    id int primary key not null auto_increment,
    value float not null,
    person_id int references Person(id),

    created_at timestamp default current_timestamp
);

delimiter $$
create trigger update_avg_weight
    before insert
    on Weight for each row
begin
    update Person
    set average_weight = (
        select avg(value) from Weight
        where person_id = new.person_id
    )
    where Person.id = new.person_id;
end $$

delimiter !!
create trigger update_weight_count
    after insert
    on Weight for each row
begin
    update Person
    set weight_in_count = weight_in_count + 1
    where Person.id = new.person_id;
end !!


insert into Person(name, age, height, gender) values
    ('Gosho', 15, 150, 'male'),
    ('Misho', 20, 200, 'male'),
    ('Stefi', 18, 169, 'female');

insert into Weight(value, person_id) values
    (50, 1),
    (57, 1),
    (53, 1),
    (78, 2),
    (80, 2),
    (75, 2),
    (50, 3),
    (48, 3),
    (52, 3);