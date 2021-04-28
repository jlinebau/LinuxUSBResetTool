#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>

int main(int argc, char **argv)
{
  //VARs
  const char *fname;
  int fhan;
  int ctlret;

  //Check to see if we got the file path
  if (argc !=2)
  {
    fprintf(stderr, "CMD LINE: usbrst dev_file_name\n");
    return 99;
  }

  //Open the file path to USB device
  fname = argv[1];
  fhan = open(fname, O_WRONLY);

  if (fhan < 0)
  {
    fprintf(stderr,"[!!] File could not be opened -> %d\n", fhan);
    return 100;
  }


  //Try to reset USB device and close file handle
  printf("[**]Attempting to reset USB device...\n");
  ctlret = ioctl(fhan, USBDEVFS_RESET, 0);
  if (ctlret < 0)
  {
    fprintf(stderr,"[!!] Error resetting USB Device -> %d\n", ctlret);
    return 101;
  }

  printf("[**] USB Device Reset Successful..\n");

  close(fhan);

  return 0;


}
