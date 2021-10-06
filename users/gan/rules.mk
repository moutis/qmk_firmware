# QMK software features

LEADER_ENABLE = no      # Enable the Leader Key feature
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
UNICODE_ENABLE = no
NKRO_ENABLE = yes       # USB Nkey Rollover
COMBO_ENABLE = yes      # chording
KEY_OVERRIDE_ENABLE = no

SRC += moutis.c

CFLAGS += -fcommon
