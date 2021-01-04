# ALL PEOPLE IN A ROOM
select person.name as Name, room.name as Room from person_room
    left join person on person.id = person_room.person_id
    left join room on room.id = person_room.room_id;

# ALL PEOPLE NOT IN A ROOM
select person.name as "People not in rooms" from person_room
    right join person on person.id = person_room.person_id
    where person_room.id is null;

# MONEY SPEND
select sum(room.price_per_person) as "Money" from person_room
    left join person on person.id = person_room.person_id
    left join room on room.id = person_room.room_id;