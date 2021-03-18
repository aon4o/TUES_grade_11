package com.company;

import static java.lang.System.*;
import bg.elsys.exam.*;

public class Main {

    public static void main(String[] args) {
        Trainer trainer = new Trainer(1, "Gosho");
        out.println(trainer.getId());
    }
}
