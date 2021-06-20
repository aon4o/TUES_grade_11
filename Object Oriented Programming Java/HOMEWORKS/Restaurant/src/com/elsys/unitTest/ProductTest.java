package com.elsys.unitTest;

import com.elsys.restaurant.Product;
import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

class ProductTest {

    Product product;

    @BeforeEach
    void setUp() {
        this.product = new Product("flour", 10, Product.Units.gram);
    }

    @Test
    void getName() {
        assertEquals("flour", product.getName());
    }

    @Test
    void getPrice() {
        assertEquals(10, product.getPrice());
    }

    @Test
    void getUnit() {
        assertEquals(Product.Units.gram, product.getUnit());
    }
}