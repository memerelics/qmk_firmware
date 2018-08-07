```
$ cd keyboards/ergodox
$ make thash
$ teensy_loader_cli -mmcu=atmega32u4 -w ../../.build/ergodox_ez_thash.hex

  Then press [RESET]. RESET = L2 + ESC
```

If RESET button with teensy_loader_cli doesn't work, try followings:

0. disconnect then reconnect USB to initialize keyboard status
1. launch teensy.app
2. load .hex file (output of make command) to the app
3. execute [RESET] command above.


When make execution fails try this:

```
$ brew uninstall avr-libc
$ brew uninstall avr-gcc
$ brew uninstall --force avr-gcc
$ brew install avr-gcc avr-libc
```

