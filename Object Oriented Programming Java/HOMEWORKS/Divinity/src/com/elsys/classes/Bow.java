package com.elsys.classes;

public class Bow extends Item implements Equippable, Usable{
    int damage;
    int durability;

    public Bow(String name, int damage, int durability) {
        try {
            if (name == null || name.length() < 3) {
                throw new Exception("Name should be at least 3 characters long!");
            }
            if (damage <= 0) {
                throw new Exception("Damage cannot be 0 or less!");
            }
            if (durability < 0) {
                throw new Exception("Durability cannot be less than 0!");
            }
            this.name = name;
            this.damage = damage;
            this.durability = durability;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void use(Character source, Character target) {
        if (durability <= 0) {
            System.out.println("The bow just broke :(");
            return;
        }else if (durability == 20){
            System.out.println("The bow is going to break soon (20 more shots)!");
        }

        if (source.dexterity == target.dexterity) {
            target.currentHealth -= damage;
        } else if (source.dexterity < target.dexterity) {
            target.currentHealth -= damage - ((target.dexterity - source.dexterity) * (10f / 100f) * damage);
        } else {
            target.currentHealth -= damage - ((source.dexterity - target.dexterity) * (10f / 100f) * damage);
        }

        --durability;
    }
}
