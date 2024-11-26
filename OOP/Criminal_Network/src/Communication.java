public class Communication {
    protected String phoneNumber1;
    protected String phoneNumber2;
    protected int year;
    protected int month;
    protected int day;

    public Communication() {
        phoneNumber1 = null;
        phoneNumber2 = null;
        year = 0;
        month = 0;
        day = 0;
    }

    public String getPhoneNumber1() {
        return phoneNumber1;
    }

    public String getPhoneNumber2() {
        return phoneNumber2;
    }

    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }
}
