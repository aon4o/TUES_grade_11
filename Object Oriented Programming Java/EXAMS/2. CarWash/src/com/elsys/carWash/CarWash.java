package com.elsys.carWash;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class CarWash {
    final int id;
    protected int slots;
    protected float cash;
    protected ArrayList<Service> services = new ArrayList<>();
    protected ArrayList<Order> activeOrders = new ArrayList<>();
    protected ArrayList<Order> completedOrders = new ArrayList<>();
    protected int countOrders;

    public CarWash(int id, int slots) {
        this.id = id;
        this.slots = slots;
        this.countOrders = 0;
    }

    public void addService(Service service) {
        try {
            if (service.name.isEmpty() || service.name.isBlank()) {
                throw new Exception("Service name MUST NOT be empty!");
            }
            if (services != null) {
                for (Service value : services) {
                    if (Objects.equals(value.name, service.name)) {
                        throw new Exception("Service name MUST be unique!");
                    }
                }
            }
            services.add(service);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public void addOrder(Automobile automobile, List<Service> services) {
        try {
            if (slots >= activeOrders.size()) {
                throw new Exception("There are not empty slots available!");
            }
            countOrders++;
            activeOrders.add(new Order(countOrders, automobile, services));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public void completeOrder(int id) {
        try {
            for (Order order : activeOrders) {
                if (order.id == id) {
                    for (Service service : order.services) {
                        this.cash += service.price * order.automobile.priceMultiplayer;
                    }
                    completedOrders.add(order);
                    activeOrders.remove(order);
                    return;
                }
                throw new Exception("An Order with the given id was NOT found!");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public String getOverview() {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < services.size(); i++) {
            int timesOrdered = 0;
            for (int j = 0; j < completedOrders.size(); j++) {
                for (int k = 0; k < completedOrders.get(j).services.size(); k++) {
                    if (completedOrders.get(j).services.get(k).name.equals(services.get(i).name)) {
                        timesOrdered++;
                    }
                }
            }
            result.append(services.get(i).name);
            result.append(" - ");
            result.append(timesOrdered);
        }
        return result.toString();
    }
}
