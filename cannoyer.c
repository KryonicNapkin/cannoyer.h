#include "cannoyer.h"
#include <stdarg.h>
#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unsigned int _delay = 10000;
bool _has_cannoy_mode_started = false;
bool _has_cannoy_mode_stopped = false;
int _is_win_init = 0;
int _name_font_sz = 80;
int _desc_font_sz = 60;
int _win_width = 800;
int _win_height = 600;
const char* _title = "Cannoyer";
const char* _name_font_path = "IosevkaNerdFont-Bold.ttf";
const char* _desc_font_path = "IosevkaNerdFont-Bold.ttf";

void init_annoy_win(cannoy_win_t* win) {
    cannoy_set_pos(win, CANNOY_MIDDLE_CENTER);
    cannoy_set_dimensions(win, (cannoy_win_dimensions_t){_win_width, _win_height});
    cannoy_set_name_font(win, _name_font_path, _name_font_sz);
    cannoy_set_name_font_sz(win, _name_font_sz);
    cannoy_set_desc_font_sz(win, _desc_font_sz);
    cannoy_set_desc_font(win, _desc_font_path, _desc_font_sz);
    cannoy_set_delay(win, _delay);
    win->is_running = 0;
    _is_win_init = 1;
}

void cannoy_begin(void) {
    BeginDrawing();
    _has_cannoy_mode_started = true;

}

void cannoy_end(void) {
    EndDrawing();
    _has_cannoy_mode_stopped = false;

}

Color* cannoy_set_cols(int n, Color color, ...) {
    Color* colors = malloc(sizeof(Color) * n);
    va_list ap;
    va_start(ap, color);
    for (int i = 0; i < n; ++i) {
        colors[i] = va_arg(ap, Color);
    }
    va_end(ap);
    return colors;
}

void cannoy_free_cols(Color* array) {

}

int cannoy_get_col_idx(void) {

}

void cannoy_set_name(cannoy_win_t* win, const char* name) {

}

void cannoy_set_desc(cannoy_win_t* win, const char* desc) {

}

void cannoy_set_name_font_sz(cannoy_win_t* win, int font_height) {

}

void cannoy_set_desc_font_sz(cannoy_win_t* win, int font_height) {

}

void cannoy_set_name_font(cannoy_win_t* win, const char* name_font_path, int height) {
    Font name_font = LoadFontEx(name_font_path, height, NULL, 0);
    win->name_font = name_font;

}

void cannoy_set_desc_font(cannoy_win_t* win, const char* desc_font_path, int height) {
    Font desc_font = LoadFontEx(desc_font_path, height, NULL, 0);
    win->desc_font = desc_font;
}

void cannoy_set_pos(cannoy_win_t* win, cannoy_win_pos_t pos) {
    win->pos = pos;

}

void cannoy_set_dimensions(cannoy_win_t* win, cannoy_win_dimensions_t dims) {
    win->dims = dims;
}

void cannoy_set_flick_interval(float interval) {

}

void cannoy_set_delay(cannoy_win_t* win, unsigned int delay) {

}

char* cannoy_get_name(cannoy_win_t win) {

}

char* cannoy_get_desc(cannoy_win_t win) {

}

Font cannoy_get_name_font(cannoy_win_t win) {

}

Font cannoy_get_desc_font(cannoy_win_t win) {

}

int cannoy_get_name_font_sz(cannoy_win_t win) {

}

int cannoy_get_desc_font_sz(cannoy_win_t win) {

}

cannoy_win_pos_t cannoy_get_pos(cannoy_win_t win) {

}

char* cannoy_get_title(cannoy_win_t win) {

}

cannoy_win_dimensions_t cannoy_get_dimensions(cannoy_win_t win) {

}

float cannoy_get_flick_interval(void) {

}

unsigned int cannoy_get_delay(cannoy_win_t win) {

}

bool cannoy_is_win_set(cannoy_win_t win) {
    if (win.dims.width != _win_width && win.dims.height != n) {
    
    }
}

bool cannoy_is_win_running(cannoy_win_t win) {
    return win.is_running;

}

void cannoy_render_win(cannoy_win_t win, Color* col_array, int update_idx) {
    if (!_has_cannoy_mode_started) {
        fprintf(stderr, "You must start the cannoy_mode before rendering window!\n");
    }
    SetWindowPosition(win.pos.x, win.pos.y);
    Vector2 text_dim_name = MeasureTextEx(win.name_font, win.name, win.name_font_sz, 0);
    Vector2 text_pos_name = {
        .x = ((float)win.dims.width/2)-(text_dim_name.x/2),
        .y = ((float)win.dims.height/4)-(text_dim_name.y/2),
    };
    Vector2 text_dim_desc = MeasureTextEx(win.desc_font, win.desc, win.desc_font_sz, 0);
    Vector2 text_pos_desc = {
        .x = ((float)win.dims.width/2)-(text_dim_desc.x/2),
        .y = ((float)win.dims.height*(3.0f/4.0f))-(text_dim_desc.y/2),
    };
    ClearBackground(RAYWHITE);
    DrawRectangleV((Vector2){win.pos.x, win.pos.y}, (Vector2){win.dims.width, win.dims.height}, col_array[update_idx]);
    DrawTextEx(win.name_font, win.name, text_pos_name, win.name_font_sz, 0, RAYWHITE);
    DrawTextEx(win.desc_font, win.desc, text_pos_desc, win.desc_font_sz, 0, RAYWHITE);
}

char* c_strdup(const char* str) {
    size_t len = strlen(str) + 1;
    char* nstr = malloc(len);
    if (str) {
        memcpy(nstr, str, len);
        return nstr;
    }
    free(nstr);
    return str;
}
