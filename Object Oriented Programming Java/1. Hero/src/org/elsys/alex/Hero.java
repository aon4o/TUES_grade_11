package org.elsys.alex;

public class Hero {
    String name;
    String heroClass;
    Weapon[] weaponsEquipped = new Weapon[2];
    Armor[] armorsEquipped = new Armor[4];
    Potion[] potionsEquipped = new Potion[6];
    Bag bag;

    public Hero(String name, String heroClass, Bag bag) {
        this.name = name;
        this.heroClass = heroClass;
        this.bag = bag;
    }

    public void pickUpItem(Item item) {
        try {
            for (int i = 0; i < 6; ++i)
            {
                if (bag.items[i] == null)
                {
                    bag.items[i] = item;
                    return;
                }
            }
            throw new Exception("The Bag is full!");
        } catch (Exception msg) {
            msg.printStackTrace();
        }
    }

    public void addItem(Item item) {
        try{
            if (item instanceof Weapon)
            {
                for (int i = 0; i < 2; i++) {
                    if (weaponsEquipped[i] == null)
                    {
                        weaponsEquipped[i] = (Weapon) item;
                        return;
                    }
                }
                throw new Exception("Weapon slots are full!");
            } else if (item instanceof Armor)
            {
                for (int i = 0; i < 4; i++) {
                    if (armorsEquipped[i] == null)
                    {
                        armorsEquipped[i] = (Armor) item;
                        return;
                    }
                }
                throw new Exception("Armor slots are full!");
            } else if (item instanceof Potion)
            {
                for (int i = 0; i < 6; i++) {
                    if (potionsEquipped[i] == null)
                    {
                        potionsEquipped[i] = (Potion) item;
                        return;
                    }
                }
                throw new Exception("Potion slots are full!");
            } else if (item instanceof Bag)
            {
                if (this.bag == null) {
                    this.bag = (Bag) item;
                } else {
                    throw new Exception("Bag slots are full!");
                }
            } else{
                throw new Exception("ERROR!!!");
            }
        } catch (Exception msg) {
            msg.printStackTrace();
        }
    }
}
