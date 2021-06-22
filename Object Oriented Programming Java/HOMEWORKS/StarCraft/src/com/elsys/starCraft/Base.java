package com.elsys.starCraft;

import java.util.ArrayList;
import java.util.concurrent.locks.ReentrantLock;

public class Base implements Runnable
{
    int crystals = 0;
    ArrayList<Worker> workers = new ArrayList<>();
    ArrayList<CrystalBlock> crystalBlocks;
    final ReentrantLock crystalsLock = new ReentrantLock();

    public Base(ArrayList<CrystalBlock> crystalBlocks)
    {
        this.crystalBlocks = crystalBlocks;
        workers.add(new Worker(1, this));
        workers.add(new Worker(2, this));
    }

    void createWorker() {
        crystals -= 50;
        workers.add(new Worker(workers.size() + 1, this));
        Thread thread = new Thread(workers.get(workers.size() - 1));
        thread.setDaemon(true);
        thread.start();
        System.out.println("Worker with id " + (workers.size()) + " created.");
    }

    @Override
    public void run() {
        for (Worker worker : workers) {
            Thread thread = new Thread(worker);
            thread.setDaemon(true);
            thread.start();
        }

        while (workers.size() != 20)
        {
//            CREATING A WORKER IF ENOUGH CRYSTALS
            synchronized (crystalsLock) {
                if (crystals >= 50) {
                    createWorker();
                }
            }
        }

//        PRINTING END MESSAGE
        System.out.println("Initial workers: 2");
        System.out.println("Current workers: " + workers.size());
        System.out.println("Current crystals in base: " + crystals);
    }


}
