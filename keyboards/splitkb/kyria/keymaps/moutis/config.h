
#pragma once

// Hardware specific bits
//
// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS

#ifdef ENCODER_ENABLE
    #define ENCODER_DIRECTION_FLIP
#endif

