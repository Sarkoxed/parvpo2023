#!/bin/bash

echo "fastcall"
echo

echo "const"
gcc main.c -m32 -o check.out 
./check.out

echo "const O2"
gcc main.c -m32 -o check.out -O2 2>/dev/null
./check.out
echo

sed -e 's/const int l = 1e9/int l = 1e9/' -i main.c
echo "not const"
gcc main.c -m32 -o check.out 
./check.out
echo

echo "not const O2"
gcc main.c -m32 -o check.out -O2 2>/dev/null
./check.out
sed -e 's/int l = 1e9/const int l = 1e9/' -i main.c
echo "------------------------------------------------------------"


sed -e 's/fastcall/stdcall/' -i main.c
echo
echo "stdcall"
echo

echo "const"
gcc main.c -m32 -o check.out 
./check.out
echo

echo "const O2"
gcc main.c -m32 -o check.out -O2 2>/dev/null
./check.out
echo

sed -e 's/const int l = 1e9/int l = 1e9/' -i main.c

echo "not const"
gcc main.c -m32 -o check.out 
./check.out
echo

echo "not const O2"
gcc main.c -m32 -o check.out -O2 2>/dev/null
./check.out
echo "------------------------------------------------------------"

sed -e 's/int l = 1e9/const int l = 1e9/' -i main.c

sed -e 's/stdcall/cdecl/' -i main.c

echo
echo "cdecl"
echo

echo "const"
gcc main.c -m32 -o check.out 
./check.out
echo

echo "const O2"
gcc main.c -m32 -o check.out -O2 2>/dev/null
./check.out
echo

sed -e 's/const int l = 1e9/int l = 1e9/' -i main.c

echo "not const"
gcc main.c -m32 -o check.out 
./check.out
echo

echo "not const O2"
gcc main.c -m32 -o check.out -O2 2>/dev/null
./check.out
echo "------------------------------------------------------------"

sed -e 's/int l = 1e9/const int l = 1e9/' -i main.c
sed -e 's/cdecl/fastcall/' -i main.c
