package com.elsys;

import com.elsys.classes.*;

public class Main {

    public static void main(String[] args) {
        Archer archer = new Archer();
        Mage mage = new Mage();

        Item note = new Note("Garjoka otkradna taksi!!!", "Taka uvajavaniqt, MC Garjoka, se napuka na piko," +
                "otkradna taksi ot Varna, no beshe zalowen v Shumen!");
        Item potion = new Potion("Healing potion", 25, 0);
        Item scroll = new Scroll("Fireball", 10);
        Item bow = new Bow("Aethelthryth's bow", 10, 50);

        archer.pick(bow);
        archer.pick(potion);
        mage.pick(note);
        mage.pick(scroll);

        System.out.print(archer.toString());
        System.out.println(mage.toString());

        mage.useAt(1, archer);
        mage.useAt(1, archer);
        mage.useAt(1, archer);
        mage.useAt(1, archer);
        mage.useAt(1, archer);
        mage.useAt(1, archer);

        System.out.print(archer.toString());
        System.out.println(mage.toString());

        archer.useAt(2, archer);

        System.out.print(archer.toString());
        System.out.println(mage.toString());
    }
}
