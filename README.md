<img src="https://img.shields.io/badge/version-1.0.0-success?style=flat" height=25px href="#"/> <img src="https://img.shields.io/badge/language-C-blue?style=flat" height=25px href="#"/> <img src="https://img.shields.io/badge/chip-ATMega16-orange?style=flat" height=25px href="#"/>

<h2>Project 1 - Timers and Clocks</h2>

<b>Part 1 - Toggle Pin by Clock</b>
<ul>
  <li>Toggle PORTA.0 to 0 and 1 every 0.5 seconds</li>
  <li>Using ATMega16 and clock frequency has been set to 12.000000Mhz</li>
</ul>

<br><b>Part 2 and 3 - 8 LED Controller using ATMega16</b>
<ul>
  <li>Enables LED #1 to #8 respectively as the PINA.0 of ATMega16 changes to 1. This loop will continue as far as the PINA.0 stays 1</li>
  <li>P.S: There is a delay (0.5 seconds) to be able to detect the procedure of the circuit</li>
</ul>

![alt text](https://i.postimg.cc/jdf9D1st/image.png)

<br><b>Part 4 - AVR Micro-Controller Clock</b>
<ul>
  <li>Information about AVR micro-controller’ clock details</li>
  <li>Represents a couple of data about its internal clock</li>
</ul>

<br><b>Part 5 - LED Currents and Resistance</b>
<ul>
  <li>Forward current and maximum current in LEDs</li>
  <li>How to calculate their resistance</li>
</ul>
<br>

<h2>Project 2 - 7 Segments</h2>

<b>Part 1 - Single 7 Segment Counter</b>
<ul>
  <li>Count from 0 to 9 and display the number on a single 7 segment</li>
  <li>Using delay.h library to have some delays between counting</li>
</ul>

<br><b>Part 2 - Multiple 7 Segment Counter</b>
<ul>
  <li>Count from 0 to 9999 using four 7 segments</li>
  <li>Using only 11 pins to control the 7 segments instead of 28 pins</li>
  <li>Enables and disables the 7 segments respectively</li>
  <li>Counting procedure is done using avr timer0 and timer1</li>
  <li>P.S: To count like real clock, there should be some calculations to set the best amount for timer1 overflow</li>
</ul>

![alt text](https://i.postimg.cc/8PvRDBtF/image.png)
<br>

<h2>Project 3 - Alphanumeric LCD</h2>

<b>Part 1 - Hello World on a LCD</b>
<ul>
  <li>Shows "Hello World" on an alphanumeric LCD</li>
</ul>

![alt text](https://i.postimg.cc/Y0PTxmF4/image.png)
<br>

<b>Part 2 - English Letters on LCD</b>
<ul>
  <li>Show all English letters on an alphanumeric LCD</li>
  <li>Uses timer1 and its overflow to generate some delays</li>
  <li>All letters will be shown in two lines</li>
</ul>

![alt text](https://i.postimg.cc/y8vgWB3b/English-Letters.gif)
<br>

<b>Part 3 - Pulse Frequency Calculator</b>
<ul>
  <li>Calculates pulse frequency using input capture mode pin</li>
  <li>Shows the frequency on the LCD</li>
</ul>

![alt text](https://i.postimg.cc/TPGvJqNj/image.png)
<br>

<h2>Project 4 - PCB</h2>

<a> Generated a PCB model for <b>Project 2 - Part 2</b> task</a>

![alt text](https://i.postimg.cc/pLXsYtGh/image.png)
<br>
