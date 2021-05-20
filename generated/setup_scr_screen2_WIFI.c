/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen2_WIFI(lv_ui *ui){

	//Write codes screen2_WIFI
	ui->screen2_WIFI = lv_obj_create(NULL, NULL);

	//Write codes screen2_WIFI_canvas_white
	ui->screen2_WIFI_canvas_white = lv_canvas_create(ui->screen2_WIFI, NULL);

	//Write style LV_CANVAS_PART_MAIN for screen2_WIFI_canvas_white
	static lv_style_t style_screen2_WIFI_canvas_white_main;
	lv_style_init(&style_screen2_WIFI_canvas_white_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_canvas_white_main
	lv_style_set_image_recolor(&style_screen2_WIFI_canvas_white_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen2_WIFI_canvas_white_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_WIFI_canvas_white, LV_CANVAS_PART_MAIN, &style_screen2_WIFI_canvas_white_main);
	lv_obj_set_pos(ui->screen2_WIFI_canvas_white, 0, 0);
	lv_obj_set_size(ui->screen2_WIFI_canvas_white, 720, 1280);
	lv_color_t *buf_screen2_WIFI_canvas_white = (lv_color_t*)lv_mem_alloc(720*1280*4);
	lv_canvas_set_buffer(ui->screen2_WIFI_canvas_white, buf_screen2_WIFI_canvas_white, 720, 1280, LV_IMG_CF_TRUE_COLOR);

	//Write codes screen2_WIFI_left_btn
	ui->screen2_WIFI_left_btn = lv_imgbtn_create(ui->screen2_WIFI, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen2_WIFI_left_btn
	static lv_style_t style_screen2_WIFI_left_btn_main;
	lv_style_init(&style_screen2_WIFI_left_btn_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_left_btn_main
	lv_style_set_text_color(&style_screen2_WIFI_left_btn_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen2_WIFI_left_btn_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen2_WIFI_left_btn_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen2_WIFI_left_btn_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_WIFI_left_btn, LV_IMGBTN_PART_MAIN, &style_screen2_WIFI_left_btn_main);
	lv_obj_set_pos(ui->screen2_WIFI_left_btn, 10, 10);
	lv_obj_set_size(ui->screen2_WIFI_left_btn, 150, 150);
	lv_imgbtn_set_src(ui->screen2_WIFI_left_btn,LV_BTN_STATE_RELEASED,&_left_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->screen2_WIFI_left_btn,LV_BTN_STATE_PRESSED,&_left_arrow_dark_alpha_150x150);

	//Write codes screen2_WIFI_left_label
	ui->screen2_WIFI_left_label = lv_label_create(ui->screen2_WIFI, NULL);
	lv_label_set_text(ui->screen2_WIFI_left_label, "MENU");
	lv_label_set_long_mode(ui->screen2_WIFI_left_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen2_WIFI_left_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen2_WIFI_left_label
	static lv_style_t style_screen2_WIFI_left_label_main;
	lv_style_init(&style_screen2_WIFI_left_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_left_label_main
	lv_style_set_radius(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_left_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_left_label, LV_LABEL_PART_MAIN, &style_screen2_WIFI_left_label_main);
	lv_obj_set_pos(ui->screen2_WIFI_left_label, 0, 160);
	lv_obj_set_size(ui->screen2_WIFI_left_label, 180, 0);

	//Write codes screen2_WIFI_avlogoimg0
	ui->screen2_WIFI_avlogoimg0 = lv_img_create(ui->screen2_WIFI, NULL);

	//Write style LV_IMG_PART_MAIN for screen2_WIFI_avlogoimg0
	static lv_style_t style_screen2_WIFI_avlogoimg0_main;
	lv_style_init(&style_screen2_WIFI_avlogoimg0_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_avlogoimg0_main
	lv_style_set_image_recolor(&style_screen2_WIFI_avlogoimg0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen2_WIFI_avlogoimg0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen2_WIFI_avlogoimg0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_WIFI_avlogoimg0, LV_IMG_PART_MAIN, &style_screen2_WIFI_avlogoimg0_main);
	lv_obj_set_pos(ui->screen2_WIFI_avlogoimg0, 272, 20);
	lv_obj_set_size(ui->screen2_WIFI_avlogoimg0, 176, 176);
	lv_obj_set_click(ui->screen2_WIFI_avlogoimg0, true);
	lv_img_set_src(ui->screen2_WIFI_avlogoimg0,&_AvnetIcon310x310_alpha_176x176);
	lv_img_set_pivot(ui->screen2_WIFI_avlogoimg0, 0,0);
	lv_img_set_angle(ui->screen2_WIFI_avlogoimg0, 0);

	//Write codes screen2_WIFI_right_btn
	ui->screen2_WIFI_right_btn = lv_imgbtn_create(ui->screen2_WIFI, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen2_WIFI_right_btn
	static lv_style_t style_screen2_WIFI_right_btn_main;
	lv_style_init(&style_screen2_WIFI_right_btn_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_right_btn_main
	lv_style_set_text_color(&style_screen2_WIFI_right_btn_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_screen2_WIFI_right_btn_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen2_WIFI_right_btn_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen2_WIFI_right_btn_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_WIFI_right_btn, LV_IMGBTN_PART_MAIN, &style_screen2_WIFI_right_btn_main);
	lv_obj_set_pos(ui->screen2_WIFI_right_btn, 560, 10);
	lv_obj_set_size(ui->screen2_WIFI_right_btn, 150, 150);
	lv_imgbtn_set_src(ui->screen2_WIFI_right_btn,LV_BTN_STATE_RELEASED,&_right_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->screen2_WIFI_right_btn,LV_BTN_STATE_PRESSED,&_right_arrow_dark_alpha_150x150);

	//Write codes screen2_WIFI_right_label
	ui->screen2_WIFI_right_label = lv_label_create(ui->screen2_WIFI, NULL);
	lv_label_set_text(ui->screen2_WIFI_right_label, "USB");
	lv_label_set_long_mode(ui->screen2_WIFI_right_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen2_WIFI_right_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen2_WIFI_right_label
	static lv_style_t style_screen2_WIFI_right_label_main;
	lv_style_init(&style_screen2_WIFI_right_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_right_label_main
	lv_style_set_radius(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_right_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_right_label, LV_LABEL_PART_MAIN, &style_screen2_WIFI_right_label_main);
	lv_obj_set_pos(ui->screen2_WIFI_right_label, 540, 160);
	lv_obj_set_size(ui->screen2_WIFI_right_label, 180, 0);

	//Write codes screen2_WIFI_img_5oodt29s
	ui->screen2_WIFI_img_5oodt29s = lv_img_create(ui->screen2_WIFI, NULL);

	//Write style LV_IMG_PART_MAIN for screen2_WIFI_img_5oodt29s
	static lv_style_t style_screen2_WIFI_img_5oodt29s_main;
	lv_style_init(&style_screen2_WIFI_img_5oodt29s_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_img_5oodt29s_main
	lv_style_set_image_recolor(&style_screen2_WIFI_img_5oodt29s_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen2_WIFI_img_5oodt29s_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen2_WIFI_img_5oodt29s_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_WIFI_img_5oodt29s, LV_IMG_PART_MAIN, &style_screen2_WIFI_img_5oodt29s_main);
	lv_obj_set_pos(ui->screen2_WIFI_img_5oodt29s, 102, 480);
	lv_obj_set_size(ui->screen2_WIFI_img_5oodt29s, 512, 512);
	lv_obj_set_click(ui->screen2_WIFI_img_5oodt29s, true);
	lv_img_set_src(ui->screen2_WIFI_img_5oodt29s,&_wifi_green_512_alpha_512x512);
	lv_img_set_pivot(ui->screen2_WIFI_img_5oodt29s, 0,0);
	lv_img_set_angle(ui->screen2_WIFI_img_5oodt29s, 0);

	//Write codes screen2_WIFI_SSIDs_label
	ui->screen2_WIFI_SSIDs_label = lv_label_create(ui->screen2_WIFI, NULL);
	lv_label_set_text(ui->screen2_WIFI_SSIDs_label, "SSIDs");
	lv_label_set_long_mode(ui->screen2_WIFI_SSIDs_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen2_WIFI_SSIDs_label, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for screen2_WIFI_SSIDs_label
	static lv_style_t style_screen2_WIFI_SSIDs_label_main;
	lv_style_init(&style_screen2_WIFI_SSIDs_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_SSIDs_label_main
	lv_style_set_radius(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_SSIDs_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_SSIDs_label, LV_LABEL_PART_MAIN, &style_screen2_WIFI_SSIDs_label_main);
	lv_obj_set_pos(ui->screen2_WIFI_SSIDs_label, 40, 240);
	lv_obj_set_size(ui->screen2_WIFI_SSIDs_label, 640, 0);

	//Write codes screen2_WIFI_ssid_list
	ui->screen2_WIFI_ssid_list = lv_list_create(ui->screen2_WIFI, NULL);
	lv_list_set_edge_flash(ui->screen2_WIFI_ssid_list, true);

	//Write style LV_LIST_PART_BG for screen2_WIFI_ssid_list
	static lv_style_t style_screen2_WIFI_ssid_list_bg;
	lv_style_init(&style_screen2_WIFI_ssid_list_bg);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_ssid_list_bg
	lv_style_set_radius(&style_screen2_WIFI_ssid_list_bg, LV_STATE_DEFAULT, 3);
	lv_style_set_border_color(&style_screen2_WIFI_ssid_list_bg, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_screen2_WIFI_ssid_list_bg, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_screen2_WIFI_ssid_list_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_screen2_WIFI_ssid_list_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_screen2_WIFI_ssid_list_bg, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->screen2_WIFI_ssid_list, LV_LIST_PART_BG, &style_screen2_WIFI_ssid_list_bg);

	//Write style LV_LIST_PART_SCROLLABLE for screen2_WIFI_ssid_list
	static lv_style_t style_screen2_WIFI_ssid_list_scrollable;
	lv_style_init(&style_screen2_WIFI_ssid_list_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_ssid_list_scrollable
	lv_style_set_radius(&style_screen2_WIFI_ssid_list_scrollable, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen2_WIFI_ssid_list_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_ssid_list_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_ssid_list_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_ssid_list_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen2_WIFI_ssid_list, LV_LIST_PART_SCROLLABLE, &style_screen2_WIFI_ssid_list_scrollable);

	//Write style LV_BTN_PART_MAIN for screen2_WIFI_ssid_list
	static lv_style_t style_screen2_WIFI_ssid_list_main_child;
	lv_style_init(&style_screen2_WIFI_ssid_list_main_child);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_ssid_list_main_child
	lv_style_set_radius(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_ssid_list_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_obj_set_pos(ui->screen2_WIFI_ssid_list, 0, 300);
	lv_obj_set_size(ui->screen2_WIFI_ssid_list, 720, 600);
	lv_obj_t *screen2_WIFI_ssid_list_btn;
	screen2_WIFI_ssid_list_btn = lv_list_add_btn(ui->screen2_WIFI_ssid_list, LV_SYMBOL_WIFI, "item");
	lv_obj_add_style(screen2_WIFI_ssid_list_btn, LV_BTN_PART_MAIN, &style_screen2_WIFI_ssid_list_main_child);

	//Write codes screen2_WIFI_e100Mb_label
	ui->screen2_WIFI_e100Mb_label = lv_label_create(ui->screen2_WIFI, NULL);
	lv_label_set_text(ui->screen2_WIFI_e100Mb_label, "100Mbit Ethernet IP:");
	lv_label_set_long_mode(ui->screen2_WIFI_e100Mb_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen2_WIFI_e100Mb_label, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen2_WIFI_e100Mb_label
	static lv_style_t style_screen2_WIFI_e100Mb_label_main;
	lv_style_init(&style_screen2_WIFI_e100Mb_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_e100Mb_label_main
	lv_style_set_radius(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_e100Mb_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_e100Mb_label, LV_LABEL_PART_MAIN, &style_screen2_WIFI_e100Mb_label_main);
	lv_obj_set_pos(ui->screen2_WIFI_e100Mb_label, 40, 940);
	lv_obj_set_size(ui->screen2_WIFI_e100Mb_label, 640, 0);

	//Write codes screen2_WIFI_e100Mb_cont
	ui->screen2_WIFI_e100Mb_cont = lv_cont_create(ui->screen2_WIFI, NULL);

	//Write style LV_CONT_PART_MAIN for screen2_WIFI_e100Mb_cont
	static lv_style_t style_screen2_WIFI_e100Mb_cont_main;
	lv_style_init(&style_screen2_WIFI_e100Mb_cont_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_e100Mb_cont_main
	lv_style_set_radius(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_e100Mb_cont_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_e100Mb_cont, LV_CONT_PART_MAIN, &style_screen2_WIFI_e100Mb_cont_main);
	lv_obj_set_pos(ui->screen2_WIFI_e100Mb_cont, 30, 1000);
	lv_obj_set_size(ui->screen2_WIFI_e100Mb_cont, 660, 70);
	lv_obj_set_click(ui->screen2_WIFI_e100Mb_cont, false);
	lv_cont_set_layout(ui->screen2_WIFI_e100Mb_cont, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->screen2_WIFI_e100Mb_cont, LV_FIT_NONE);

	//Write codes screen2_WIFI_e100Mb_text
	ui->screen2_WIFI_e100Mb_text = lv_label_create(ui->screen2_WIFI, NULL);
	lv_label_set_text(ui->screen2_WIFI_e100Mb_text, "0.0.0.0");
	lv_label_set_long_mode(ui->screen2_WIFI_e100Mb_text, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen2_WIFI_e100Mb_text, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen2_WIFI_e100Mb_text
	static lv_style_t style_screen2_WIFI_e100Mb_text_main;
	lv_style_init(&style_screen2_WIFI_e100Mb_text_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_e100Mb_text_main
	lv_style_set_radius(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_e100Mb_text_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_e100Mb_text, LV_LABEL_PART_MAIN, &style_screen2_WIFI_e100Mb_text_main);
	lv_obj_set_pos(ui->screen2_WIFI_e100Mb_text, 50, 1010);
	lv_obj_set_size(ui->screen2_WIFI_e100Mb_text, 620, 0);

	//Write codes screen2_WIFI_e1Gb_label
	ui->screen2_WIFI_e1Gb_label = lv_label_create(ui->screen2_WIFI, NULL);
	lv_label_set_text(ui->screen2_WIFI_e1Gb_label, "1Gbit Ethernet IP:");
	lv_label_set_long_mode(ui->screen2_WIFI_e1Gb_label, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen2_WIFI_e1Gb_label, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen2_WIFI_e1Gb_label
	static lv_style_t style_screen2_WIFI_e1Gb_label_main;
	lv_style_init(&style_screen2_WIFI_e1Gb_label_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_e1Gb_label_main
	lv_style_set_radius(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_e1Gb_label_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_e1Gb_label, LV_LABEL_PART_MAIN, &style_screen2_WIFI_e1Gb_label_main);
	lv_obj_set_pos(ui->screen2_WIFI_e1Gb_label, 40, 1100);
	lv_obj_set_size(ui->screen2_WIFI_e1Gb_label, 640, 0);

	//Write codes screen2_WIFI_e1Gb_cont
	ui->screen2_WIFI_e1Gb_cont = lv_cont_create(ui->screen2_WIFI, NULL);

	//Write style LV_CONT_PART_MAIN for screen2_WIFI_e1Gb_cont
	static lv_style_t style_screen2_WIFI_e1Gb_cont_main;
	lv_style_init(&style_screen2_WIFI_e1Gb_cont_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_e1Gb_cont_main
	lv_style_set_radius(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_e1Gb_cont_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_e1Gb_cont, LV_CONT_PART_MAIN, &style_screen2_WIFI_e1Gb_cont_main);
	lv_obj_set_pos(ui->screen2_WIFI_e1Gb_cont, 30, 1160);
	lv_obj_set_size(ui->screen2_WIFI_e1Gb_cont, 660, 70);
	lv_obj_set_click(ui->screen2_WIFI_e1Gb_cont, false);
	lv_cont_set_layout(ui->screen2_WIFI_e1Gb_cont, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->screen2_WIFI_e1Gb_cont, LV_FIT_NONE);

	//Write codes screen2_WIFI_e1Gb_text
	ui->screen2_WIFI_e1Gb_text = lv_label_create(ui->screen2_WIFI, NULL);
	lv_label_set_text(ui->screen2_WIFI_e1Gb_text, "0.0.0.0");
	lv_label_set_long_mode(ui->screen2_WIFI_e1Gb_text, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->screen2_WIFI_e1Gb_text, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for screen2_WIFI_e1Gb_text
	static lv_style_t style_screen2_WIFI_e1Gb_text_main;
	lv_style_init(&style_screen2_WIFI_e1Gb_text_main);

	//Write style state: LV_STATE_DEFAULT for style_screen2_WIFI_e1Gb_text_main
	lv_style_set_radius(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, &lv_font_simsun_48);
	lv_style_set_text_letter_space(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_screen2_WIFI_e1Gb_text_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->screen2_WIFI_e1Gb_text, LV_LABEL_PART_MAIN, &style_screen2_WIFI_e1Gb_text_main);
	lv_obj_set_pos(ui->screen2_WIFI_e1Gb_text, 50, 1170);
	lv_obj_set_size(ui->screen2_WIFI_e1Gb_text, 620, 0);

	//Init events for screen
	events_init_screen2_WIFI(ui);
}