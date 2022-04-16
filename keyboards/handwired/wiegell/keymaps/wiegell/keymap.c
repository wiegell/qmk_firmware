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
#define _NAV_WIN 6
#define _SYMB_WIN 7
#define _NUM_WIN 8

bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

enum custom_keycodes {
  COL = SAFE_RANGE,
EMPFUNC,
  ALT_TAB,
SALT_TAB,
  THIS,
  LSLAH,HOME,
  DIRUP,
  MAIL,
  MAIL_WIN,
  SYMB,
  SYMB_WIN,
  NAV,
  ADJUST,
  NUM,
  NUM_WIN,
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
   case LSLAH:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("ls "SS_TAP(X_SLSH)"lah"SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
   case DIRUP:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("cd .."SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
   case HOME:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("cd ");
          register_code(KC_ALGR);
          SEND_STRING(SS_TAP(X_RBRC));
          unregister_code(KC_ALGR);
            SEND_STRING(SS_TAP(X_ENT));
            SEND_STRING(SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
   case MAIL_WIN:

        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("bj.wiegell"SS_ALGR(SS_TAP(X_2))"gmail.com");
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

#define KC_NAPD LT(_NAV, KC_PGDN)
#define KC_NAME LT(_NAV, KC_SPACE)
#define KC_NAW LT(_NAV_WIN, KC_SPACE)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define KC_NUMD LT(_NUM, KC_DEL)
#define KC_NUWD LT(_NUM_WIN, KC_DEL)
#define KC_SYMV LT(_SYMB, KC_F17)
#define MT_CMDD MT(MOD_LGUI, KC_BSPC)
#define MT_CMDDD MT(MOD_LGUI, KC_F19)
#define KC_NAMS LT(_NAV, KC_SPACE)
#define KC_SYMBS LT(_SYMB, KC_BSPC)
#define KC_SYW LT(_SYMB_WIN, KC_BSPC)
#define MT_LSP MT(MOD_LSFT,KC_F18)
#define MT_LST MT(MOD_LSFT,KC_TAB)
#define MT_LSENT MT(MOD_LSFT,KC_ENT)
#define MT_RSOS MT(MOD_RSFT,DK_OSTR)
#define DEVTOOLS G(LALT(KC_I))
#define DEVTS G(LSFT(KC_C))
#define KC_CTC LCTL_T(KC_F17) 
#define KC_GTP LGUI_T(KC_F17)
#define MT_LACU MT(MOD_LALT,KC_F19)


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
     * | LCTRL  | G   | FN     | LALT   |      SPACE      |      SPACE      | RALT   | RGUI   | RCTRL  | LEFT   | DOWN   | RIGHT  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */

      [_COL] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC ,KC_F1    ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_SLCK                              ,KC_PAUS   ,KC_F8  ,KC_F9   ,KC_F10  ,LSG(KC_A),LSG(KC_R),KC_F11 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    DEVTOOLS  ,DEVTS    ,KC_W    ,KC_F    ,KC_P    ,KC_G  ,KC_F5                            ,KC_F6 ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,ALT_TAB   ,TG(_WIN)  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     G(KC_Z) ,KC_Q    ,KC_R    ,KC_S    ,KC_T     ,KC_D                                               ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,DK_AE ,DK_ARNG ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      MT_LST ,KC_A      ,KC_X    ,KC_C   ,KC_V   ,KC_B    ,DK_ARNG                             ,KC_F16  ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_O ,MT_RSOS ,
  //├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┤       ├────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
    KC_CTC   ,KC_Z    ,KC_PMNS ,MT_LACU ,      KC_GTP ,     KC_SYMBS ,MT_LSP         ,MT_LSENT ,KC_NAMS     ,KC_NUMD ,  G(KC_S),G(KC_T),KC_SLSH,G(KC_F) 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
    [_SYMB] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC__VOLDOWN                          ,KC__VOLUP, _______,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,DK_AMPR ,DK_MINS ,DK_PLUS ,DK_TILD  ,KC_TRNS                            ,KC_TRNS,DK_HASH ,DK_QUES ,DK_ASTR ,ALGR(KC_I),XXXXXXX, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DK_PERC,DK_LBRC,DK_LPRN,DK_HALF  ,DK_DQUO                                              ,DK_QUOT ,DK_SECT ,DK_RPRN ,DK_RBRC ,DK_MINS, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MAIL  ,LSA(DK_8),ALGR(DK_QUOT),DK_SLSH,DK_EQL ,THIS     ,KC_TRNS                           ,KC_TRNS ,LSFT(DK_ACUT) ,DK_EXLM ,DK_BSLS ,DK_SCLN,LSA(DK_9), XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,EMPFUNC ,_______ ,_______ ,     _______ ,    _______ ,_______         ,_______ ,_______ ,   _______   ,   _______  ,_______ ,DK_LABK ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
      [_SYMB_WIN] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC__VOLDOWN                          ,KC__VOLUP, _______,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,DK_AMPR ,DK_MINS ,DK_PLUS ,DK_TILD  ,KC_TRNS                            ,KC_TRNS,DK_HASH ,DK_QUES ,DK_ASTR ,DK_PIPE,XXXXXXX, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DK_PERC,DK_LBRC,DK_LPRN,DK_HALF  ,DK_DQUO                                              ,DK_QUOT ,DK_SECT ,DK_RPRN ,DK_RBRC ,DK_MINS, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MAIL_WIN,DK_LCBR,DK_AT,DK_SLSH,DK_EQL ,THIS     ,KC_TRNS                           ,KC_TRNS ,LSFT(DK_ACUT) ,DK_EXLM ,DK_BSLS ,DK_SCLN,DK_RCBR, XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,EMPFUNC ,_______ ,_______ ,     _______ ,    _______ ,_______         ,_______ ,_______ ,   _______   ,   _______  ,_______ ,KC_UNDS ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
    [_NAV_WIN] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                         , _______  , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_D ,XXXXXXX ,_______                         , _______ ,XXXXXXX,S(KC_HOME),C(KC_BSPC),C(KC_DEL),XXXXXXX ,RESET ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_U ,XXXXXXX                                            ,XXXXXXX  ,KC_LEFT  ,KC_DOWN  ,KC_UP    ,S(KC_END) ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______                          ,XXXXXXX ,XXXXXXX ,KC_HOME,C(KC_LEFT),C(KC_RIGHT),KC_RIGHT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LALT ,     MT_CMDDD ,    KC_BTN1 ,KC_BTN2         ,_______ ,_______ ,    XXXXXXX ,   C(KC_C) ,XXXXXXX ,KC_END ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
      [_NAV] = LAYOUT_wiegell(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                         , _______  , _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_D ,XXXXXXX ,_______                         , _______ ,HOME ,G(KC_BSPC),LALT(KC_BSPC),LALT(KC_DEL),XXXXXXX ,RESET ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_U ,XXXXXXX                                            ,LSLAH ,KC_LEFT ,KC_DOWN ,KC_UP   ,G(KC_DEL) ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______                          ,XXXXXXX ,DIRUP ,G(KC_LEFT),LALT(KC_LEFT),LALT(KC_RIGHT),KC_RIGHT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LALT ,     MT_CMDDD ,    KC_BTN1 ,KC_BTN2         ,_______ ,_______ ,    XXXXXXX ,   C(KC_C) ,XXXXXXX ,G(KC_RIGHT) ,XXXXXXX 
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
      [_NUM_WIN] = LAYOUT_wiegell(
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
     DEVTOOLS  ,DEVTS  ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,TG(_WIN)   ,                        LSFT(KC_TAB) ,KC_J ,KC_L  ,KC_U    ,KC_Y    ,_______   ,TG(_WIN)  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     C(KC_Z) ,KC_Q    ,KC_R    ,KC_S    ,KC_T    ,KC_D                                                ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,DK_AE    ,DK_ARNG ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MT_LST ,KC_A    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_NAPD                          ,KC_RGUI ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_O  ,MT_RSOS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTRL ,KC_Z ,KC_PMNS ,C(KC_X) ,   KC_LCTRL ,    KC_SYW ,MT_LSP          ,MT_LSENT ,KC_NAW     ,KC_NUWD ,  G(KC_S),G(KC_T),KC_SLSH,C(KC_F) 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

};

