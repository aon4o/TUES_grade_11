package com.elsys.restaurant;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class Cashier implements Runnable {
    String name;
    Restaurant restaurant;

    Cashier(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    Note makeOrder(Map<String, Integer> dishes) throws Exception {
        Map<Dish, Integer> noteMap = new HashMap<>();
        boolean flag = true;

        for (Map.Entry<String, Integer> dish : dishes.entrySet()) {
            flag = true;
            for (Dish i : restaurant.dishes) {
                if (Objects.equals(i.getName(), dish.getKey())) {
                    noteMap.put(i, dish.getValue());
                    flag = false;
                    break;
                }
            }
            if (flag) {
                throw new Exception("Dish not found!");
            }
        }
        return new Note(noteMap);
    }

    @Override
    public void run() {

    }
}
