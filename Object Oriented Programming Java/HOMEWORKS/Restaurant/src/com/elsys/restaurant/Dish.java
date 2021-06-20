package com.elsys.restaurant;

import java.util.Map;

public class Dish
{
    private final String name;
    private final Map<Product, Integer> products;
    private final int timeToCook;

    public Dish(String name, Map<Product, Integer> products, int timeToCook) {
        this.name = name;
        this.products = products;
        this.timeToCook = timeToCook;
    }

    public float getSalePrice()
    {
        float finalPrice = 0;
        for(Map.Entry<Product, Integer> product : products.entrySet())
        {
            finalPrice += product.getKey().getPrice() * product.getValue();
        }
        return finalPrice * 2;
    }

    public String getName() {
        return name;
    }

    public Map<Product, Integer> getProducts() {
        return products;
    }

    public int getTimeToCook() {
        return timeToCook;
    }
}
