/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_screen0_MENU(lv_ui *ui){

	//Write codes screen0_MENU
	ui->screen0_MENU = lv_obj_create(NULL, NULL);

	//Write codes screen0_MENU_img1
	ui->screen0_MENU_img1 = lv_img_create(ui->screen0_MENU, NULL);

	//Write style LV_IMG_PART_MAIN for screen0_MENU_img1
	static lv_style_t style_screen0_MENU_img1_main;
	lv_style_init(&style_screen0_MENU_img1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen0_MENU_img1_main
	lv_style_set_image_recolor(&style_screen0_MENU_img1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen0_MENU_img1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen0_MENU_img1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen0_MENU_img1, LV_IMG_PART_MAIN, &style_screen0_MENU_img1_main);
	lv_obj_set_pos(ui->screen0_MENU_img1, 68, 53);
	lv_obj_set_size(ui->screen0_MENU_img1, 566, 860);
	lv_obj_set_click(ui->screen0_MENU_img1, true);
	lv_img_set_src(ui->screen0_MENU_img1,&_SBC_Help_Image_alpha_566x860);
	lv_img_set_pivot(ui->screen0_MENU_img1, 0,0);
	lv_img_set_angle(ui->screen0_MENU_img1, 0);

	//Write codes screen0_MENU_btn_1
	ui->screen0_MENU_btn_1 = lv_btn_create(ui->screen0_MENU, NULL);

	//Write style LV_BTN_PART_MAIN for screen0_MENU_btn_1
	static lv_style_t style_screen0_MENU_btn_1_main;
	lv_style_init(&style_screen0_MENU_btn_1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen0_MENU_btn_1_main
	lv_style_set_radius(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xaf, 0x00));
	lv_style_set_border_width(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen0_MENU_btn_1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen0_MENU_btn_1, LV_BTN_PART_MAIN, &style_screen0_MENU_btn_1_main);
	lv_obj_set_pos(ui->screen0_MENU_btn_1, 20, 980);
	lv_obj_set_size(ui->screen0_MENU_btn_1, 315, 50);
	ui->screen0_MENU_btn_1_label = lv_label_create(ui->screen0_MENU_btn_1, NULL);
	lv_label_set_text(ui->screen0_MENU_btn_1_label, "LED Control");
	lv_obj_set_style_local_text_color(ui->screen0_MENU_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen0_MENU_btn_1_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_36);

	//Write codes screen0_MENU_btn_2
	ui->screen0_MENU_btn_2 = lv_btn_create(ui->screen0_MENU, NULL);

	//Write style LV_BTN_PART_MAIN for screen0_MENU_btn_2
	static lv_style_t style_screen0_MENU_btn_2_main;
	lv_style_init(&style_screen0_MENU_btn_2_main);

	//Write style state: LV_STATE_DEFAULT for style_screen0_MENU_btn_2_main
	lv_style_set_radius(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xaf, 0x00));
	lv_style_set_border_width(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen0_MENU_btn_2_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen0_MENU_btn_2, LV_BTN_PART_MAIN, &style_screen0_MENU_btn_2_main);
	lv_obj_set_pos(ui->screen0_MENU_btn_2, 26, 1090);
	lv_obj_set_size(ui->screen0_MENU_btn_2, 315, 50);
	ui->screen0_MENU_btn_2_label = lv_label_create(ui->screen0_MENU_btn_2, NULL);
	lv_label_set_text(ui->screen0_MENU_btn_2_label, "WiFi + Network");
	lv_obj_set_style_local_text_color(ui->screen0_MENU_btn_2_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen0_MENU_btn_2_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_36);

	//Write codes screen0_MENU_btn_3
	ui->screen0_MENU_btn_3 = lv_btn_create(ui->screen0_MENU, NULL);

	//Write style LV_BTN_PART_MAIN for screen0_MENU_btn_3
	static lv_style_t style_screen0_MENU_btn_3_main;
	lv_style_init(&style_screen0_MENU_btn_3_main);

	//Write style state: LV_STATE_DEFAULT for style_screen0_MENU_btn_3_main
	lv_style_set_radius(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xaf, 0x00));
	lv_style_set_border_width(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen0_MENU_btn_3_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen0_MENU_btn_3, LV_BTN_PART_MAIN, &style_screen0_MENU_btn_3_main);
	lv_obj_set_pos(ui->screen0_MENU_btn_3, 30, 1200);
	lv_obj_set_size(ui->screen0_MENU_btn_3, 315, 50);
	ui->screen0_MENU_btn_3_label = lv_label_create(ui->screen0_MENU_btn_3, NULL);
	lv_label_set_text(ui->screen0_MENU_btn_3_label, "USB + Expansion");
	lv_obj_set_style_local_text_color(ui->screen0_MENU_btn_3_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen0_MENU_btn_3_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_36);

	//Write codes screen0_MENU_btn_4
	ui->screen0_MENU_btn_4 = lv_btn_create(ui->screen0_MENU, NULL);

	//Write style LV_BTN_PART_MAIN for screen0_MENU_btn_4
	static lv_style_t style_screen0_MENU_btn_4_main;
	lv_style_init(&style_screen0_MENU_btn_4_main);

	//Write style state: LV_STATE_DEFAULT for style_screen0_MENU_btn_4_main
	lv_style_set_radius(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xaf, 0x00));
	lv_style_set_border_width(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen0_MENU_btn_4_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen0_MENU_btn_4, LV_BTN_PART_MAIN, &style_screen0_MENU_btn_4_main);
	lv_obj_set_pos(ui->screen0_MENU_btn_4, 384, 980);
	lv_obj_set_size(ui->screen0_MENU_btn_4, 315, 50);
	ui->screen0_MENU_btn_4_label = lv_label_create(ui->screen0_MENU_btn_4, NULL);
	lv_label_set_text(ui->screen0_MENU_btn_4_label, "Audio + Video");
	lv_obj_set_style_local_text_color(ui->screen0_MENU_btn_4_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen0_MENU_btn_4_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_36);

	//Write codes screen0_MENU_btn_5
	ui->screen0_MENU_btn_5 = lv_btn_create(ui->screen0_MENU, NULL);

	//Write style LV_BTN_PART_MAIN for screen0_MENU_btn_5
	static lv_style_t style_screen0_MENU_btn_5_main;
	lv_style_init(&style_screen0_MENU_btn_5_main);

	//Write style state: LV_STATE_DEFAULT for style_screen0_MENU_btn_5_main
	lv_style_set_radius(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xaf, 0x00));
	lv_style_set_border_width(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen0_MENU_btn_5_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen0_MENU_btn_5, LV_BTN_PART_MAIN, &style_screen0_MENU_btn_5_main);
	lv_obj_set_pos(ui->screen0_MENU_btn_5, 384, 1090);
	lv_obj_set_size(ui->screen0_MENU_btn_5, 315, 50);
	ui->screen0_MENU_btn_5_label = lv_label_create(ui->screen0_MENU_btn_5, NULL);
	lv_label_set_text(ui->screen0_MENU_btn_5_label, "System,Security");
	lv_obj_set_style_local_text_color(ui->screen0_MENU_btn_5_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen0_MENU_btn_5_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_36);

	//Write codes screen0_MENU_btn_6
	ui->screen0_MENU_btn_6 = lv_btn_create(ui->screen0_MENU, NULL);

	//Write style LV_BTN_PART_MAIN for screen0_MENU_btn_6
	static lv_style_t style_screen0_MENU_btn_6_main;
	lv_style_init(&style_screen0_MENU_btn_6_main);

	//Write style state: LV_STATE_DEFAULT for style_screen0_MENU_btn_6_main
	lv_style_set_radius(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, 50);
	lv_style_set_bg_color(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0xaf, 0x00));
	lv_style_set_border_width(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, 3);
	lv_style_set_border_opa(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, 255);
	lv_style_set_outline_color(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, lv_color_make(0xd4, 0xd7, 0xd9));
	lv_style_set_outline_opa(&style_screen0_MENU_btn_6_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen0_MENU_btn_6, LV_BTN_PART_MAIN, &style_screen0_MENU_btn_6_main);
	lv_obj_set_pos(ui->screen0_MENU_btn_6, 384, 1200);
	lv_obj_set_size(ui->screen0_MENU_btn_6, 315, 50);
	ui->screen0_MENU_btn_6_label = lv_label_create(ui->screen0_MENU_btn_6, NULL);
	lv_label_set_text(ui->screen0_MENU_btn_6_label, "Help Info");
	lv_obj_set_style_local_text_color(ui->screen0_MENU_btn_6_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_obj_set_style_local_text_font(ui->screen0_MENU_btn_6_label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, &lv_font_simsun_36);

	//Init events for screen
	events_init_screen0_MENU(ui);
}