#include "../apps.h"

void appWifiConnect()
{
    MyMenu.drawAppMenu(F("WIFI CONNECTION"), F(""), F("OK"), F(""));

    while (M5.BtnB.wasPressed())
    {
        M5.Lcd.setCursor(0, 40);
        //M5.Lcd.setTextColor(WHITE);
        M5.Lcd.setTextFont(2);
        WiFi.disconnect();
        delay(100);
        WiFi.mode(WIFI_STA);
        WiFi.begin("Master", "NissanTiida16");
        M5.Lcd.print("Connecting to Master");
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            M5.Lcd.print(".");
        }
        M5.Lcd.println();
        M5.Lcd.println("Connected!");
        M5.Lcd.print("IP: ");
        M5.Lcd.println(WiFi.localIP());
        M5.update();
    }

    while (!M5.BtnB.wasPressed())
    {
        M5.update();
    }

    MyMenu.show();
}