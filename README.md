# os-bsu

A repository with Operating Systems labs (BSU/FAMCS).

# Getting started on Ubuntu
## Install utilities
### Make
```bash
sudo apt-get install make
```

### Wine
```bash
sudo apt-get install wine
```

### MingW GCC
```bash
sudo apt-get install mingw-w64
```

## Compiling
Makefile is already preconfigured to use **mingw-64** compile, so you can build the project with 
```bash
make all
```

## Running
To run a compiled files, use **Wine**, for example
```bash
wine build/main.exe
```

