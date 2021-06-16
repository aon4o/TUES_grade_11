package com.elsys.restaurant;

public class Product {
    final private String name;
    final private int maxAmount;

    public Product(String name, int maxAmount) {
        this.name = name;
        this.maxAmount = maxAmount;
    }

    public String getName() {
        return name;
    }

    public int getMaxAmount() {
        return maxAmount;
    }
}
