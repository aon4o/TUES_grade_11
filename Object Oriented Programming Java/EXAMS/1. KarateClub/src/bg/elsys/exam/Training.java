package bg.elsys.exam;

public class Training {
    int id;
    String training;
    Trainer[] trainers;
    Trainee[] trainees;

    public Training(int id, String training, Trainer[] trainers, Trainee[] trainees) {
        this.id = id;
        this.training = training;
        this.trainers = trainers;
        this.trainees = trainees;

        for (Trainee trainee : trainees) {
            trainee.addTraining();
        }
    }

    public int getId() {
        return id;
    }

    public String getTraining() {
        return training;
    }

    public Trainer[] getTrainers() {
        return trainers;
    }

    public Trainee[] getTrainees() {
        return trainees;
    }
}
