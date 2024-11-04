# Real-time Lidar Data Processing and Mapping for Autonomous Vehicles

## Project Overview
This project aims to implement real-time Lidar data processing and mapping for autonomous vehicles using ESP32 and SLAM algorithms. The system leverages ESP32 microcontroller capabilities to collect, transmit, and process Lidar data in real-time, facilitating safe navigation for autonomous vehicles. The project report and source code are included.

### Table of Contents
- [Project Overview](#project-overview)
- [Objectives](#objectives)
- [Components](#components)
- [Installation](#installation)
- [Usage](#usage)
- [Folder Structure](#folder-structure)
- [Future Scope](#future-scope)
- [License](#license)

## Objectives
- **Lidar Data Processing**: Collect and preprocess Lidar data using ESP32 for real-time applications.
- **Mapping and Navigation**: Implement SLAM for precise mapping and path planning.
- **Data Transmission**: Use WiFi to send processed Lidar data from ESP32 to a computer for further SLAM processing in ROS.

## Components
- **ESP32 Microcontroller**: Low-power microcontroller for Lidar data processing and WiFi communication.
- **YDLidar X2**: 2D Lidar sensor for capturing point cloud data.
- **ROS (Robot Operating System)**: For running SLAM and visualizing mapping results.
- **Ubuntu 20.04**: Operating system for ROS and SLAM algorithms.

## Installation

### Prerequisites
1. **Arduino IDE** for ESP32 programming.
2. **Python** for any ROS Python scripts.
3. **ROS** (Robot Operating System) with Ubuntu 20.04.

### Setting Up the ESP32 Code
1. Open `code/lidar_data_processing.ino` in Arduino IDE.
2. Install necessary libraries (e.g., `WiFi`, `ESP32Servo`) in Arduino IDE.
3. Connect the ESP32 to the computer and upload the sketch.

### Setting Up the ROS Environment
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/LIDAR-Data-Processing-Autonomous-Vehicles.git


[System Design Image](https://github.com/user-attachments/assets/0cf5b1a5-dcdc-42eb-94f0-bfde31ff3000)

