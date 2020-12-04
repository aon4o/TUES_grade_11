create table Person
(
    id int unsigned primary key auto_increment not null,
    name varchar(100) unique not null
);

create table Item
(
    id int unsigned primary key auto_increment not null,
    name varchar(100) unique not null,
    type varchar(50) not null,
    price float not null
);

create table Store
(
    id int unsigned primary key auto_increment not null,
    person_id int unsigned not null references Person(id),
    item_id int unsigned not null references Item(id),
    created_at timestamp default CURRENT_TIMESTAMP()
);
