package com.elsys.unitTest;

import com.elsys.restaurant.Dish;
import com.elsys.restaurant.Product;
import org.junit.jupiter.api.*;

import java.util.HashMap;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

class DishTest {

    Dish dish;

    @BeforeEach
    void setUp() {
        Product prod = new Product("prod", 10, Product.Units.gram);
        Map<Product, Integer> prods = new HashMap<>();
        prods.put(prod, 2);
        this.dish = new Dish("dish", prods, 2);
    }

    @Test
    void getSalePrice() {
         assertEquals(40, dish.getSalePrice());
    }

    @Test
    void getName() {
        assertEquals("dish", dish.getName());
    }

    @Test
    void getTimeToCook() {
        assertEquals(2, dish.getTimeToCook());
    }
}