package com.elsys.restaurant;

public class Product
{
    public enum Units { millilitre, litre, gram, kilogram }

    protected final String name;
    protected final float price;
    protected final Units unit;

    public Product(String name, float price, Units unit) {
        this.name = name;
        this.price = price;
        this.unit = unit;
    }

    public String getName() {
        return name;
    }

    public float getPrice() {
        return price;
    }

    public Units getUnit() {
        return unit;
    }
}
