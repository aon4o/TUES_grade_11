package com.elsys;

import com.elsys.restaurant.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws Exception {
        Restaurant restaurant = new Restaurant("Typoto");

        Product flour = new Product("flour", 10);
        Product may = new Product("may", 10);
        Product salt = new Product("salt", 10);
        Product sugar = new Product("sugar", 10);
        Product oil = new Product("oil", 10);
        Product tomatoSauce = new Product("tomato sauce", 10);
        Product cheese = new Product("cheese", 10);

        Map<String, Integer> productsForPizza = new HashMap<>();
        productsForPizza.put("flour", 500);
        productsForPizza.put("may", 1);
        productsForPizza.put("salt", 15);
        productsForPizza.put("sugar", 15);
        productsForPizza.put("oil", 50);
        productsForPizza.put("tomatoSauce", 200);
        productsForPizza.put("cheese", 200);

        Dish pizzaQuattroFormaggi = new Dish("pizza quattro formaggi", productsForPizza, 30);
    }
}
