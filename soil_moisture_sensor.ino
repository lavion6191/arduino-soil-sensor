// Import necessary libraries
#include <LiquidCrystal.h> // Library for LCD display
#include "Adafruit_seesaw.h" // Library for capacitive touch sensor

// Set the habitable temperature range in Celsius
const float HABITABLE_TEMP_MIN = -10.0;
const float HABITABLE_TEMP_MAX = 40.0;

// Set the habitable moisture range
const int HABITABLE_MOISTURE_MIN = 0;
const int HABITABLE_MOISTURE_MAX = 100;

// Set the capacitive range for 0% to 100% moisture
const int MOISTURE_START = 200;
const int MOISTURE_END = 1000;

// Set delays in milliseconds
const int INFO_DELAY = 2000; // Delay for displaying temperature and moisture values on the LCD
const int STATUS_DELAY = 2000; // Delay for displaying habitable status and moisture level on the LCD
const int END_DELAY = 2000; // Delay at the end of the loop

// Initialize the LCD and seesaw objects
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Initialize the LCD object with the necessary pins
Adafruit_seesaw ss; // Initialize the seesaw object for the capacitive touch sensor

// Set moisture level status strings
/*
const char * TOO_DRY = "Too Dry         ";
const char * DRY =     "Dry             ";
const char * OPTIMAL = "Optimal         ";
const char * WET =     "Wet             ";
const char * TOO_WET = "Too Wet         ";
*/
const char * TOO_DRY = "Moisture:   VLOW";
const char * DRY =     "Moisture:    LOW";
const char * OPTIMAL = "Moisture:    MED";
const char * WET =     "Moisture:   HIGH";
const char * TOO_WET = "Moisture:  VHIGH";


void setup() {
  Serial.begin(115200); // Start the serial monitor for debugging
  lcd.begin(16, 2); // Begin the LCD display with 16 columns and 2 rows
  lcd.print("Initializing"); // Print initializing message on the LCD

  // Initialize the seesaw object and print version to serial monitor
  if (!ss.begin(0x36)) { // Check if seesaw object initialization was successful
    Serial.println("ERROR! Seesaw not found"); // Print error message to serial monitor
    while (1) delay(1); // Loop indefinitely
  } else {
    Serial.print("Seesaw started! Version: "); // Print successful initialization message to serial monitor
    Serial.println(ss.getVersion(), HEX); // Print the version number of the seesaw object in hexadecimal format
  }
}

void loop() {
  // Read temperature and capacitive moisture values
  float tempC = ss.getTemp(); // Read the temperature in Celsius
  uint16_t capRead = ss.touchRead(0); // Read the capacitive moisture value
  Serial.print("Capacitive Moisture: ");
  Serial.println(capRead);

  // Display temperature and moisture readings on the LCD
  lcd.setCursor(0, 0); // Set the cursor to the first row and first column of the LCD
  if (tempC >= 100) {
    lcd.print("Temp:     "); // If temperature value is 3 digits long, print "Temp:" with 1 less space
  } else {
    lcd.print("Temp:      "); // If temperature value is 2 digits long, print "Temp:" with normal spacing
  }
  lcd.print(tempC, 1); // Display temperature with 1 decimal point
  lcd.print("C"); // Print the Celsius symbol after the temperature value

  int moisturePercent = map(capRead, MOISTURE_START, MOISTURE_END, 0, 100); // Map capacitance reading to percentage
  moisturePercent = constrain(moisturePercent, 0, 100); // Ensure percentage stays within 0-100
  lcd.print(moisturePercent); // Print the moisture percentage value

  // Adjust the spacing of the text depending on the value of moisturePercent
  if (moisturePercent >= 100) { // If moisturePercent is triple-digit
    uint16_t capRead = ss.touchRead(0); // Read the capacitive moisture value
    lcd.setCursor(0, 1);
    lcd.print("Moisture:   "); // Print with 2 spaces after the text
  } else if (moisturePercent < 100 && moisturePercent >= 10) { // If moisturePercent is double-digit
    uint16_t capRead = ss.touchRead(0); // Read the capacitive moisture value
    lcd.setCursor(0, 1);
    lcd.print("Moisture:    "); // Print with 1 space after the text
  } else if (moisturePercent < 10) { // If moisturePercent is single-digit
    uint16_t capRead = ss.touchRead(0); // Read the capacitive moisture value
    lcd.setCursor(0, 1);
    lcd.print("Moisture:     "); // Print with no space after the text
  }
  lcd.print(moisturePercent); // Print the moisture percentage
  lcd.print("%"); // Print the percentage sign

  // Display whether the environment is habitable or not
  delay(STATUS_DELAY);
  lcd.setCursor(0, 0);
  if (tempC >= HABITABLE_TEMP_MIN && tempC <= HABITABLE_TEMP_MAX && moisturePercent >= HABITABLE_MOISTURE_MIN && moisturePercent <= HABITABLE_MOISTURE_MAX ) {
    
    // lcd.print("HABITABLE       "); // Print if temperature is within the habitable range
    lcd.print("Stats:       HAB"); // Print if temperature is within the habitable range
  } else {
    // lcd.print("NOT HABITABLE   "); // Print if temperature is within the habitable range
    lcd.print("Stats:      NHAB"); // Print if temperature is outside the habitable range
  }

  // Display the moisture level status
  lcd.setCursor(0, 1);
  if (moisturePercent < 20) {
    lcd.print(TOO_DRY); // Print if moisturePercent is below 20
  } else if (moisturePercent < 40) {
    lcd.print(DRY); // Print if moisturePercent is between 20 and 40
  } else if (moisturePercent <= 60) {
    lcd.print(OPTIMAL); // Print if moisturePercent is between 40 and 60
  } else if (moisturePercent <= 80) {
    lcd.print(WET); // Print if moisturePercent is between 60 and 80
  } else {
    lcd.print(TOO_WET); // Print if moisturePercent is above 80
  }

  // Add a delay at the end of the loop
  delay(END_DELAY);
} // End of loop