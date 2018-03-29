#include "../apps.h"

void appIICScanner()
{
    byte error, address;
    int nDevices;
    byte ridx = 0;
    byte lidx = 0;
    boolean scanrun = HIGH;

    MyMenu.drawAppMenu(F("I2C SCANNER"), F("SCAN"), F("ESC"), F(""));

    while (M5.BtnB.wasPressed())
    {
        M5.update();
    }

    while (!M5.BtnB.wasPressed())
    {
        if (scanrun == HIGH)
        {
            scanrun = LOW;
            nDevices = 0;
            for (address = 1; address < 127; address++)
            {
                ridx++;
                if (ridx == 17)
                {
                    ridx = 1;
                    lidx++;
                }
                Wire.beginTransmission(address);
                error = Wire.endTransmission();
                if (error == 0)
                {
                    M5.Lcd.drawString(String(address, HEX), 0 + (ridx * 18), 45 + (lidx * 20), 2);
                    nDevices++;
                }
                else if (error == 4)
                {
                    M5.Lcd.drawString(F("ER"), 0 + (ridx * 18), 45 + (lidx * 20), 2);
                }
                else
                {
                    M5.Lcd.drawString(F("--"), 0 + (ridx * 18), 45 + (lidx * 20), 2);
                }
            }
            M5.update();
        }
        else
        {
            if (M5.BtnA.wasPressed())
            {
                MyMenu.windowClr();
                ridx = 0;
                lidx = 0;
                scanrun = HIGH;
            }
            M5.update();
        }
    }
    MyMenu.show();
}