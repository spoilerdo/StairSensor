# Arduino Library base folder and example structure
HUB_BASE = hub
STAIR_BASE = stair/mainframe
SKETCH ?= MainFrame

# Arduino CLI executable name and directory location
ARDUINO_CLI = arduino-cli
ARDUINO_CLI_DIR = .

# Arduino CLI Board type
BOARD_TYPE ?= arduino:avr:uno

# Default port to upload to
SERIAL_PORT ?= COM18

# Optional verbose compile/upload trigger
V ?= 0
VERBOSE=

# Build path -- used to store built binary and object files
BUILD_DIR=build
HUB_BUILD_PATH=$(PWD)/$(HUB_BASE)/$(SKETCH)/$(BUILD_DIR)
STAIR_BUILD_PATH=$(PWD)/$(HUB_BASE)/$(SKETCH)/$(BUILD_DIR)

ifneq ($(V), 0)
    VERBOSE=-v
endif

.PHONY: all verify_hub build_hub clean

all: verify_hub

verify_hub:
    arduino-cli compile $(VERBOSE) --build-path=$(HUB_BUILD_PATH) --build-cache-path=$(HUB_BUILD_PATH) -b $(BOARD_TYPE) $(HUB_BASE)/$(SKETCH)

build_hub:
    $(ARDUINO_CLI_DIR)/$(ARDUINO_CLI) upload $(VERBOSE) -p $(SERIAL_PORT) --fqbn $(BOARD_TYPE) $(HUB_BASE)/$(SKETCH)

clean:
    @rm -rf $(BUILD_PATH)
    @rm $(HUB_BASE)/$(SKETCH)/*.elf
    @rm $(HUB_BASE)/$(SKETCH)/*.hex
