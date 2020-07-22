//display.h
#pragma once

#include <inttypes.h>
#include "guitypes.h"
#include "display_helper.h"
#include <algorithm>

typedef void(display_init_t)(void);
typedef void(display_done_t)(void);
typedef void(display_clear_t)(color_t clr);
typedef void(display_set_pixel_t)(point_ui16_t pt, color_t clr);
typedef void(display_draw_line_t)(point_ui16_t pt0, point_ui16_t pt1, color_t clr);
typedef void(display_draw_rect_t)(rect_ui16_t rc, color_t clr);
typedef void(display_fill_rect_t)(rect_ui16_t rc, color_t clr);
typedef bool(display_draw_char_t)(point_ui16_t pt, uint8_t charX, uint8_t charY, const font_t *pf, color_t clr_bg, color_t clr_fg);
typedef bool(display_draw_text_t)(rect_ui16_t rc, string_view_utf8 str, const font_t *pf, color_t clr_bg, color_t clr_fg);
typedef void(display_draw_icon_t)(point_ui16_t pt, uint16_t id_res, color_t clr0, uint8_t rop);
typedef void(display_draw_png_t)(point_ui16_t pt, FILE *pf);

// just to test the FW with fonts - will be refactored
struct FCIndex {
    uint16_t unc; /// utf8 character value (stripped of prefixes)
    uint8_t charX, charY;
};

static constexpr const FCIndex fontCharIndices[] = //{{1,1,1}};
#include "fnt-indices.ipp"
    static constexpr const uint32_t fontCharIndicesNumItems = sizeof(fontCharIndices) / sizeof(FCIndex);

template <uint16_t W, uint16_t H, display_init_t *INIT, display_done_t *DONE, display_clear_t *CLEAR, display_set_pixel_t *SET_PIXEL, display_draw_line_t *DRAW_LINE, display_draw_rect_t *DRAW_RECT, display_fill_rect_t *FIL_RECT, display_draw_char_t *DRAW_CHAR, display_draw_text_t *DRAW_TEXT, display_draw_icon_t *DRAW_ICON, display_draw_png_t *DRAW_PNG>
class Display {
    // sorted raw array of known utf8 character indices
public:
    constexpr static uint16_t GetW() { return W; }
    constexpr static uint16_t GetH() { return H; }
    constexpr static void Init() { INIT(); }
    constexpr static void Done() { DONE(); }
    constexpr static void Clear(color_t clr) { CLEAR(clr); }
    constexpr static void SetPixel(point_ui16_t pt, color_t clr) { SET_PIXEL(pt, clr); }
    constexpr static void DrawLine(point_ui16_t pt0, point_ui16_t pt1, color_t clr) { DRAW_LINE(pt0, pt1, clr); }
    constexpr static void DrawRect(rect_ui16_t rc, color_t clr) { DRAW_RECT(rc, clr); }
    constexpr static void FillRect(rect_ui16_t rc, color_t clr) { FIL_RECT(rc, clr); }
    constexpr static bool DrawChar(point_ui16_t pt, unichar c, const font_t *pf, color_t clr_bg, color_t clr_fg) {
        static_assert(sizeof(FCIndex) == 4, "font char indices size mismatch");
        // convert unichar into font index - all fonts have the same layout, thus this can be computed here
        // ... and also because doing it in C++ is much easier than in plain C
        uint8_t charX = 15, charY = 1;
        if (c < 128) {
            // normal ASCII character
            charX = (c - pf->asc_min) % 16;
            charY = (c - pf->asc_min) / 16;
        } else {
            // extended utf8 character - must search in the fontCharIndices map
            const FCIndex *i = std::lower_bound(fontCharIndices, fontCharIndices + fontCharIndicesNumItems, c, [](const FCIndex &i, unichar c) {
                return i.unc < c;
            });
            if (i == fontCharIndices + fontCharIndicesNumItems || i->unc != c) {
                // character not found
                charX = 15; // put '?' as a replacement
                charY = 1;
            } else {
                charX = i->charX;
                charY = i->charY;
            }
            //            for(const FCIndex *i = fontCharIndices; i < fontCharIndices + fontCharIndicesNumItems; ++i){
            //                if( i->unc == c ){
            //                    charX = i->charX;
            //                    charY = i->charY;
            //                    break;
            //                }
            //            }
        }
        return DRAW_CHAR(pt, charX, charY, pf, clr_bg, clr_fg);
    }
    static bool DrawText(rect_ui16_t rc, string_view_utf8 str, const font_t *pf, color_t clr_bg, color_t clr_fg) { return DRAW_TEXT(rc, str, pf, clr_bg, clr_fg); }
    constexpr static void DrawIcon(point_ui16_t pt, uint16_t id_res, color_t clr0, uint8_t rop) { DRAW_ICON(pt, id_res, clr0, rop); }
    constexpr static void DrawPng(point_ui16_t pt, FILE *pf) { DRAW_PNG(pt, pf); }
};

#include "st7789v.h"
using display = Display<ST7789V_COLS, ST7789V_ROWS,
    st7789v_init,
    st7789v_done,
    st7789v_clear,
    st7789v_set_pixel,
    st7789v_draw_line,
    st7789v_draw_rect,
    st7789v_fill_rect,
    st7789v_draw_charUnicode,
    //    st7789v_draw_text,
    render_text,
    st7789v_draw_icon,
    st7789v_draw_png>;
