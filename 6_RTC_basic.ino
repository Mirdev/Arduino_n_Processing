#include <DS1302.h> //DS3231 also used for RTC

#define CLK 5
#define DAT 4
#define RST 2

DS1302 rtc(RST, DAT, CLK);

void setup() {
  // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);

  // Setup Serial connection
  Serial.begin(9600);

  // The following lines can be commented out to use the values already stored in the DS1302
  rtc.setDOW(TUESDAY);    // Set Day-of-Week to today [set time on now; manually]
  rtc.setTime(22,59,2);     // Set the time to 12:00:00 (24hr format) [set time on now; manually]
  rtc.setDate(20,07,2021);   // Set the date to July 20th, 2021 [set time on now; manually]
  // Once set this, then must be remove these lines for next running.(RTC already running our setting values)
}

void loop() {
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");

  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());

  // Wait one second before repeating :)
  delay (1000);
}
