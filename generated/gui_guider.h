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
	lv_obj_t *welcome_screen;
	lv_obj_t *welcome_screen_bkgimg;
	lv_obj_t *welcome_screen_rightbtn0;
	lv_obj_t *welcome_screen_rightbtn0_label;
	lv_obj_t *welcome_screen_wifilabel0;
	lv_obj_t *welcome_screen_avlogoimg0;
	lv_obj_t *welcome_screen_leftbtn0;
	lv_obj_t *welcome_screen_leftbtn0_label;
	lv_obj_t *welcome_screen_helplabel0;
	lv_obj_t *welcome_screen_redbtn0;
	lv_obj_t *welcome_screen_redbtn0_label;
	lv_obj_t *welcome_screen_greenbtn0;
	lv_obj_t *welcome_screen_greenbtn0_label;
	lv_obj_t *welcome_screen_bluebtn0;
	lv_obj_t *welcome_screen_bluebtn0_label;
	lv_obj_t *welcome_screen_usrtglimg0;
	lv_obj_t *welcome_screen_usruntglimg0;
	lv_obj_t *welcome_screen_userlabel0;
	lv_obj_t *welcome_screen_redlabel0;
	lv_obj_t *welcome_screen_greenlabel0;
	lv_obj_t *welcome_screen_bluelabel0;
	lv_obj_t *welcome_screen_iotimg;
	lv_obj_t *help_screen;
	lv_obj_t *help_screen_img1;
	lv_obj_t *help_screen_imgbtn1;
	lv_obj_t *help_screen_imgbtn1_label;
	lv_obj_t *network_screen;
	lv_obj_t *network_screen_bkgimg;
	lv_obj_t *network_screen_rightbtn0;
	lv_obj_t *network_screen_rightbtn0_label;
	lv_obj_t *network_screen_usblabel;
	lv_obj_t *network_screen_avlogoimg0;
	lv_obj_t *network_screen_leftbtn0;
	lv_obj_t *network_screen_leftbtn0_label;
	lv_obj_t *network_screen_startlabel;
	lv_obj_t *network_screen_ssidlabel;
	lv_obj_t *network_screen_ssidlist;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_welcome_screen(lv_ui *ui);
void setup_scr_help_screen(lv_ui *ui);
void setup_scr_network_screen(lv_ui *ui);
LV_IMG_DECLARE(_green_button_alpha_200x200);
LV_IMG_DECLARE(_AvnetIcon310x310_alpha_250x250);
LV_IMG_DECLARE(_left_arrow_alpha_150x150);
LV_IMG_DECLARE(_right_arrow_dark_alpha_150x150);
LV_IMG_DECLARE(_maaxBoard01_alpha_499x772);
LV_IMG_DECLARE(_blue_button_alpha_200x200);
LV_IMG_DECLARE(_cyan_inactive_button_alpha_100x100);
LV_IMG_DECLARE(_red_button_dark_alpha_200x200);
LV_IMG_DECLARE(_red_button_alpha_200x200);
LV_IMG_DECLARE(_blue_button_dark_alpha_200x200);
LV_IMG_DECLARE(_right_arrow_alpha_150x150);
LV_IMG_DECLARE(_left_arrow_dark_alpha_150x150);
LV_IMG_DECLARE(_image008_alpha_100x100);
LV_IMG_DECLARE(_image008_dark_alpha_100x100);
LV_IMG_DECLARE(_whitebkg_alpha_720x1280);
LV_IMG_DECLARE(_green_button_dark_alpha_200x200);
LV_IMG_DECLARE(_cyan_active_button_alpha_100x100);
LV_IMG_DECLARE(_IoT_Smart_Asset_Monitoring_G_600ppi_alpha_400x400);

void set_red_led(bool state);
void set_green_led(bool state);
void set_blue_led(bool state);

bool get_red_led();
bool get_green_led();
bool get_blue_led();

#ifdef __cplusplus
}
#endif
#endif
