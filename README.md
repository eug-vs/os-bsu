# os-bsu

A repository with Operating Systems labs (BSU/FAMCS). Every lab interacts with `WinAPI`, though the development is going on **Linux** and involves using special utilities.

## Prerequisites
### MingW GCC
This compiler is needed for assembling `WinAPI` applications:
```bash
sudo apt-get install mingw-w64
```
**NOTE**: if linker exits with error (`ld returned 1`), try using `c++` postfix (instead of `gcc`) in a `$WINCC` var in a Makefile.

### Make
Make is a **crucial** tool for build automation:
```bash
sudo apt-get install build-essential
```

### Wine
Wine is used for running compiled programs:
```bash
sudo apt-get install wine64
```
**NOTE**: if some dll's are missing, you might want to add your `/usr/i686-w64-mingw-32/bin/` to Wine `PATH`.

## Compiling
Makefile is already preconfigured to use **mingw-64** compiler, so project is built with the simple command:
```bash
make
```

## Running
Compiled programs are executed with Wine, for example:
```bash
wine bin/main.exe
```

## CircleCI
CircleCI unleashes all power of automation: it is configured to *compile and publish* executables along with any **tag** pushed. They can be found in attachments to the [releases](https://github.com/eug-vs/os-bsu/releases).
