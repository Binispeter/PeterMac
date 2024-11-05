public class Player {
    private String name;
    private char chip;

    //Player object constructor
    Player(String name, char chip) {
        this.name = name;
        this.chip = chip;
    }

    //Getters and setters
    public String getName() {
        return name;
    }

    public char getChip() {
        return chip;
    }

    public void setName(String inputName) {
        name = inputName;
    }

    public void setChip(char inputChip) {
        chip = inputChip;
    }

}
