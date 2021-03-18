package bg.elsys.exam;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TrainingTest {

    @Test
    void getId() {
        Training training = new Training(1, "legs", null, null);
        assertEquals(1, training.getId());
    }

    @Test
    void getTraining() {
        Training training = new Training(1, "legs", null, null);
        assertEquals("legs", training.getTraining());
    }

    @Test
    void getTrainers() {
        Training training = new Training(1, "legs", null, null);
        assertNull(training.getTrainers());
    }

    @Test
    void getTrainees() {
        Training training = new Training(1, "legs", null, null);
        assertNull(training.getTrainees());
    }
}