#include "cannoyer.h"
#include <stdarg.h>
#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

unsigned int _delay = 10000;
bool _has_cannoy_mode_started = false;
bool _has_cannoy_mode_stopped = false;
bool _has_rendering_started = false;
bool _has_rendering_ended = false;
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

void cannoy_mode_start(int width, int height, const char* title) {
    SetConfigFlags(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_UNFOCUSED);
    InitWindow(width, height, title);
    SetTargetFPS(60);
    _has_cannoy_mode_started = true;
}

void cannoy_mode_end(void) {
    CloseWindow();
    _has_cannoy_mode_ended = true;
}

void cannoy_begin(void) {
    BeginDrawing();
    _has_rendering_started = true;
}

void cannoy_end(void) {
    EndDrawing();
    _has_cannoy_mode_stopped = true;
}

Color* cannoy_set_cols(int n, Color color, ...) {
    Color* colors = malloc(sizeof(Color) * (n + 1));
    va_list ap;
    va_start(ap, color);
    for (int i = 0; i < n; ++i) {
        colors[i] = va_arg(ap, Color);
    }
    colors[n] = (Color){
        .a = 0,
        .r = 0,
        .g = 0,
        .b = 0
    };
    va_end(ap);
    return colors;
}

void cannoy_free_cols(Color* array) {
    free(array);
}

long cannoy_get_cols_len(Color* array) {
    long length = 0;
    while ((*array).a != 0 && (*array).r != 0 && (*array).g != 0 && (*array).b != 0) {
        ++array;
        ++length;
    }
    return length;
}

int cannoy_get_col_idx(Color* array) {
    float timer;
    int update_idx = 0;
    timer += GetFrameTime();
    if (timer >= _flick_interval) {
        update_idx = (update_idx + 1) % cannoy_get_cols_len(array);
        timer = 0.0f;
    }
    return update_idx;
}

void cannoy_set_name(cannoy_win_t* win, const char* name) {
    win->name = c_strdup(name);
}

void cannoy_set_desc(cannoy_win_t* win, const char* desc) {
    win->desc = c_strdup(desc);
}

void cannoy_set_name_font_sz(cannoy_win_t* win, int font_height) {
    win->name_font_sz = font_height;
}

void cannoy_set_desc_font_sz(cannoy_win_t* win, int font_height) {
    win->desc_font_sz = font_height;
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
    _flick_interval = interval;
}

void cannoy_set_delay(cannoy_win_t* win, unsigned int delay) {
    win->delay = delay;
}

char* cannoy_get_name(cannoy_win_t win) {
    return win.name;
}

char* cannoy_get_desc(cannoy_win_t win) {
    return win.desc;
}

Font cannoy_get_name_font(cannoy_win_t win) {
    return win.name_font;
}

Font cannoy_get_desc_font(cannoy_win_t win) {
    return win.desc_font;
}

int cannoy_get_name_font_sz(cannoy_win_t win) {
    return win.name_font_sz;
}

int cannoy_get_desc_font_sz(cannoy_win_t win) {
    return win.desc_font_sz;
}

cannoy_win_pos_t cannoy_get_pos(cannoy_win_t win) {
    return win.pos;
}

cannoy_win_dimensions_t cannoy_get_dimensions(cannoy_win_t win) {
    return win.dims;
}

float cannoy_get_flick_interval(void) {
    return _flick_interval;
}

unsigned int cannoy_get_delay(cannoy_win_t win) {
    return win.delay;
}

bool cannoy_is_win_set(cannoy_win_t win) {
    if (_is_win_init && ) {
    
    } else if (!_is_win_init) {
        return false;
    }
    return false;
}

bool cannoy_is_win_running(cannoy_win_t win) {
    return win.is_running;
}

void cannoy_render_win(cannoy_win_t win, Color* col_array, int update_idx) {
    if (!_has_cannoy_mode_started) {
        fprintf(stderr, "You must start the cannoy_mode before rendering window!\n");
    } 
    if (!_has_rendering_started) {
        fprintf(stderr, "You must start the the cannoy_renderig_mode!\n");
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
