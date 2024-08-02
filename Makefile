# Define Colors
PRINT_GENERATING=”Generating $(shell basename $@) ... ”
PRINT_BUILDING =”Building $(shell basename $@) ... ”

# SQLITE
SQLITE_DIR=./Backend/Database/src
SQLITE_NAME=sqlite3

# Project Name
PROJ_NAME=EasyHealthy

# Database Daemon Name
DB_DAEMON_NAME=daemonDB

# USB Daemon Name
USB_DAEMON_NAME=daemonUSB

# GUI Executable location
GUI_LOCATION=/home/diogo/Projects/EasyHealthy/Frontend/GUI/build-EasyHealthyGUI-RPI4-Release/EasyHealthyGUI

# Deploy Backend Directory
DEPLOY_BACKEND_DIR=./EasyHealthy/EasyHealthy/Backend

# Deploy Daemons Directory
DEPLOY_DAEMONS_DIR=./EasyHealthy/EasyHealthy/Daemons

# Deploy GUI Directory
DEPLOY_GUI_DIR=./EasyHealthy/EasyHealthy/GUI

# Define the Libraries
LIBS=-lrt -ludev

# Define the Compiler and Linker
CCC=/home/diogo/buildroot/buildroot-2022.02.7/output/host/bin/arm-buildroot-linux-gnueabihf-g++
CC=/home/diogo/buildroot/buildroot-2022.02.7/output/host/bin/arm-buildroot-linux-gnueabihf-gcc

# Define the Flags
CFLAGS=-Wall -g

# Define the Objects Directory
BLD_DIR=build

# Define the Output Directory
OUT_DIR=bin

# Define exclude directories
EXCLUDE_MODULES= Firmware/Buzzer/module 
EXCLUDE_FRONTEND= Frontend

# Define the Source Files
PROJECT_SRC = $(shell find -name $(PROJ_NAME).cpp)
DB_DAEMON_SRC = $(shell find -name $(DB_DAEMON_NAME).cpp)
USB_DAEMON_SRC = $(shell find -name $(USB_DAEMON_NAME).cpp)
SRC_NAMES=$(shell find . \( -path ./$(EXCLUDE_MODULES) -prune -o -path ./$(EXCLUDE_FRONTEND) -prune \) -o -print | grep -E ".*\.cpp$$" | grep -v "$(PROJ_NAME).cpp" | grep -v "$(DB_DAEMON_NAME).cpp" | grep -v "$(USB_DAEMON_NAME).cpp" | sed 's/.*\///' | sed 's/\.cpp$$//')

# Define Include Directories
INC=$(shell find . \( -path ./$(EXCLUDE_MODULES) -prune -o -path ./$(EXCLUDE_FRONTEND) -prune \) -o -print | grep -E ".*\.h$$" | sed 's/[^/]*$$//' | uniq | sed 's/^/-I/')

# Define the Object Files
OBJ=$(SRC_NAMES:%=$(BLD_DIR)/%.o)
OBJ+=$(BLD_DIR)/$(SQLITE_NAME).o

.DEFAULT_GOAL := all 

all: setup $(PROJ_NAME) $(DB_DAEMON_NAME) $(USB_DAEMON_NAME) deploy

# Create the Directories
setup:
	@ mkdir -p $(BLD_DIR)
	@ mkdir -p $(OUT_DIR)
	@ mkdir -p $(DEPLOY_BACKEND_DIR)
	@ mkdir -p $(DEPLOY_DAEMONS_DIR)
	@ mkdir -p $(DEPLOY_GUI_DIR)
		
# Compile Objects
$(BLD_DIR)/%.o:
	@echo $(PRINT_BUILDING)
	@$(CCC) $(CFLAGS) $(INC) -c $(shell find -name $(shell basename $@ | sed 's/\.o$$/.cpp/')) -o $@
	
# Compile SQLite	
$(BLD_DIR)/$(SQLITE_NAME).o: $(SQLITE_DIR)/$(SQLITE_NAME).c
	@echo $(PRINT_BUILDING)
	@$(CC) $(CFLAGS) -c $< -o $@

# Link the Project
$(PROJ_NAME): $(OBJ) 
	@echo $(PRINT_GENERATING) 
	@$(CCC) $(CFLAGS) $(INC) $(OBJ) $(PROJECT_SRC) -o $(OUT_DIR)/$(PROJ_NAME) $(LIBS)

# Link the Database Daemon
$(DB_DAEMON_NAME): $(OBJ) 
	@echo $(PRINT_GENERATING)
	@$(CCC) $(CFLAGS) $(INC) $(OBJ) $(DB_DAEMON_SRC) -o $(OUT_DIR)/$(DB_DAEMON_NAME) $(LIBS)

# Link the USB Daemon
$(USB_DAEMON_NAME): $(OBJ)
	@echo $(PRINT_GENERATING)
	@$(CCC) $(CFLAGS) $(INC) $(OBJ) $(USB_DAEMON_SRC) -o $(OUT_DIR)/$(USB_DAEMON_NAME) $(LIBS)

deploy:
	@ cp $(GUI_LOCATION) $(DEPLOY_GUI_DIR)
	@ echo "Deployed to $(DEPLOY_GUI_DIR)"
	@ cp $(OUT_DIR)/$(PROJ_NAME) $(DEPLOY_BACKEND_DIR)
	@ echo "Deployed to $(DEPLOY_BACKEND_DIR)"
	@ cp $(OUT_DIR)/$(DB_DAEMON_NAME) $(DEPLOY_DAEMONS_DIR)
	@ echo "Deployed to $(DEPLOY_DAEMONS_DIR)"
	@ cp $(OUT_DIR)/$(USB_DAEMON_NAME) $(DEPLOY_DAEMONS_DIR)
	@ echo "Deployed to $(DEPLOY_DAEMONS_DIR)"

.PHONY: clean

# Clean the Directories
clean:
	@ echo "Cleaning ..."
	@ rm -rf $(BLD_DIR)
	@ rm -rf $(OUT_DIR)

# Build Buzzer Module
modules:
	@ echo "Building Buzzer Module ..."
	@ cd Firmware/Buzzer/module && make