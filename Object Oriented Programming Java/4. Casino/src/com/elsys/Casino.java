package com.elsys;

import java.util.ArrayList;

public class Casino {
    private double money;
    final int numberSlotMachines;
    ArrayList<SlotMachine> slotMachines = new ArrayList<>();
    ArrayList<Player> players = new ArrayList<>();

    Casino(int money, int numberSlotMachines){
        this.money = money;
        this.numberSlotMachines = numberSlotMachines;
    }

    void addMachine(SlotMachine machine) throws Exception {
        if (slotMachines.size() < numberSlotMachines) {
            slotMachines.add(machine);
        } else {
            throw new Exception("Nqma mqsto!");
        }
    }

    synchronized public double getMoney() {
        return money;
    }
    synchronized public void addMoney(double money) {
        this.money += money;
    }
    public ArrayList<SlotMachine> getSlotMachines() {
        return slotMachines;
    }
}
