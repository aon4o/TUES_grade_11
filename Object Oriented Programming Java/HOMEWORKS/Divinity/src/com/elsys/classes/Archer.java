package com.elsys.classes;

public class Archer extends Character{

    public Archer() {
        this.maxHealth = 100;
        this.currentHealth = 100;
        this.intelligence = 5;
        this.dexterity = 10;
    }

    @Override
    protected String getCharacterClass() {
        return "Archer";
    }
}
