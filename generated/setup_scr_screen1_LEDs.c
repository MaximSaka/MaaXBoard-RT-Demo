/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen1_LEDs(lv_ui *ui){

	//Write codes screen1_LEDs
	ui->screen1_LEDs = lv_obj_create(NULL, NULL);

	//Write codes screen1_LEDs_canvas_white
	ui->screen1_LEDs_canvas_white = lv_canvas_create(ui->screen1_LEDs, NULL);

	//Write style LV_CANVAS_PART_MAIN for screen1_LEDs_canvas_white
	static lv_style_t style_screen1_LEDs_canvas_white_main;
	lv_style_init(&style_screen1_LEDs_canvas_white_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_canvas_white_main
	lv_style_set_image_recolor(&style_screen1_LEDs_canvas_white_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen1_LEDs_canvas_white_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen1_LEDs_canvas_white, LV_CANVAS_PART_MAIN, &style_screen1_LEDs_canvas_white_main);
	lv_obj_set_pos(ui->screen1_LEDs_canvas_white, 0, 0);
	lv_obj_set_size(ui->screen1_LEDs_canvas_white, 720, 1280);
	lv_color_t *buf_screen1_LEDs_canvas_white = (lv_color_t*)lv_mem_alloc(720*1280*4);
	lv_canvas_set_buffer(ui->screen1_LEDs_canvas_white, buf_screen1_LEDs_canvas_white, 720, 1280, LV_IMG_CF_TRUE_COLOR);

	//Write codes screen1_LEDs_left_btn
	ui->screen1_LEDs_left_btn = lv_imgbtn_create(ui->screen1_LEDs, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen1_LEDs_left_btn
	static lv_style_t style_screen1_LEDs_left_btn_main;
	lv_style_init(&style_screen1_LEDs_left_btn_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_left_btn_main
	lv_style_set_text_color(&style_screen1_LEDs_left_btn_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen1_LEDs_left_btn_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen1_LEDs_left_btn_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen1_LEDs_left_btn_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen1_LEDs_left_btn, LV_IMGBTN_PART_MAIN, &style_screen1_LEDs_left_btn_main);
	lv_obj_set_pos(ui->screen1_LEDs_left_btn, 10, 10);
	lv_obj_set_size(ui->screen1_LEDs_left_btn, 150, 150);
	lv_imgbtn_set_src(ui->screen1_LEDs_left_btn,LV_BTN_STATE_RELEASED,&_left_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->screen1_LEDs_left_btn,LV_BTN_STATE_PRESSED,&_left_arrow_dark_alpha_150x150);

	//Write codes screen1_LEDs_left_label
	ui->screen1_LEDs_left_label = lv_label_create(ui->screen1_LEDs, NULL);
	lv_label_set_text(ui->screen1_LEDs_left_label, "MENU");
	lv_label_set_long_mode(ui->screen1_LEDs_left_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen1_LEDs_left_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen1_LEDs_left_label
	static lv_style_t style_screen1_LEDs_left_label_main;
	lv_style_init(&style_screen1_LEDs_left_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_left_label_main
	lv_style_set_radius(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen1_LEDs_left_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen1_LEDs_left_label, LV_LABEL_PART_MAIN, &style_screen1_LEDs_left_label_main);
	lv_obj_set_pos(ui->screen1_LEDs_left_label, 0, 160);
	lv_obj_set_size(ui->screen1_LEDs_left_label, 180, 0);

	//Write codes screen1_LEDs_avlogoimg0
	ui->screen1_LEDs_avlogoimg0 = lv_img_create(ui->screen1_LEDs, NULL);

	//Write style LV_IMG_PART_MAIN for screen1_LEDs_avlogoimg0
	static lv_style_t style_screen1_LEDs_avlogoimg0_main;
	lv_style_init(&style_screen1_LEDs_avlogoimg0_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_avlogoimg0_main
	lv_style_set_image_recolor(&style_screen1_LEDs_avlogoimg0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen1_LEDs_avlogoimg0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen1_LEDs_avlogoimg0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen1_LEDs_avlogoimg0, LV_IMG_PART_MAIN, &style_screen1_LEDs_avlogoimg0_main);
	lv_obj_set_pos(ui->screen1_LEDs_avlogoimg0, 235, 20);
	lv_obj_set_size(ui->screen1_LEDs_avlogoimg0, 250, 250);
	lv_obj_set_click(ui->screen1_LEDs_avlogoimg0, true);
	lv_img_set_src(ui->screen1_LEDs_avlogoimg0,&_AvnetIcon310x310_alpha_250x250);
	lv_img_set_pivot(ui->screen1_LEDs_avlogoimg0, 0,0);
	lv_img_set_angle(ui->screen1_LEDs_avlogoimg0, 0);

	//Write codes screen1_LEDs_right_btn
	ui->screen1_LEDs_right_btn = lv_imgbtn_create(ui->screen1_LEDs, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen1_LEDs_right_btn
	static lv_style_t style_screen1_LEDs_right_btn_main;
	lv_style_init(&style_screen1_LEDs_right_btn_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_right_btn_main
	lv_style_set_text_color(&style_screen1_LEDs_right_btn_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen1_LEDs_right_btn_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen1_LEDs_right_btn_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen1_LEDs_right_btn_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen1_LEDs_right_btn, LV_IMGBTN_PART_MAIN, &style_screen1_LEDs_right_btn_main);
	lv_obj_set_pos(ui->screen1_LEDs_right_btn, 560, 10);
	lv_obj_set_size(ui->screen1_LEDs_right_btn, 150, 150);
	lv_imgbtn_set_src(ui->screen1_LEDs_right_btn,LV_BTN_STATE_RELEASED,&_right_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->screen1_LEDs_right_btn,LV_BTN_STATE_PRESSED,&_right_arrow_dark_alpha_150x150);

	//Write codes screen1_LEDs_right_label
	ui->screen1_LEDs_right_label = lv_label_create(ui->screen1_LEDs, NULL);
	lv_label_set_text(ui->screen1_LEDs_right_label, "WIFI");
	lv_label_set_long_mode(ui->screen1_LEDs_right_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen1_LEDs_right_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen1_LEDs_right_label
	static lv_style_t style_screen1_LEDs_right_label_main;
	lv_style_init(&style_screen1_LEDs_right_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_right_label_main
	lv_style_set_radius(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen1_LEDs_right_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen1_LEDs_right_label, LV_LABEL_PART_MAIN, &style_screen1_LEDs_right_label_main);
	lv_obj_set_pos(ui->screen1_LEDs_right_label, 540, 160);
	lv_obj_set_size(ui->screen1_LEDs_right_label, 180, 0);

	//Write codes screen1_LEDs_img_5oodt29s
	ui->screen1_LEDs_img_5oodt29s = lv_img_create(ui->screen1_LEDs, NULL);

	//Write style LV_IMG_PART_MAIN for screen1_LEDs_img_5oodt29s
	static lv_style_t style_screen1_LEDs_img_5oodt29s_main;
	lv_style_init(&style_screen1_LEDs_img_5oodt29s_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_img_5oodt29s_main
	lv_style_set_image_recolor(&style_screen1_LEDs_img_5oodt29s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen1_LEDs_img_5oodt29s_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen1_LEDs_img_5oodt29s_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen1_LEDs_img_5oodt29s, LV_IMG_PART_MAIN, &style_screen1_LEDs_img_5oodt29s_main);
	lv_obj_set_pos(ui->screen1_LEDs_img_5oodt29s, 85, 383);
	lv_obj_set_size(ui->screen1_LEDs_img_5oodt29s, 550, 550);
	lv_obj_set_click(ui->screen1_LEDs_img_5oodt29s, true);
	lv_img_set_src(ui->screen1_LEDs_img_5oodt29s,&_IoT_Smart_Asset_Monitoring_G_600ppi_alpha_550x550);
	lv_img_set_pivot(ui->screen1_LEDs_img_5oodt29s, 0,0);
	lv_img_set_angle(ui->screen1_LEDs_img_5oodt29s, 0);

	//Write codes screen1_LEDs_label_LED_buttons
	ui->screen1_LEDs_label_LED_buttons = lv_label_create(ui->screen1_LEDs, NULL);
	lv_label_set_text(ui->screen1_LEDs_label_LED_buttons, "User LED Control ");
	lv_label_set_long_mode(ui->screen1_LEDs_label_LED_buttons, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen1_LEDs_label_LED_buttons, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen1_LEDs_label_LED_buttons
	static lv_style_t style_screen1_LEDs_label_LED_buttons_main;
	lv_style_init(&style_screen1_LEDs_label_LED_buttons_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_label_LED_buttons_main
	lv_style_set_radius(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen1_LEDs_label_LED_buttons_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen1_LEDs_label_LED_buttons, LV_LABEL_PART_MAIN, &style_screen1_LEDs_label_LED_buttons_main);
	lv_obj_set_pos(ui->screen1_LEDs_label_LED_buttons, 40, 990);
	lv_obj_set_size(ui->screen1_LEDs_label_LED_buttons, 640, 0);

	//Write codes screen1_LEDs_redbtn0
	ui->screen1_LEDs_redbtn0 = lv_imgbtn_create(ui->screen1_LEDs, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen1_LEDs_redbtn0
	static lv_style_t style_screen1_LEDs_redbtn0_main;
	lv_style_init(&style_screen1_LEDs_redbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_redbtn0_main
	lv_style_set_text_color(&style_screen1_LEDs_redbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen1_LEDs_redbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen1_LEDs_redbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen1_LEDs_redbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen1_LEDs_redbtn0, LV_IMGBTN_PART_MAIN, &style_screen1_LEDs_redbtn0_main);
	lv_obj_set_pos(ui->screen1_LEDs_redbtn0, 27, 1063);
	lv_obj_set_size(ui->screen1_LEDs_redbtn0, 190, 190);
	lv_imgbtn_set_src(ui->screen1_LEDs_redbtn0,LV_BTN_STATE_RELEASED,&_ButtonRedDARK_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_redbtn0,LV_BTN_STATE_PRESSED,&_ButtonRed_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_redbtn0,LV_BTN_STATE_CHECKED_RELEASED,&_ButtonRed_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_redbtn0,LV_BTN_STATE_CHECKED_PRESSED,&_ButtonRedDARK_alpha_190x190);
	lv_imgbtn_set_checkable(ui->screen1_LEDs_redbtn0, true);

	//Write codes screen1_LEDs_greenbtn0
	ui->screen1_LEDs_greenbtn0 = lv_imgbtn_create(ui->screen1_LEDs, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen1_LEDs_greenbtn0
	static lv_style_t style_screen1_LEDs_greenbtn0_main;
	lv_style_init(&style_screen1_LEDs_greenbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_greenbtn0_main
	lv_style_set_text_color(&style_screen1_LEDs_greenbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen1_LEDs_greenbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen1_LEDs_greenbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen1_LEDs_greenbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen1_LEDs_greenbtn0, LV_IMGBTN_PART_MAIN, &style_screen1_LEDs_greenbtn0_main);
	lv_obj_set_pos(ui->screen1_LEDs_greenbtn0, 264, 1062);
	lv_obj_set_size(ui->screen1_LEDs_greenbtn0, 190, 190);
	lv_imgbtn_set_src(ui->screen1_LEDs_greenbtn0,LV_BTN_STATE_RELEASED,&_ButtonGreenDARK_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_greenbtn0,LV_BTN_STATE_PRESSED,&_ButtonGreen_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_greenbtn0,LV_BTN_STATE_CHECKED_RELEASED,&_ButtonGreen_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_greenbtn0,LV_BTN_STATE_CHECKED_PRESSED,&_ButtonGreenDARK_alpha_190x190);
	lv_imgbtn_set_checkable(ui->screen1_LEDs_greenbtn0, true);

	//Write codes screen1_LEDs_bluebtn0
	ui->screen1_LEDs_bluebtn0 = lv_imgbtn_create(ui->screen1_LEDs, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen1_LEDs_bluebtn0
	static lv_style_t style_screen1_LEDs_bluebtn0_main;
	lv_style_init(&style_screen1_LEDs_bluebtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_screen1_LEDs_bluebtn0_main
	lv_style_set_text_color(&style_screen1_LEDs_bluebtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen1_LEDs_bluebtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen1_LEDs_bluebtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen1_LEDs_bluebtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen1_LEDs_bluebtn0, LV_IMGBTN_PART_MAIN, &style_screen1_LEDs_bluebtn0_main);
	lv_obj_set_pos(ui->screen1_LEDs_bluebtn0, 503, 1061);
	lv_obj_set_size(ui->screen1_LEDs_bluebtn0, 190, 190);
	lv_imgbtn_set_src(ui->screen1_LEDs_bluebtn0,LV_BTN_STATE_RELEASED,&_ButtonBlueDARK_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_bluebtn0,LV_BTN_STATE_PRESSED,&_ButtonBlue_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_bluebtn0,LV_BTN_STATE_CHECKED_RELEASED,&_ButtonBlue_alpha_190x190);
	lv_imgbtn_set_src(ui->screen1_LEDs_bluebtn0,LV_BTN_STATE_CHECKED_PRESSED,&_ButtonBlueDARK_alpha_190x190);
	lv_imgbtn_set_checkable(ui->screen1_LEDs_bluebtn0, true);

	//Init events for screen
	events_init_screen1_LEDs(ui);
}