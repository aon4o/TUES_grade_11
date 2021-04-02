package com.elsys.classes;

public class Potion extends Item implements Equippable, Consumable {
    int health;
    int mana;

    public Potion(String name, int health, int mana) {
        try {
            if (name == null || name.length() < 3) {
                throw new Exception("Name should be at least 3 characters long!");
            }
            if (health < 0) {
                throw new Exception("Health cannot be less than 0!");
            }
            if (mana < 0) {
                throw new Exception("Mana cannot be less than 0!");
            }
            if (health == 0 && mana == 0) {
                throw new Exception("The potion should be useful");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.name = name;
        this.health = health;
        this.mana = mana;
    }

    @Override
    public void consume(Character target) {
        if (target.maxHealth - target.currentHealth <= health) {
            target.currentHealth = target.maxHealth;
        } else {
            target.currentHealth += health;
        }

        if (target instanceof Mage) {
            if (((Mage) target).maxMana - ((Mage) target).currentMana <= mana) {
                ((Mage) target).currentMana = ((Mage) target).maxMana;
            } else {
                ((Mage) target).currentMana += mana;
            }
        }
    }
}
