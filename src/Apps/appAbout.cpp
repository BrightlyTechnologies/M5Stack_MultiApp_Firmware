#include "../apps.h"

void appAbout()
{
    MyMenu.drawAppMenu(F("ABOUT"), F(""), F("ESC"), F(""));

    while (M5.BtnB.wasPressed())
    {
        M5.update();
    }
    MyMenu.windowClr();
    M5.Lcd.drawCentreString(F("Botofan Calin"), M5.Lcd.width() / 2, (M5.Lcd.height() / 2) - 10, 2);
    M5.Lcd.drawCentreString(F("www.NsTeam.org"), M5.Lcd.width() / 2, (M5.Lcd.height() / 2) + 10, 2);
    while (!M5.BtnB.wasPressed())
    {
        M5.update();
    }

    MyMenu.show();
}