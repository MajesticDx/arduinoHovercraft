void BLE_RX (void)
{
if (SerialBT.available()){      // Daten liegen an
    Serial.println("nachricht");
    message = SerialBT.readString(); // Nachricht lesen
    Serial.println(message);
    kommando = message.toInt();

    switch(kommando) {
      case 1:
        if (valueESCg == 90) {
          valueESCg = 0;
        } else {
          valueESCg = 90;
        }
        break;
      case 2: 
        if (valueESCh >= 60) {
          valueESCh = 0;
        } else {
          valueESCh = 90;
        }
        break;
      case 3: 
        if (valueESCh >= 60) {
          valueESCh = 0;
        } else {
          valueESCh = 180;
        }
        break;
      case 4: 
        valueservo = 0;
        break;
      case 5: 
        valueservo = 125;
        break;
      case 6: 
        valueservo = 180;
        break;
      case 0:
        valueESCg = 0;
        valueESCh = 0;
        valueservo = 125;
        break;
      case 8:
        if (valueESCh >= 60) {
          valueESCh = 0;
        } else {
          valueESCh = 60;
        } 
        break;
      case 10: 
        valueservo = 120;
        break;
      case 11: 
        valueservo = 130;
        break;
      case 12: 
        valueservo = 135;
        break;
      case 13: 
        valueservo = 140;
        break;-
     }
    }
}

// M1dutyCycle = map(20,0,100,0,65535);
// M2dutyCycle = map(20,0,100,0,65535);