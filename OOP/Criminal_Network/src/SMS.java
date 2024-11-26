public class SMS extends Communication{
    private String textMessage;

    public SMS(String phoneString1, String phoneString2, int day, int month, int year, String message) {
        this.phoneNumber1 = phoneString1;
        this.phoneNumber2 = phoneString2;
        this.day = day;
        this.month = month;
        this.year = year;
        this.textMessage = message;
    }

    public void printInfo() {
        System.out.println("This SMS has the following info");
        System.out.println("Between " + phoneNumber1 + " --- " + phoneNumber2);
        System.out.println("on " + year + "/" + month + "/" + day);
        System.out.println("Text: " + textMessage);
    }

    public String getTextMessage() {
        return textMessage;
    }
}
