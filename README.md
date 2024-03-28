# Field Rover: Autonomous Food Delivery Vehicle for Open Spaces

The successful implementation of a GPS-controlled 4-wheel autonomous robot opens up several promising scopes across various domains. Autonomous robots equipped with GPS navigation can be employed in open spaces for efficient emergency food and medicine supply, reducing the need for manual labor. These robots can patrol autonomously, covering designated paths and providing real-time data. Autonomous mobile robots are self-operated vehicles that do not require any command from the operator. The movement is predefined, and the robot navigates according to the predefined coordinates. These robots have various applications.

## System Design

![Field Rover System Design](https://github.com/sunzidulislam/Autonomous-CAR-System-project-/assets/60359567/bb462654-4530-4a67-8d2f-fc3a1c9a0dc7)

![Field Rover Components](https://github.com/sunzidulislam/Autonomous-CAR-System-project-/assets/60359567/c899c367-e31d-475c-a2aa-10d883bd754b)

## Components Used

This project utilizes the following components:

- Arduino Uno R3 (ARD-00028)
- GPS Module U-Blox Neo M8NC
- HMC5883L electronic compass
- Motor Driver L298N
- Wheels (130*60 mm)
- Lipo Battery (12V)
- HC-05 Bluetooth Module

## Project Implementation

### Distance Measurement using Haversine Formula

The Haversine formula is used to calculate the distance between two coordinates on Earth's surface. It takes into account the curvature of the Earth and provides accurate distance calculations. The formula used in this project is:

\[ d = 2R \sin^{-1}\left(\sqrt{\sin^2\left(\frac{\phi_2 - \phi_1}{2}\right) + \cos(\phi_1)\cos(\phi_2)\sin^2\left(\frac{\lambda_2 - \lambda_1}{2}\right)}\right) \]

Where:
- \( d \) is the distance between two coordinates
- \( R \) is the radius of the Earth (approximately 6371 km or 3961 miles)
- \( \phi_1, \phi_2 \) are the latitudes of point 1 and point 2 respectively
- \( \lambda_1, \lambda_2 \) are the longitudes of point 1 and point 2 respectively

### Heading Angle Calculation

The heading angle between two coordinates is calculated using the following formula:

\[ h = \text{atan2}\left(\sin(\lambda_2 - \lambda_1) \cdot \cos(\phi_2), \cos(\phi_1)\sin(\phi_2) - \sin(\phi_1)\cos(\phi_2)\cos(\lambda_2 - \lambda_1)\right) \]

Where:
- \( h \) is the heading angle
- \( \phi_1, \phi_2 \) are the latitudes of point 1 and point 2 respectively
- \( \lambda_1, \lambda_2 \) are the longitudes of point 1 and point 2 respectively
