package org.elsys.alex;

public class Motherboard implements IPart
{
    String chipset;

    public Motherboard(String chipset) {
        this.chipset = chipset;
    }

    @Override
    public PowerData getConsumption() {
        float typical;
        if (chipset.equals("am1")) {
            typical = 25f;
        } else if (chipset.equals("am2")) {
            typical = 35f;
        } else if (chipset.equals("am3")) {
            typical = 50f;
        } else {
            typical = 30f;
        }
        return new PowerData(typical, typical, typical);
    }
}
