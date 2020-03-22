# strucitc
Projet de compilation - L3 Informatique UCA

## Install the requirements
```
sudo apt-get update -y
sudo apt-get install -y build-essential
sudo apt-get install -y flex bison
```
## How to install
```
git clone https://github.com/theoricien/strucitc
```
## How to use
```
flex ANSI-C.l
bison -d structfe.y
mv structfe.tab.h y.tab.h
gcc -c lex.yy.c structfe.tab.c
mv structfe.tab.o y.tab.o
gcc -o program lex.yy.c y.tab.o -ll
```
