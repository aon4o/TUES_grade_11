-- all people, that bought something
select Person.name as 'Buyers' from Person
right join Store
on Person.id = Store.person_id
group by Person.name;

-- all products, that are bought atleast once
select Item.name as 'Bought products' from Item
right join Store
on Item.id = Store.item_id
group by Item.name;

-- the profit of the shop
select sum(Item.price) as 'Shop profit'
from Item
right join Store
on Item.id = Store.item_id;

-- money spent from every buyer
select Person.name as 'Name of Buyer', sum(Item.price) as 'Money spent'
from Person
inner join Store
on Person.id = Store.person_id
inner join Item
on Store.item_id = Item.id
group by Person.name;
