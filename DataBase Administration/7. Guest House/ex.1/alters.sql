alter table person add column type varchar(10);
# TODO
delimiter $$
create trigger person_type
    after insert on person for each row
    begin
        if NEW.age >= 18 then
            update person set type = 'elder' where id = last_insert_id();
        end if;
        if NEW.age < 18 then
            update person set type = 'younger' where id = last_insert_id();
        end if;
    end $$

delimiter ;