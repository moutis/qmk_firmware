# hardware features (set in keyboard rules.mk)
# BOOTMAGIC_ENABLE = lite     # Enables nvmemory & reset?
# ENCODER_ENABLE = yes        # Enables the use of one or more encoders

# BACKLIGHT_ENABLE = no
# RGB_ENABLE = no            # Enable per key RGB
# OLED_ENABLE = no           # Enables the use of OLED displays
# OLED_DRIVER = SSD1306

# QMK software features
LTO_ENABLE = yes
EXTRAFLAGS += -flto

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = no     # Mouse keys
UNICODE_ENABLE = no      # will need this for HD Polyglot
NKRO_ENABLE = no         # USB Nkey Rollover
KEY_OVERRIDE_ENABLE = no
CONSOLE_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = no
SWAP_HANDS_ENABLE = no
EXTRAKEY_ENABLE = yes    # Audio control and System control
COMBO_ENABLE = yes       # chording

SRC += keiji.c

CFLAGS += -fcommon
