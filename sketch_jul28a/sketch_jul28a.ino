// Initialising variables
const int TEMP_PIN = A5;
const int SEL1_PIN = 3;
const int SEL2_PIN = 4;
const int HA_PIN = 5;
const int HB_PIN = 6;
const int D1_PIN = 8;
const int D2_PIN = 9;
const int D3_PIN = 10;
const int D4_PIN = 11;
const int ADD_PIN = 12;
const int SUB_PIN = 13;


void setup() {
  // put your setup code here, to run once:

  pinMode(TEMP_PIN, INPUT); // ANALOG INPUT
  
  pinMode(HA_PIN, OUTPUT);   // Configure the pin as an output
  digitalWrite(HA_PIN, LOW); // Initially set to LOW
  
  pinMode(HB_PIN, OUTPUT);   // Configure the pin as an output
  digitalWrite(HB_PIN, LOW); // Initially set to LOW
  
  pinMode(SEL1_PIN, OUTPUT);   // Configure the pin as an output
  digitalWrite(SEL1_PIN, LOW); // Initially set to LOW
  
  pinMode(SEL2_PIN, OUTPUT);   // Configure the pin as an output
  digitalWrite(SEL2_PIN, LOW); // Initially set to LOW

  pinMode(D1_PIN, OUTPUT);   // Configure the pin as an output
  digitalWrite(D1_PIN, LOW); // Initially set to LOW

  pinMode(D2_PIN, OUTPUT);   // Configure the pin as an output
  digitalWrite(D2_PIN, LOW); // Initially set to LOW

  pinMode(D3_PIN, OUTPUT);   // Configure the pin as an output
  digitalWrite(D3_PIN, LOW); // Initially set to LOW

  pinMode(D4_PIN, OUTPUT);   // Configure the pin as an output
  digitalWrite(D4_PIN, LOW); // Initially set to LOW

  pinMode(ADD_PIN, INPUT);   // Configure the pin as an input
  digitalWrite(ADD_PIN, LOW); // Initially set to LOW

  pinMode(SUB_PIN, INPUT);   // Configure the pin as an input
  digitalWrite(SUB_PIN, LOW); // Initially set to LOW

}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = get_temp();

  //Get tens and ones
  int tens = 0;
  int ones = 0;
  while (temp >= 10.0) {
    tens += 1;
    temp -= 10.0;
  }
  ones = (int)temp;
  
  //TESTING DEBUG
  tens = 5;
  //REMOVE DEBUG
  
  display_all(ones, tens);

  //if ()

}

float get_temp() {
  int adc_temp = analogRead(TEMP_PIN);

  //Do math here to convert into deg C

  //Return deg C
  return 10.0;
}


void display_seg(int value) {
  //Sends out decoders input
  int binary_array[] = {0, 0, 0, 0};
  if (value == 1) {
    binary_array[3] = 1;
    
  } else if (value == 2) {
    binary_array[2] = 1;
    
  } else if (value == 3) {
    binary_array[3] = 1;
    binary_array[2] = 1;
    
  } else if (value == 4) {
    binary_array[1] = 1;
    
  } else if (value == 5) {
    binary_array[1] = 1;
    binary_array[3] = 1;
    
  } else if (value == 6) {
    binary_array[1] = 1;
    binary_array[2] = 1;
    
  } else if (value == 7) {
    binary_array[1] = 1;
    binary_array[2] = 1;
    binary_array[3] = 1;
    
  } else if (value == 8) {
    binary_array[0] = 1;
    
  } else if (value == 9) {
    binary_array[0] = 1;
    binary_array[3] = 1;
    
  }

  //Output value on 7 seg
  if (binary_array[0] == 1) {
    digitalWrite(D1_PIN, HIGH);
    
  } else if (binary_array[1] == 1) {
    digitalWrite(D2_PIN, HIGH);
    
  } else if (binary_array[2] == 1) {
    digitalWrite(D3_PIN, HIGH);
    
  } else if (binary_array[3] == 1) {
    digitalWrite(D4_PIN, HIGH);
    
  }
}

void clear_seg() {
  digitalWrite(D1_PIN, LOW);
  digitalWrite(D2_PIN, LOW);
  digitalWrite(D3_PIN, LOW);
  digitalWrite(D4_PIN, LOW);
}

void display_all(int ones, int tens) {
  //Multiplex 7 Seg displays
  //clear_seg();

  //Checks if value is single or double digit
  if (tens == 0) {
    digitalWrite(SEL1_PIN, LOW);
    digitalWrite(SEL2_PIN, LOW);
  } else {
    digitalWrite(SEL1_PIN, HIGH);
    digitalWrite(SEL2_PIN, LOW);
  }
  display_seg(tens);
  
  digitalWrite(SEL1_PIN, LOW);
  digitalWrite(SEL2_PIN, HIGH);
  display_seg(ones);

  
}
