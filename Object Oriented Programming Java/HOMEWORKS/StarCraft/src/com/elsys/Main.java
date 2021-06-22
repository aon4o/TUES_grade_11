package com.elsys;

import com.elsys.starCraft.Base;
import com.elsys.starCraft.CrystalBlock;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args)
    {
//        CREATING THE CRYSTAL BLOCKS
        ArrayList<CrystalBlock> crystalBlocks = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            crystalBlocks.add(new CrystalBlock());
        }

//        CREATING THE BASE
        Base base = new Base(crystalBlocks);
        new Thread(base).start();
    }
}
