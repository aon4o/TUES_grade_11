insert into Person(name) values
    ("Alex"),
    ("Kris"),
    ("Misho");

insert into Item(name, type, price) values
    ("Samsung Galaxy J6 2019", "phone", 400),
    ("iPhone XI Pro", "phone", 2000),
    ("Xiomi Note 9 Pro", "phone", 500),
    ("Nokia 4.2", "phone", 600),
    ("iPhone XS", "phone", 1500);

insert into Store(person_id, item_id) values
    (1, 1),
    (1, 2),
    (1, 2),
    (1, 1),
    (2, 5),
    (2, 5),
    (2, 3),
    (1, 3),
    (1, 2),
    (2, 1);
