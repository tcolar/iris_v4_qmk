#include QMK_KEYBOARD_H

enum custom_keycodes {
    VI_BYE = SAFE_RANGE, // ESCAPE :
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // MACRO TO TYPE "ESCAPE :" to help with VI painful finger gymnastic"
        case VI_BYE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE) ":");
            }
            break;
    }
    return true;
};

// Layers
enum kb_layers {
  _DVORAK,   // 0
  _SYMBOLS,  // 1
  _FUNCTION, // 2
  _QWERTY,   // 3
};

// Layer keys
const uint16_t PROGMEM L2      = LT(2, KC_NO);   // activate func layers
const uint16_t PROGMEM TOG_3   = TG(3);          // toggle qwerty layer
const uint16_t PROGMEM L1_LEFT = LT(1, KC_LEFT); // Layer1 or left arrow
const uint16_t PROGMEM L1_RGHT = LT(1, KC_RGHT); // Layer1 or Right arrow

// Modifier Taps
const uint16_t PROGMEM CTL_Q   = LCTL_T(KC_Q);    // Control when held, Q otherwise
const uint16_t PROGMEM ALT_J   = LALT_T(KC_J);    // Alt or J
const uint16_t PROGMEM CMD_K   = LGUI_T(KC_K);    // Command or K
const uint16_t PROGMEM CMD_M   = RGUI_T(KC_M);    // Command or M
const uint16_t PROGMEM ALT_W   = RALT_T(KC_W);    // Alt or W
const uint16_t PROGMEM CTL_V   = RCTL_T(KC_V);    // Command or V
const uint16_t PROGMEM SFT_U   = LSFT_T(KC_U);    // Shift or U
const uint16_t PROGMEM SFT_H   = RSFT_T(KC_H);    // Shift or H

// Shortcuts
const uint16_t PROGMEM WIN_LEFT  = LGUI(LALT(KC_LEFT));
const uint16_t PROGMEM WIN_RGHT  = LGUI(LALT(KC_RGHT));
const uint16_t PROGMEM SCR_SHOT  = SGUI(KC_4);          // Screnshot
const uint16_t PROGMEM UNDO      = LGUI(KC_Z);
const uint16_t PROGMEM REDO      = LCTL(LSFT(KC_Z));
const uint16_t PROGMEM CUT       = LGUI(KC_X);
const uint16_t PROGMEM COPY      = LGUI(KC_C);
const uint16_t PROGMEM PASTE     = LGUI(KC_V);
const uint16_t PROGMEM LOGOUT    = LCTL(LGUI(KC_Q)); 
const uint16_t PROGMEM HOME      = LCTL(KC_A);
const uint16_t PROGMEM _END       = LCTL(KC_E);
const uint16_t PROGMEM SFT_BR = LSFT_T(KC_LBRC); // Shift or [
const uint16_t PROGMEM SFT_RBR= LSFT_T(KC_RBRC); // Shift or ]
const uint16_t PROGMEM CTL_ESC= LCTL_T(KC_ESC);  // Ctl or Esc

// Layout for My Ireis V4 keyboard. Thibaut Ciolar.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Dvorak (alpha & punctuation).
    // @ and / are also available on this layer as they are used often.
    // Modifiers (CMD, CTL, ALT) are on strongest fingers, but on lower row to avoid misfires when typing fast (rolling), 
    // q, j ,k, m, w, v are almost never seen consecutively in English, so no modifier misfires.
    // Top row is used for shortcuts.
    //
    // -------------------------------------------------------------                      ------------------------------------------------------------
    // |   Esc  | WinLeft |         | ScrShot |         |  Undo    |                      |  Redo  |   Cut   |   Copy  |  Paste  | WinRight| Toggle1 |
    // |--------|---------|---------|---------|--------------------|                      |--------|---------|---------|---------|---------|---------| 
    // |   Tab  |   ' "   |   , <   |   . >   |    P    |    Y     |                      |   F    |    G    |    C    |    R    |    L    |    ?    | 
    // |--------|---------|---------|---------|--------------------|                      |--------|---------|---------|---------|---------|---------| 
    // |Backspac|    A    |    O    |    E    | Sft / U |    I     |                      |   D    | Sft / H |    T    |    N    |    S    |    -    | 
    // |--------|---------|---------|---------|--------------------|----------------------|--------|---------|---------|---------|---------|---------| 
    // |   @    |    ;    | Ctrl / Q| Alt / J | Cmd / K |    X     |  Toggle3  |  Layer2  |   B    | Cmd / M | Alt / W | Ctl / V |    Z    |    /    | 
    // ---------|---------|---------|---------|--------------------|-----------|----------|--------|---------|---------|---------|---------|---------| 
    //                                        |    Up   |  Enter   | L1 / Left | L1 / Rght|  Space |   Down  |
    //                                        ----------------------------------------------------------------   
    [_DVORAK] = LAYOUT(
        KC_ESC  , WIN_LEFT, KC_NO   , SCR_SHOT, KC_NO   , UNDO                 ,           REDO    , CUT     , COPY    , PASTE   , WIN_RGHT, TG(1),
        KC_TAB  , KC_QUOT , KC_COMM , KC_DOT  , KC_P    , KC_Y                 ,           KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_QUES , 
        KC_BSPC , KC_A    , KC_O    , KC_E    , SFT_U   , KC_I                 ,           KC_D    , SFT_H   , KC_T    , KC_N    , KC_S    , KC_MINS , 
        KC_AT   , KC_SCLN , CTL_Q   , ALT_J   , CMD_K   , KC_X     , TOG_3     , L2      , KC_B    , CMD_M   , ALT_W   , CTL_V   , KC_Z    , KC_PSLS, 
                                                 KC_UP  , KC_ENT   , L1_LEFT   , L1_RGHT , KC_SPC  , KC_DOWN),

    // Numbers and Math symbols on right (Numbers are top to bottom, standard numpads make little sense to me).
    // Nav keys on left, "WASD like".
    // Rest of programming symbols on left as well. Closing parentheses and brackets are on top row because IDE usually closes them for me.
    //
    // -------------------------------------------------------------                      ------------------------------------------------------------
    // | Vi Bye |         |    }    | Page Up |    )    |    ]     |                      | Logout |         |         |         |         | Toggle1 |
    // |--------|---------|---------|---------|--------------------|                      |--------|---------|---------|---------|---------|---------| 
    // |   \    |    `    |    {    |    Up   |    (    |    [     |                      |   0    |    1    |    2    |    3    |    %    |    ^    | 
    // |--------|---------|---------|---------|--------------------|                      |--------|---------|---------|---------|---------|---------| 
    // |   #    |    ~    |   Left  |   Down  |  Right  |    !     |                      |   =    |    4    |    5    |    6    |    +    |    -    | 
    // |--------|---------|---------|---------|--------------------|----------------------|--------|---------|---------|---------|---------|---------| 
    // |   @    |    :    |    $    | Page Dn |    &    |    |     |           |          |   B    |    7     |   8    |    9    |    *    |    /    | 
    // ---------|---------|---------|---------|--------------------|-----------|----------|--------|---------|---------|---------|---------|---------| 
    //                                        |    Up   |  Enter   |  Home     |   End    |   ,    |   Down  |
    //                                        ----------------------------------------------------------------   
    [_SYMBOLS] = LAYOUT(
        VI_BYE  , KC_NO   , KC_RCBR , KC_PGUP , KC_RPRN , KC_RBRC              ,           LOGOUT   , KC_NO    , KC_NO   , KC_NO  , KC_NO   , KC_TRNS , 
        KC_BSLS , KC_GRV  , KC_LCBR , KC_UP   , KC_LPRN , KC_LBRC              ,           KC_P0    , KC_P1    , KC_P2   , KC_P3  , KC_PERC , KC_CIRC , 
        KC_HASH , KC_TILD , KC_LEFT , KC_DOWN , KC_RGHT , KC_EXLM              ,           KC_PEQL  , KC_P4    , KC_P5   , KC_P6  , KC_PLUS , KC_PMNS ,
        KC_AT   , KC_COLN , KC_DLR  , KC_PGDN , KC_AMPR , KC_PIPE  , KC_NO     , KC_NO   , KC_PDOT  , KC_P7    , KC_P8   , KC_P9  , KC_ASTR , KC_PSLS,
                                                KC_TRNS , KC_TRNS  , HOME      , _END    , KC_COMM  , KC_TRNS),

    // Function keys, brightness, volume, and other rarely used keys.
    // Numbers and Math symbols on right (Numbers are top to bottom, standard numpads make little sense to me).
    // Nav keys on left, "WASD like".
    // Rest of programming symbols on left as well. Closing parentheses and brackets are on top row because IDE usually closes them for me.
    //
    // -------------------------------------------------------------                      ------------------------------------------------------------
    // |  F1    |    F2   |    F3   |    F4   |    F5   |    F6    |                      |   F7   |    F8   |    F9   |   F10   |   F11   |   F12   |
    // |--------|---------|---------|---------|--------------------|                      |--------|---------|---------|---------|---------|---------| 
    // |        |         |         | RgbMod+ | Bright+ |   Vol+   |                      |        |         |         |         |  Insert | Delete  | 
    // |--------|---------|---------|---------|--------------------|                      |--------|---------|---------|---------|---------|---------| 
    // |        |         |         | RgbMod- | Bright- |   Vol-   |                      |        |         |         |         |  Eject  |  Pause  | 
    // |--------|---------|---------|---------|--------------------|----------------------|--------|---------|---------|---------|---------|---------| 
    // |        |         |         | RbgTog  |         |   Mute   |           |          |        |         |         |         |  PrtScr |  Scroll | 
    // ---------|---------|---------|---------|--------------------|-----------|----------|--------|---------|---------|---------|---------|---------| 
    //                                        |         |          |  CapsLck  |  CapsLck |        |         |
    //                                        ----------------------------------------------------------------      
    [_FUNCTION] = LAYOUT(
        KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6                ,           KC_F7    , KC_F8    , KC_F9   , KC_F10 , KC_F11  , KC_F12, 
        KC_NO   , KC_NO   , KC_NO   , RGB_MOD , KC_BRIU , KC_VOLU              ,           KC_NO    , KC_NO    , KC_NO   , KC_NO  , KC_INS  , KC_DEL,
        KC_NO   , KC_NO   , KC_NO   , RGB_RMOD, KC_BRID , KC_VOLD              ,           KC_NO    , KC_NO    , KC_NO   , KC_NO  , KC_EJCT , KC_PAUS, 
        KC_NO   , KC_NO   , KC_NO   , RGB_TOG , KC_NO   , KC_MUTE  , RESET     , KC_TRNS , KC_NO    , KC_NO    , KC_NO   , KC_NO  , KC_PSCR , KC_SLCK, 
                                                KC_NO   ,  KC_NO   , KC_CAPS   , KC_CAPS , KC_NO    , KC_NO),

    // Normal-ish QWERTY keyboard, maybe to play a game without key remapping or something ...
    //
    // -------------------------------------------------------------                      ------------------------------------------------------------
    // |  ` ~   |    1    |    2    |    3    |    4    |    5     |                      |   6    |    7    |    8    |   9     |    0    |Backspace|
    // |--------|---------|---------|---------|--------------------|                      |--------|---------|---------|---------|---------|---------| 
    // |   Tab  |     Q   |    W    |    E    |    R     |   T     |                      |   Y    |    U    |    I    |   O     |    P    |   \ |   | 
    // |--------|---------|---------|---------|--------------------|                      |--------|---------|---------|---------|---------|---------| 
    // |Ctrl Esc|     A   |    S    |    D    |    F     |   G     |                      |   H    |    J    |    K    |   L     |  ; :    |   ' "   | 
    // |--------|---------|---------|---------|--------------------|----------------------|--------|---------|---------|---------|---------|---------| 
    // |Shift [ |     Z   |    X    |    C    |    V     |   B     |  Toggle3  |   ` ~    |   N    |    M    |   , <   |   . >   |  / ?    | Shift ] | 
    // ---------|---------|---------|---------|--------------------|-----------|----------|--------|---------|---------|---------|---------|---------| 
    //                                        |   Cmd    |  Enter  |   - _     |   + =    |  Space | Alt     |
    //                                        ----------------------------------------------------------------      
    [_QWERTY] = LAYOUT(
        KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5                 ,           KC_6     , KC_7     , KC_8    , KC_9   , KC_0    , KC_BSPC, 
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T                 ,           KC_Y     , KC_U     , KC_I    , KC_O   , KC_P    , KC_BSLS, 
        CTL_ESC , KC_A    , KC_S    , KC_D    , KC_F    , KC_G                 ,           KC_H     , KC_J     , KC_K    , KC_L   , KC_COLN , KC_QUOT, 
        SFT_BR  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , TOG_3      , KC_GRV  , KC_N     , KC_M     , KC_COMM , KC_DOT , KC_SLSH , SFT_RBR, 
                                                KC_LGUI , KC_ENT  , KC_MINS    , KC_PLUS ,KC_SPC   , KC_LALT)
};
