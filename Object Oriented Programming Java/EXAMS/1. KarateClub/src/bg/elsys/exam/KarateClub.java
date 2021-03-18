package bg.elsys.exam;

public class KarateClub {
    Trainee[] trainees;
    Trainer[] trainers;
    Training[] trainings;

    public KarateClub(Trainee[] trainees, Trainer[] trainers, Training[] trainings) {
        this.trainees = trainees;
        this.trainers = trainers;
        this.trainings = trainings;
    }

    public void train(Trainer[] trainers, Trainee[] trainees, String training) {
        try
        {
//            CHECKING FOR ERRORS
            for (Trainer trainer : this.trainers) {
                for (Trainer t : trainers) {
                    if (trainer == t) {
                        throw new ClubMemberNotFound();
                    }
                }
            }
            for (Trainee trainee : this.trainees) {
                for (Trainee t : trainees) {
                    if (trainee == t) {
                        throw new ClubMemberNotFound();
                    }
                }
            }

//            ADDING THE TRAINING
            Training[] temp = new Training[trainings.length];
            temp[temp.length-1] = new Training(temp.length, training, trainers, trainees);
            System.arraycopy(trainings, 0, temp, 0, trainings.length);
            trainings = temp;

        }
        catch (ClubMemberNotFound e) {
            e.printStackTrace();
        }
    }

    public void addTrainer(Trainer trainer) {
        try
        {
            for (Trainer t : trainers) {
                if (t.getId() == trainer.getId()) {
                    throw new Exception("addTrainerException");
                }
            }
            Trainer[] temp = new Trainer[trainers.length];
            temp[temp.length-1] = trainer;
            System.arraycopy(trainers, 0, temp, 0, trainers.length);
            trainers = temp;
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void addTrainee(Trainee trainee) {
        try
        {
            for (Trainee t : trainees) {
                if (t.getId() == trainee.getId()) {
                    throw new Exception("addTraineeException");
                }
            }
            Trainee[] temp = new Trainee[trainees.length];
            temp[temp.length-1] = trainee;
            System.arraycopy(trainees, 0, temp, 0, trainees.length);
            trainees = temp;
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }
}
