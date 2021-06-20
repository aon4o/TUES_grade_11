package com.elsys.restaurant;

import java.util.HashMap;
import java.util.Map;

public class Storage
{
    protected Map<Product, Integer> products = new HashMap<>();

    public void addProduct(Product product, int amount)
    {
        if (products.containsKey(product))
        {
            products.replace(product, products.get(product) + amount);
        }
        else
        {
            products.put(product, amount);
        }
    }

    public void getProduct(Product product, int amount) throws Exception
    {
        if (products.containsKey(product))
        {
            if (products.get(product) >= amount)
            {
                products.replace(product, products.get(product) - amount);
                return;
            }
        }
        throw new Exception("There's not enough from the wanted product in storage!");
    }
}
