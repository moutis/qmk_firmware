/*
 Adaptive Keys
 Called from within process_record_user
 
 Tailored for HD Mithril (mi)
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).
 
 All the goto shenanigans should be resolved after complete migration to STM/RP controllersr
 (not totally possible, as many of my boards have embedded AVR mcus)

 */


bool process_adaptive_key(uint16_t *calling_keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.
    uint16_t keycode = *calling_keycode;
    
    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM) { // outside adaptive threshhold
        prior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true; // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    if (!caps_word_timer) { // turn off shift, (first-words & Proper nouns)
        unregister_mods(MOD_MASK_SHIFT);  //CAPS_WORD/LOCK won't be affected.
    } // may want more granular control than this…

    switch (keycode & QK_BASIC_MAX) { // process ignoring multi-function keys

/*
// Left hand adaptives (most are single-handed neighbor fingers, bc speed, dexterity limits)
*/


/*
// right hand adaptives
*/
            
        case KC_QUOT:
            switch (prior_keycode) {
                case KC_DOT:
                    send_string("org");
                    return_state = false; // done.
                    break;
                case KC_SLSH:
                    tap_code(KC_BSPC);
                    send_string(".org");
                    return_state = false; // done.
                    break;
#ifndef ADAPT_H
                case KC_A: //
                    tap_code(KC_U); // "A'" yields "AU"
                    return_state = false; // done.
                    break;
                case KC_U:
                    tap_code(KC_A); // "U'" yields "UA"
                    return_state = false; // done.
                    break;
                case KC_E:
                    tap_code(KC_O); // "E'" yields "EO"
                    return_state = false; // done.
                    break;
                case KC_O:
                    tap_code(KC_E); // "O'" yields "OE"
                    return_state = false; // done.
                    break;
/*#else // regain v-H rolls (kludgy? unnecessary?)
                case KC_A:
                case KC_U:
                case KC_E:
                case KC_O:
                case KC_I:
                    tap_code(KC_H); // "IH" yields "IF" (96x more common)
                    return_state = false; // done.
*/
#endif
            }
            break;
        case KC_SLSH:
            if (preprior_keycode == KC_DOT)
                break;
            if (prior_keycode == KC_DOT) { // ./ but not ../
                send_string("com");
                return_state = false; // done.
            }
            break;
        case KC_DQUO:
            switch (prior_keycode) {
                case KC_DOT:
                    send_string("edu");
                    return_state = false; // done.
                    break;
                case KC_SLSH: // /" => ?
                    tap_code(KC_BSPC);
                    tap_code16(KC_QUES);
                    return_state = false; // done.
            }
            break;
        case KC_COMM:
            switch (prior_keycode) {
                case KC_COMM: // double comma = CAPS_WORD.
                    tap_code(KC_BSPC);
                    toggle_caps_word();
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_DOT:
            if (preprior_keycode == KC_DOT)
                break;
            switch (prior_keycode) {
                case KC_SLSH: // /. => !
                    tap_code(KC_BSPC);
                    tap_code16(KC_EXLM);
                    return_state = false; // done.
                    break;
            }
            break;

#ifdef ADAPT_H
#if defined(ADAPT_AE_AU) || defined(DE_ADAPTIVES) // AU is really common in German (and influences EN/FR)
       case KC_E:
           switch (prior_keycode) {
               case KC_A: // "AE" yields "AU" (8x more common)
                   tap_code(KC_U);
                   return_state = false; // done.
           }
           break;
#endif // ADAPT_AE_AU
#endif // ADAPT_H
       case KC_H: // H precedes a vowel much more often than it follows (thanks, Ancient Greek!) so adaptive H is a sort of Magic Key
           switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
#ifdef ADAPT_H
#if !defined(ADAPT_AE_AU) && !defined(DE_ADAPTIVES) // AU is really common it German (and influences EN/FR)
               case KC_A: // AE is a fraction less common (8x), but the EAE trill may be harder than EAH.
                   tap_code(KC_U); // "AH" yields "AU" (7x more common)
                   return_state = false; // done.
                   break;
#endif // ADAPT_AE_AU or !DE_ADAPTIVES
               case KC_U:
                   tap_code(KC_A); // "UH" yields "UA" (126x more common)
                   return_state = false; // done.
                   break;
               case KC_E: // these EO/OE adaptives are of questionable value
                   tap_code(KC_O); // "EH" yields "EO" (1.75:1)
                   return_state = false; // done.
                   break;
               case KC_O:
                   tap_code(KC_E); // "OH" yields "OE" (almost 1:1, but eliminates an SFB?)
                   return_state = false; // done.
                   break;
#endif // ADAPT_H
               case KC_I: // IF = IY (eliminate SFB on ring finger)
                   tap_code(KC_Y); // (inverted IH->IF = IF->IY)
                   return_state = false; // done.
                   break;
#ifndef FR_ADAPTIVES
               case KC_Y: // eliminate YI SFB
                   tap_code(KC_I); //
                   return_state = false; // done.
                   break;
               case KC_L: // LH->LN
               case KC_M: // MH->MN
               case KC_N: // NH->NN
                   tap_code(KC_N); //
                   return_state = false; // done.
                   break;
#else // FR_ADAPTIVES // eliminate 'h SFB for French
               case KC_J: // ex. j'habite
               case KC_L: // ex. l'hôtel
               case KC_N: // ex. n'habite
               case KC_D: // ex. d'habitude
#ifdef EN_HDIGRAPH_COMBOS
               case KC_T: // t'habitude can't do this (bc Th) unless Th digraph combo is used…
#endif // EN_HDIGRAPH_COMBOS
                   tap_code(KC_QUOT); // YH => Y' (pull down to reduce ring-pinky T-B scissor)
                   break;
#endif // FR_ADAPTIVES

           }
           break;
#ifdef DE_ADAPTIVES // AU is really common in German (and influences EN/FR)
       case KC_I:
           switch (prior_keycode) {
               case KC_A: // "AI" yields "AU" (8x more common)
                   tap_code(KC_U);
                   return_state = false; // done.
                   break;
           }
           break;
#endif // DE_ADAPTIVES

#if defined (HD_MAGIC) || defined (HD_MAGIC_A) || defined (HD_MAGIC_B)
#include "adaptive_magic.c"
#endif //

    }
    if (return_state) { // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);
        prior_keycode = keycode = 0;
    }
    return return_state; //
}
