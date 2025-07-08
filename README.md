Wireless Sensor Network for Disaster Management

Overview

This project implements a Wireless Sensor Network (WSN) designed for disaster management and early warning systems. The system uses various sensors to monitor environmental conditions such as water levels, seismic activity, temperature, humidity, atmospheric pressure, and gas levels. Data is transmitted wirelessly to a central station for real-time analysis, enabling early detection of natural and industrial disasters and facilitating timely alerts to authorities and residents.

Features





Real-Time Monitoring: Continuously tracks environmental parameters for early disaster detection.



Multi-Hazard Detection: Integrates monitoring for floods, earthquakes, extreme weather, and hazardous gases.



Wireless Communication: Uses ESP-01 RF modules for seamless data transmission.



Scalability: Easily expandable to cover larger areas or include additional sensors.



Alert System: Activates a buzzer and sends alerts when thresholds for hazardous conditions are exceeded.

Hardware Components





Arduino Uno



Water Level Sensor



Temperature and Humidity Sensor (DHT11)



Atmospheric Pressure Sensor



Gas Sensor



Accelerometer (MPU6050)



Ultrasonic Sensor



LCD Display



Buzzer



LED Indicators



ESP-01 RF Modules (Wi-Fi chip)



Connecting Wires



PCB

Software Components





Arduino IDE: For programming and uploading code to the Arduino.



Arduino-C: Core programming language for sensor data processing and system logic.

Installation





Hardware Setup:





Connect the sensors, LCD, buzzer, and ESP-01 module to the Arduino Uno as per the block diagram (refer to the project documentation).



Ensure proper wiring and secure connections on the PCB.



Software Setup:





Install the Arduino IDE from arduino.cc.



Install required libraries:





LiquidCrystal for LCD display.



DFRobot_DHT11 for temperature and humidity sensor.



Adafruit_MPU6050 and Adafruit_Sensor for accelerometer.



Upload the provided Arduino code to the Arduino Uno.



Configuration:





Configure the ESP-01 module for wireless communication with the central station.



Set threshold values in the code for alerts (e.g., temperature > 37°C, gas level > 500).

Usage





Power on the system.



The sensors will begin monitoring environmental parameters (temperature, humidity, gas levels, distance, and acceleration).



Data is displayed on the LCD and transmitted wirelessly to the central station.



If any parameter exceeds the defined threshold (e.g., high acceleration, low distance, or high gas levels), the buzzer will activate, and alerts will be sent.



Periodically, data is logged for remote monitoring (every 15 cycles, as defined in the code).

Code

The provided Arduino code initializes the sensors, reads environmental data, and triggers alerts when thresholds are exceeded. Key features include:





Real-time sensor data display on the LCD.



Buzzer activation for immediate alerts.



Periodic data transmission for remote monitoring.

Applications





Flood Monitoring: Deploy in flood-prone areas to detect rising water levels and issue early warnings.



Earthquake Detection: Monitor seismic activity in earthquake-prone regions.



Industrial Safety: Detect hazardous gas leaks in industrial environments.



Weather Monitoring: Track extreme weather conditions for timely alerts.

Advantages





Early Detection: Provides real-time alerts to mitigate disaster impact.



Integrated System: Combines multiple hazard monitoring into a single network.



Scalable Design: Adaptable to various environments and disaster types.

Limitations





Requires stable power and network connectivity for continuous operation.



Limited range of wireless communication depending on the ESP-01 module.



Thresholds need calibration based on specific environmental conditions.

References





Kaur, Harminder, et al. "Wireless sensor networks for disaster management." International Journal of Advanced Research in Computer Engineering & Technology 1, no. 5 (2012): 2278-1323.



Changnon, Stanley A., and Misganaw Demissie. "Detection of changes in streamflow and floods resulting from climate fluctuations and land use-drainage changes." Climatic Change 32, no. 4 (1996): 411-421.



Tan, Qiulin, et al. "Three-gas detection system with IR optical sensor based on NDIR technology." Optics and Lasers in Engineering 74 (2015): 103-108.
