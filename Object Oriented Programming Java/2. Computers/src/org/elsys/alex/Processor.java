package org.elsys.alex;

public class Processor implements IPart
{
    int cores;
    int frequency;

    public Processor(int cores, int frequency) {
        this.cores = cores;
        this.frequency = frequency;
    }

    @Override
    public PowerData getConsumption() {
        float typical = cores * frequency * frequency / 2f * 0.5f;
        float min = typical * 0.25f;
        float max = typical * 5;
        return new PowerData(min, max, typical);
    }
}
