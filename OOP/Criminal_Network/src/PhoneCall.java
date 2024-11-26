public class PhoneCall extends Communication{
    private int callDuration;

    public PhoneCall(String phoneString1, String phoneString2, int day, int month, int year, int duration) {
        this.phoneNumber1 = phoneString1;
        this.phoneNumber2 = phoneString2;
        this.day = day;
        this.month = month;
        this.year = year;
        this.callDuration = duration;
    }

    public void printInfo() {
        System.out.println("This phone call has the following info");
        System.out.println("Between " + phoneNumber1 + " --- " + phoneNumber2);
        System.out.println("on " + year + "/" + month + "/" + day);
        System.out.println("Duration: " + callDuration);
    }

    public int getCallDuration() {
        return callDuration;
    }
}
