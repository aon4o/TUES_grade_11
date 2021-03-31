# 1
drop database if exists facebook;
create database facebook;
use facebook;

create table `group`(
id int unsigned primary key not null auto_increment,
name varchar(100) not null
);

create table user(
id int unsigned primary key not null auto_increment,
name varchar(100) not null
);

create table `group_user`(
id int unsigned primary key not null auto_increment,
group_id int unsigned not null references `group`(id),
user_id int unsigned not null references user(id)
);

create table post(
id int unsigned primary key not null auto_increment,
name varchar(100) not null,
content text not null,
# user_id int unsigned not null references user(id),
group_id int unsigned not null references `group`(id)
);

create table comment(
id int unsigned primary key not null auto_increment,
content text not null,
user_id int unsigned not null references user(id),
post_id int unsigned not null references post(id)
);

# 2
insert into `group`(name) values
('Weed'),
('Cops'),
('Empty');

insert into user(name) values
('Alex'),
('Kris'),
('Stefi'),
('Gosho'),
('Misho'),
('Dilara'),
('Stancho e tam'),
('GP'),
('Milchev'),
('Vasko barman');

insert into group_user(group_id, user_id) values
(1, 1),
(1, 3),
(1, 4),
(1, 6),
(2, 2),
(2, 5),
(2, 8);

insert into post(name, content, group_id) values
('Garjoka kradna taksi', 'Garjoka kradna taksi ot Varna i beshe zaloven Shumen, naprawen na piko(metka)!', 1),
('Zalowiha wsichki dilari w Strelbata', 'Sega sme na suho', 1),
('Pisna mi da mislq', 'asdasdasddsadsadsa', 2);

insert into comment(content, user_id, post_id) values
('Lud sii', 1, 1),
('Pak typite kuki', 3, 1),
('Mn zle, mn', 1, 2),
('asd', 2, 3),
('dsa', 5, 3);

# 3 todo
select c.content, u.name, p.name, g.name from comment c
left join user u on u.id = c.user_id
left join post p on p.id = c.post_id
left join group_user gu on gu.group_id = u.id
left join `group` g on g.id = gu.group_id;

# 4 - People who haven't written comments.
select u.name as 'Name' from user u
left join comment c on u.id = c.user_id
where c.id is null;

# 5 - People who are in groups
select u.name as "Name" from user u
left join group_user gu on u.id = gu.user_id
where gu.id is null;

# 6 - Groups without people in them
select `group`.name as 'Group Name' from `group`
left join group_user gu on `group`.id = gu.group_id
where gu.id is null;

# 7
select g.name as 'Group Name' from comment c
left join post p on p.id = c.post_id
left join `group` g on g.id = p.group_id
where length(c.content) < 10
group by g.name;