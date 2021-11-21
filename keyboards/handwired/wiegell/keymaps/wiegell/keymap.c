/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_danish.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COL 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3
#define _NUM 4
#define _WIN 5

bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

enum custom_keycodes {
  COL = SAFE_RANGE,
EMPFUNC,
  ALT_TAB,
SALT_TAB,
  THIS,
  MAIL,
  SYMB,
  NAV,
  ADJUST,
  NUM,
  WIN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EMPFUNC:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LSFT(SS_TAP(X_8))"inp"SS_DOWN(X_LSFT)SS_TAP(X_9)" "SS_TAP(X_0)SS_TAP(X_GRV)" "SS_LALT(SS_TAP(X_8))SS_LALT(SS_TAP(X_9))SS_UP(X_LSFT)SS_TAP(X_LEFT)SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
   case THIS:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("this.");
        } else {
            // when keycode QMKBEST is released
        }
        break;
   case MAIL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("bj.wiegell"SS_ALGR(SS_TAP(X_NUHS))"gmail.com");
        } else {
            // when keycode QMKBEST is released
        }
        break;
   case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_RGUI);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      } 
      break;

   case SALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_RGUI);
        }
        alt_tab_timer = timer_read();
        
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else {
        unregister_code(KC_LSFT);
        unregister_code(KC_TAB);
      }
      break;
    }
    return true;
};

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 500) {
      unregister_code(KC_RGUI);
      is_alt_tab_active = false;
    }
  }
}

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)
#define NUM_L   MO(_NUM)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAPD LT(_NAV, KC_PGDN)
#define KC_NAME LT(_NAV, KC_SPACE)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define KC_NUMC LT(_NUM, KC_F18)
#define KC_SYMV LT(_SYMB, KC_F17)
#define MT_CMDD MT(MOD_LGUI, KC_BSPC)
#define MT_CMDDD MT(MOD_LGUI, KC_F19)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | "      | ENTER  | PG UP  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | SHIFT  | UP     | PG DN  |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | FN     | LALT   |      SPACE      |      SPACE      | RALT   | RGUI   | RCTRL  | LEFT   | DOWN   | RIGHT  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */

      [_COL] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC ,KC_F1    ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_SLCK                              ,KC_PAUS   ,KC_F8  ,KC_F9   ,KC_F10  ,LSG(KC_A),LSG(KC_R),LSG(KC_S) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,TG(_WIN)                       ,SALT_TAB ,KC_J   ,KC_L    ,KC_U    ,KC_Y    ,DK_AE   ,DK_ARNG  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D                                                ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O ,DK_OSTR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,RESET                             ,ALT_TAB  ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┤       ├────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
     KC_CTPL ,KC_PPLS ,KC_PMNS ,KC_ALAS ,MT_CMDD ,KC_SYMV ,KC_NUMC                           , LGUI(KC_Z),KC_ENT ,KC_NAME ,LGUI(KC_S),LGUI(KC_T),LGUI(KC_W),LGUI(KC_F) 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
    [_SYMB] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC__VOLDOWN                          ,KC__VOLUP, _______,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DK_PERC ,DK_AMPR ,DK_MINS ,DK_PLUS ,DK_TILD  ,KC_TRNS                            ,KC_TRNS,DK_HASH ,DK_QUES ,DK_ASTR ,ALGR(KC_I),DK_MINS, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,LSA(DK_8),DK_LBRC,DK_LPRN,DK_HALF  ,DK_DQUO                                              ,DK_QUOT ,DK_SECT ,DK_RPRN ,DK_RBRC ,LSA(DK_9), XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MAIL  ,EMPFUNC,ALGR(DK_QUOT),DK_SLSH,DK_EQL ,THIS     ,KC_TRNS                           ,KC_TRNS ,LSFT(DK_ACUT) ,DK_EXLM ,DK_BSLS ,DK_SCLN,DK_LABK, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______         ,_______ ,_______ ,   _______   ,   _______  ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
    [_NAV] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                         , _______  , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_D ,XXXXXXX ,_______                         , _______ ,XXXXXXX ,XXXXXXX ,RCTL(KC_C) ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_U ,XXXXXXX                                             ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______                          ,XXXXXXX ,XXXXXXX ,LALT(KC_BSPC),LALT(KC_LEFT),LALT(KC_RIGHT),LALT(KC_DEL),XXXXXXX,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LALT ,     MT_CMDDD ,    KC_BTN1 ,KC_BTN2         ,_______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_NUM] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,XXXXXXX,XXXXXXX                , XXXXXXX , XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,XXXXXXX  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                           ,XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                                             ,XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______                          ,_______ ,XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX         ,XXXXXXX ,XXXXXXX ,    XXXXXXX ,     KC_0    ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
      [_WIN] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5,KC_SLCK                              ,KC_PAUS, KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,TG(_WIN)   ,                          LSFT(KC_TAB) ,KC_J ,KC_L  ,KC_U    ,KC_Y    ,DK_AE   ,DK_ARNG  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSPC ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D                                                ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O ,DK_OSTR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_NAPD                          ,KC_RGUI ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTRL ,KC_PPLS ,KC_PMNS ,KC_LGUI ,     KC_LALT ,    SYM_L   ,NUM_L ,        KC_ENT  ,KC_ENT  ,    KC_NAME ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

};
