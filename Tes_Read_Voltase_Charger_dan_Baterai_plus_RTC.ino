// Ini perubahan urang qi
//tambah led
//cobain pake ui

int valueinputCharger = 0;
int valueinputBattery = 0;
float valuevoltageCharger;
float valuevoltageBattery;
float R1 = 100000.0;
float R2 = 20000.0;
float R3 = 100000.0;
float R4 = 20000.0;

//RTC
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time waktu;

#define voltageCharger A0
#define voltageBattery A1

#define controlCharger 9

void setup() {
  // put your setup code here, to run once:

  rtc.begin(); // Initialize the rtc object
  
  Serial.begin(9600);
  pinMode(controlCharger, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(controlCharger, 225);
  
  
  read_voltase();
  tampilkan_serial();
}

void read_voltase(void)
  {
    valueinputCharger = analogRead(voltageCharger);
    valuevoltageCharger = valueinputCharger * (5.0/1024)*((R1 + R2)/R2);

    valueinputBattery = analogRead(voltageBattery);
    valuevoltageBattery = valueinputBattery * (5.0/1024)*((R3 + R4)/R4);
    
    delay(1000);
  }

void tampilkan_serial(void)
    {
        /*// Send Day-of-Week
        Serial.print(rtc.getDOWStr());
        Serial.print(" ");
  
        // Send date
        Serial.print(rtc.getDateStr());
        Serial.print(" -- ");

        // Send time
        Serial.println(rtc.getTimeStr());*/

        // menampilkan tanggal pada serial monitor
      Serial.print(rtc.getDOWStr(FORMAT_LONG));
      Serial.print(";");
      Serial.print(rtc.getDateStr());
      Serial.print(";");

        // menampilkan waktu pada serial monitor
      waktu = rtc.getTime();
      int dataJam = waktu.hour;     
      int dataMenit = waktu.min;
      int dataDetik = waktu.sec;
      Serial.print(dataJam);
      Serial.print(':');
      Serial.print(dataMenit);
      Serial.print(':');
      Serial.print(dataDetik);
      Serial.print(";");
      Serial.print(rtc.getTemp());
      Serial.print(";");
      Serial.print(valuevoltageCharger);
      Serial.print(";");
      Serial.println(valuevoltageBattery);
    }
