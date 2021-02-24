package org.elsys.alex;

public class Weapon extends Item {
    int damage;

    public Weapon(String name, int damage) {
        this.name = name;
        this.damage = damage;
    }
}
