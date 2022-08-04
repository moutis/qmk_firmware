# QMK software features

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = no     # Mouse keys
UNICODE_ENABLE = no      # will need this for HD Polyglot
NKRO_ENABLE = no         # USB Nkey Rollover
KEY_OVERRIDE_ENABLE = no
CONSOLE_ENABLE = no
BACKLIGHT_ENABLE = no
RGB_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
EXTRAKEY_ENABLE = yes    # Audio control and System control
COMBO_ENABLE = yes       # chording
LTO_ENABLE = yes
EXTRAFLAGS += -flto

SRC += moutis.c

CFLAGS += -fcommon


