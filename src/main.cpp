#include "apps.h"

int sleeptime = 0;
int waiting = 60000;
unsigned long lastcheck = millis(); // timer check
bool wifishow = true;

void setup()
{
    M5.begin();
    Serial.begin(115200);
    Wire.begin();

    while (!SD.begin(TFCARD_CS_PIN))
    {
        unsigned long now = millis();
        M5.Lcd.setCursor(10, 100);
        M5.Lcd.setTextColor(WHITE);
        M5.Lcd.print("Insert SD");
        // go to sleep after a minute
        if (lastcheck + 60000 < now)
        {
            M5.setWakeupButton(BUTTON_B_PIN);
            M5.powerOFF();
        }
    }
    hasSD = true;

    if (!EEPROM.begin(EEPROM_SIZE))
    {
        M5.powerOFF();
    }
    else
    {
        M5.lcd.setBrightness(byte(EEPROM.read(0)));
    }

    // CHANGING COLOR SCHEMA:
    //  MyMenu.setColorSchema(MENU_COLOR, WINDOW_COLOR, TEXT_COLOR);
    //  COLORS are uint16_t (RGB565 format)
    // .MyMenu.getrgb(byte R, byte G, byte B); - CALCULATING RGB565 format

    //HERCULES MONITOR COLOR SCHEMA
   // MyMenu.setColorSchema(MyMenu.getrgb(51, 102, 255), MyMenu.getrgb(153, 0, 153), MyMenu.getrgb(0, 255, 0));

    // ADD MENU ITEM
    // MyMenu.addMenuItem(SUBMENU_ID,MENU_TITTLE,BTN_A_TITTLE,BTN_B_TITTLE,BTN_C_TITTLE,SELECTOR,FUNCTION_NAME);
    //    SUBMENU_ID byte [0-7]: TOP MENU = 0, SUBMENUs = [1-7]
    //    SELECTOR
    //           IF SELECTOR = -1 then MyMenu.execute() run function with name in last parameter (FUNCTION_NAME)
    //           IF SELECTOR = [0-7] then MyMenu.execute() switch menu items to SUBMENU_ID
    //    FUNCTION_NAME: name of function to run....

    MyMenu.addMenuItem(0, "APPLICATIONS", "<", "OK", ">", 1, appReturn);
    MyMenu.addMenuItem(0, "SYSTEM", "<", "OK", ">", 2, appReturn);
    MyMenu.addMenuItem(0, "SETTINGS", "<", "OK", ">", 3, appReturn);
    MyMenu.addMenuItem(0, "ABOUT", "<", "OK", ">", -1, appAbout);

    MyMenu.addMenuItem(1, "WiFi SCANNER", "<", "OK", ">", -1, appWiFiScanner);
    MyMenu.addMenuItem(1, "I2C SCANNER", "<", "OK", ">", -1, appIICScanner);
    MyMenu.addMenuItem(1, "STOPWATCH", "<", "OK", ">", -1, appStopWatch);
    MyMenu.addMenuItem(1, "OSCILOSCOPE", "<", "OK", ">", -1, appOsciloscope);
    MyMenu.addMenuItem(1, "GAMES", "<", "OK", ">", -1, appListDemo);
    MyMenu.addMenuItem(1, "RETURN", "<", "OK", ">", 0, appReturn);

    MyMenu.addMenuItem(2, "SYSTEM INFORMATIONS", "<", "OK", ">", -1, appSysInfo);
    MyMenu.addMenuItem(2, "SLEEP/CHARGING", "<", "OK", ">", -1, appSleep);
    MyMenu.addMenuItem(2, "RETURN", "<", "OK", ">", 0, appReturn);

    MyMenu.addMenuItem(3, "DISPLAY BACKLIGHT", "<", "OK", ">", -1, appCfgBrigthness);
     MyMenu.addMenuItem(3, "WIFI CONNECTION", "<", "OK", ">", -1, appWifiConnect);
    MyMenu.addMenuItem(3, "RETURN", "<", "OK", ">", 0, appReturn);

    MyMenu.show();
    M5.Speaker.mute();
    sleeptime = millis() + waiting;
}

void loop()
{
    M5.update();
    if (M5.BtnC.wasPressed())
    {
        sleeptime = millis() + waiting;
        MyMenu.up();
    }
    if (M5.BtnA.wasPressed())
    {
        sleeptime = millis() + waiting;
        MyMenu.down();
    }
    if (M5.BtnB.wasPressed())
    {
        sleeptime = millis() + waiting;
        MyMenu.execute();
    }
    if (sleeptime <= millis())
    {
        M5.setWakeupButton(BUTTON_B_PIN);
        M5.powerOFF();
    }
}
