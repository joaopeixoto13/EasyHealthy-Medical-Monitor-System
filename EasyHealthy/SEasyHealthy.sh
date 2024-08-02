#!/bin/sh

# Start Wifi
wpa_supplicant -c /etc/wpa_supplicant.conf -i wlan0 -B

# Start Daemons
/root/EasyHealthy/Daemons/daemonDB
/root/EasyHealthy/Daemons/daemonUSB

# Start Backend
/root/EasyHealthy/Backend/EasyHealthy &

# Start Frontend
/root/EasyHealthy/GUI/EasyHealthyGUI &

# Core Affity
taskset -p 0x4 `pidof daemonDB`
taskset -p 0x4 `pidof daemonUSB`
taskset -p 0xE `pidof EasyHealthyGUI`

