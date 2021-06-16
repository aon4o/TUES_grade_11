package com.elsys.restaurant;

public class Chef implements Runnable {
    final String name;
    final Restaurant restaurant;

    public Chef(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    synchronized public void run() {
        
    }
}
