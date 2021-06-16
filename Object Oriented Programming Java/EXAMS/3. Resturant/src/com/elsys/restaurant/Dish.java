package com.elsys.restaurant;

import java.util.Map;

public class Dish {
    private final String name;
    private final Map<String, Integer> products;
    private final int time;

    public Dish(String name, Map<String, Integer> products, int time) {
        this.name = name;
        this.products = products;
        this.time = time;
    }

    public String getName() {
        return name;
    }

    public int getTimeToCook() {
        return time;
    }
}
