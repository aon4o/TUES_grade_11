package com.elsys.restaurant;

import java.util.ArrayList;
import java.util.List;

public class Order
{
    protected final int id;
    private final List<Dish> dishes;

    public Order(int id, ArrayList<Dish> dishes) {
        this.id = id;
        this.dishes = dishes;
    }

    public List<Dish> getDishes() {
        return dishes;
    }

    public float getSalePrice()
    {
        float finalPrice = 0;
        for (Dish dish : dishes ) {
            finalPrice += dish.getSalePrice();
        }
        return finalPrice;
    }
}
