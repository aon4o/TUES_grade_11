package com.elsys;

public class Player {
    private String name;
    private double money;

    Player(String name, int money){
        this.name = name;
        this.money = money;
    }

    public String getName(){
        return name;
    }
    synchronized public double getMoney(){
        return money;
    }
    synchronized void addMoney(double money){
        this.money += money;
    }
}
