```
$ cd keyboards/ergodox
$ make thash
$ teensy_loader_cli -mmcu=atmega32u4 -w ../../.build/ergodox_ez_thash.hex
... (RESET)
```

RESET = L2 + ESC

When make execution fails try this:

```
$ brew uninstall avr-libc
$ brew uninstall avr-gcc
$ brew uninstall --force avr-gcc
$ brew install avr-gcc avr-libc
```

