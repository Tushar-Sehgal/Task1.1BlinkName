const char* morseCode[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void outputMorseCode(const char* morse) {
  for (int i = 0; morse[i] != '\0'; i++) {
    if (morse[i] == '.') {
      // Dot
      digitalWrite(LED_BUILTIN, HIGH); // Turn on LED
      delay(500); // Dot duration
      digitalWrite(LED_BUILTIN, LOW); // Turn off LED
      delay(1500); // Inter-element gap
    } else if (morse[i] == '-') {
      // Dash
      digitalWrite(LED_BUILTIN, HIGH); // Turn on LED
      delay(1500); // Dash duration
      digitalWrite(LED_BUILTIN, LOW); // Turn off LED
      delay(1500); // Inter-element gap
    }
  }
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Enter Your First Name:");
  char name = toupper(Serial.read());
  // Wait for user input
  while(!Serial.available());

  // Print the input character
  Serial.print("You entered: ");
  Serial.println(name);
  if (name >= 'A' && name <= 'Z') {
    // Get the index of the input character in the Morse code array
    int index = name - 'A';
    // Output the Morse code for the input character
    outputMorseCode(morseCode[index]);
  } else {
    // Output an error message for unsupported characters
    Serial.println("Character not supported");
  }
}
