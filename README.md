# DS3231 driver examples

This repository contains examples of using DS3231 driver - [ds3231_driver](https://github.com/HexRx/ds3231_driver).

## Getting Started
1. `git clone --recursive https://github.com/HexRx/ds3231_driver_examples.git`
2. Do the below steps depend on your platform to compile the example. 

##### NRF52832
The example uses OpenOCD + ST-Link for flashing. P0.6 pin as UART TX debug see the variable `NRF_LOG_BACKEND_UART_TX_PIN` in `config/sdk_config.h`.

1. Go to the directory `nrf52832`.
2. Change the `SDK_ROOT` variable to your path of [nRF5 SDK](https://www.nordicsemi.com/Software-and-tools/Software/nRF5-SDK) in the `Makefile`.
3. Change `SDA_GPIO` and `SCL_GPIO` for your I2C pins in `main.c`. By default `SDA_GPIO` = 26 (P0.26) and `SCL_GPIO` = 27 (P0.27).
4. Run `make flash` to compile the code and flash in MCU.

The output to UART should be like:
```
<info> app: App started.                                                        
<info> app: 2000-01-01 01:31:16                                                 
                                                                                
<info> app: 25.50 deg Cel                                                       
<info> app: 2000-01-01 01:31:17                                                 
                                                                                
<info> app: 25.50 deg Cel                                                       
<info> app: 2000-01-01 01:31:18
```

## License
This project is licensed under the MIT License - see the [LICENSE](/master/LICENSE) file for details.