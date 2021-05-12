package com.elsys.carWash;

public abstract class Automobile {
    protected String maker;
    protected String model;
    protected float priceMultiplayer;

    public Automobile(String maker, String model, float priceMultiplayer) {
        try {
            if (maker.isEmpty() || maker.isBlank()) {
                throw new Exception("Maker MUST NOT be empty!");
            }
            if (model.isEmpty() || model.isBlank()) {
                throw new Exception("Model MUST NOT be empty!");
            }
            this.maker = maker;
            this.model = model;
            this.priceMultiplayer = priceMultiplayer;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String getMaker() {
        return maker;
    }
    public String getModel() {
        return model;
    }
}
