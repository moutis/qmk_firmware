/*
 Adaptive Keys
 Called from within process_record_user
 
 Tailored for HD Vibranium-v (vv)
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).
 
 */


bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.

    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM
        || ((keycode == KC_SLSH) && (timer_elapsed(prior_keydown) > ADAPTIVE_TERM * 16))) {
        prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
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
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch
                    send_string("ch"); // 85% of tc is tch, so this saves a lot of "H" key presses
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_D: // (for KD=KL; least code, no side effects)
            switch (prior_keycode) { //
                case KC_K:
                case KC_V:
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_L:
                    if (preprior_keycode == KC_P) { // PLD = PWD?
                        tap_code(KC_BSPC);
                        tap_code(KC_W); // replace the L with W
                        break; // process the D normally
                    }
            }
            break;
        case KC_F:
            switch (prior_keycode) {
                case KC_D: //
                    tap_code(KC_G); // eliminate SFB (DG is 10x more common than DF)
                    return_state = false; // done.
                    break;
                case KC_V: //
                    tap_code(KC_BSPC);
                    tap_code(KC_S); // avoid row step (311x more common than VF)
                    break;
            }
            break;
        case KC_G:
            switch (prior_keycode) {
                case KC_K:
                    tap_code(KC_L);  // pull up "L" (KL is 5x more common than KG)
                    return_state = false; // done.
                    break;
               case KC_M:
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break; // and let current keycode send normally
                case KC_J: // JG = jpg
                    tap_code(KC_P); // insert a P
                    break; // and let current keycode send normally
                case KC_W:
                    tap_code(KC_BSPC);
                    send_string("lml"); // for "calmly" though not quite intuitive…
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_J:
            switch (prior_keycode) {
                case KC_G: // "GTH" is an awkward trigram/skipgram
                    send_string("th"); // for "length"
                    return_state = false; // done.
                    break;
                case KC_M: // Eliminate MN SFB
                    tap_code(KC_N); // MJ = MN
                    return_state = false; // done.
                    break;
                case KC_W: // Eliminate WL scissor
                    tap_code(KC_L); // WJ = wl (WL is 468x more common than WJ)
                    return_state = false; // done.
                    break;
            }
            // remedy ring-index split by shifting fingering
            // Since the hand is already displaced to reach the inner column,
            // pull the L over with alternate fingering to avoid the stretch.
        case KC_K:
            switch (prior_keycode) {
                case KC_D: // eliminate index-middle stretch with alt fingering
                case KC_G:
                    tap_code(KC_BSPC); // replace D/G
                    tap_code(KC_L); // D/GK = LK (LK ismore common than D/GK)
                    break; // Send K normally
                case KC_T: // eliminate lateral stretch
                    tap_code(KC_BSPC); // replace T
                    tap_code(KC_C); // HK = CK
                    break; // Send K normally
            }
            break;
        case KC_L: // catch this so we can unshift L on these rolls.
            switch (prior_keycode) {
                case KC_P:
                case KC_S: //
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_G: // pull up "L" (GL is 5x more common than GM)
                case KC_X: // pull up "L" (XL is 1.5x more common than XM)
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_W: // WM = LM (LM 20x more common)
                    if (!preprior_keycode) {
                        tap_code(KC_BSPC);
                        tap_code(KC_L);
                        break;
                    }
                    switch (preprior_keycode) {
                        case KC_M:
                        case KC_X:
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                    };
            }
            break;
            // If not using H-digraph combos, consider this adaptive solution?
#ifndef EN_HDIGRAPH_COMBOS
        case KC_N: // N becomes H (for H-Digraph rolls)
            switch (prior_keycode) {
                case KC_P: // pn = ph (ph 78x more common)
                case KC_G: // gn = gh (gh 2.5x more common)
                case KC_S: // sn = sh (sh 33x more common)
                case KC_W: // wn = wh (wh 3.8x more common)
                case KC_C: // cn = ch (sh 694x more common)
                case KC_T: // tn = th (LM 354x more common)
                    tap_code(KC_H);
                    return_state = false; // done.
            }
            break;
#else
        case KC_N: // N becomes H (for H-Digraph rolls)
            switch (prior_keycode) {
                case KC_T: // "TION" is 58x more common than "TN"
                    send_string("ion");
                    return_state = false; // done.
                    break;
//                case KC_C: // cn = ln (CN 5x more common)
                case KC_X: // xn = ln (LN 101x more common)
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    return_state = true; // let the N happen.
                    break;
            }
            break;
#endif
        case KC_R:  // LL is the highest consonant repeat, and it's off home, so eliminate this SFB
            switch (prior_keycode) {
                case KC_L: // quickly typing "lr" yields "ll" (+56x)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_T:  // alt fingering remedy for middle-index splits
            switch (prior_keycode) {
                case KC_K: // quickly typing "k?" yields "kn" (+48x)
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_W: // W becomes P (pull up "P" to same row)
            switch (prior_keycode) {
                case KC_X: // pull up P (W becomes P after X to set up "xp"+l)
                case KC_M: // pull up P (W becomes P after M to set up "mp"+l)
                    tap_code(KC_P); // pull up P from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G:
                    tap_code(KC_D); // eliminate SFB on index
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_V:
            switch (prior_keycode) {
                case KC_F: // avoid row step (91x more frequent)
                    tap_code(KC_S);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_X:
            switch (prior_keycode) {
                case KC_W: // eliminate scissor (2818x gain)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
                case KC_M: // eliminate scissor (107x gain)
                    tap_code(KC_F); // pull up F from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G: // "GX" is 778x more frequent than "GT"
                    tap_code(KC_T); // eliminate GT SFB.
                    return_state = false; // done.
                    break;
            }
            break;


/*
// right hand adaptives
*/
            
        case KC_P:
            switch (prior_keycode) {
                case KC_Y: //
                    tap_code(KC_I); // YP = YI (eliminate SFB on ring finger YI is 37x YF)
                    return_state = false; // done.
                break;
            }
            break;
        case KC_B:
              switch (prior_keycode) {
                  case KC_DOT:
                      tap_code(KC_BSPC);
                      send_string(".org");
                      return_state = false; // done.
                  break;
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
        case KC_COMM:
            switch (prior_keycode) { // a tap-dance of sorts
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
        case KC_QUOT:
             switch (prior_keycode) {
                 case KC_DOT:
                     send_string("org");
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
#endif
             }
             break;
#ifdef ADAPT_H
#if defined(ADAPT_AE_AU) || defined(DE_ADAPTIVES) // AU is really common in German (and influences EN/FR)
       case KC_E:
           switch (prior_keycode) {
               case KC_A: // "AE" yields "AU" (8x more common) keeping it on home row
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
               case KC_I: // IH = IY (eliminate SFB on ring finger)
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
        prior_keycode = preprior_keycode = keycode = 0;
    }
    return return_state; //
}
