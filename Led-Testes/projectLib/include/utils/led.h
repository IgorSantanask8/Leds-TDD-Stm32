#ifndef LED_H_
#define LED_H_

#ifdef __cplusplus
extern "C"{
#endif

void LedOn(int id);

void LedOff(int id);

void LedToggle(int id);

void PushButton(int id);



#ifdef __cplusplus
}
#endif

#endif //LED_H_

