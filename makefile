# Arduino Library base folder and example structure
HUB_BASE = hub/mainframe
STAIR_BASE = stair/mainframe
SKETCH ?= Main.ino

# Arduino CLI Board type
BOARD_TYPE ?= arduino:avr:uno

# Default port to upload to
SERIAL_PORT ?= COM3

# Optional verbose compile/upload trigger
V ?= 0
VERBOSE=

ifneq ($(V), 0)
	VERBOSE=-v
endif

.PHONY: verify_hub build_hub verify_stair build_stair

verify_hub:
	arduino-cli compile $(VERBOSE) -n -b $(BOARD_TYPE) -t $(HUB_BASE)/$(SKETCH)

build_hub:
	arduino-cli upload $(VERBOSE) -p $(SERIAL_PORT) -b $(BOARD_TYPE) $(HUB_BASE)/$(SKETCH)

verify_stair:
	arduino-cli compile $(VERBOSE) -n -b $(BOARD_TYPE) -t $(STAIR_BASE)/$(SKETCH)

build_stair:
	arduino-cli upload $(VERBOSE) -p $(SERIAL_PORT) -b $(BOARD_TYPE) $(HUB_BASE)/$(SKETCH)