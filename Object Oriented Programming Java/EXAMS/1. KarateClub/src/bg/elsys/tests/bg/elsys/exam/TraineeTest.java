package bg.elsys.exam;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TraineeTest {

    @Test
    void getId() {
        Trainee trainee = new Trainee(1, "Alex", 1);
        assertEquals(1, trainee.getId());
    }

    @Test
    void getName() {
        Trainee trainee = new Trainee(1, "Alex", 1);
        assertEquals("Alex", trainee.getName());
    }

    @Test
    void getLevel() {
        Trainee trainee = new Trainee(1, "Alex", 1);
        assertEquals(1, trainee.getLevel());
    }

    @Test
    void getTrainings() {
        Trainee trainee = new Trainee(1, "Alex", 1);
        assertEquals(0, trainee.getTrainings());
    }

    @Test
    void addTraining() {
        Trainee trainee = new Trainee(1, "Alex", 1);
        trainee.addTraining();
        assertEquals(1, trainee.getTrainings());
    }
}