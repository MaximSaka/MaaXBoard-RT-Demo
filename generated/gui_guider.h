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
	lv_obj_t *screen1_LEDs;
	lv_obj_t *screen1_LEDs_canvas_white;
	lv_obj_t *screen1_LEDs_left_btn;
	lv_obj_t *screen1_LEDs_left_btn_label;
	lv_obj_t *screen1_LEDs_left_label;
	lv_obj_t *screen1_LEDs_avlogoimg0;
	lv_obj_t *screen1_LEDs_right_btn;
	lv_obj_t *screen1_LEDs_right_btn_label;
	lv_obj_t *screen1_LEDs_right_label;
	lv_obj_t *screen1_LEDs_img_5oodt29s;
	lv_obj_t *screen1_LEDs_redbtn0;
	lv_obj_t *screen1_LEDs_redbtn0_label;
	lv_obj_t *screen1_LEDs_greenbtn0;
	lv_obj_t *screen1_LEDs_greenbtn0_label;
	lv_obj_t *screen1_LEDs_bluebtn0;
	lv_obj_t *screen1_LEDs_bluebtn0_label;
	lv_obj_t *screen1_LEDs_led_red_on;
	lv_obj_t *screen1_LEDs_led_red_off;
	lv_obj_t *screen1_LEDs_home_btn;
	lv_obj_t *screen1_LEDs_home_btn_label;
	lv_obj_t *screen1_LEDs_page_label;
	lv_obj_t *screen1_LEDs_led_green_on;
	lv_obj_t *screen1_LEDs_led_green_off;
	lv_obj_t *screen1_LEDs_led_blue_on;
	lv_obj_t *screen1_LEDs_led_blue_off;
	lv_obj_t *screen0_MENU;
	lv_obj_t *screen0_MENU_img1;
	lv_obj_t *screen0_MENU_btn_1;
	lv_obj_t *screen0_MENU_btn_1_label;
	lv_obj_t *screen0_MENU_btn_2;
	lv_obj_t *screen0_MENU_btn_2_label;
	lv_obj_t *screen0_MENU_btn_3;
	lv_obj_t *screen0_MENU_btn_3_label;
	lv_obj_t *screen0_MENU_btn_4;
	lv_obj_t *screen0_MENU_btn_4_label;
	lv_obj_t *screen0_MENU_btn_5;
	lv_obj_t *screen0_MENU_btn_5_label;
	lv_obj_t *screen0_MENU_btn_6;
	lv_obj_t *screen0_MENU_btn_6_label;
	lv_obj_t *screen2_WIFI;
	lv_obj_t *screen2_WIFI_canvas_white;
	lv_obj_t *screen2_WIFI_left_btn;
	lv_obj_t *screen2_WIFI_left_btn_label;
	lv_obj_t *screen2_WIFI_left_label;
	lv_obj_t *screen2_WIFI_avlogoimg0;
	lv_obj_t *screen2_WIFI_right_btn;
	lv_obj_t *screen2_WIFI_right_btn_label;
	lv_obj_t *screen2_WIFI_right_label;
	lv_obj_t *screen2_WIFI_img_5oodt29s;
	lv_obj_t *screen2_WIFI_SSIDs_label;
	lv_obj_t *screen2_WIFI_ssid_list;
	lv_obj_t *screen2_WIFI_e100Mb_label;
	lv_obj_t *screen2_WIFI_e100Mb_cont;
	lv_obj_t *screen2_WIFI_e100Mb_text;
	lv_obj_t *screen2_WIFI_e1Gb_label;
	lv_obj_t *screen2_WIFI_e1Gb_cont;
	lv_obj_t *screen2_WIFI_e1Gb_text;
	lv_obj_t *screen3_USB;
	lv_obj_t *screen3_USB_canvas_white;
	lv_obj_t *screen3_USB_left_btn;
	lv_obj_t *screen3_USB_left_btn_label;
	lv_obj_t *screen3_USB_left_label;
	lv_obj_t *screen3_USB_avlogoimg0;
	lv_obj_t *screen3_USB_right_btn;
	lv_obj_t *screen3_USB_right_btn_label;
	lv_obj_t *screen3_USB_right_label;
	lv_obj_t *screen3_USB_img_5oodt29s;
	lv_obj_t *screen4_AV;
	lv_obj_t *screen4_AV_canvas_white;
	lv_obj_t *screen4_AV_left_btn;
	lv_obj_t *screen4_AV_left_btn_label;
	lv_obj_t *screen4_AV_left_label;
	lv_obj_t *screen4_AV_avlogoimg0;
	lv_obj_t *screen4_AV_right_btn;
	lv_obj_t *screen4_AV_right_btn_label;
	lv_obj_t *screen4_AV_right_label;
	lv_obj_t *screen4_AV_img_5oodt29s;
	lv_obj_t *screen5_SYSTEM;
	lv_obj_t *screen5_SYSTEM_canvas_white;
	lv_obj_t *screen5_SYSTEM_left_btn;
	lv_obj_t *screen5_SYSTEM_left_btn_label;
	lv_obj_t *screen5_SYSTEM_left_label;
	lv_obj_t *screen5_SYSTEM_avlogoimg0;
	lv_obj_t *screen5_SYSTEM_right_btn;
	lv_obj_t *screen5_SYSTEM_right_btn_label;
	lv_obj_t *screen5_SYSTEM_right_label;
	lv_obj_t *screen5_SYSTEM_img_5oodt29s;
	lv_obj_t *screen6_HELP;
	lv_obj_t *screen6_HELP_canvas_white;
	lv_obj_t *screen6_HELP_left_btn;
	lv_obj_t *screen6_HELP_left_btn_label;
	lv_obj_t *screen6_HELP_left_label;
	lv_obj_t *screen6_HELP_img_5oodt29s;
	lv_obj_t *screen6_HELP_label_1;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen1_LEDs(lv_ui *ui);
void setup_scr_screen0_MENU(lv_ui *ui);
void setup_scr_screen2_WIFI(lv_ui *ui);
void setup_scr_screen3_USB(lv_ui *ui);
void setup_scr_screen4_AV(lv_ui *ui);
void setup_scr_screen5_SYSTEM(lv_ui *ui);
void setup_scr_screen6_HELP(lv_ui *ui);
LV_IMG_DECLARE(_led_blue_off_alpha_110x110);
LV_IMG_DECLARE(_led_red_on_alpha_110x110);
LV_IMG_DECLARE(_AV_alpha_512x512);
LV_IMG_DECLARE(_left_arrow_alpha_150x150);
LV_IMG_DECLARE(_right_arrow_dark_alpha_150x150);
LV_IMG_DECLARE(_SBC_Help_Image_alpha_566x860);
LV_IMG_DECLARE(_wifi_green_512_alpha_512x512);
LV_IMG_DECLARE(_home_icon_alpha_132x132);
LV_IMG_DECLARE(_led_green_off_alpha_110x110);
LV_IMG_DECLARE(_AvnetIcon310x310_alpha_176x176);
LV_IMG_DECLARE(_lock_alpha_512x512);
LV_IMG_DECLARE(_led_green_on_alpha_110x110);
LV_IMG_DECLARE(_left_icon_alpha_132x132);
LV_IMG_DECLARE(_USB_alpha_512x512);
LV_IMG_DECLARE(_IoT_Smart_Asset_Monitoring_G_600ppi_alpha_500x500);
LV_IMG_DECLARE(_left_arrow_dark_alpha_150x150);
LV_IMG_DECLARE(_right_arrow_alpha_150x150);
LV_IMG_DECLARE(_led_red_off_alpha_110x110);
LV_IMG_DECLARE(_Avnet_designedby_hrz_rgb_alpha_310x151);
LV_IMG_DECLARE(_avnet_logo_alpha_110x110);
LV_IMG_DECLARE(_right_icon_alpha_132x132);
LV_IMG_DECLARE(_button_alpha_190x106);
LV_IMG_DECLARE(_button_on_alpha_190x106);
LV_IMG_DECLARE(_led_blue_on_alpha_110x110);

#ifdef __cplusplus
}
#endif
#endif
