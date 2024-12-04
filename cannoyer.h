#ifndef CANNOYER_H_
#define CANNOYER_H_

#ifndef RAYLIB_H
#include "raylib.h"
#endif /* RAYLIB_H */

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
    Font name_font;
    int name_font_sz;
    Font desc_font;
    int desc_font_sz;
    bool is_running;
    unsigned int delay;
} cannoy_win_t;

#define cannoy_mode_end()      (CloseWindow())
#define cannoy_screen_height() (GetScreenHeight())
#define cannoy_screen_width()  (GetScreenWidth())

extern unsigned int _delay;
extern bool _has_cannoy_mode_started;
extern bool _has_cannoy_mode_stopped;
extern int _is_win_init;
extern int _win_width;
extern int _win_height;
extern int _name_font_sz;
extern int _desc_font_sz;
extern const char* _title;
extern const char* _name_font_path;
extern const char* _desc_font_path;

#define cannoy_mode_start()    (InitWindow((_win_width), (_win_height), ("Cannoyer")))

#define CANNOY_TOP_LEFT        (cannoy_win_pos_t){0.0f, 0.0f}
#define CANNOY_TOP_CENTER      (cannoy_win_pos_t){(float)(cannoy_screen_width()-_win_width)/2, 0.0f}
#define CANNOY_TOP_RIGHT       (cannoy_win_pos_t){(float)cannoy_screen_width()-_win_width, 0.0f}
#define CANNOY_MIDDLE_LEFT     (cannoy_win_pos_t){0.0f, (float)(cannoy_screen_height()-_win_height)/2}
#define CANNOY_MIDDLE_CENTER   (cannoy_win_pos_t){(float)(cannoy_screen_width()-_win_width)/2, (float)(cannoy_screen_height()-_win_height)/2}
#define CANNOY_MIDDLE_RIGHT    (cannoy_win_pos_t){(float)cannoy_screen_width()-_win_width, (float)(cannoy_screen_height()-_win_height)/2}
#define CANNOY_BOTTOM_LEFT     (cannoy_win_pos_t){0.0f, (float)cannoy_screen_height()-_win_height}
#define CANNOY_BOTTOM_CENTER   (cannoy_win_pos_t){(float)(cannoy_screen_width()-_win_width)/2, (float)cannoy_screen_height()-_win_height}
#define CANNOY_BOTTOM_RIGHT    (cannoy_win_pos_t){(float)cannoy_screen_width()-_win_width, (float)cannoy_screen_height()-_win_height}

void init_annoy_win(cannoy_win_t* win);
void cannoy_begin(void);
void cannoy_end(void);
Color* cannoy_set_cols(int n, Color color, ...);
void cannoy_free_cols(Color* array);
int cannoy_get_col_idx(void);
void cannoy_set_name(cannoy_win_t* win, const char* name);
void cannoy_set_desc(cannoy_win_t* win, const char* desc);
void cannoy_set_name_font_sz(cannoy_win_t* win, int font_height);
void cannoy_set_desc_font_sz(cannoy_win_t* win, int font_height);
void cannoy_set_name_font(cannoy_win_t* win, const char* name_font_path, int height);
void cannoy_set_desc_font(cannoy_win_t* win, const char* desc_font_path, int height);
void cannoy_set_pos(cannoy_win_t* win, cannoy_win_pos_t pos);
void cannoy_set_dimensions(cannoy_win_t* win, cannoy_win_dimensions_t dims);
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
