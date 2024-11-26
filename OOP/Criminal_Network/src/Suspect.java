import java.util.ArrayList;

public class Suspect {
    private String name;
    private String codeName;
    private String city;
    private ArrayList<String> phoneNumbers = new ArrayList<String>();
    private ArrayList<Suspect> connectedSuspects = new ArrayList<Suspect>();

    public Suspect(String name, String codeName, String city) {
        this.name = name;
        this.codeName = codeName;
        this.city = city;
    }

    public void addNumber(String number) {
        phoneNumbers.add(number);
    }

    public void addPossiblePartner(Suspect aSuspect) {
        if (!this.isConnectedTo(aSuspect))
            connectedSuspects.add(aSuspect);
    }

    //checks if list of partners contains the input suspect
    public boolean isConnectedTo(Suspect aSuspect) {
        if (connectedSuspects.contains(aSuspect))
            return true;
        return false;
    }

    //initializes a list of partners copying this.connectedSuspects and removes the ones that are not in the sSuspect.connectedSuspects list
    public ArrayList<Suspect> getCommonPartners(Suspect aSuspect) {
        ArrayList<Suspect> commonSuspects = new ArrayList<>(connectedSuspects);
        commonSuspects.retainAll(aSuspect.getPartners());
        return commonSuspects;
    }

    public void printPartners(Suspect aSuspect) {
        int i=0;
        for (Suspect suspect: connectedSuspects){
            System.out.println(i + ". " + suspect.name + ", " + suspect.codeName);
        }
    }


    //Getters
    public String getName() {
        return name;
    }

    public String getCodeName() {
        return codeName;
    }

    public String getCity() {
        return city;
    }

    public ArrayList<Suspect> getPartners() {
        return connectedSuspects;
    }

    public ArrayList<String> getPhoneNumbers() {
        return phoneNumbers;
    }
}
