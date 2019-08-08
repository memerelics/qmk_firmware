make from top dir of the repository.

```
$ pwd
  /Users/thash/.ghq/github.com/thash/qmk_firmware
$ make ergodox_ez:thash
```

Then, 1st option is using `teensy_loader_cli` but as of 2019-07 I don't install it.

```
$ teensy_loader_cli -mmcu=atmega32u4 -w ergodox_ez_thash.hex
  Then press [RESET]. RESET = L2 + ESC
```

If teensy_loader_cli doesn't work, try followings (manual operation):

0. disconnect then reconnect USB to initialize keyboard status
1. launch teensy.app
2. load .hex file (output of make command) to the app
3. execute [RESET] command above.


### troubleshooting

#### (deprecated, maybe) When make execution fails try this:

```
$ brew uninstall avr-libc
$ brew uninstall avr-gcc
$ brew uninstall --force avr-gcc
$ brew install avr-gcc avr-libc
```


#### if build doesn't work because it looks ergodox lib, not ergodox_ez

maybe removing `.build` dir makes it work. ref: https://yhara.jp/2017/09/27/compiling-qmk_firmware-201709
