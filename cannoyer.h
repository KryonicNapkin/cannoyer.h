#ifndef CANNOYER_H_
#define CANNOYER_H_

#ifndef RAYLIB_H
#include "raylib.h"
#endif /* RAYLIB_H */

typedef struct {
    Font font;
    int font_size;
    Color fg_color;
} complex_font_t;

typedef struct {
    int x;
    int y;
} cannoy_win_pos_t;

typedef struct {
    int width;
    int height;
} cannoy_win_dimensions_t;

typedef struct {
    cannoy_win_dimensions_t dims;
    cannoy_win_pos_t pos;
    const char* name;
    const char* desc;
    complex_font_t name_font;
    complex_font_t desc_font;
    bool is_running;
    unsigned int delay;
} cannoy_win_t;

#define cannoy_screen_height() (GetScreenHeight())
#define cannoy_screen_width()  (GetScreenWidth())

extern unsigned int _delay;
extern float _flick_interval;
extern bool _has_cannoy_mode_started;
extern bool _has_cannoy_mode_ended;
extern bool _has_rendering_started;
extern bool _has_rendering_ended;
extern int _is_win_init;
extern int _win_width;
extern int _win_height;
extern int _name_font_sz;
extern int _desc_font_sz;
extern const char* _title;
extern const char* _name_font_path;
extern const char* _desc_font_path;
extern Color _fg_font_color;

#define CANNOY_TOP_LEFT        (cannoy_win_pos_t){0, 0}
#define CANNOY_TOP_CENTER      (cannoy_win_pos_t){(int)(cannoy_screen_width()-_win_width)/2, 0}
#define CANNOY_TOP_RIGHT       (cannoy_win_pos_t){(int)cannoy_screen_width()-_win_width, 0}
#define CANNOY_MIDDLE_LEFT     (cannoy_win_pos_t){0, (int)(cannoy_screen_height()-_win_height)/2}
#define CANNOY_MIDDLE_CENTER   (cannoy_win_pos_t){(int)(cannoy_screen_width()-_win_width)/2, (int)(cannoy_screen_height()-_win_height)/2}
#define CANNOY_MIDDLE_RIGHT    (cannoy_win_pos_t){(int)cannoy_screen_width()-_win_width, (int)(cannoy_screen_height()-_win_height)/2}
#define CANNOY_BOTTOM_LEFT     (cannoy_win_pos_t){0, (int)cannoy_screen_height()-_win_height}
#define CANNOY_BOTTOM_CENTER   (cannoy_win_pos_t){(int)(cannoy_screen_width()-_win_width)/2, (int)cannoy_screen_height()-_win_height}
#define CANNOY_BOTTOM_RIGHT    (cannoy_win_pos_t){(int)cannoy_screen_width()-_win_width, (int)cannoy_screen_height()-_win_height}

void cannoy_init_win(cannoy_win_t* win, int width, int height);
void cannoy_destroy_win(void);
void cannoy_begin_render(void);
void cannoy_end_render(void);
Color* cannoy_set_cols(int elements_in_array, ...);
void cannoy_free_cols(Color* array);
long cannoy_get_cols_len(Color* array);
int cannoy_get_col_idx(Color* array);
void cannoy_set_name(cannoy_win_t* win, const char* name);
void cannoy_set_desc(cannoy_win_t* win, const char* desc);
void cannoy_set_name_font_sz(cannoy_win_t* win, int font_height);
void cannoy_set_desc_font_sz(cannoy_win_t* win, int font_height);
void cannoy_set_name_font(cannoy_win_t* win, const char* name_font_path, int height);
void cannoy_set_desc_font(cannoy_win_t* win, const char* desc_font_path, int height);
void cannoy_set_name_font_color(cannoy_win_t* win, Color color);
void cannoy_set_desc_font_color(cannoy_win_t* win, Color color);
void cannoy_set_pos(cannoy_win_t* win, cannoy_win_pos_t pos);
/* void cannoy_set_dimensions(cannoy_win_t* win, cannoy_win_dimensions_t dims); */
void cannoy_set_flick_interval(float interval);
void cannoy_set_delay(cannoy_win_t* win, unsigned int delay);
char* cannoy_get_name(cannoy_win_t win);
char* cannoy_get_desc(cannoy_win_t win);
Font cannoy_get_name_font(cannoy_win_t win);
Font cannoy_get_desc_font(cannoy_win_t win);
int cannoy_get_name_font_sz(cannoy_win_t win);
int cannoy_get_desc_font_sz(cannoy_win_t win);
cannoy_win_pos_t cannoy_get_pos(cannoy_win_t win);
cannoy_win_dimensions_t cannoy_get_dimensions(cannoy_win_t win);
float cannoy_get_flick_interval(void);
unsigned int cannoy_get_delay(cannoy_win_t win);
bool cannoy_is_win_set(cannoy_win_t win);
bool cannoy_is_win_running(cannoy_win_t win);
void cannoy_render_win(cannoy_win_t win, Color* col_array, int update_idx);

char* c_strdup(const char* str);

#endif /* CANNOYER_H_ */
