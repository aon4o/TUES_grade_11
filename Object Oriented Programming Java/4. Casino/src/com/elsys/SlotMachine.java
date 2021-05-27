package com.elsys;
import java.util.concurrent.ThreadLocalRandom;

public class SlotMachine implements Runnable{
    Casino casino;
    Player player;
    Thread thread;

    public SlotMachine(Casino casino) {
        this.casino = casino;
    }

    @Override
    public void run() {
        while (true) {
            if (player.getMoney() < 10) {
                if (casino.players.size() > 0) {
                    this.setPlayer();
                }
            } else {
                if (ThreadLocalRandom.current().nextInt(-2, 2) == 1){
                    double coefficient = ThreadLocalRandom.current().nextDouble(0.1, 3.1);
                    player.addMoney(10 * coefficient);
                } else {
                    player.addMoney(-10);
                    casino.addMoney(10);
                }

                System.out.printf("Player:%s Money:%.2f\n", player.getName(), player.getMoney());

            }

        }
    }

    public void setPlayer() {
        this.player = casino.players.remove(0);
    }

    public void start(){
        if (thread == null) {
            thread = new Thread(this);
        }
        thread.start();
    }
}
