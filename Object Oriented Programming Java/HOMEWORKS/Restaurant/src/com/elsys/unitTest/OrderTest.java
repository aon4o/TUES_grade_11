package com.elsys.unitTest;

import com.elsys.restaurant.Dish;
import com.elsys.restaurant.Order;
import com.elsys.restaurant.Product;
import org.junit.jupiter.api.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

class OrderTest {

    com.elsys.restaurant.Order order;
    ArrayList<Dish> dishes;

    @BeforeEach
    void setUp() {
        Product prod = new Product("prod", 10, Product.Units.gram);
        Map<Product, Integer> prods = new HashMap<>();
        prods.put(prod, 2);
        Dish dish = new Dish("dish", prods, 2);
        dishes = new ArrayList<>();
        dishes.add(dish);
        dishes.add(dish);
        this.order = new Order(1, dishes);
    }

    @Test
    void getDishes() {
        assertEquals(dishes, order.getDishes());
    }

    @Test
    void getSalePrice() {
        assertEquals(80, order.getSalePrice());
    }
}