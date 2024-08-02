#!/bin/sh
PKG_CONFIG_SYSROOT_DIR=/home/diogo/buildroot/buildroot-2022.02.7/output/host/arm-buildroot-linux-gnueabihf/sysroot
export PKG_CONFIG_SYSROOT_DIR
PKG_CONFIG_LIBDIR=/home/diogo/buildroot/buildroot-2022.02.7/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/lib/pkgconfig:/home/diogo/buildroot/buildroot-2022.02.7/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/share/pkgconfig:/home/diogo/buildroot/buildroot-2022.02.7/output/host/arm-buildroot-linux-gnueabihf/sysroot/usr/lib/arm-buildroot-linux-gnueabihf/pkgconfig
export PKG_CONFIG_LIBDIR
exec pkg-config "$@"
