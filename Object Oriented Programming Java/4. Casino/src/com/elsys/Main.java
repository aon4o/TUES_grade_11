package com.elsys;


import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws Exception {
        Casino casino = new Casino(10000000, 20);

        for (int i = 0; i < 10; i++) {
            casino.players.add(new Player("Gosho" + i, (i+1) * 50));
        }

        for (int i = 0; i < casino.numberSlotMachines; i++) {
            SlotMachine machine = new SlotMachine(casino);
            machine.setPlayer();
            casino.addMachine(machine);
            machine.start();
        }
    }
}
