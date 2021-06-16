package com.elsys.restaurant;

public class Helper implements Runnable {
    final String name;
    final Restaurant restaurant;

    public Helper(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    synchronized public void run() {
        while (true) {

        }
    }
}
