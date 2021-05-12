package com.elsys;

import com.elsys.carWash.CarWash;
import com.elsys.carWash.Service;

public class Main {

    public static void main(String[] args) {
	// write your code here
    // molq za 5 gospodine

        CarWash carWash = new CarWash(69, 20);
        Service washCar = new Service("Wash Car", 20);
        carWash.addService(washCar);
    }
}
