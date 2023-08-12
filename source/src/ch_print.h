#ifndef  CH_PRINT_H
#define CH_PRINT_H

#define FONTWIDTH  (6)
#define FONTHEIGHT (12)

#define BG_NO_FILL (-1)


#define FONT_BATTERY0_GBK          "\x13\x16\x17" // empty
#define FONT_BATTERY1_GBK          "\x13\x15\x12"
#define FONT_BATTERY2_GBK          "\x13\x14\x12"
#define FONT_BATTERY3_GBK          "\x10\x11\x12" // full
#define FONT_GBA_ICON_GBK          "\x18\xA1\x4C"
#define FONT_PSP_ICON_GBK          "\x19\xA1\x4D"
#define FONT_MSC_ICON_GBK          "\x1A\xA1\x4E"
#define FONT_OPT_ICON_GBK          "\x1B\xA1\x4F"
#define FONT_PAD_ICON_GBK          "\x1C\xA1\x50"

#define FONT_KEY_ICON_GBK          "\xA1\x40"
#define FONT_R_TRIGGER_GBK         "\xA1\x41"
#define FONT_L_TRIGGER_GBK         "\xA1\x42"
#define FONT_CURSOR_RIGHT_GBK      "\xA1\x43"
#define FONT_CURSOR_LEFT_GBK       "\xA1\x44"
#define FONT_CURSOR_UP_GBK         "\xA1\x45"
#define FONT_CURSOR_DOWN_GBK       "\xA1\x46"
#define FONT_CURSOR_RIGHT_FILL_GBK "\xA1\x47"
#define FONT_CURSOR_LEFT_FILL_GBK  "\xA1\x48"
#define FONT_CURSOR_UP_FILL_GBK    "\xA1\x49"
#define FONT_CURSOR_DOWN_FILL_GBK  "\xA1\x4A"
#define FONT_UP_DIRECTORY_GBK      "\xA1\x4B"


#define FONT_BATTERY0          FONT_BATTERY0_GBK
#define FONT_BATTERY1          FONT_BATTERY1_GBK
#define FONT_BATTERY2          FONT_BATTERY2_GBK
#define FONT_BATTERY3          FONT_BATTERY3_GBK
#define FONT_GBA_ICON          FONT_GBA_ICON_GBK
#define FONT_PSP_ICON          FONT_PSP_ICON_GBK
#define FONT_MSC_ICON          FONT_MSC_ICON_GBK

#define FONT_KEY_ICON          FONT_KEY_ICON_GBK
#define FONT_R_TRIGGER         FONT_R_TRIGGER_GBK
#define FONT_L_TRIGGER         FONT_L_TRIGGER_GBK
#define FONT_CURSOR_RIGHT      FONT_CURSOR_RIGHT_GBK
#define FONT_CURSOR_LEFT       FONT_CURSOR_LEFT_GBK
#define FONT_CURSOR_UP         FONT_CURSOR_UP_GBK
#define FONT_CURSOR_DOWN       FONT_CURSOR_DOWN_GBK
#define FONT_CURSOR_RIGHT_FILL FONT_CURSOR_RIGHT_FILL_GBK
#define FONT_CURSOR_LEFT_FILL  FONT_CURSOR_LEFT_FILL_GBK
#define FONT_CURSOR_UP_FILL    FONT_CURSOR_UP_FILL_GBK
#define FONT_CURSOR_DOWN_FILL  FONT_CURSOR_DOWN_FILL_GBK
#define FONT_UP_DIRECTORY      FONT_UP_DIRECTORY_GBK

void ch_print(const char *str, u16 x, u16 y, u16 col, s16 bg_col, u16 *base_vram, u16 bufferwidth);

#endif // ! CH_PRINT_H
