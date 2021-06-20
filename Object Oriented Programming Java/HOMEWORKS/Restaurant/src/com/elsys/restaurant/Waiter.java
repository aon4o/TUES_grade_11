package com.elsys.restaurant;

public class Waiter implements Runnable {
    protected final String name;
    protected final Restaurant restaurant;

    public Waiter(String name, Restaurant restaurant) {
        this.name = name;
        this.restaurant = restaurant;
    }

    @Override
    public void run() {
        while (true) {
            synchronized (restaurant.readyLock)
            {
                if (restaurant.readyOrders.size() == 0) {
                    continue;
                }
                try {
                    System.out.println("Order " + restaurant.readyOrders.get(0).id + " served.");
                    restaurant.completeOrder(restaurant.readyOrders.get(0).id);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
