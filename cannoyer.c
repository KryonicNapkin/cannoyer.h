#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "cannoyer.h"

unsigned int _delay = 10000;
float _flick_interval = 0.25f;
bool _has_cannoy_mode_started = false;
bool _has_cannoy_mode_ended = false;
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
Color _fg_font_color = RAYWHITE;

void cannoy_init_win(cannoy_win_t* win, int width, int height) {
    InitWindow(width, height, _title);
    cannoy_set_pos(win, CANNOY_MIDDLE_CENTER);
    cannoy_set_name_font_sz(win, _name_font_sz);
    cannoy_set_desc_font_sz(win, _desc_font_sz);
    cannoy_set_name_font(win, _name_font_path, _name_font_sz);
    cannoy_set_desc_font(win, _desc_font_path, _desc_font_sz);
    cannoy_set_name_font_color(win, _fg_font_color);
    cannoy_set_desc_font_color(win, _fg_font_color);
    cannoy_set_delay(win, _delay);
    win->is_running = 0;
    _is_win_init = 1;
    _has_cannoy_mode_started = true;
}

void cannoy_destroy_win(void) {
    CloseWindow();
    _has_cannoy_mode_ended = true;
}

void cannoy_begin_render(void) {
    BeginDrawing();
    _has_rendering_started = true;
}

void cannoy_end_render(void) {
    EndDrawing();
    _has_rendering_ended = true;
}

Color* cannoy_set_cols(int elements_in_array, ...) {
    Color* colors = malloc(sizeof(Color) * (elements_in_array + 1));
    va_list ap;
    va_start(ap, elements_in_array);
    for (int i = 0; i < elements_in_array; ++i) {
        colors[i] = va_arg(ap, Color);
        printf("%d : %d %d %d %d\n", i, colors[i].a, colors[i].r, colors[i].g, 
               colors[i].b);
    }
    va_end(ap);
    colors[elements_in_array] = (Color){
        .a = 0,
        .r = 0,
        .g = 0,
        .b = 0
    };
    return colors;
}

void cannoy_free_cols(Color* array) {
    free(array);
}

long cannoy_get_cols_len(Color* array) {
    long length = 0;
    while ((*array).a != 0) {
        array++;
        ++length;
    }
    return length;
}

int cannoy_get_col_idx(Color* array) {
    static float timer = 0;
    static int update_idx = 0;
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
    win->name_font.font_size = font_height;
}

void cannoy_set_desc_font_sz(cannoy_win_t* win, int font_height) {
    win->name_font.font_size = font_height;
}

void cannoy_set_name_font(cannoy_win_t* win, const char* name_font_path, int height) {
    Font name_font = LoadFontEx(name_font_path, height, NULL, 0);
    win->name_font.font = name_font;
}

void cannoy_set_desc_font(cannoy_win_t* win, const char* desc_font_path, int height) {
    Font desc_font = LoadFontEx(desc_font_path, height, NULL, 0);
    win->desc_font.font = desc_font;
}

void cannoy_set_name_font_color(cannoy_win_t* win, Color color) {
    win->name_font.fg_color = color;
}

void cannoy_set_desc_font_color(cannoy_win_t* win, Color color) {
    win->desc_font.fg_color = color;
}

void cannoy_set_pos(cannoy_win_t* win, cannoy_win_pos_t pos) {
    SetWindowPosition(pos.x, pos.y);
    win->pos = pos;
}

/* void cannoy_set_dimensions(cannoy_win_t* win, cannoy_win_dimensions_t dims) {
    SetWindowSize(dims.width, dims.height);
    win->dims = dims;
} */

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
    return win.name_font.font;
}

Font cannoy_get_desc_font(cannoy_win_t win) {
    return win.desc_font.font;
}

int cannoy_get_name_font_sz(cannoy_win_t win) {
    return win.name_font.font_size;
}

int cannoy_get_desc_font_sz(cannoy_win_t win) {
    return win.desc_font.font_size;
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
    /* if (_is_win_init && ) {
    
    } else if (!_is_win_init) {
        return false;
    }
    return false; */
}

bool cannoy_is_win_running(cannoy_win_t win) {
    return win.is_running;
}

void cannoy_render_win(cannoy_win_t win, Color* col_array, int update_idx) {
    if (!_has_cannoy_mode_started) {
        fprintf(stderr, "You must start the cannoy_mode before rendering window!\n");
        exit(EXIT_FAILURE);
    } 
    if (!_has_rendering_started) {
        fprintf(stderr, "You must start the the cannoy_renderig_mode!\n");
        exit(EXIT_FAILURE);
    }
    Vector2 text_dim_name = MeasureTextEx(win.name_font.font, win.name, (float)win.name_font.font_size, 0);
    Vector2 text_pos_name = {
        .x = ((float)win.dims.width/2)-(text_dim_name.x/2),
        .y = ((float)win.dims.height/4)-(text_dim_name.y/2),
    };
    Vector2 text_dim_desc = MeasureTextEx(win.desc_font.font, win.desc, (float)win.desc_font.font_size, 0);
    Vector2 text_pos_desc = {
        .x = ((float)win.dims.width/2)-(text_dim_desc.x/2),
        .y = ((float)win.dims.height*(3.0f/4.0f))-(text_dim_desc.y/2),
    };
    ClearBackground(RAYWHITE);
    DrawRectangle(win.pos.x, win.pos.y, win.dims.width, win.dims.height, col_array[update_idx]);
    DrawTextEx(win.name_font.font, win.name, text_pos_name, (float)win.name_font.font_size, 0, win.name_font.fg_color);
    DrawTextEx(win.desc_font.font, win.desc, text_pos_desc, (float)win.desc_font.font_size, 0, win.desc_font.fg_color);
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
