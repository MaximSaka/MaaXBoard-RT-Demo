/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"


void setup_scr_network_screen(lv_ui *ui){

	//Write codes network_screen
	ui->network_screen = lv_obj_create(NULL, NULL);

	//Write codes network_screen_bkgimg
	ui->network_screen_bkgimg = lv_img_create(ui->network_screen, NULL);

	//Write style LV_IMG_PART_MAIN for network_screen_bkgimg
	static lv_style_t style_network_screen_bkgimg_main;
	lv_style_init(&style_network_screen_bkgimg_main);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_bkgimg_main
	lv_style_set_image_recolor(&style_network_screen_bkgimg_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_network_screen_bkgimg_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_network_screen_bkgimg_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->network_screen_bkgimg, LV_IMG_PART_MAIN, &style_network_screen_bkgimg_main);
	lv_obj_set_pos(ui->network_screen_bkgimg, 0, 0);
	lv_obj_set_size(ui->network_screen_bkgimg, 720, 1280);
	lv_obj_set_click(ui->network_screen_bkgimg, true);
	lv_img_set_src(ui->network_screen_bkgimg,&_whitebkg_alpha_720x1280);
	lv_img_set_pivot(ui->network_screen_bkgimg, 0,0);
	lv_img_set_angle(ui->network_screen_bkgimg, 0);

	//Write codes network_screen_rightbtn0
	ui->network_screen_rightbtn0 = lv_imgbtn_create(ui->network_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for network_screen_rightbtn0
	static lv_style_t style_network_screen_rightbtn0_main;
	lv_style_init(&style_network_screen_rightbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_rightbtn0_main
	lv_style_set_text_color(&style_network_screen_rightbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_network_screen_rightbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_network_screen_rightbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_network_screen_rightbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->network_screen_rightbtn0, LV_IMGBTN_PART_MAIN, &style_network_screen_rightbtn0_main);
	lv_obj_set_pos(ui->network_screen_rightbtn0, 530, 140);
	lv_obj_set_size(ui->network_screen_rightbtn0, 150, 150);
	lv_imgbtn_set_src(ui->network_screen_rightbtn0,LV_BTN_STATE_RELEASED,&_right_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->network_screen_rightbtn0,LV_BTN_STATE_PRESSED,&_right_arrow_dark_alpha_150x150);

	//Write codes network_screen_usblabel
	ui->network_screen_usblabel = lv_label_create(ui->network_screen, NULL);
	lv_label_set_text(ui->network_screen_usblabel, "USB");
	lv_label_set_long_mode(ui->network_screen_usblabel, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->network_screen_usblabel, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for network_screen_usblabel
	static lv_style_t style_network_screen_usblabel_main;
	lv_style_init(&style_network_screen_usblabel_main);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_usblabel_main
	lv_style_set_radius(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, &lv_font_simsun_36);
	lv_style_set_text_letter_space(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_network_screen_usblabel_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->network_screen_usblabel, LV_LABEL_PART_MAIN, &style_network_screen_usblabel_main);
	lv_obj_set_pos(ui->network_screen_usblabel, 545, 300);
	lv_obj_set_size(ui->network_screen_usblabel, 128, 0);

	//Write codes network_screen_avlogoimg0
	ui->network_screen_avlogoimg0 = lv_img_create(ui->network_screen, NULL);

	//Write style LV_IMG_PART_MAIN for network_screen_avlogoimg0
	static lv_style_t style_network_screen_avlogoimg0_main;
	lv_style_init(&style_network_screen_avlogoimg0_main);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_avlogoimg0_main
	lv_style_set_image_recolor(&style_network_screen_avlogoimg0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_network_screen_avlogoimg0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_network_screen_avlogoimg0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->network_screen_avlogoimg0, LV_IMG_PART_MAIN, &style_network_screen_avlogoimg0_main);
	lv_obj_set_pos(ui->network_screen_avlogoimg0, 235, 80);
	lv_obj_set_size(ui->network_screen_avlogoimg0, 250, 250);
	lv_obj_set_click(ui->network_screen_avlogoimg0, true);
	lv_img_set_src(ui->network_screen_avlogoimg0,&_AvnetIcon310x310_alpha_250x250);
	lv_img_set_pivot(ui->network_screen_avlogoimg0, 0,0);
	lv_img_set_angle(ui->network_screen_avlogoimg0, 0);

	//Write codes network_screen_leftbtn0
	ui->network_screen_leftbtn0 = lv_imgbtn_create(ui->network_screen, NULL);

	//Write style LV_IMGBTN_PART_MAIN for network_screen_leftbtn0
	static lv_style_t style_network_screen_leftbtn0_main;
	lv_style_init(&style_network_screen_leftbtn0_main);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_leftbtn0_main
	lv_style_set_text_color(&style_network_screen_leftbtn0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_network_screen_leftbtn0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_network_screen_leftbtn0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_network_screen_leftbtn0_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->network_screen_leftbtn0, LV_IMGBTN_PART_MAIN, &style_network_screen_leftbtn0_main);
	lv_obj_set_pos(ui->network_screen_leftbtn0, 40, 140);
	lv_obj_set_size(ui->network_screen_leftbtn0, 150, 150);
	lv_imgbtn_set_src(ui->network_screen_leftbtn0,LV_BTN_STATE_RELEASED,&_left_arrow_alpha_150x150);
	lv_imgbtn_set_src(ui->network_screen_leftbtn0,LV_BTN_STATE_PRESSED,&_left_arrow_dark_alpha_150x150);

	//Write codes network_screen_startlabel
	ui->network_screen_startlabel = lv_label_create(ui->network_screen, NULL);
	lv_label_set_text(ui->network_screen_startlabel, "START");
	lv_label_set_long_mode(ui->network_screen_startlabel, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->network_screen_startlabel, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for network_screen_startlabel
	static lv_style_t style_network_screen_startlabel_main;
	lv_style_init(&style_network_screen_startlabel_main);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_startlabel_main
	lv_style_set_radius(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, &lv_font_simsun_36);
	lv_style_set_text_letter_space(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_network_screen_startlabel_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->network_screen_startlabel, LV_LABEL_PART_MAIN, &style_network_screen_startlabel_main);
	lv_obj_set_pos(ui->network_screen_startlabel, 46, 300);
	lv_obj_set_size(ui->network_screen_startlabel, 128, 0);

	//Write codes network_screen_ssidlabel
	ui->network_screen_ssidlabel = lv_label_create(ui->network_screen, NULL);
	lv_label_set_text(ui->network_screen_ssidlabel, "SSIDs");
	lv_label_set_long_mode(ui->network_screen_ssidlabel, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->network_screen_ssidlabel, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for network_screen_ssidlabel
	static lv_style_t style_network_screen_ssidlabel_main;
	lv_style_init(&style_network_screen_ssidlabel_main);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_ssidlabel_main
	lv_style_set_radius(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, &lv_font_simsun_36);
	lv_style_set_text_letter_space(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_network_screen_ssidlabel_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->network_screen_ssidlabel, LV_LABEL_PART_MAIN, &style_network_screen_ssidlabel_main);
	lv_obj_set_pos(ui->network_screen_ssidlabel, 111, 370);
	lv_obj_set_size(ui->network_screen_ssidlabel, 291, 0);

	//Write codes network_screen_ssidlist
	ui->network_screen_ssidlist = lv_list_create(ui->network_screen, NULL);
	lv_list_set_edge_flash(ui->network_screen_ssidlist, true);
	lv_list_set_anim_time(ui->network_screen_ssidlist, 255);

	//Write style LV_LIST_PART_BG for network_screen_ssidlist
	static lv_style_t style_network_screen_ssidlist_bg;
	lv_style_init(&style_network_screen_ssidlist_bg);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_ssidlist_bg
	lv_style_set_radius(&style_network_screen_ssidlist_bg, LV_STATE_DEFAULT, 3);
	lv_style_set_border_color(&style_network_screen_ssidlist_bg, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_network_screen_ssidlist_bg, LV_STATE_DEFAULT, 1);
	lv_obj_add_style(ui->network_screen_ssidlist, LV_LIST_PART_BG, &style_network_screen_ssidlist_bg);

	//Write style LV_LIST_PART_SCROLLABLE for network_screen_ssidlist
	static lv_style_t style_network_screen_ssidlist_scrollable;
	lv_style_init(&style_network_screen_ssidlist_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_network_screen_ssidlist_scrollable
	lv_style_set_radius(&style_network_screen_ssidlist_scrollable, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_network_screen_ssidlist_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_network_screen_ssidlist_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_network_screen_ssidlist_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_network_screen_ssidlist_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->network_screen_ssidlist, LV_LIST_PART_SCROLLABLE, &style_network_screen_ssidlist_scrollable);

	// //Write style LV_BTN_PART_MAIN for network_screen_ssidlist
	// static lv_style_t style_network_screen_ssidlist_main_child;
	// lv_style_init(&style_network_screen_ssidlist_main_child);

	// //Write style state: LV_STATE_DEFAULT for style_network_screen_ssidlist_main_child
	// lv_style_set_radius(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, 3);
	// lv_style_set_bg_color(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	// lv_style_set_bg_grad_color(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	// lv_style_set_bg_grad_dir(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	// lv_style_set_bg_opa(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, 255);
	// lv_style_set_text_color(&style_network_screen_ssidlist_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_obj_set_pos(ui->network_screen_ssidlist, 110, 420);
	lv_obj_set_size(ui->network_screen_ssidlist, 500, 500);
	// lv_obj_t *network_screen_ssidlist_btn;
	// network_screen_ssidlist_btn = lv_list_add_btn(ui->network_screen_ssidlist, NULL, "item1");
	// lv_obj_add_style(network_screen_ssidlist_btn, LV_BTN_PART_MAIN, &style_network_screen_ssidlist_main_child);
	// network_screen_ssidlist_btn = lv_list_add_btn(ui->network_screen_ssidlist, NULL, "item2");
	// lv_obj_add_style(network_screen_ssidlist_btn, LV_BTN_PART_MAIN, &style_network_screen_ssidlist_main_child);

	//Init events for screen
	events_init_network_screen(ui);
}