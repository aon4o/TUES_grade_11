package org.elsys.alex;

public class PowerData
{
    float minimalPower;
    float maximumPower;
    float typicalPower;

    public PowerData(float minimalPower, float maximumPower, float typicalPower)
    {
        try {
            if (minimalPower <= 0 || maximumPower <= 0 || typicalPower <= 0){
                throw new Exception("The powers cannot be less than or equal to zero!");
            }
            this.minimalPower = minimalPower;
            this.maximumPower = maximumPower;
            this.typicalPower = typicalPower;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public float getMinimalPower() {
        return minimalPower;
    }

    public float getMaximumPower() {
        return maximumPower;
    }

    public float getTypicalPower() {
        return typicalPower;
    }
}
