package com.elsys.classes;

public class Mage extends Character{

    int maxMana;
    int currentMana;

    public Mage() {
        this.maxHealth = 60;
        this.currentHealth = maxHealth;
        this.intelligence = 10;
        this.dexterity = 5;
        this.maxMana = 80;
        this.currentMana = maxMana;
    }

    @Override
    protected String getCharacterClass() {
        return "Mage";
    }
}
