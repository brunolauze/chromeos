#!/bin/sh

CHROME_SRC=`pwd`

patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__bfd__Makefile.in
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__bfd__elfxx-mips.c
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__gold__Makefile.in
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__gold__archive.h
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__gold__configure
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__gold__gold.h
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__gold__incremental.h
patch < ../nacl-patches/patch-native_client__toolchain_build__src__llvm__tools__gold__gold-plugin.cpp
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__gold__Makefile.in
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__gold__testsuite__Makefile.am
patch < ../nacl-patches/patch-native_client__toolchain_build__src__binutils__gold__testsuite__Makefile.in
rm native_client/toolchain_build/src/binutils/gprof/*.m
