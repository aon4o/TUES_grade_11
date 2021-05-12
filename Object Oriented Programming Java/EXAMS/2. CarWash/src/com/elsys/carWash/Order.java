package com.elsys.carWash;

import java.util.ArrayList;
import java.util.List;

public class Order {
    protected int id;
    protected Automobile automobile;
    protected List<Service> services = new ArrayList<>();

    public Order(int id, Automobile automobile, List<Service> services) {
        try {
            if (automobile == null) {
                throw new Exception("Automobile MUST NOT be null!");
            }
            if (services.isEmpty()) {
                throw new Exception("The list of Servises MUST NOT empty!");
            }
            this.id = id;
            this.automobile = automobile;
            this.services = services;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public Automobile getAutomobile() {
        return automobile;
    }
    public List<Service> getServices() {
        return services;
    }
}
