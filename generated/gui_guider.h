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
//pf #include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen;
	lv_obj_t *screen_canvas8;
	lv_obj_t *screen_button_yes;
	lv_obj_t *screen_button_yes_label;
	lv_obj_t *screen_button_no;
	lv_obj_t *screen_button_no_label;
	lv_obj_t *screen_led_rgb_green;
	lv_obj_t *screen_led_rgb_red;
	lv_obj_t *screen_avnet_logo;
	lv_obj_t *screen_iot_graphic;
	lv_obj_t *screen_button_info;
	lv_obj_t *screen_button_info_label;
	lv_obj_t *screen_led_rgb_blue;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
LV_IMG_DECLARE(_IoT_Smart_Asset_Monitoring_G_600ppi_alpha_475x475);
LV_IMG_DECLARE(_accept2_alpha_200x200);
LV_IMG_DECLARE(_decline_alpha_200x200);
LV_IMG_DECLARE(_AvnetIcon310x310_alpha_220x220);
LV_IMG_DECLARE(_accept_alpha_200x200);
LV_IMG_DECLARE(_PngItem_314246_alpha_195x195);

#ifdef __cplusplus
}
#endif
#endif
