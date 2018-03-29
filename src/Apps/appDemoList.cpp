#include "../apps.h"


void appListDemo()
{
    MyMenu.drawAppMenu(F("GAMES"),F("ESC"),F("SELECT"),F("LIST"));

    while (M5.BtnB.wasPressed())
    {
        M5.update();
    }

    MyMenu.clearList();
    MyMenu.setListCaption("GAMES");
    MyMenu.addList("TETRIS");
    MyMenu.addList("FLAPPY BIRD");
    MyMenu.addList("METERS");
    MyMenu.addList("CLOCK");
    MyMenu.showList();

    while (!M5.BtnA.wasPressed())
    {
        if (M5.BtnC.wasPressed())
        {
            MyMenu.nextList();
        }
        if (M5.BtnB.wasPressed())
        {
            if (MyMenu.getListString() == "TETRIS")
            {
                tetris_setup();
                M5.update();
                while (!M5.BtnC.pressedFor(2000))
                {
                    tetris_run();
                }
                M5.Lcd.fillScreen(0);
                MyMenu.drawAppMenu(F("GAMES"),F("ESC"),F("SELECT"),F("LIST"));
                MyMenu.showList();
            }
             if (MyMenu.getListString() == "FLAPPY BIRD")
            {
                flappybird_setup();
                M5.update();
                while (!M5.BtnC.wasPressed())
                {
                    flappypird_run();
                }
                M5.Lcd.setRotation(0);
                M5.Lcd.fillScreen(0);
                MyMenu.drawAppMenu(F("GAMES"),F("ESC"),F("SELECT"),F("LIST"));
                MyMenu.showList();
            }
            if (MyMenu.getListString() == "METERS")
            {
                meters_setup();
                M5.update();
                while (!M5.BtnC.wasPressed())
                {
                    meters_run();
                }
                M5.Lcd.setRotation(0);
                M5.Lcd.fillScreen(0);
                MyMenu.drawAppMenu(F("GAMES"),F("ESC"),F("SELECT"),F("LIST"));
                MyMenu.showList();
            }
            if (MyMenu.getListString() == "CLOCK")
            {
                clock_setup();
                M5.update();
                while (!M5.BtnC.wasPressed())
                {
                    clock_run();
                }
                M5.Lcd.setRotation(0);
                M5.Lcd.fillScreen(0);
                MyMenu.drawAppMenu(F("GAMES"),F("ESC"),F("SELECT"),F("LIST"));
                MyMenu.showList();
            }
        }
        M5.update();
    }
    MyMenu.show();
}