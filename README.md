# Sensirion Raspberry Pi UART SFC6XXX Driver

The repository provides a driver for setting up a SFC6XXX sensor to run on a Raspberry Pi over UART using the SHDLC protocol. 

<center><img src="images/product-image-sfc6xxx.png" width="300px"></center>

Click [here](https://sensirion.com/sfc6000) to learn more about the Sensirion SFC6XXX sensor family.

## Supported sensor types

- [SFC6000](https://sensirion.com/products/catalog/SFC6000/)
- [SFC6000D-5SLM](https://sensirion.com/products/catalog/SFC6000D-5slm/)
- [SFC6000D-50SLM](https://sensirion.com/products/catalog/SFC6000D-50slm/)
- [SFC6000D-20SLM](https://sensirion.com/products/catalog/SFC6000D-20slm/)

The following instructions and examples use a *SFC6000*.


## Connect the sensor

1. Connect the sensor to a 24V power supply.
2. Connect the sensor to your Raspberry Pi by using the provided USB cable.

Please note that due to the delays introduced by the FTDI driver you can 
reach a maximum sampling frequency of about 20Hz with this setup.

For special setups check out the sensor pinout in the section below.

<details><summary>RS485 interface pinout</summary>
<p>
<img src="images/product-pinout-sfc6xxx.png" width="300px">
</p>
</details>

## Quick start example

- [Install the Raspberry Pi OS on to your Raspberry Pi](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up)
- Download the SFC6XXX driver from [Github](https://github.com/Sensirion/raspberry-pi-uart-sfc6xxx) and extract the `.zip`
  on your Raspberry Pi
- Connect the SFC6XXX sensor as explained in the [section above](#connect-the-sensor)
- Check that the correct serial port is set in the define in `sensirion_uart_portdescriptor.h`
   - For connection over USB (in case you have other devices connected check the USB number)

     `#define SERIAL_0 "/dev/ttyUSB0"`

   - For connection over UART Pins 

     `#define SERIAL_0 "/dev/serial0"`

- Compile the driver
    1. Open a [terminal](https://projects.raspberrypi.org/en/projects/raspberry-pi-using/8)
    2. Navigate to the driver directory. E.g. `cd ~/raspberry-pi-uart-sfc6xxx`
    3. Navigate to the subdirectory example-usage.
    4. Run the `make` command to compile the driver

       Output:
       ```
       rm -f sfc6xxx_uart_example_usage
       cc -Os -Wall -fstrict-aliasing -Wstrict-aliasing=1 -Wsign-conversion -fPIC -I. -o sfc6xxx_uart_example_usage sfc6xxx_uart.h sfc6xxx_uart.c sensirion_uart_hal.h sensirion_shdlc.h sensirion_shdlc.c \ 
           sensirion_uart_hal.c sensirion_config.h sensirion_common.h sensirion_common.c sfc6xxx_uart_example_usage.c
       ```
- Test your connected sensor
    - Run `./sfc6xxx_uart_example_usage` in the same directory you used to compile the driver. You should see the
      measurement values in the console.

## Troubleshooting

### Building driver failed

If the execution of `make` in the compilation step 3 fails with something like

```bash
 make: command not found
```

your RaspberryPi likely does not have the build tools installed. Proceed as follows:

```
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential
```



## Contributing

**Contributions are welcome!**

We develop and test this driver using our company internal tools (version
control, continuous integration, code review etc.) and automatically
synchronize the master branch with GitHub. But this doesn't mean that we don't
respond to issues or don't accept pull requests on GitHub. In fact, you're very
welcome to open issues or create pull requests :)

This Sensirion library uses
[`clang-format`](https://releases.llvm.org/download.html) to standardize the
formatting of all our `.c` and `.h` files. Make sure your contributions are
formatted accordingly:

The `-i` flag will apply the format changes to the files listed.

```bash
clang-format -i *.c *.h
```

Note that differences from this formatting will result in a failed build until
they are fixed.


## License

See [LICENSE](LICENSE).