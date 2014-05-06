trivial-xcb
===========

test xcb program

Build
===========

gcc -Wall mixing_call.c -o mixing_call `pkg-config --cflags --libs xcb x11-xcb xkbcommon-x11`

