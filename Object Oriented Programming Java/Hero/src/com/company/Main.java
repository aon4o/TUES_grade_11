package com.company;

import org.elsys.alex.*;

public class Main {
    public static void main(String[]args){
        Bag bag = new Bag("Gosho's bag");
        Hero hero = new Hero("Gosho", "warior", bag);
        Weapon sword = new Weapon("Gosho's Sword", 69);
        Armor helmet = new Armor("Gosho's Helmet", 75);
        Armor chestplate = new Armor("Gosho's Chestplate", 150);
        Armor leggings = new Armor("Gosho's Leggings", 75);
        Armor boots = new Armor("Gosho's Boots", 50);
        Armor oldArmor = new Armor("Old armor", 10);

        hero.addItem(sword);
        hero.addItem(helmet);
        hero.addItem(chestplate);
        hero.addItem(leggings);
        hero.addItem(boots);
//        hero.addItem(oldArmor);


//        BAG TEST
        hero.pickUpItem(oldArmor);
    }
}
