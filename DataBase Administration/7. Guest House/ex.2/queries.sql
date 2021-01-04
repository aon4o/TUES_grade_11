# People that slept the most nights TODO

# select p.name as name, (count(reception.id)) as ns from reception
# left join person as p on p.id = reception.person_id
# group by person_id
# order by ns desc;
#
# drop view max_ns;
# create view max_ns
# as select max(ns) from max_nights_slept
# limit 1;
#
# select * from max_ns;
#
# select * from max_nights_slept
# where ns =

# drop view max_nights;
# create view max_nights as (
#         select count(*) as 'ns' from reception
#         left join person p on p.id = reception.person_id
#         group by person_id
#         order by ns desc
# );
# set @max_asd = first_value(max_nights.ns) over ();
#
# select name, count(*) as 'ns' from reception
# left join person p on p.id = reception.person_id
# group by person_id
# having ns = @max_asd
# order by ns;
#



# Money spent by Alex form 01.01.2020 to 31.12.2020
select sum(room.price_per_person)
as 'Money spent by Alex form 01.01.2020 to 31.12.2020'
from reception
left join person on person.id = reception.person_id
left join room on reception.room_id = room.id
where person.name = 'Alex'
and reception.sleep_date between '2020-01-01' and '2020-12-31';

# How many different people have slept in the guest house
select count(distinct(person_id))
as "Different people that slept in the guest house."
from reception;

# Average rating of room with name 'A72'
select room.name as 'Room name', avg(reception.rating) as 'Average rating'
from reception
left join room on room.id = reception.room_id
where room.name = 'A72';