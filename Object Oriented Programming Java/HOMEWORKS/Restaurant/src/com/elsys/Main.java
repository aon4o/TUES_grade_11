package com.elsys;

import com.elsys.restaurant.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws Exception {
        Restaurant restaurant = new Restaurant();

//        CREATING PRODUCTS
        Product flour = new Product("flour", 10, Product.Units.gram);
        Product may = new Product("may", 10, Product.Units.gram);
        Product salt = new Product("salt", 10, Product.Units.gram);
        Product sugar = new Product("sugar", 10, Product.Units.gram);
        Product oil = new Product("oil", 10, Product.Units.millilitre);
        Product tomatoSauce = new Product("tomato sauce", 10, Product.Units.gram);
        Product cheese = new Product("cheese", 10, Product.Units.gram);

//        ADDING PRODUCTS
        restaurant.addProduct(flour, 2500);
        restaurant.addProduct(may, 5);
        restaurant.addProduct(salt, 1000);
        restaurant.addProduct(sugar, 1000);
        restaurant.addProduct(oil, 1000);
        restaurant.addProduct(tomatoSauce, 1000);
        restaurant.addProduct(cheese, 5000);

        Map<Product, Integer> productsForPizza = new HashMap<>();
        productsForPizza.put(flour, 500);
        productsForPizza.put(may, 1);
        productsForPizza.put(salt, 15);
        productsForPizza.put(sugar, 15);
        productsForPizza.put(oil, 50);
        productsForPizza.put(tomatoSauce, 200);
        productsForPizza.put(cheese, 200);

//        CREATING DISHES
        Dish pizzaQuattroFormaggi = new Dish("pizza quattro formaggi", productsForPizza, 30);
        Dish asd = new Dish("asd", productsForPizza, 15);

//        CREATING ORDERS
        ArrayList<Dish> order1 = new ArrayList<>();
        ArrayList<Dish> order2 = new ArrayList<>();

        order1.add(pizzaQuattroFormaggi);
        order2.add(asd);

//        ADDING ORDERS
        restaurant.addOrder(new Order(1, order1));
        restaurant.addOrder(new Order(2, order2));

//        ADDING THREADS
        restaurant.addChef(new Chef("Manchev", restaurant));
        restaurant.addChef(new Chef("manchev2", restaurant));
        restaurant.addWaiter(new Waiter("waiter1", restaurant));
        restaurant.addWaiter(new Waiter("waiter2", restaurant));

        restaurant.start();
    }
}
