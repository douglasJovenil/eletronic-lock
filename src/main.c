#include "main.h"
#include <xc.h>

void main(void){
  uint8_t master_pass[SIZE_PASS] = "3692580147";
  uint8_t correct_pass[SIZE_PASS] = "123456";
  uint8_t password[SIZE_PASS ] = "\0";
  uint8_t index_password = 0;
  uint8_t cont_wrong_pass = 0;
  uint8_t pressed_enter = FALSE;

  definitions();

  while (TRUE) {
    if (!pressed_enter) {
      keyboardScan("Digite a senha: ", password, &index_password, &pressed_enter);
    } else {
      if (checkPassword(password, master_pass)) {
        changePass(correct_pass, &index_password, &pressed_enter);
      } 
      
      if (checkPassword(password, correct_pass)) {
        correctPass();
        cont_wrong_pass = 0;        
      } else {
        wrongPass();
      }

      pressed_enter = FALSE;
      index_password = 0;
      clearArray(password);
      myDelay(DELAY_TIME);
      clearLCD();
    }
  }
}

void keyboardScan(uint8_t message[] ,uint8_t password[], uint8_t *index_password, uint8_t *pressed_enter){
  uint8_t dictionary[] = {_ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ERASE, ENTER};

  writeArrayLCD(message, UP);
  for (LATD = 1; LATD <= NUM_COLUMNS; LATD = LATD << 1){
    for (uint8_t j = 0; j <= NUM_BUTTONS; j++){
      if (PORTD == dictionary[j]){
        if ((dictionary[j] == ERASE) && (*index_password > 0)){
          *index_password -= 1;
          password[*index_password] = '\0';
          writeCharLCD(password[*index_password], *index_password, DOWN);
        } else if (dictionary[j] == ENTER){
          *pressed_enter = TRUE;
        } else {
          password[*index_password] = ZERO_ASCII + j;
          writeCharLCD(password[*index_password], *index_password, DOWN);
          *index_password += 1;
        }
        while(RD4 | RD5 | RD6 | RD7);
      }
    }
  }
}

void writeCharLCD(uint8_t character, uint8_t horizontal_increment, uint8_t vertical_position){
  while(BusyXLCD());
  SetDDRamAddr((vertical_position == UP) ? START_LCD + horizontal_increment : END_LCD + horizontal_increment);
  while(BusyXLCD());
  putcXLCD(character);
  while(BusyXLCD());
}

void writeArrayLCD(const int8_t string[], int8_t vertical_position){
  uint8_t ram_position = (vertical_position == UP) ? START_LCD : END_LCD;
  
  for (uint8_t i = 0; i <= sizeArray(string); i++){
    while(BusyXLCD());
    SetDDRamAddr(ram_position);
    while(BusyXLCD());
    putcXLCD(string[i]);
    while(BusyXLCD());
    ram_position++;
  }
}

void wrongPass(){
  static uint8_t cont_wrong_pass = 0;
  cont_wrong_pass += 1;
  
  clearLCD(); 
  writeArrayLCD("Senha incorreta!", UP);
  if (cont_wrong_pass == MAX_WRONG_PASS){
    writeArrayLCD("Sistema bloqueado!", UP);
    writeArrayLCD("Sistema bloqueado!", DOWN);
    for (uint8_t i = 1; i <= TIME_BLINK_WRONG_PASS; i++) blinkLed(TIME_BLINK);
    cont_wrong_pass = 0;
    clearLCD(); 
  }
}

void changePass(uint8_t correct_pass[], uint8_t *index_password, uint8_t *pressed_enter){
  *index_password = 0;
  *pressed_enter = FALSE;

  clearLCD();
  while (!*pressed_enter) keyboardScan("Nova senha: ", correct_pass, index_password, pressed_enter);
  clearLCD();
  writeArrayLCD("Senha modificada", UP);
}

__bit checkPassword(uint8_t input_pass[], uint8_t correct_pass[]){
  for (uint8_t i = 0; i < SIZE_PASS; i++) {
    if ((input_pass[i] != correct_pass[i]) && (input_pass[i] != '\0')) {
      return FALSE;
    }
  }
  return TRUE;
}

void clearArray(uint8_t array[]){
  for (uint8_t i = 0; i <= SIZE_PASS; i++) array[i] = '\0';
}

uint8_t sizeArray(const uint8_t array[]){
  uint8_t i = 0;
  while (array[i] != '\0') i++;
  return i;
}

void blinkLed(uint8_t time){
  LED = ON;
  myDelay(time);
  LED = OFF;
  myDelay(time);
}

void clearLCD(){	
   while(BusyXLCD());  
   WriteCmdXLCD(CMD_CLEAR);
   while(BusyXLCD());
   myDelay(DELAY_CLEAR);
}

void correctPass(){
  clearLCD(); 
  writeArrayLCD("Senha correta!", UP);
}