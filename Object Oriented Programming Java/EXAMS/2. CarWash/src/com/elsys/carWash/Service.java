package com.elsys.carWash;

public class Service {
    protected String name;
    protected float price;

    public Service(String name, float price) {
        try {
            if (name.isEmpty() || name.isBlank()) {
                throw new Exception("Service name MUST NOT be empty!");
            }
            if (price <= 0) {
                throw new Exception("Price MUST be a positive value!");
            }
            this.name = name;
            this.price = price;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String getName() {
        return name;
    }
    public float getPrice() {
        return price;
    }
}
