#include "ESPmDNS.h"
#include "WiFiUdp.h"
#include "M5Stack.h"
#include "Wire.h"
#include "EEPROM.h"
#include "M5StackSAM.h"
#include "WebServer.h"

#define EEPROM_SIZE 64

static bool hasSD = false;

/*
void appTEMPLATE()
{
    MyMenu.drawAppMenu(F("APP_TITTLE"), F("BTN_A_TITTLE"), F("BTN_B_TITTLE"), F("BTN_C_TITTLE"));

    while (M5.BtnB.wasPressed())
    {
        M5.update();
    }

    while (!M5.BtnB.wasPressed())
    {
        M5.update();
    }

    MyMenu.show();
}
*/

void appSysInfo();
void appAbout();
void appListDemo();
void appSysInfo();
void appIICScanner();
void appWiFiScanner();
void appSleep();
void appCfgBrigthness();
void appStopWatch();
void appReturn();
void otaProcess();
void appWifiConnect();

void appOsciloscope();

void tetris_setup();
void tetris_run();

void flappybird_setup();
void flappypird_run();

void meters_setup();
void meters_run();

void clock_setup();
void clock_run();