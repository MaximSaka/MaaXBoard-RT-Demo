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

	//Write codes screen_img1
	ui->screen_img1 = lv_img_create(ui->screen, NULL);

	//Write style LV_IMG_PART_MAIN for screen_img1
	static lv_style_t style_screen_img1_main;
	lv_style_init(&style_screen_img1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_img1_main
	lv_style_set_image_recolor(&style_screen_img1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_img1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_img1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_img1, LV_IMG_PART_MAIN, &style_screen_img1_main);
	lv_obj_set_pos(ui->screen_img1, 109, 142);
	lv_obj_set_size(ui->screen_img1, 499, 772);
	lv_obj_set_click(ui->screen_img1, true);
	lv_img_set_src(ui->screen_img1,&_maaxBoard01_alpha_499x772);
	lv_img_set_pivot(ui->screen_img1, 0,0);
	lv_img_set_angle(ui->screen_img1, 0);

	//Write codes screen_imgbtn1
	ui->screen_imgbtn1 = lv_imgbtn_create(ui->screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for screen_imgbtn1
	static lv_style_t style_screen_imgbtn1_main;
	lv_style_init(&style_screen_imgbtn1_main);

	//Write style state: LV_STATE_DEFAULT for style_screen_imgbtn1_main
	lv_style_set_text_color(&style_screen_imgbtn1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_screen_imgbtn1_main, LV_STATE_DEFAULT, &lv_font_simsun_12);
	lv_style_set_image_recolor(&style_screen_imgbtn1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_screen_imgbtn1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_screen_imgbtn1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->screen_imgbtn1, LV_IMGBTN_PART_MAIN, &style_screen_imgbtn1_main);
	lv_obj_set_pos(ui->screen_imgbtn1, 21, 21);
	lv_obj_set_size(ui->screen_imgbtn1, 100, 100);
	lv_imgbtn_set_src(ui->screen_imgbtn1,LV_BTN_STATE_RELEASED,&_image008_alpha_100x100);
	lv_imgbtn_set_src(ui->screen_imgbtn1,LV_BTN_STATE_PRESSED,&_image008_dark_alpha_100x100);
	ui->screen_imgbtn1_label = lv_label_create(ui->screen_imgbtn1, NULL);
	lv_label_set_text(ui->screen_imgbtn1_label, "test");

	//Init events for screen
	events_init_screen(ui);
}