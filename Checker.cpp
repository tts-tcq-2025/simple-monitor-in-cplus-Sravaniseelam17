#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool isTemperatureOk(float temperature) {
    bool ok = (temperature >= 0 && temperature <= 45);
    if (!ok) {
        printf("Temperature out of range!\n");
    }
    return ok;
}

bool isSocOk(float soc) {
    bool ok = (soc >= 20 && soc <= 80);
    if (!ok) {
        printf("State of Charge out of range!\n");
    }
    return ok;
}

bool isChargeRateOk(float chargeRate) {
    bool ok = (chargeRate <= 0.8);
    if (!ok) {
        printf("Charge Rate out of range!\n");
    }
    return ok;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    // Only 1 return, no branches in this function
    return isTemperatureOk(temperature) &
           isSocOk(soc) &
           isChargeRateOk(chargeRate);
}

int main() {
    assert(batteryIsOk(25, 70, 0.7) == true);
    assert(batteryIsOk(50, 85, 0) == false);
    return 0;
}
