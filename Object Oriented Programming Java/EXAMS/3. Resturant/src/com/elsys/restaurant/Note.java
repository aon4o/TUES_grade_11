package com.elsys.restaurant;

import java.util.Map;

public class Note {
    Map<Dish, Integer> dishes;

    Note (Map<Dish, Integer> dishes) {
        this.dishes = dishes;
    }
}
