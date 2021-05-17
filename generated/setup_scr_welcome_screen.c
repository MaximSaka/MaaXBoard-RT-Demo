/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"


void setup_scr_welcome_screen(lv_ui *ui){

	//Write codes welcome_screen
	ui->welcome_screen = lv_obj_create(NULL, NULL);

	//Write codes welcome_screen_bkgimg
	ui->welcome_screen_bkgimg = lv_img_create(ui->welcome_screen, NULL);

	//Write style LV_IMG_PART_MAIN for welcome_screen_bkgimg
	static lv_style_t style_welcome_screen_bkgimg_main;
	lv_style_init(&style_welcome_screen_bkgimg_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_bkgimg_main
	lv_style_set_image_recolor(&style_welcome_screen_bkgimg_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_bkgimg_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_bkgimg_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_bkgimg, LV_IMG_PART_MAIN, &style_welcome_screen_bkgimg_main);
	lv_obj_set_pos(ui->welcome_screen_bkgimg, 0, 0);
	lv_obj_set_size(ui->welcome_screen_bkgimg, 720, 1280);
	lv_obj_set_click(ui->welcome_screen_bkgimg, true);
	lv_img_set_src(ui->welcome_screen_bkgimg,&_whitebkg_alpha_720x1280);
	lv_img_set_pivot(ui->welcome_screen_bkgimg, 0,0);
	lv_img_set_angle(ui->welcome_screen_bkgimg, 0);

	//Write codes welcome_screen_rightbtn0
	ui->welcome_screen_rightbtn0 = lv_imgbtn_create(ui->welcome_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for welcome_screen_rightbtn0
	static lv_style_t style_welcome_screen_rightbtn0_main;
	lv_style_init(&style_welcome_screen_rightbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_rightbtn0_main
	lv_style_set_text_color(&style_welcome_screen_rightbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_welcome_screen_rightbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_rightbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_rightbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_rightbtn0, LV_IMGBTN_PART_MAIN, &style_welcome_screen_rightbtn0_main);
	lv_obj_set_pos(ui->welcome_screen_rightbtn0, 530, 140);
	lv_obj_set_size(ui->welcome_screen_rightbtn0, 150, 150);
	lv_imgbtn_set_src(ui->welcome_screen_rightbtn0,LV_BTN_STATE_RELEASED,&_right_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->welcome_screen_rightbtn0,LV_BTN_STATE_PRESSED,&_right_arrow_dark_alpha_150x150);

	//Write codes welcome_screen_wifilabel0
	ui->welcome_screen_wifilabel0 = lv_label_create(ui->welcome_screen, NULL);
	lv_label_set_text(ui->welcome_screen_wifilabel0, "NET");
	lv_label_set_long_mode(ui->welcome_screen_wifilabel0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->welcome_screen_wifilabel0, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for welcome_screen_wifilabel0
	static lv_style_t style_welcome_screen_wifilabel0_main;
	lv_style_init(&style_welcome_screen_wifilabel0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_wifilabel0_main
	lv_style_set_radius(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, &lv_font_simsun_36);
	lv_style_set_text_letter_space(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_welcome_screen_wifilabel0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->welcome_screen_wifilabel0, LV_LABEL_PART_MAIN, &style_welcome_screen_wifilabel0_main);
	lv_obj_set_pos(ui->welcome_screen_wifilabel0, 550, 300);
	lv_obj_set_size(ui->welcome_screen_wifilabel0, 120, 0);

	//Write codes welcome_screen_avlogoimg0
	ui->welcome_screen_avlogoimg0 = lv_img_create(ui->welcome_screen, NULL);

	//Write style LV_IMG_PART_MAIN for welcome_screen_avlogoimg0
	static lv_style_t style_welcome_screen_avlogoimg0_main;
	lv_style_init(&style_welcome_screen_avlogoimg0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_avlogoimg0_main
	lv_style_set_image_recolor(&style_welcome_screen_avlogoimg0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_avlogoimg0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_avlogoimg0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_avlogoimg0, LV_IMG_PART_MAIN, &style_welcome_screen_avlogoimg0_main);
	lv_obj_set_pos(ui->welcome_screen_avlogoimg0, 235, 80);
	lv_obj_set_size(ui->welcome_screen_avlogoimg0, 250, 250);
	lv_obj_set_click(ui->welcome_screen_avlogoimg0, true);
	lv_img_set_src(ui->welcome_screen_avlogoimg0,&_AvnetIcon310x310_alpha_250x250);
	lv_img_set_pivot(ui->welcome_screen_avlogoimg0, 0,0);
	lv_img_set_angle(ui->welcome_screen_avlogoimg0, 0);

	//Write codes welcome_screen_leftbtn0
	ui->welcome_screen_leftbtn0 = lv_imgbtn_create(ui->welcome_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for welcome_screen_leftbtn0
	static lv_style_t style_welcome_screen_leftbtn0_main;
	lv_style_init(&style_welcome_screen_leftbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_leftbtn0_main
	lv_style_set_text_color(&style_welcome_screen_leftbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_welcome_screen_leftbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_leftbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_leftbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_leftbtn0, LV_IMGBTN_PART_MAIN, &style_welcome_screen_leftbtn0_main);
	lv_obj_set_pos(ui->welcome_screen_leftbtn0, 40, 140);
	lv_obj_set_size(ui->welcome_screen_leftbtn0, 150, 150);
	lv_imgbtn_set_src(ui->welcome_screen_leftbtn0,LV_BTN_STATE_RELEASED,&_left_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->welcome_screen_leftbtn0,LV_BTN_STATE_PRESSED,&_left_arrow_dark_alpha_150x150);

	//Write codes welcome_screen_helplabel0
	ui->welcome_screen_helplabel0 = lv_label_create(ui->welcome_screen, NULL);
	lv_label_set_text(ui->welcome_screen_helplabel0, "HELP");
	lv_label_set_long_mode(ui->welcome_screen_helplabel0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->welcome_screen_helplabel0, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for welcome_screen_helplabel0
	static lv_style_t style_welcome_screen_helplabel0_main;
	lv_style_init(&style_welcome_screen_helplabel0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_helplabel0_main
	lv_style_set_radius(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, &lv_font_simsun_36);
	lv_style_set_text_letter_space(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_welcome_screen_helplabel0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->welcome_screen_helplabel0, LV_LABEL_PART_MAIN, &style_welcome_screen_helplabel0_main);
	lv_obj_set_pos(ui->welcome_screen_helplabel0, 46, 300);
	lv_obj_set_size(ui->welcome_screen_helplabel0, 130, 0);

	//Write codes welcome_screen_redbtn0
	ui->welcome_screen_redbtn0 = lv_imgbtn_create(ui->welcome_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for welcome_screen_redbtn0
	static lv_style_t style_welcome_screen_redbtn0_main;
	lv_style_init(&style_welcome_screen_redbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_redbtn0_main
	lv_style_set_text_color(&style_welcome_screen_redbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_welcome_screen_redbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_redbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_redbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_redbtn0, LV_IMGBTN_PART_MAIN, &style_welcome_screen_redbtn0_main);
	lv_obj_set_pos(ui->welcome_screen_redbtn0, 28, 1050);
	lv_obj_set_size(ui->welcome_screen_redbtn0, 200, 200);
	lv_imgbtn_set_src(ui->welcome_screen_redbtn0,LV_BTN_STATE_RELEASED,&_red_button_dark_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_redbtn0,LV_BTN_STATE_PRESSED,&_red_button_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_redbtn0,LV_BTN_STATE_CHECKED_RELEASED,&_red_button_dark_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_redbtn0,LV_BTN_STATE_CHECKED_PRESSED,&_red_button_alpha_200x200);
	lv_imgbtn_set_checkable(ui->welcome_screen_redbtn0, true);

	//Write codes welcome_screen_greenbtn0
	ui->welcome_screen_greenbtn0 = lv_imgbtn_create(ui->welcome_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for welcome_screen_greenbtn0
	static lv_style_t style_welcome_screen_greenbtn0_main;
	lv_style_init(&style_welcome_screen_greenbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_greenbtn0_main
	lv_style_set_text_color(&style_welcome_screen_greenbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_welcome_screen_greenbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_greenbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_greenbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_greenbtn0, LV_IMGBTN_PART_MAIN, &style_welcome_screen_greenbtn0_main);
	lv_obj_set_pos(ui->welcome_screen_greenbtn0, 260, 1050);
	lv_obj_set_size(ui->welcome_screen_greenbtn0, 200, 200);
	lv_imgbtn_set_src(ui->welcome_screen_greenbtn0,LV_BTN_STATE_RELEASED,&_green_button_dark_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_greenbtn0,LV_BTN_STATE_PRESSED,&_green_button_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_greenbtn0,LV_BTN_STATE_CHECKED_RELEASED,&_green_button_dark_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_greenbtn0,LV_BTN_STATE_CHECKED_PRESSED,&_green_button_alpha_200x200);
	lv_imgbtn_set_checkable(ui->welcome_screen_greenbtn0, true);

	//Write codes welcome_screen_bluebtn0
	ui->welcome_screen_bluebtn0 = lv_imgbtn_create(ui->welcome_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for welcome_screen_bluebtn0
	static lv_style_t style_welcome_screen_bluebtn0_main;
	lv_style_init(&style_welcome_screen_bluebtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_bluebtn0_main
	lv_style_set_text_color(&style_welcome_screen_bluebtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_welcome_screen_bluebtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_bluebtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_bluebtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_bluebtn0, LV_IMGBTN_PART_MAIN, &style_welcome_screen_bluebtn0_main);
	lv_obj_set_pos(ui->welcome_screen_bluebtn0, 492, 1050);
	lv_obj_set_size(ui->welcome_screen_bluebtn0, 200, 200);
	lv_imgbtn_set_src(ui->welcome_screen_bluebtn0,LV_BTN_STATE_RELEASED,&_blue_button_dark_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_bluebtn0,LV_BTN_STATE_PRESSED,&_blue_button_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_bluebtn0,LV_BTN_STATE_CHECKED_RELEASED,&_blue_button_dark_alpha_200x200);
	lv_imgbtn_set_src(ui->welcome_screen_bluebtn0,LV_BTN_STATE_CHECKED_PRESSED,&_blue_button_alpha_200x200);
	lv_imgbtn_set_checkable(ui->welcome_screen_bluebtn0, true);

	//Write codes welcome_screen_usrtglimg0
	ui->welcome_screen_usrtglimg0 = lv_img_create(ui->welcome_screen, NULL);

	//Write style LV_IMG_PART_MAIN for welcome_screen_usrtglimg0
	static lv_style_t style_welcome_screen_usrtglimg0_main;
	lv_style_init(&style_welcome_screen_usrtglimg0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_usrtglimg0_main
	lv_style_set_image_recolor(&style_welcome_screen_usrtglimg0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_usrtglimg0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_usrtglimg0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_usrtglimg0, LV_IMG_PART_MAIN, &style_welcome_screen_usrtglimg0_main);
	lv_obj_set_pos(ui->welcome_screen_usrtglimg0, 50, 850);
	lv_obj_set_size(ui->welcome_screen_usrtglimg0, 100, 100);
	lv_obj_set_click(ui->welcome_screen_usrtglimg0, true);
	lv_img_set_src(ui->welcome_screen_usrtglimg0,&_cyan_active_button_alpha_100x100);
	lv_img_set_pivot(ui->welcome_screen_usrtglimg0, 0,0);
	lv_img_set_angle(ui->welcome_screen_usrtglimg0, 0);

	//Write codes welcome_screen_usruntglimg0
	ui->welcome_screen_usruntglimg0 = lv_img_create(ui->welcome_screen, NULL);

	//Write style LV_IMG_PART_MAIN for welcome_screen_usruntglimg0
	static lv_style_t style_welcome_screen_usruntglimg0_main;
	lv_style_init(&style_welcome_screen_usruntglimg0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_usruntglimg0_main
	lv_style_set_image_recolor(&style_welcome_screen_usruntglimg0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_usruntglimg0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_usruntglimg0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_usruntglimg0, LV_IMG_PART_MAIN, &style_welcome_screen_usruntglimg0_main);
	lv_obj_set_pos(ui->welcome_screen_usruntglimg0, 50, 850);
	lv_obj_set_size(ui->welcome_screen_usruntglimg0, 100, 100);
	lv_obj_set_click(ui->welcome_screen_usruntglimg0, true);
	lv_img_set_src(ui->welcome_screen_usruntglimg0,&_cyan_inactive_button_alpha_100x100);
	lv_img_set_pivot(ui->welcome_screen_usruntglimg0, 0,0);
	lv_img_set_angle(ui->welcome_screen_usruntglimg0, 0);

	//Write codes welcome_screen_userlabel0
	ui->welcome_screen_userlabel0 = lv_label_create(ui->welcome_screen, NULL);
	lv_label_set_text(ui->welcome_screen_userlabel0, "User button OFF");
	lv_label_set_long_mode(ui->welcome_screen_userlabel0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->welcome_screen_userlabel0, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for welcome_screen_userlabel0
	static lv_style_t style_welcome_screen_userlabel0_main;
	lv_style_init(&style_welcome_screen_userlabel0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_userlabel0_main
	lv_style_set_radius(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_welcome_screen_userlabel0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->welcome_screen_userlabel0, LV_LABEL_PART_MAIN, &style_welcome_screen_userlabel0_main);
	lv_obj_set_pos(ui->welcome_screen_userlabel0, 165, 869);
	lv_obj_set_size(ui->welcome_screen_userlabel0, 227, 0);

	//Write codes welcome_screen_redlabel0
	ui->welcome_screen_redlabel0 = lv_label_create(ui->welcome_screen, NULL);
	lv_label_set_text(ui->welcome_screen_redlabel0, "Red LED OFF");
	lv_label_set_long_mode(ui->welcome_screen_redlabel0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->welcome_screen_redlabel0, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for welcome_screen_redlabel0
	static lv_style_t style_welcome_screen_redlabel0_main;
	lv_style_init(&style_welcome_screen_redlabel0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_redlabel0_main
	lv_style_set_radius(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_welcome_screen_redlabel0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->welcome_screen_redlabel0, LV_LABEL_PART_MAIN, &style_welcome_screen_redlabel0_main);
	lv_obj_set_pos(ui->welcome_screen_redlabel0, 45, 978);
	lv_obj_set_size(ui->welcome_screen_redlabel0, 170, 0);

	//Write codes welcome_screen_greenlabel0
	ui->welcome_screen_greenlabel0 = lv_label_create(ui->welcome_screen, NULL);
	lv_label_set_text(ui->welcome_screen_greenlabel0, "Green LED OFF");
	lv_label_set_long_mode(ui->welcome_screen_greenlabel0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->welcome_screen_greenlabel0, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for welcome_screen_greenlabel0
	static lv_style_t style_welcome_screen_greenlabel0_main;
	lv_style_init(&style_welcome_screen_greenlabel0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_greenlabel0_main
	lv_style_set_radius(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_welcome_screen_greenlabel0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->welcome_screen_greenlabel0, LV_LABEL_PART_MAIN, &style_welcome_screen_greenlabel0_main);
	lv_obj_set_pos(ui->welcome_screen_greenlabel0, 275, 978);
	lv_obj_set_size(ui->welcome_screen_greenlabel0, 170, 0);

	//Write codes welcome_screen_bluelabel0
	ui->welcome_screen_bluelabel0 = lv_label_create(ui->welcome_screen, NULL);
	lv_label_set_text(ui->welcome_screen_bluelabel0, "Blue LED OFF");
	lv_label_set_long_mode(ui->welcome_screen_bluelabel0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->welcome_screen_bluelabel0, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for welcome_screen_bluelabel0
	static lv_style_t style_welcome_screen_bluelabel0_main;
	lv_style_init(&style_welcome_screen_bluelabel0_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_bluelabel0_main
	lv_style_set_radius(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, &lv_font_simsun_28);
	lv_style_set_text_letter_space(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_welcome_screen_bluelabel0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->welcome_screen_bluelabel0, LV_LABEL_PART_MAIN, &style_welcome_screen_bluelabel0_main);
	lv_obj_set_pos(ui->welcome_screen_bluelabel0, 505, 978);
	lv_obj_set_size(ui->welcome_screen_bluelabel0, 170, 0);

	//Write codes welcome_screen_iotimg
	ui->welcome_screen_iotimg = lv_img_create(ui->welcome_screen, NULL);

	//Write style LV_IMG_PART_MAIN for welcome_screen_iotimg
	static lv_style_t style_welcome_screen_iotimg_main;
	lv_style_init(&style_welcome_screen_iotimg_main);

	//Write style state: LV_STATE_DEFAULT for style_welcome_screen_iotimg_main
	lv_style_set_image_recolor(&style_welcome_screen_iotimg_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_welcome_screen_iotimg_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_welcome_screen_iotimg_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->welcome_screen_iotimg, LV_IMG_PART_MAIN, &style_welcome_screen_iotimg_main);
	lv_obj_set_pos(ui->welcome_screen_iotimg, 160, 380);
	lv_obj_set_size(ui->welcome_screen_iotimg, 400, 400);
	lv_obj_set_click(ui->welcome_screen_iotimg, true);
	lv_img_set_src(ui->welcome_screen_iotimg,&_IoT_Smart_Asset_Monitoring_G_600ppi_alpha_400x400);
	lv_img_set_pivot(ui->welcome_screen_iotimg, 0,0);
	lv_img_set_angle(ui->welcome_screen_iotimg, 0);

	//Init events for screen
	events_init_welcome_screen(ui);
}