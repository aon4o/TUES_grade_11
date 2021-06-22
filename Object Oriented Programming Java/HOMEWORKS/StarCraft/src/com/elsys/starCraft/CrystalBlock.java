package com.elsys.starCraft;

import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;

public class CrystalBlock
{
    protected int crystals = 50;
    protected ReentrantLock crystalLock = new ReentrantLock();
    protected ArrayList<ReentrantLock> placeLocks = new ArrayList<>();

    public CrystalBlock() {
        placeLocks.add(new ReentrantLock());
        placeLocks.add(new ReentrantLock());
        placeLocks.add(new ReentrantLock());
    }
}
