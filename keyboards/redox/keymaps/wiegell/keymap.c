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

enum custom_keycodes {
  COL = SAFE_RANGE,
  EMPFUNC = SAFE_RANGE,
  LSLAH,HOME,
  DIRUP,
  THIS,
  VOID,
  MAIL,
  SYMB,
  NAV,
  ADJUST,
  NUM,
  WIN
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
   case VOID:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("public void ");
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
   case MAIL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("bj.wiegell"SS_ALGR(SS_TAP(X_NUHS))"gmail.com");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)
#define NUM_L   MO(_NUM)

#define KC_ALAS LALT_T(KC_PAST)


#define KC_NAPD LT(_NAV, KC_PGDN)
#define KC_NAME LT(_NAV, KC_SPACE)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

#define KC_NUMD LT(_NUM, KC_DEL)
#define KC_SYMV LT(_SYMB, KC_F17)
#define MT_CMDD MT(MOD_LGUI, KC_BSPC)
#define MT_CMDDD MT(MOD_LGUI, KC_F19)

#define KC_NAMS LT(_NAV, KC_SPACE)
#define KC_SYMBS LT(_SYMB, KC_BSPC)
#define MT_LSP MT(MOD_LSFT,KC_F18)
#define MT_LACU MT(MOD_LALT,KC_F19)
#define MT_LSENT MT(MOD_LSFT,KC_ENT)
#define DEVTOOLS LGUI(LALT(KC_I))
#define DEVTS LGUI(LSFT(KC_C))
#define KC_CTC LCTL_T(KC_F17) 
#define KC_GTP LGUI_T(KC_F17)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F14    ,                                       KC_F6    ,KC_F7   ,KC_F8   ,LSG(KC_A),LSG(KC_R),KC_F11 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DEVTOOLS  ,DEVTS    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,KC_F14   ,                        TG(_WIN) ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,DK_MINS   ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LGUI(KC_Z) ,KC_Q    ,KC_R    ,KC_S    ,KC_T     ,KC_D    ,KC_LBRC ,                          KC_TAB  ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,DK_AE ,DK_ARNG ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB ,KC_A      ,KC_X    ,KC_C   ,KC_V   ,KC_B    ,KC_NAPD ,KC_ADPU ,        LGUI(KC_Z) ,KC_RGUI ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_O ,DK_OSTR ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_CTC ,KC_Z ,KC_PMNS ,MT_LACU ,         KC_GTP ,  KC_SYMBS ,MT_LSP         ,MT_LSENT ,KC_NAMS     ,KC_NUMD ,  RGUI(KC_S) ,RGUI(KC_T) ,RGUI(KC_W)   ,RGUI(KC_F) 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,DK_AMPR ,_______ ,_______ ,DK_TILD ,KC_TRNS,                            KC_TRNS,DK_HASH ,DK_QUES ,DK_ASTR ,ALGR(KC_I),_______,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,DK_PERC,DK_LPRN,DK_LBRC ,DK_HALF ,DK_DQUO ,KC_TRNS                            ,KC_TRNS,DK_QUOT ,DK_SECT ,DK_RBRC ,DK_RPRN ,_______,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MAIL    ,LSA(DK_8),ALGR(DK_QUOT),DK_SLSH,_______,VOID   ,KC_TRNS ,KC_TRNS          ,KC_TRNS ,KC_TRNS,LSFT(DK_ACUT) ,DK_EXLM ,DK_EQL ,DK_PLUS ,LSA(DK_9) , XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,EMPFUNC ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,   _______   ,   _______  ,_______ ,DK_LABK ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ), 
    [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,HOME ,LGUI(KC_BSPC),LALT(KC_BSPC),LALT(KC_DEL),XXXXXXX ,RESET ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,DIRUP ,KC_LEFT ,KC_DOWN ,KC_UP   ,LGUI(KC_DEL) ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,LSLAH ,LGUI(KC_LEFT),LALT(KC_LEFT),LALT(KC_RIGHT),KC_RIGHT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LALT ,     KC_GTP ,    _______ ,_______ ,        _______ ,_______ ,    XXXXXXX ,   LCTL(KC_C) ,XXXXXXX ,LGUI(KC_RIGHT) ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

    [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,                                 XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,XXXXXXX   ,XXXXXXX  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     KC_0    ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

        [_WIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5                                           , KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DEVTOOLS  ,KC_E  ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,_______   ,                        TG(_WIN) ,KC_J ,KC_L  ,KC_U    ,KC_Y    ,_______   ,TG(_WIN)  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     C(KC_Z) ,KC_Q    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,KC_SLCK                            ,KC_PAUS,KC_H    ,KC_N    ,KC_E    ,KC_I    ,DK_AE    ,DK_ARNG ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_A    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_NAPD   ,_______        ,_______ ,KC_RGUI ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_O  ,DK_OSTR ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTRL ,KC_Z ,KC_PMNS ,C(KC_X) ,   KC_LALT ,        KC_SYMBS ,MT_LSP          ,MT_LSENT ,KC_NAMS     ,KC_NAME ,  G(KC_S),G(KC_T),KC_SLSH,C(KC_F) 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
};
