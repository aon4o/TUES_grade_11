package com.elsys.unitTest;

import com.elsys.restaurant.Product;
import com.elsys.restaurant.Storage;
import org.junit.jupiter.api.*;

import static org.junit.jupiter.api.Assertions.*;

class StorageTest {

    Storage storage = new Storage();
    Product prod = new Product("prod", 10, Product.Units.gram);

    @Test
    void getProduct() {
        storage.addProduct(prod, 10);
        assertThrows(Exception.class, () -> storage.getProduct(prod, 100));
    }
}