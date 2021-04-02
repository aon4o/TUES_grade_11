package com.elsys.classes;

public class Scroll extends Item implements Equippable, Usable {
    int damage;

    public Scroll(String name, int damage) {
        try {
            if (name == null || name.length() < 3) {
                throw new Exception("Name should be at least 3 characters long!");
            }
            if (damage <= 0) {
                throw new Exception("Damage cannot be less or equal to 0!");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.name = name;
        this.damage = damage;
    }

    @Override
    public void use(Character source, Character target) {
        try {
            if (source instanceof Mage) {
                if (((Mage) source).currentMana < 10) {
                    throw new Exception("Scroll needs 10 mana to be used!");
                } else {
                    ((Mage) source).currentMana -= 10;
                    if (source.intelligence == target.intelligence) {
                        target.currentHealth -= damage;
                    } else if (source.intelligence < target.intelligence) {
                        target.currentHealth -= damage - ((target.intelligence - source.intelligence) * (10f / 100f) * damage);
                    } else {
                        target.currentHealth -= damage - ((source.intelligence - target.intelligence) * (10f / 100f) * damage);
                    }
                }
            } else {
                throw new Exception("Scroll needs mana to be used!");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
