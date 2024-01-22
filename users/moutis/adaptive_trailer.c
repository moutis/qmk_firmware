//
//  adaptive_trailer.c
//  
//
//  Created by Alan on 1/22/24.
//
//
// embedded in the switch in adaptive.c
//

// Using Adaptives for macros (like a flexible LeaderKey)
case ADAPTIVE_TRAILER:
tap_code(KC_BSPC); // may have been lowercase
return_state = false; // done.
switch (prior_keycode) {
#ifdef adaptAHASH
    case KC_A: //
        send_string(adaptAHASH);  //
        break;
#endif
#ifdef adaptBHASH
    case KC_B: //
        send_string(adaptBHASH);  //
        break;
#endif
#ifdef adaptCHASH
    case KC_C: //
        send_string(adaptCHASH);  //
        break;
#endif
#ifdef adaptDHASH
    case KC_D: //
        send_string(adaptDHASH);  //
        break;
#endif
#ifdef adaptEHASH
    case KC_E: //
        send_string(adaptEHASH);  //
        break;
#endif
#ifdef adaptFHASH
    case KC_F: //
        send_string(adaptFHASH);  //
        break;
#endif
#ifdef adaptGHASH
    case KC_G: //
        send_string(adaptGHASH);  //
        break;
#endif
#ifdef adaptHHASH
    case KC_H: //
        send_string(adaptHHASH);  //
        break;
#endif
#ifdef adaptIHASH
    case KC_I: //
        send_string(adaptIHASH);  //
        break;
#endif
#ifdef adaptJHASH
    case KC_J: //
        send_string(adaptJHASH);  //
        break;
#endif
#ifdef adaptKHASH
    case KC_K: //
        send_string(adaptKHASH);  //
        break;
#endif
#ifdef adaptLHASH
    case KC_L: //
        send_string(adaptLHASH);  //
        break;
#endif
#ifdef adaptMHASH
    case KC_M: //
        send_string(adaptMHASH);  //
        break;
#endif
#ifdef adaptNHASH
    case KC_N: //
        send_string(adaptNHASH);  //
        break;
#endif
#ifdef adaptOHASH
    case KC_O: //
        send_string(adaptOHASH);  //
        break;
#endif
#ifdef adaptPHASH
    case KC_P: //
        send_string(adaptPHASH);  //
        break;
#endif
#ifdef adaptRHASH
    case KC_R: //
        send_string(adaptRHASH);  //
        break;
#endif
#ifdef adaptSHASH
    case KC_S: //
        send_string(adaptSHASH);  //
        break;
#endif
#ifdef adaptTHASH
    case KC_T: //
        send_string(adaptTHASH);  //
        break;
#endif
#ifdef adaptUHASH
    case KC_U: //
        send_string(adaptUHASH);  //
        break;
#endif
#ifdef adaptVHASH
    case KC_V: //
        send_string(adaptVHASH);  //
        break;
#endif
#ifdef adaptWHASH
    case KC_W: //
        send_string(adaptWHASH);  //
        break;
#endif
#ifdef adaptXHASH
    case KC_X: //
        send_string(adaptYHASH);  //
        break;
#endif
#ifdef adaptYHASH
    case KC_Y: //
        send_string(adaptYHASH);  //
        break;
#endif
#ifdef adaptZHASH
    case KC_Z: //
        send_string(adaptYHASH);  //
        break;
#endif
    default: //
        return_state = true; // didn't end up doing anything.
}
break;
