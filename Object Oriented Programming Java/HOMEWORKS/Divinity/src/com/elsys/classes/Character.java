package com.elsys.classes;

import java.util.ArrayList;
import java.util.List;

public abstract class Character {
    int currentHealth;
    int maxHealth;
    int intelligence;
    int dexterity;
    List<Item> inventory = new ArrayList<>();
    List<Item> hotBar = new ArrayList<>();

    abstract protected String getCharacterClass();

    public String toString() {
        if (this instanceof Mage) {
            return getCharacterClass() + " - Health: " + currentHealth + "; Mana: " + ((Mage) this).currentMana + ";\n";
        } else {
            return getCharacterClass() + " - Health: " + currentHealth + ";\n";
        }

    }

    public void pick(Item item) {
        try {
//        TRYING TO ADD ITEM IN HOTBAR
            if (item instanceof Equippable) {
                if (hotBar.size() < 3) {
                    hotBar.add(item);
                    return;
                } else {
                    for (int i = 0; i < 3; i++) {
                        if (hotBar.get(i) == null) {
                            hotBar.set(i, item);
                            return;
                        }
                    }
                }
            }

//        TRYING TO ADD ITEM IN INVENTORY
            if (inventory.size() < 10) {
                inventory.add(item);
                return;
            } else {
                for (int i = 0; i < 10; i++) {
                    if (inventory.get(i) == null) {
                        inventory.set(i, item);
                        return;
                    }
                }
            }

            throw new Exception("Inventory and Hotbar are full!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void useAt(int index, Character target) {
        try {
            if (index < 1 || index > 3) {
                throw new Exception("The HotBar can hold exactly 3 items!");
            }
            if (hotBar.size() < index) {
                throw new Exception("There's not an Item in this place!");
            }
            --index;
            if (hotBar.get(index) == null) {
                throw new Exception("There's not an Item in this place!");
            }

            if (hotBar.get(index) instanceof Consumable) {
                ((Consumable) hotBar.get(index)).consume(this);
                hotBar.set(index, null);
            } else if (hotBar.get(index) instanceof Usable) {
                ((Usable) hotBar.get(index)).use(this, target);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
