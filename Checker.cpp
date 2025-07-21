#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool isTemperatureOk(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}

bool isSocOk(float soc) {
    return (soc >= 20 && soc <= 80);
}

bool isChargeRateOk(float chargeRate) {
    return (chargeRate <= 0.8);
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    bool status = true;

    if (!isTemperatureOk(temperature)) {
        printf("Temperature out of range!\n");
        status = false;
    }
    if (!isSocOk(soc)) {
        printf("State of Charge out of range!\n");
        status = false;
    }
    if (!isChargeRateOk(chargeRate)) {
        printf("Charge Rate out of range!\n");
        status = false;
    }
    return status;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
    return 0;
}
