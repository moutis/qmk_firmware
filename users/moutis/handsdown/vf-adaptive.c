/*
 Adaptive Keys
 Called from early within process_record_user
 
 Tailored for HD Vibranium-f (vf)
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).
 
 */


bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.
    
    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM) { // outside adaptive threshhold
        prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true; // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    if (!caps_word_timer) { // turn off shift, (first-words & Proper nouns)
        unregister_mods(MOD_MASK_SHIFT);  //CAPS_WORD/LOCK won't be affected.
    } // may want more granular control than this…

//        switch (((keycode >= SAFE_RANGE) && (keycode <= SemKeys_COUNT)) ? (keycode) : (keycode & QK_BASIC_MAX)) { // only handling normal, SHFT or ALT cases.

    switch (keycode) { // process ignoring multi-function keys & shift state?

/*
// Left hand adaptives (most are single-handed neighbor fingers, bc speed, dexterity limits)
*/
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch
                    send_string("ch"); // 85% of tc is tch, so this saves a lot of key press "H"
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
                case KC_D: // eliminate DT SFB
                    tap_code(KC_T);
                    return_state = false; // done.
                    break;
                case KC_P: // avoid row step (PS is 36x more common than PF)
                    tap_code(KC_S);
                    return_state = false; // done.
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
                case KC_V: // Eliminate VL Scissor
                case KC_W: // Eliminate WL scissor
                    tap_code(KC_L); // WJ = wl (WL is 468x more common than WJ)
                    return_state = false; // done.
                    break;
            }
            break;

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
                    tap_code(KC_N); // HK = NK ()
                    break; // Send K normally
            }
            break;
        case KC_L: // catch this so we can unshift L on these involving pinky/ring rolls.
            switch (prior_keycode) {
                case KC_P:
                case KC_B: //
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
        case KC_P:
            switch (prior_keycode) {
                case KC_D: // DP = DT eliminate SFB (DT is 2.5x more common)
                    tap_code(KC_G);
                    return_state = false; // done.
                    break;
                case KC_F: // Pull S down (SP is 860x more common than FP)
                    tap_code(KC_BSPC);
                    tap_code(KC_S); //(but maybe should be BS? SP/BS are about equal...)
                    return_state = true; // not done (process this key normally)
                    break;
            }
            break;
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
        case KC_V: // remedy inner column split by shifting fingering
            switch (prior_keycode) {
                case KC_D: // DV/TV/GV = LV ()
                case KC_T: // TK/DK/GK = LK ()
                case KC_G: //
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break; // and let current keycode send normally
           }
            break;
        case KC_W: // W becomes P (pull up "P" to same row)
            switch (prior_keycode) {
                case KC_G:
                    tap_code(KC_D); // eliminate SFB on index
                    return_state = false; // done.
                    break;
                case KC_M: // pull up P (W becomes P after M to set up "mp"+l)
                case KC_X: // pull up P (W becomes P after X to set up "xp"+l)
                    tap_code(KC_P); // pull up P from bottom row.
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_X:
            switch (prior_keycode) {
                case KC_G: // eliminate GT SFB.
                    tap_code(KC_T); // "GT" is 778x more frequent than "GX"
                    return_state = false; // done.
                    break;
                case KC_M:  // eliminate MF scissor.
                    tap_code(KC_F); // "MB" is 2558x more frequent than "MX"
                    return_state = false; // done.
                    break;
                case KC_W:  // eliminate WS scissor.
                    tap_code(KC_S); //
                    return_state = false; // done.
                    break;
            }
            break;

/*
// right hand adaptives
*/
            
        case KC_B:
            switch (prior_keycode) {
                case KC_Y: // avoid ring->pinky scissor
                    tap_code(KC_BSPC);
                    tap_code(KC_I);
                    break; // process the B normally
            }
            break;
         case KC_QUOT:
              switch (prior_keycode) {
                  case KC_DOT:
                      send_string("org");
                      return_state = false; // done.
                      break;
#ifndef ADAPT_VOWEL_H
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
        case KC_SLSH:
            switch (prior_keycode) {
                case KC_DOT:
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
            switch (prior_keycode) {
                case KC_SLSH: // /. => !
                    tap_code(KC_BSPC);
                    tap_code16(KC_EXLM);
                    return_state = false; // done.
                    break;
            }
            break;

#ifdef ADAPT_VOWEL_H
#if defined(ADAPT_AE_AU) || defined(DE_ADAPTIVES) // AU is really common in German (and influences EN/FR)
        case KC_E:
            switch (prior_keycode) {
                case KC_A: // "AE" yields "AU" (8x more common)
                    tap_code(KC_U);
                    return_state = false; // done.
            }
            break;
#endif // ADAPT_AE_AU
#endif // ADAPT_VOWEL_H
        case KC_H: // H precedes a vowel much more often than it follows (thanks, Ancient Greek!) so adaptive H is a sort of Magic Key
            switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
#ifdef ADAPT_VOWEL_H
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
#endif // ADAPT_VOWEL_H
                case KC_I: // IF = IY (eliminate SFB on ring finger)
                    tap_code(KC_Y); // (inverted IH->IF = IF->IY)
                    return_state = false; // done.
                    break;
/*
                case KC_I: // avoid row skip on outward pinky roll
                    tap_code(KC_Y); // "IH" yields "IF" (96x more common)
                    return_state = false; // done.
                    break;
*/
#ifndef FR_ADAPTIVES
                case KC_Y: // eliminate YI SFB
                    tap_code(KC_I); //
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
                    
                case KC_M: // MH->MN eliminate SFB (15x)
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
                case KC_L: // LH->LL eliminate double tap SFB "ll" (355x)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
#ifdef DE_ADAPTIVES // AU is really common it German (and influences EN/FR)
        case KC_I:
            switch (prior_keycode) {
                case KC_A: // "AI" yields "AU" (8x more common)
                    tap_code(KC_U);
                    return_state = false; // done.
                    break;
            }
            break;
#endif // DE_ADAPTIVES

#ifdef THUMB_REPEATER
        case HD_REPEATER_A: // Make a repeat key of the secondary thumb key on both sides
        case HD_REPEATER_B: // for most common double letters (inherently SFBs)
            switch (prior_keycode) {
                case KC_A ... KC_SLASH: // should any alpha be repeated?
/* double-letter frequencies from Peter Norvig's data <https://norvig.com/mayzner.html>
                case KC_L: // 0.577% // Hands Down Platinum – not exactly recommended
                case KC_S: // 0.405%
                case KC_E: // 0.378%
                case KC_O: // 0.210%
                case KC_T: // 0.171% // Hands Down Gold
                case KC_F: // 0.146%
                case KC_P: // 0.137%
                case KC_R: // 0.121% // Hands Down Titanium/Rhodium/Vibranium
                case KC_M: // 0.096%
                case KC_C: // 0.083%
                case KC_N: // 0.073% // Hands Down Silver
                case KC_D: // 0.043%
                case KC_G: // 0.025%
                case KC_I: // 0.023%
                case KC_B: // 0.011%
                case KC_A: // 0.003%
                case KC_Z: // 0.003%
                case KC_X: // 0.003%
                case KC_U: // 0.001%
                case KC_H: // 0.001%  // Hands Down Bronze
*/
                    tap_code(prior_keycode); // eliminate SFB on double
                    return_state = false; // done.
            }
            break;
#endif
#ifdef ADAPTIVE_TRAILER
#include "adaptive_trailer.c"
#endif // ADAPTIVE_TRAILER

    }
    if (return_state) { // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);
        prior_keycode = preprior_keycode = keycode = 0;
    }
    return return_state; //
}
