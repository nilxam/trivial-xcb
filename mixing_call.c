/* http://xcb.freedesktop.org/MixingCalls/ */

#include <X11/Xlib-xcb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <xkbcommon/xkbcommon-x11.h>

int main()
{
    Display *dpy = XOpenDisplay(NULL);
    xcb_connection_t *c; 
    const xcb_setup_t *setup;
    xcb_screen_t *screen;
    xcb_window_t window;
    int32_t keyboard_device_id;

    const int depth = 0, x = 0, y = 0, width = 150, height = 150,
          border_width = 1;

    if (!dpy)
    {   
        fprintf(stderr, "Could not open display.\n");
        exit(EXIT_FAILURE);
    }   

    /* Now that we have an open Display object, cast it to an
     * XCBConnection object so it can be used with native XCB
     * functions.
     */
    c = XGetXCBConnection(dpy);

    if (!c)
    {   
        fprintf(stderr, "Could not cast the Display object to an "
                "XCBConnection object.\n");
        exit(EXIT_FAILURE);
    }   

    keyboard_device_id = xkb_x11_get_core_keyboard_device_id(c);
    printf("keyboard_device_id is %d\n", device_id);

    /* Do something meaningful, fun, and interesting with the new
     * XCBConnection object.
     */
    setup  = xcb_get_setup (c);
    screen = (xcb_setup_roots_iterator (setup)).data;
    window = xcb_generate_id (c);

    xcb_create_window (c, depth, window, screen->root, x, y, width, height,
            border_width, InputOutput, screen->root_visual, 0, NULL);
    xcb_map_window (c, window);
    xcb_flush (c);

    pause();

    xcb_disconnect (c);

    return EXIT_SUCCESS;
}
