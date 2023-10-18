/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"



#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,      KC_PGUP,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,      KC_PGDOWN,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,      KC_LBRC,
        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,      KC_DEL,
        KC_LCTRL,   KC_LGUI,    KC_LALT,    LAYER_1,    KC_BSPC,    KC_SPACE,  KC_ENTER
    )};

void setupKeymap() {

   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}
#endif


#if KEYBOARD_SIDE == LEFT


std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,      KC_PGUP,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,      KC_PGDOWN,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,      KC_LBRC,
        KC_LSHIFT,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,      KC_DEL,
        KC_LCTRL,   KC_LGUI,    KC_LALT,    LAYER_1,    KC_BSPC,    KC_SPACE,  KC_ENTER
    )};

 
void setupKeymap() {


    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        KC_GRAVE,   KC_F1,      KC_F2,    KC_F3,    KC_F4,   KC_F5,     OUT_USB,\
        OUT_AUTO,   KC_EXLM,    KC_AT,    KC_LCBR,  KC_RCBR, KC_PIPE,   OUT_BT,\
        _______,    KC_HASH,    KC_DLR,   KC_LBRC,  KC_RBRC, KC_GRAVE,  _______,\
        KC_LSHIFT,    KC_PERC,    KC_CARET, KC_LPRN,  KC_RPRN, KC_TILD,   _______,\
        _______,    _______,    _______,  _______,  _______, _______,   _______\
);

    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        _______, _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______, _______,\
        _______, _______, _______, _______, _______, _______, _______\
);

    /*
     * add the other layers on the regular presses.
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
        }
    }

    // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

}

#endif  // left



#if KEYBOARD_SIDE == RIGHT



std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_HOME,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,\
        KC_END,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_EQL,\
        KC_RBRC,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCOLON,  KC_QUOT,\
        LAYER_2,    KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_UP,      KC_RSHIFT,\
        KC_ENTER,   KC_SPC,  KC_BSPC, KC_SLASH,KC_LEFT, KC_DOWN,    KC_RIGHT\
    )};

 

void setupKeymap() {


    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        KC_PSCREEN,    KC_F6,           KC_F7,    KC_F8,        KC_F9,          KC_F10,         KC_F11,\
        _______,       KC_KP_SLASH,     KC_KP7,   KC_KP_8,      KC_KP_9,        KC_KP_MINUS,    KC_F12,\
        _______,       KC_KP_ASTERISK,  KC_KP_4,  KC_KP_5,      KC_KP_6,        KC_KP_PLUS,     KC_F13,\
        _______,       _______,         KC_KP_1,  KC_KP_2,      KC_KP_3,        KC_KP_ENTER,    KC_F14,\
        _______,       _______,         KC_KP_0,  KC_DOT,       KC_KP_ENTER,    KC_KP_DOT,      KC_F15\
);


    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( \
        _______,                _______,                _______, _______, _______,              _______,            _______,\
        _______,                _______,                _______, _______, _______,              _______,            _______,\
        _______,                _______,                _______, _______, _______,              _______,            _______,\
        _______,                _______,                _______, _______, _______,              KC_AUDIO_VOL_UP,    KC_MUTE,\
        KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_PLAY_PAUSE,    _______, _______, KC_MEDIA_PREV_TRACK,  KC_AUDIO_VOL_DOWN,  KC_MEDIA_NEXT_TRACK\
);

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
        }
    }

}


#endif




