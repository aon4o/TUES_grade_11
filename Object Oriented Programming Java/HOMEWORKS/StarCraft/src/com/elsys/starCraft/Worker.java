package com.elsys.starCraft;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;

public class Worker implements Runnable
{
    protected int id;
    protected int crystals = 0;
    Base base;
    ArrayList<CrystalBlock> crystalBlocks;
    boolean done = false;

    protected Worker(int id, Base base) {
        this.id = id;
        this.base = base;
        this.crystalBlocks = new ArrayList<>(base.crystalBlocks);
    }

    @Override
    public void run() {
        CrystalBlock currentBlock;
        boolean endFlag;
        boolean emptyFlag;

        while (true)
        {
//            STOPPING THE WORKER
            if (crystalBlocks.isEmpty()) {
                done = true;
                while (true);
            }

            currentBlock = null;
            endFlag = false;
            emptyFlag = false;

//            CYCLING THROUGH THE BLOCKS
            for (CrystalBlock block : crystalBlocks)
            {
//                CHECKING IF THE BLOCK IS EMPTY
                block.crystalLock.lock();
                if (block.crystals == 0) {
                    crystalBlocks.remove(block);
                    block.crystalLock.unlock();
                    break;
                }
                block.crystalLock.unlock();

//                CYCLING THROUGH THE LOCKS
                for (Lock lock : block.placeLocks)
                {
//                    GOING TO A BLOCK
                    if (lock.tryLock())
                    {
                        lock.unlock();
                        try {
                            if (currentBlock == null) {
                                Thread.sleep(1000);
                            } else {
                                Thread.sleep((long) (0.5 * 1000));
                            }
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                        currentBlock = block;
                        break;
                    }
                }

//                CHECKING AGAIN
                for (Lock lock : block.placeLocks)
                {
                    if (lock.tryLock())
                    {
//                        GETTING THE CRYSTALS
                        block.crystalLock.lock();
                        if (block.crystals == 0) {
                            crystalBlocks.remove(block);
                            emptyFlag = true;
                        }
                        else if (block.crystals <= 20) {
                            crystals = block.crystals;
                            block.crystals = 0;
                            crystalBlocks.remove(block);
                        } else {
                            crystals = 20;
                            block.crystals -= 20;
                        }
                        block.crystalLock.unlock();

//                        MINING THE CRYSTALS
                        if (!emptyFlag) {
                            try {
                                Thread.sleep((long) (1.5 * 1000));
                            } catch (InterruptedException e) {
                                e.printStackTrace();
                            }
                        }

//                        GOING TO THE BASE
                        try {
                            Thread.sleep(1000);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }

//                        GIVING THE CRYSTALS
                        if (crystals != 0) {
                            base.crystalsLock.lock();
                            base.crystals += crystals;
                            base.crystalsLock.unlock();
                            System.out.println("Worker with id " + (id) + " returned with " + crystals + " crystals.");
                            crystals = 0;
                        }

//                        GETTING REST
                        try {
                            Thread.sleep((long) (0.5 * 1000));
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }

                        endFlag = true;
                        break;
                    }
                }
                if (endFlag) {
                    break;
                }
            }
        }
    }
}
