package bg.elsys.exam;

public class ClubMemberNotFound extends Exception{
    public ClubMemberNotFound(){
        super();
    }
    public ClubMemberNotFound(String message){
        super(message);
    }
}
