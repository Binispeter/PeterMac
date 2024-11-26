import java.util.ArrayList;
import java.util.Arrays;

public class Registry {
    private ArrayList<Communication> communications = new ArrayList<Communication>();
    private ArrayList<Suspect> suspects = new ArrayList<Suspect>();

    public void addSuspect(Suspect aSuspect) {
        suspects.add(aSuspect);
    }

    //adds new communication to the communications arraylist
    /*when it finds the 2 suspects the phones belong to (counter == 2) 
    it uses the addPossiblePartner method of Suspect class*/
    public void addCommunication(Communication aCommunication) {
        communications.add(aCommunication);
        
        String num1 = aCommunication.getPhoneNumber1();
        String num2 = aCommunication.getPhoneNumber2();

        int counter = 0;
        int suspectIndex1 = 0;
        int suspectIndex2 = 0;

        for (Suspect suspect: suspects) {
            if (suspect.getPhoneNumbers().contains(num1)) {
                suspectIndex1 = suspects.indexOf(suspect);
                counter++;
            }
              
            else if (suspect.getPhoneNumbers().contains(num2)) {
                suspectIndex2 = suspects.indexOf(suspect);
                counter++;
            }

            if (counter == 2) {
                suspects.get(suspectIndex1).addPossiblePartner(suspects.get(suspectIndex2));
                suspects.get(suspectIndex2).addPossiblePartner(suspects.get(suspectIndex1));
                break;
            }

        }
    }

    //returns suspect with the largest connectedSuspects list size
    public Suspect getSuspectWithMostPartners() {
        int suspectIndex = 0;
        int mostPartners = suspects.get(suspectIndex).getPartners().size();

        for (Suspect suspect: suspects) {
            if (suspect.getPartners().size() > mostPartners) { 
                mostPartners = suspect.getPartners().size();
                suspectIndex = suspects.indexOf(suspect);
            }
        }
        return suspects.get(suspectIndex);
    }

    /*after checking if a communication is a PhoneCall
    it compares the duration of all the phone calls between 
    the 2 phone numbers and returns the longest*/
    public PhoneCall getLongestPhoneCallBetween(String number1, String number2) {
        int longestDuration = 0;
        int commIndex = 0;
        for (Communication communication: communications ) {
            if (communication instanceof PhoneCall) {
                if (communication.getPhoneNumber1() == number1 && communication.getPhoneNumber2() == number2) {
                    if (((PhoneCall)communication).getCallDuration() > longestDuration) {
                        longestDuration = ((PhoneCall)communication).getCallDuration();
                        commIndex = communications.indexOf(communication); 
                    }
                }
            }
        }
        return (PhoneCall)communications.get(commIndex);
    }

    //same checking logic with the getLongestPhoneCallBetween member function
    //it returns a list of messages (communications) containing at least one 
    //of the words Bomb, Attack, Explosives and Gun
    public ArrayList<SMS> getMessagesBetween(String number1, String number2) {
        ArrayList<String> words = new ArrayList<>(Arrays.asList("Bomb", "Attack", "Explosives", "Gun"));
        ArrayList<SMS> messages = new ArrayList<>();

        for (Communication communication: communications) {
            if (communication instanceof SMS) {
                if (communication.getPhoneNumber1() == number1 && communication.getPhoneNumber2() == number2) {
                    for (String word: words) {
                        if (((SMS)communication).getTextMessage().contains(word)) {
                            messages.add(((SMS)communication));
                        }
                    }
                }
            }
        }
        return messages;
    }

    //getters
    public ArrayList<Communication> getCommunications() {
        return communications;
    }

    public ArrayList<Suspect> getSuspects() {
        return suspects;
    }
}
