/* 
Adapted by Andri Yadi.
Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "output_handler.h"

#include "Arduino.h"




const int ledPinR = 3;        // D3 핀, 빨강색 출력
const int ledPinG = 2;        // D2  핀, 초록색 출력--> 보라색 선
const int ledPinB = 7;        // D7  핀, 파랑색 출력
const int ledPinRed = 4;      // ble D4 핀 
const int ledPinGreen = 5;    // ble D5 핀
const int ledPinBlue = 6;     // ble D6 핀

#define XMAS_DEMO 0

#if XMAS_DEMO
#include "xmas_demo.hpp" 
#endif

void LightUpRGB(int kind) {

  digitalWrite(ledPinRed, HIGH);
  digitalWrite(ledPinGreen, HIGH);
  digitalWrite(ledPinBlue, HIGH);

  switch (kind)
  {
  case 0/* W */:
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinB, LOW);
    digitalWrite(ledPinR, HIGH);
    
    digitalWrite(ledPinRed, LOW);    //이 핀이 LOW가 됐을때 아두이노 나노로 전송되는 아날로그 신호값이 뚝 떨어지므로 그때의 범위 설정해서 if문 써서 통신하면 됨 
   
    break;
  case 1/* O */:
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinB, LOW);
    digitalWrite(ledPinG, HIGH);
    digitalWrite(ledPinGreen, LOW);
    
    break;
  case 2/* L */:
    digitalWrite(ledPinG, LOW);
    digitalWrite(ledPinR, LOW);
    digitalWrite(ledPinB, HIGH);
    digitalWrite(ledPinBlue, LOW);
   
    break;
    
  default:
    break;
  }
}

void HandleOutput(tflite::ErrorReporter* error_reporter, int kind) {
  // The first time this method runs, set up our LED
  static bool is_initialized = false;
  if (!is_initialized) {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ledPinRed, OUTPUT);
    pinMode(ledPinGreen, OUTPUT);
    pinMode(ledPinBlue, OUTPUT);
    is_initialized = true;
  }
  // Toggle the LED every time an inference is performed///
  static int count = 0;
  ++count;
  if (count & 1) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  LightUpRGB(kind);

  // Print some ASCII art for each gesture
  if (kind == 0) {
    // error_reporter->Report("\n\r█ Wingardium Leviosa █\n\r");
    error_reporter->Report(
        "\n\r*         *         *\n\r *       * *       "
        "*\n\r  *     *   *     *\n\r   *   *     *   *\n\r    * *       "
        "* *\n\r     *         *\n\r\n\r");
#if !XMAS_DEMO
    error_reporter->Report("\n\r");
    error_reporter->Report("╔══════════════════════╗");
    error_reporter->Report("║  Wingardium Leviosa  ║");
    error_reporter->Report("╚══════════════════════╝\n\r");
#else
    error_reporter->Report(w_label.c_str());    
    delay(2000);
#endif
  } else if (kind == 1) {
    // error_reporter->Report("\n\r█ Obliviate █\n\r");
    error_reporter->Report(
        "\n\r          *\n\r       *     *\n\r     *         *\n\r "
        "   *           *\n\r     *         *\n\r       *     *\n\r      "
        "    *\n\r");
#if !XMAS_DEMO
    error_reporter->Report("\n\r");
    error_reporter->Report("╔══════════════════════╗");
    error_reporter->Report("║       Obliviate      ║");
    error_reporter->Report("╚══════════════════════╝\n\r");
#else
    error_reporter->Report(o_label.c_str());
    delay(2000);
#endif
  } else if (kind == 2) {
    // error_reporter->Report("\n\r█ Lumos █\n\r");
    error_reporter->Report(
        "\n\r        *\n\r       *\n\r      *\n\r     *\n\r    "
        "*\n\r   *\n\r  *\n\r * * * * * * * *\n\r");
#if !XMAS_DEMO
    error_reporter->Report("\n\r");
    error_reporter->Report("╔══════════════════════╗");
    error_reporter->Report("║         Lumos        ║");
    error_reporter->Report("╚══════════════════════╝\n\r");
#else
    error_reporter->Report(l_label.c_str());
    error_reporter->Report("\r\nLet there be light\n\r"); 
    delay(3000);
    error_reporter->Report(dycodex_label.c_str());
    error_reporter->Report(asciiArt.c_str());
    delay(5000);
    error_reporter->Report(dycodex_logo.c_str());
    error_reporter->Report(tensorflow_logo.c_str());
    delay(8000);
#endif
  }
}
