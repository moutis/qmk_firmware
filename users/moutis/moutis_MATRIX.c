

bool did_leader_succeed;
LEADER_EXTERNS();

void matrix_scan_user(void) {

#ifdef LEADER_ENABLE
    #include "moutis_LEADER.c"
#endif

    if (appmenu_timer) { // timer running if holding KC_APP key, or if entered menu mode
        if (appmenu_on) {
            if (timer_elapsed(appmenu_timer) > TAPPING_TERM * 5) {
                appmenu_on = false;  // no press for a while so turn off menu mode
                appmenu_timer = 0;
                if (user_config.osIsWindows) {
                    unregister_code(KC_LALT);
                } else {
                    unregister_code(KC_LGUI);
                }
            }
        } else {
            if (timer_elapsed(appmenu_timer) > TAPPING_TERM * 2) { // if held, the toggle menu mode
                appmenu_on = true;
            }
//            appmenu_timer = timer_read(); // now use timer for time since last press
        }
    }

#ifdef COMBO_ENABLE
        matrix_scan_user_process_combo();
#endif

}

#ifdef LEADER_ENABLE

void leader_start(void) {
  // Add your code to run when pressing the leader key here
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, 3);
    oled_write_P(PSTR("Leader: "), false);
#endif
    
}
void leader_end(void) {
// Add your code to run when a leader key sequence ends here

#ifdef OLED_DRIVER_ENABLE
    if (!leading) {
        oled_set_cursor(0, 3);
        oled_write_P(PSTR("                   "), false);
//        oled_render();
    }
#endif

}

#endif
