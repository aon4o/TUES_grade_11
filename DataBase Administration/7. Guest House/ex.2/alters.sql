alter table reception
add rating int check ( rating >= 0 and rating <= 5) default 0,
alter column sleep_date set default (DATE_FORMAT(NOW(), '%Y-%m-%d'));

update reception
set rating = '5'
where sleep_date < '2020-05-01';

update reception
set rating = '4'
where sleep_date >= '2020-05-01';