package bg.elsys.exam;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TrainerTest {

    @Test
    void getId() {
        Trainer trainer = new Trainer(1, "Gosho");
        assertEquals(1, trainer.getId());
    }

    @Test
    void getName() {
        Trainer trainer = new Trainer(1, "Gosho");
        assertEquals("Gosho", trainer.getName());
    }
}