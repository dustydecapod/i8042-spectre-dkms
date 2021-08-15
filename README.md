Derived from the original [i8042 driver](https://github.com/torvalds/linux/blob/master/drivers/input/serio/i8042.c) in the Linux Kernel, using a [patch](https://patchwork.kernel.org/project/linux-input/patch/20210201160336.16008-1-anton@cpp.in/) written and provided by Anton Zhilyaev.

**Install**

   ```bash
  git clone https://github.com/berzoidberg/i8042-spectre-dkms
   sudo cp -R i8042-spectre-dkms /usr/src/i8042-spectre-1.0
   sudo dkms add -m i8042-spectre -v 1.0
   sudo dkms build -m i8042-spectre -v 1.0
   sudo dkms install -m i8042-spectre -v 1.0
   echo blacklist i8042 | sudo tee -a /etc/modprobe.d/blacklist.conf
```


