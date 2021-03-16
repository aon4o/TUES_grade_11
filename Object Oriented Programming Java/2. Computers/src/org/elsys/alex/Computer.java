package org.elsys.alex;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;

public class Computer implements IPart
{
    ArrayList<IPart> parts = new ArrayList<>();
    int motherboards = 0, processors = 0;

    public Computer(IPart[] parts)
    {
        if (parts != null) {
            for (IPart part : parts)
            {
                try {
                    if (part instanceof Motherboard) {
                        ++motherboards;
                    } else if (part instanceof Processor) {
                        ++processors;
                    }

                    if (motherboards > 1 || processors > 2) {
                        throw new Exception("Motherboards can be 1 at most!\nProcessors can be 2 at most!");
                    } else {
                        this.parts.add(part);
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }

    @Override
    public PowerData getConsumption()
    {
        ArrayList<PowerData> powerData = new ArrayList<>();
        float min = 0, max = 0, typical = 0;

        for (int i = 0; i < parts.size(); i++) {
            powerData.add(i, this.parts.get(i).getConsumption());
        }
        for (PowerData power : powerData) {
            min += power.minimalPower;
            max += power.maximumPower;
            typical += power.typicalPower;
        }

        return new PowerData(min, max, typical);
    }

    public void addPart(IPart part)
    {
        try {
            if (part instanceof Motherboard) {
                ++motherboards;
            } else if (part instanceof Processor) {
                ++processors;
            }

            if (motherboards > 1 || processors > 2) {
                throw new Exception("Motherboards can be 1 at most!\nProcessors can be 2 at most!");
            } else {
                this.parts.add(part);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
