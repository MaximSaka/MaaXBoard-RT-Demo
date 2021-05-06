/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "guider_fonts/guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_img1;
	lv_obj_t *screen_imgbtn1;
	lv_obj_t *screen_imgbtn1_label;
	lv_obj_t *screen2;
	lv_obj_t *screen2_img0;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
void setup_scr_screen2(lv_ui *ui);
LV_IMG_DECLARE(_image008_alpha_100x100);
LV_IMG_DECLARE(_image008_dark_alpha_100x100);
LV_IMG_DECLARE(_maaxBoard01_alpha_499x772);
LV_IMG_DECLARE(_image009_alpha_158x158);

#ifdef __cplusplus
}
#endif
#endif
