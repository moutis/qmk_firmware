#　ferris hardware

# MCU name
#MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina
#BOOTLOADER = atmel-dfu

#SPLIT_KEYBOARD = yes        # Use shared split_common code
#DEFAULT_FOLDER = ferris/sweep
#SRC += keymap.c

#CFLAGS += -fcommon
#LAYOUTS = split_3x5_2
#
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
#CUSTOM_MATRIX = lite
AUDIO_ENABLE = no           # Audio output
BLUETOOTH_ENABLE = no       # Enable Bluetooth
UNICODE_ENABLE = no        # Unicode
AUDIO_ENABLE = no           # Audio output
NO_USB_STARTUP_CHECK = yes
LTO_ENABLE = yes

ENCODER_ENABLE = no        # Enables the use of one or more encoders

