package com.elsys.restaurant;

import java.util.*;

public class Restaurant {
    final String name;
    private Map<Product, Integer> products = new HashMap<>();
    List<Dish> dishes = new ArrayList<>();

    public Restaurant(String name) {
        this.name = name;
    }

    void addProduct(String product, int total) throws Exception {
        for ( Map.Entry<Product, Integer> pr : products.entrySet() ) {
            if (Objects.equals(pr.getKey().getName(), product)) {
                throw new Exception("Product already added!");
            }
        }
        products.put(new Product(product, total), total / 10);
    }

    void useProduct(String product, int amount) throws Exception {
        for ( Map.Entry<Product, Integer> pr : products.entrySet() ) {
            if (Objects.equals(pr.getKey().getName(), product)) {
                if (pr.getValue() >= amount) {
                    products.replace(pr.getKey(), pr.getValue() - amount);
                    return;
                }
                throw new Exception("Not enough products!");
            }
        }
        throw new Exception("The product is missing");
    }

    void loadProduct(String product, int amount) throws Exception {
        for ( Map.Entry<Product, Integer> pr : products.entrySet() ) {
            if (Objects.equals(pr.getKey().getName(), product)) {
                if (pr.getKey().getMaxAmount() < pr.getValue() + amount) {
                    throw new Exception("Max amount Exceeded!");
                }
                products.replace(pr.getKey(), pr.getValue() + amount);
            }
        }
        throw new Exception("The product is missing");
    }

    public int getProductAmount(String product) throws Exception {
        for ( Map.Entry<Product, Integer> pr : products.entrySet() ) {
            if (Objects.equals(pr.getKey().getName(), product)) {
                return pr.getValue();
            }
        }
        throw new Exception("The product is missing!");
    }

    public int getProductMaxAmount(String product) throws Exception {
        for ( Map.Entry<Product, Integer> pr : products.entrySet() ) {
            if (Objects.equals(pr.getKey().getName(), product)) {
                return pr.getKey().getMaxAmount();
            }
        }
        throw new Exception("The product is missing!");
    }

    public void addDish (Dish dish) throws Exception {
        for (Dish i : dishes) {
            if (Objects.equals(i.getName(), dish.getName())) {
                dishes.remove(i);
                dishes.add(dish);
                return;
            }
        }
        dishes.add(dish);
    }
}
