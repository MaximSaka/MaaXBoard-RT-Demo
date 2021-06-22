/*
 * audio_test.h
 *
 *  Created on: Jun 7, 2021
 *      Author: gulziibayar
 */

#ifndef AUDIO_DEMO_H_
#define AUDIO_TEST_H_

void disableAllMicChannels();
uint8_t * getEnabledChannels();
void enableMicChannel(int id, bool state);
void audio_task_init();
void enableAudioMicChannels(uint8_t ch, uint8_t val);

#endif /* AUDIO_DEMO_H_ */
