# COUNTING MISHO'S WINS
select count(*) as `Times Misho has won` from battle
left join person
on person.id = battle.winner_id
where person.name = 'Misho';

# PEOPLE MISHO LOST TO
select winner.name as "People that won vs Misho" from battle
left join person as loser
on loser.id = battle.looser_id
left join person as winner
on winner.id = battle.winner_id
where loser.name = 'Misho'
group by winner_id;

# ALL BATTLES WITH WINNER AND LOOSER NAMES
select battle.id as "Battle No.", winner.name as "Winner", looser.name as "Looser"
from battle
left join person as looser
on looser.id = battle.looser_id
left join person as winner
on winner.id = battle.winner_id;