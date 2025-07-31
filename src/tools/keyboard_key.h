#ifndef KEYBOARD_KEY_H
#define KEYBOARD_KEY_H

#define ESCAPE 27
#define ENTER 13
#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100
#define KEY_F 102
#define KEY_H 104
#define KEY_E 101

inline int globalKeyId;

inline bool isKeyDown(const int keyId) {
    return globalKeyId == keyId;
}

inline bool movementKeys() {
    return isKeyDown(KEY_W) ||
           isKeyDown(KEY_S) ||
           isKeyDown(KEY_A) ||
           isKeyDown(KEY_D);
}

#endif //KEYBOARD_KEY_H
