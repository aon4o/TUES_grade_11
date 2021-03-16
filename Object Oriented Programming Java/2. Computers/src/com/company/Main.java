package com.company;

import org.elsys.alex.*;

public class Main {

    public static void main(String[] args) {
        Processor processor = new Processor(4, 5);
        Motherboard motherboard = new Motherboard("am3");
//        Computer pc1 = new Computer(null);
        Computer pc2 = new Computer(new Processor[]{processor});
        pc2.addPart(motherboard);
//        pc1.getConsumption();
        PowerData asd = pc2.getConsumption();
        System.out.println(asd.getMinimalPower());
        System.out.println(asd.getMaximumPower());
        System.out.println(asd.getTypicalPower());
    }
}
