#include <stdio.h>

#include "app_util_platform.h"
#include "app_error.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "nrf_delay.h"

#include "ds3231.h"

#define SDA_GPIO 26
#define SCL_GPIO 27

int main()
{
    APP_ERROR_CHECK(NRF_LOG_INIT(NULL));
    NRF_LOG_DEFAULT_BACKENDS_INIT();

    NRF_LOG_INFO("App started.");
    NRF_LOG_FLUSH();

    i2c_dev_t dev = {0};
    ds3231_init(&dev, 0, SDA_GPIO, SCL_GPIO);

    struct tm timeinfo;
    float temp;
    while (true) {
        if (ds3231_get_time(&dev, &timeinfo) == true) {
            NRF_LOG_INFO("%04d-%02d-%02d %02d:%02d:%02d\n", timeinfo.tm_year, timeinfo.tm_mon + 1,
                    timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
            NRF_LOG_FLUSH();
        }
        if (ds3231_get_temp_float(&dev, &temp) == true) {
            NRF_LOG_INFO(NRF_LOG_FLOAT_MARKER " deg Cel", NRF_LOG_FLOAT(temp));
        }
        nrf_delay_ms(1000);
    }
}
