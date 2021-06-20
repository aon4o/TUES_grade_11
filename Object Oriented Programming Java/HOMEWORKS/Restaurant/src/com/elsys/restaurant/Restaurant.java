package com.elsys.restaurant;

import java.util.ArrayList;
import java.util.List;

public class Restaurant {
    protected List<Dish> dishes = new ArrayList<>();
    protected List<Chef> chefs = new ArrayList<>();
    protected List<Waiter> waiters = new ArrayList<>();
    protected Storage storage = new Storage();
    protected float money = 0;

    protected List<Order> activeOrders = new ArrayList<>();
    protected List<Order> readyOrders = new ArrayList<>();
    protected List<Order> completedOrders = new ArrayList<>();
    protected List<Order> failedOrders = new ArrayList<>();

    protected final Object activeLock = new Object();
    protected final Object readyLock = new Object();
    protected final Object completedLock = new Object();
    protected final Object failedLock = new Object();
    protected final Object storageLock = new Object();

    public void addOrder (Order order) throws Exception
    {
        if (order == null || order.getDishes().isEmpty()) {
            throw new Exception("The order is empty!");
        }
        synchronized (activeLock) {
            activeOrders.add(order);
        }
    }

    protected void completeOrder (int id) throws Exception
    {
        for (Order order : readyOrders)
        {
            synchronized (completedLock)
            {
                if (order.id == id) {
                    this.money += order.getSalePrice();
                    completedOrders.add(order);
                    readyOrders.remove(order);
                    return;
                }
            }
        }
        throw new Exception("Order with that id does not exist!");
    }

    public void addChef (Chef chef) throws Exception
    {
        if (chefs.contains(chef)) {
            throw new Exception("The chef is already added!");
        }
        chefs.add(chef);
    }

    public void addWaiter (Waiter waiter) throws Exception
    {
        if (waiters.contains(waiter)) {
            throw new Exception("The waiter is already added!");
        }
        waiters.add(waiter);
    }

    public void addProduct(Product product, int amount)
    {
        storage.addProduct(product, amount);
    }

    public void start ()
    {
        for (Chef chef : chefs) {
            new Thread(chef).start();
        }
        for (Waiter waiter : waiters) {
            new Thread(waiter).start();
        }
    }
}
