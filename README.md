# Real-time Lidar Data Processing and Mapping for Autonomous Vehicles

## Project Overview
This project implements real-time Lidar data processing and mapping for autonomous vehicles using the ESP32 microcontroller and SLAM (Simultaneous Localization and Mapping) algorithms. The system leverages the capabilities of the ESP32 to collect, transmit, and process Lidar data in real-time, facilitating safe navigation for autonomous vehicles. The project report and source code are included for further insights.

## Table of Contents
- [Objectives](#objectives)
- [Components](#components)
- [Installation](#installation)
- [Usage](#usage)
- [Future Scope](#future-scope)

## Objectives
- **Lidar Data Processing**: Collect and preprocess Lidar data using the ESP32 for real-time applications.
- **Mapping and Navigation**: Implement SLAM for precise mapping and path planning.
- **Data Transmission**: Utilize WiFi to send processed Lidar data from the ESP32 to a computer for further SLAM processing in ROS.

## Components
- **ESP32 Microcontroller**: A low-power microcontroller for Lidar data processing and WiFi communication.
- **YDLidar X2**: A 2D Lidar sensor for capturing point cloud data.
- **ROS (Robot Operating System)**: A flexible framework for running SLAM algorithms and visualizing mapping results.
- **Ubuntu 20.04**: The operating system on which ROS and SLAM algorithms run.

## Installation

### Prerequisites
1. **Arduino IDE** for programming the ESP32.
2. **Python** for running any ROS Python scripts.
3. **ROS** (Robot Operating System) installed on Ubuntu 20.04.

### Setting Up the ESP32 Code
1. Open `code/lidar_data_processing.ino` in Arduino IDE.
2. Install necessary libraries (e.g., `WiFi`, `ESP32Servo`) in Arduino IDE.
3. Connect the ESP32 to your computer and upload the sketch.

### Setting Up the ROS Environment
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/LIDAR-Data-Processing-Autonomous-Vehicles.git

## Usage
1. Connect the YDLidar X2 to the ESP32 and ensure it is powered on.
2. Run the ESP32 code to start collecting and processing Lidar data.
3. Launch the ROS nodes for SLAM
4. Visualize the mapping results using RViz or any other preferred tool.

### Future Scope
1. Integration with additional sensors (e.g., cameras, ultrasonic sensors) for enhanced environmental perception.
2. Development of advanced navigation algorithms for improved path planning.
3. Optimization of the data processing pipeline for real-time performance on low-power devices.


[System Design Image](https://github.com/user-attachments/assets/0cf5b1a5-dcdc-42eb-94f0-bfde31ff3000)

[Transform Tree image](https://github.com/user-attachments/assets/a30aa614-c76b-4fa9-9ccb-83f6af30965d)

[Slam image](https://github.com/user-attachments/assets/d9b0eb00-d8ec-4341-8b7c-6e8142621d70)


↓Prototype image↓
![Prototype image](https://github.com/user-attachments/assets/d7d24d2a-93b5-43f7-9928-ebcb7b0d6aea)








