# LinuxUSBResetTool
Use Linux IOCTRL to "write" reset command to a stuck USB device.

I wrote this to reset USB dongles that connect to network console ports using USB-Serial converters.
It was coded for Raspberry Pi - reset stuck or non-responsive USB device


On the command line as sudo or root:
usbrst /dev/bus/usb/[BUS ## from LSUSB OUTPUT]/[DEVICE ## from LSUSB OUTPUT]

You can use lsusb and other tools ( dmesg | grep USB, udevadm info -a -n /dev/[DEVICE]| grep serial)
