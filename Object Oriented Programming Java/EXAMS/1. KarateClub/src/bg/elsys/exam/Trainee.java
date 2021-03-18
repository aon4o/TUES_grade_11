package bg.elsys.exam;

public class Trainee {
    int id;
    String name;
    int level;
    int trainings;

    public Trainee(int id, String name, int level) {
        this.id = id;
        this.name = name;
        this.level = level;
        this.trainings = 0;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getLevel() {
        return level;
    }

    public int getTrainings() {
        return trainings;
    }

    public void addTraining() {
        ++this.trainings;
        if (this.trainings % 10 == 0) {
            ++level;
        }
    }
}
