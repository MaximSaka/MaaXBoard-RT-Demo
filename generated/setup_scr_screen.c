/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"


void setup_scr_screen(lv_ui *ui){

	//Write codes screen
	ui->screen = lv_obj_create(NULL, NULL);

	//Write codes screen_canvas8
	ui->screen_canvas8 = lv_canvas_create(ui->screen, NULL);

	//Write style LV_CANVAS_PART_MAIN for screen_canvas8
	static lv_style_t style_screen_canvas8_main;
	lv_style_init(&style_screen_canvas8_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_canvas8_main
	lv_style_set_image_recolor(&style_screen_canvas8_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_canvas8_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_canvas8, LV_CANVAS_PART_MAIN, &style_screen_canvas8_main);
	lv_obj_set_pos(ui->screen_canvas8, 0, 0);
	lv_obj_set_size(ui->screen_canvas8, 720, 1280);
	lv_color_t *buf_screen_canvas8 = (lv_color_t*)lv_mem_alloc(720*1280*4);
	lv_canvas_set_buffer(ui->screen_canvas8, buf_screen_canvas8, 720, 1280, LV_IMG_CF_TRUE_COLOR);

	//Write codes screen_button_yes
	ui->screen_button_yes = lv_imgbtn_create(ui->screen, NULL);
	lv_obj_set_pos(ui->screen_button_yes, 255, 999);
	lv_obj_set_size(ui->screen_button_yes, 200, 200);
	lv_imgbtn_set_src(ui->screen_button_yes,LV_BTN_STATE_RELEASED,&_accept_alpha_200x200);
	lv_imgbtn_set_src(ui->screen_button_yes,LV_BTN_STATE_PRESSED,&_accept2_alpha_200x200);

	//Write codes screen_button_no
	ui->screen_button_no = lv_imgbtn_create(ui->screen, NULL);
	lv_obj_set_pos(ui->screen_button_no, 22, 994);
	lv_obj_set_size(ui->screen_button_no, 200, 200);
	lv_imgbtn_set_src(ui->screen_button_no,LV_BTN_STATE_RELEASED,&_decline_alpha_200x200);
	lv_imgbtn_set_src(ui->screen_button_no,LV_BTN_STATE_PRESSED,&_decline_alpha_200x200);
	lv_imgbtn_set_checkable(ui->screen_button_no, true);

	//Write codes screen_led_rgb_green
	ui->screen_led_rgb_green = lv_led_create(ui->screen, NULL);

	//Write style LV_LED_PART_MAIN for screen_led_rgb_green
	static lv_style_t style_screen_led_rgb_green_main;
	lv_style_init(&style_screen_led_rgb_green_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_led_rgb_green_main
	lv_style_set_radius(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, 20);
	lv_style_set_bg_color(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_bg_grad_color(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, lv_color_make(0x12, 0xf2, 0x02));
	lv_style_set_bg_grad_dir(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_color(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_shadow_width(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_led_rgb_green_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_led_rgb_green, LV_LED_PART_MAIN, &style_screen_led_rgb_green_main);
	lv_obj_set_pos(ui->screen_led_rgb_green, 308, 318);
	lv_obj_set_size(ui->screen_led_rgb_green, 90, 90);
	lv_led_set_bright(ui->screen_led_rgb_green, 200);

	//Write codes screen_led_rgb_red
	ui->screen_led_rgb_red = lv_led_create(ui->screen, NULL);

	//Write style LV_LED_PART_MAIN for screen_led_rgb_red
	static lv_style_t style_screen_led_rgb_red_main;
	lv_style_init(&style_screen_led_rgb_red_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_led_rgb_red_main
	lv_style_set_radius(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, 20);
	lv_style_set_bg_color(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_bg_grad_color(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, lv_color_make(0xf2, 0x02, 0x02));
	lv_style_set_bg_grad_dir(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_color(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_shadow_width(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_led_rgb_red_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_led_rgb_red, LV_LED_PART_MAIN, &style_screen_led_rgb_red_main);
	lv_obj_set_pos(ui->screen_led_rgb_red, 119, 318);
	lv_obj_set_size(ui->screen_led_rgb_red, 90, 90);
	lv_led_set_bright(ui->screen_led_rgb_red, 200);

	//Write codes screen_avnet_logo
	ui->screen_avnet_logo = lv_img_create(ui->screen, NULL);
	lv_obj_set_pos(ui->screen_avnet_logo, 249, 52);
	lv_obj_set_size(ui->screen_avnet_logo, 220, 220);
	lv_obj_set_click(ui->screen_avnet_logo, true);
	lv_img_set_src(ui->screen_avnet_logo,&_AvnetIcon310x310_alpha_220x220);
	lv_img_set_pivot(ui->screen_avnet_logo, 0,0);
	lv_img_set_angle(ui->screen_avnet_logo, 0);

	//Write codes screen_iot_graphic
	ui->screen_iot_graphic = lv_img_create(ui->screen, NULL);
	lv_obj_set_pos(ui->screen_iot_graphic, 118, 461);
	lv_obj_set_size(ui->screen_iot_graphic, 475, 475);
	lv_obj_set_click(ui->screen_iot_graphic, true);
	lv_img_set_src(ui->screen_iot_graphic,&_IoT_Smart_Asset_Monitoring_G_600ppi_alpha_475x475);
	lv_img_set_pivot(ui->screen_iot_graphic, 0,0);
	lv_img_set_angle(ui->screen_iot_graphic, 0);

	//Write codes screen_button_info
	ui->screen_button_info = lv_imgbtn_create(ui->screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_button_info
	static lv_style_t style_screen_button_info_main;
	lv_style_init(&style_screen_button_info_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_button_info_main
	lv_style_set_text_color(&style_screen_button_info_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen_button_info_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_button_info_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_button_info_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_button_info, LV_IMGBTN_PART_MAIN, &style_screen_button_info_main);
	lv_obj_set_pos(ui->screen_button_info, 498, 1001);
	lv_obj_set_size(ui->screen_button_info, 195, 195);
	lv_imgbtn_set_src(ui->screen_button_info,LV_BTN_STATE_RELEASED,&_PngItem_314246_alpha_195x195);
	lv_imgbtn_set_src(ui->screen_button_info,LV_BTN_STATE_PRESSED,&_PngItem_314246_alpha_195x195);
	lv_imgbtn_set_checkable(ui->screen_button_info, true);

	//Write codes screen_led_rgb_blue
	ui->screen_led_rgb_blue = lv_led_create(ui->screen, NULL);

	//Write style LV_LED_PART_MAIN for screen_led_rgb_blue
	static lv_style_t style_screen_led_rgb_blue_main;
	lv_style_init(&style_screen_led_rgb_blue_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_led_rgb_blue_main
	lv_style_set_radius(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, 20);
	lv_style_set_bg_color(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, lv_color_make(0x80, 0x80, 0x80));
	lv_style_set_bg_grad_color(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x08, 0xfa));
	lv_style_set_bg_grad_dir(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, 255);
	lv_style_set_shadow_color(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xa1, 0xb5));
	lv_style_set_shadow_width(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, 0);
	lv_style_set_border_color(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, 2);
	lv_style_set_border_opa(&style_screen_led_rgb_blue_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_led_rgb_blue, LV_LED_PART_MAIN, &style_screen_led_rgb_blue_main);
	lv_obj_set_pos(ui->screen_led_rgb_blue, 501, 319);
	lv_obj_set_size(ui->screen_led_rgb_blue, 90, 90);
	lv_led_set_bright(ui->screen_led_rgb_blue, 200);
}