package org.elsys.alex;

public class HardDisc implements IPart
{
    int speed;
    int capacity;

    HardDisc(int speed, int capacity) {
        this.speed = speed;
        this.capacity = capacity;
    }

    @Override
    public PowerData getConsumption() {
        float typical = speed * capacity / 160000f;
        float min = typical * 0.1f;
        float max = typical * 2;
        return new PowerData(min, max, typical);
    }
}
