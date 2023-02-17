<h1>Arduino UNO Plant Moisture and Temperature Monitor</h1>
<p>
  This is an Arduino UNO project that allows you to monitor the moisture level and temperature of a plant. 
  The project uses a capacitive touch sensor to measure the moisture level of the soil, and a temperature sensor to measure the temperature of the environment. 
  The data is displayed on a 16x2 LCD screen.
</p>

<h2 id="table-of-contents">Table of Contents</h2>
<ol>
  <li><a href="#table-of-contents">Table of Contents</a></li>
  <li><a href="#getting-started">Getting Started
    <ul>
      <li><a href="#prerequisites">Prerequisites</a></li>
      <li><a href="#libraries">Libraries</a></li>
    </ul>  
  </a></li>
  <li><a href="#installation">Installation</a></li>
  <li><a href="#usage">Usage</a></li>
  <li><a href="#code-overview">Code Overview</a></li>
  <li><a href="#setup">Setup</a></li>
  <li><a href="#loop">Loop</a></li>
  <li><a href="#customization">Customization</a></li>
  <li><a href="#license">License</a></li>
  <li><a href="#acknowledgement">Acknowledgement</a></li>
</ol>


<h2 id="getting-started">Getting Started</h2>


<h3 id="prerequisites">Prerequisites</h3>

<p>To use this project, you'll need the following items</p>
<ol>
  <li>An <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/ref=sr_1_1?keywords=arduino%2Buno&qid=1676666059&sr=8-1&th=1">Arduino UNO</a> board</li>
  <li>A <a href="https://www.amazon.com/Adafruit-4026-Stemma-Soil-Sensor/dp/B07M7PNVG7">capacitive touch sensor</a></li>
  <li>A <a href="https://www.amazon.com/Adafruit-4026-Stemma-Soil-Sensor/dp/B07M7PNVG7">temperature sensor</a></li>
  <li>A 16x2 <a href="https://www.digikey.se/sv/products/detail/displaytech/162J%2520CC%2520BC-3LP/10494906?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Zombie%20DKU&utm_term=&productid=10494906">162J CC BC-3LP</a> LCD screen</li>
  <li>Jumper wires</li>
</ol>

<h3 id=libraries>Libraries</h3>
<p>The code uses two libraries.</p>
<ul>
  <li><a href="https://reference.arduino.cc/reference/en/libraries/liquidcrystal/">LiquidCrystal.h</a>: A library for controlling LCD screens.</li>
  <li><a href="https://github.com/adafruit/Adafruit_Seesaw">Adafruit_seesaw.h</a>: A library for the capacitive touch sensor.</li>
</ul>

<h2 id="installation">Installation</h2>
<p>To get started with this project, you can simply download the code from the repository and upload it to your Arduino board.</p>
<ol>
  <li>Download the project code from this <a href="https://github.com/lavion6191/arduino-soil-sensor/releases">repository</a>. Or you can get it with <br> <code>git clone https://github.com/lavion6191/arduino-soil-sensor.git</code></li>
  <li>Open the </a href="https://www.arduino.cc/en/software">Arduino IDE</a> on your computer.</li>
  <li>Connect your Arduino board to your computer using a USB cable.</li>
  <li>Open the project code in the Arduino IDE.</li>
  <li>Click the "Upload" button in the Arduino IDE to upload the code to your Arduino board.</li>
  <li>Once the code is uploaded, you can disconnect the USB cable from your computer and the Arduino board.</li>
</ol>

<h2 id="usage">Usage</h2>
To use the Plant Moisture and Temperature Monitor, simply connect the capacitive touch sensor, temperature sensor, and LCD screen to your Arduino board using the jumper wires.
<br>
Once everything is connected, you can power on your Arduino board and the LCD screen will display the temperature and moisture level of the plant.

<h2 id="code-overview">Code Overview</h2>
The code for this project is written in <a href="https://www.w3schools.com/cpp/#:~:text=C%2B%2B%20is%20a%20popular%20programming,used%20language%20in%20game%20development.">C++</a> and is designed to run on an Arduino UNO board. The code is divided into two main functions: setup() and loop().

<h2 id="setup">Setup</h2>
The setup() function is called once when the Arduino board is powered on. It initializes the LCD screen and the capacitive touch sensor, and prints a message on the LCD screen to indicate that the system is initializing. If there are any errors during initialization, the function will print an error message to the serial monitor and loop indefinitely.

<h2 id="loop">Loop</h2>
The loop() function is called continuously while the Arduino board is powered on. It reads the temperature and moisture level values from the sensors and displays them on the LCD screen. It also determines whether the environment is habitable or not based on the temperature and moisture level values.

<h2 id="customization">Customization</h2>
You can customize this project by adjusting the habitable temperature and moisture ranges in the code. You can also adjust the delays for displaying information on the LCD screen, and change the status messages for different moisture levels.

<h2 id="license">License</h2>
This project is licensed under the <a href="https://github.com/lavion6191/arduino-soil-sensor/blob/main/LICENSE.md">MIT License</a> - see the <a href="https://github.com/lavion6191/arduino-soil-sensor/blob/main/LICENSE.md">LICENSE</a> file for details.

<h2 id="acknowledgements">Acknowledgments</h2>
<p>
  We would like to express our gratitude to Niklas Hallgren and Hawar Hussein for their guidance and support throughout the development of the project. 
  Their expertise and insights were invaluable in helping us achieve our goals.
</p>
<p>
  We would also like to thank our classmates in class TE21, who provided us with valuable feedback and support throughout the project. 
  In particular, we would like to thank the members of our group who worked tirelessly to test the sensor, setup the jumpers, and writing our presentation and documents.
</p>
<p>
Finally, we would like to express our appreciation to the gymnasium NTI Sollentuna for providing us with the resources and facilities necessary to complete this project. 
  Without their support, this project would not have been possible.
</p>
