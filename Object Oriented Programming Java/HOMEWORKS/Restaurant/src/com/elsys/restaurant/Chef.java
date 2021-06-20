package com.elsys.restaurant;

import java.util.HashMap;
import java.util.Map;

public class Chef implements Runnable {
    protected final String name;
    protected final Restaurant restaurant;

    public Chef(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {
        Order currentOrder;
        int time = 0;
        boolean failedFlag = false;

        while (true)
        {
//            GETTING AN ACTIVE ORDER IF ANY
            synchronized (restaurant.activeLock) {
                if (restaurant.activeOrders.size() == 0) {
                    continue;
                }
                currentOrder = restaurant.activeOrders.remove(0);
            }

//            CHECKING FOR PRODUCTS
            Map<Product, Integer> products = new HashMap<>();
            for (Dish dish : currentOrder.getDishes())
            {
                synchronized (restaurant.storageLock)
                {
                    for (Map.Entry<Product, Integer> entry : dish.getProducts().entrySet())
                    {
                        try {
                            restaurant.storage.getProduct(entry.getKey(), entry.getValue());
                            products.put(entry.getKey(), entry.getValue());
                        } catch (Exception e) {
                            e.printStackTrace();
                            failedFlag = true;
                            break;
                        }
                    }
                    if (failedFlag) {
                        break;
                    }
                }
            }

//            IF FAILED RETURNING THE PRODUCTS AND ADDING TO FAILED ORDERS
            if (failedFlag) {
                synchronized (restaurant.storageLock)
                {
                    for (Map.Entry<Product, Integer> entry : products.entrySet()) {
                        restaurant.storage.addProduct(entry.getKey(), entry.getValue());
                    }
                }
                synchronized (restaurant.failedLock)
                {
                    restaurant.failedOrders.add(currentOrder);
                }
                System.out.println("Order " + currentOrder.id + " failed.");
                continue;
            }

//            COOKING THE ORDER AND ADDING TO READY ORDERS
            for (Dish dish : currentOrder.getDishes()) {
                time += dish.getTimeToCook();
            }

            try {
                Thread.sleep(time * 1000L);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            synchronized (restaurant.readyLock) {
                restaurant.readyOrders.add(currentOrder);
            }
            System.out.println("Order " + currentOrder.id + " ready to be served.");
        }
    }
}
