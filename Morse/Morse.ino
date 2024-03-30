// Morse code representations
const char* morseCode[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Flag indicating whether the system is waiting for user input
bool isWaitingForInput = true;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

// Function to output Morse code representation of an alphabet
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

void loop() {
  // Delay to separate two sequences and for providing time to open serial monitor
  delay(5000);
  if (isWaitingForInput){
    Serial.println("Enter Your First Name:");
    isWaitingForInput = false;
  }
  if (Serial.available() > 0) {
    // Read user input
    String name = Serial.readStringUntil('\n');
    name.toUpperCase();
    // Print user input
    Serial.print("You entered: ");
    Serial.println(name);
    Serial.println("Displaying your name on Arduino");
    // Display user input in Morse
    for (int i = 0; i < name.length(); i++) {
      if (name[i] >= 'A' && name[i] <= 'Z') {
        int index = name[i] - 'A';
        outputMorseCode(morseCode[index]);
      } else {
        Serial.println("Character not supported");
      }
    }
    // Set flag to waiting for input again
    isWaitingForInput = true;
  }
}
