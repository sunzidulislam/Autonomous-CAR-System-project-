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

    ℎ𝑎𝑣𝑒𝑟𝑠𝑖𝑛 (𝑑/2𝑅) = ℎ𝑎𝑣𝑒𝑟𝑠𝑖𝑛(∅2 − ∅2 ) + cos(∅1 ) cos(∅2 ) ℎ𝑎𝑣𝑒𝑟𝑠𝑖𝑛(𝜆2 – 𝜆1)
   
    𝑑 = 2𝑅 sin-1 (√𝑠𝑖𝑛2 (∅2−∅1/ 2) + cos(∅1) cos(∅2 ) 𝑠𝑖𝑛2 ( 𝜆2− 𝜆1/ 2 ) ) 
   
      Here,
         d is the distance between two co-ordinates, 
         R is the radius of earth i.e. 6371 km or 3961 miles
         ∅1, ∅2 are latitudes of point 1 and latitude of point 2 
         𝜆1, 𝜆2 are longitude of point 1 and longitude of point 2 

### Heading Angle Calculation

     ℎ = 𝑎𝑡𝑎𝑛2(sin(𝜆2 – 𝜆1 ) cos(∅2 ) , cos(∅1) sin(∅2) − sin(∅1) cos(∅2) cos(𝜆2− 𝜆1))
  
                  Here, h is the heading, 
                   ∅1, ∅2 are latitudes of point 1 and latitude of point 2,
                  𝜆1, 𝜆2 are longitude of point 1 and longitude of point 2. 
