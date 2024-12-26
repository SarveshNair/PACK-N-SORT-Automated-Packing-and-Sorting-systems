# **Pack N’ Sort**

## **Project Overview**
**Pack N’ Sort** is an automated packaging and sorting system designed for small-scale businesses. The system aims to reduce operational costs, improve efficiency, and enhance sustainability. It automates key steps in the packaging process, such as taping and sorting, using conveyor belts, sensors, and actuators.

This project is divided into two main phases:
1. **Phase 1**: Automated packaging with tape dispensing and cutting mechanisms.
2. **Phase 2**: Automated sorting based on QR code detection.

---

## **Features**
### **Phase 1: Automated Packaging**
- Conveyor belt system to transport boxes.
- IR sensor to detect box position.
- DC motor-driven tape dispenser to seal boxes.
- Servo motor-controlled blade for cutting tape after sealing.
- Time-controlled conveyor stopping for precision.

### **Phase 2: Automated Sorting**
- Conveyor belt system to transport packages to the sorting station.
- MH ET LIVE QR scanner to read QR codes on packages.
- Sorting mechanism with 4 servo motors for directing packages to 3 predefined positions based on QR data.

---

## **Hardware Components**
### **Common Components**
- **Arduino Uno**: Microcontroller for system control.
- **L298 Motor Driver**: Controls DC motors for the conveyor belts.
- **12V DC Motors**: Drives the conveyor belts and tape dispenser.
- **Power Supply**: 12V and 5V SMPS.

### **Phase 1**
- **IR Sensor**: Detects boxes for tape dispensing.
- **Tape Dispenser**: Operated by a DC motor.
- **SG90 Servo Motor**: Controls the blade for tape cutting.

### **Phase 2**
- **MH ET LIVE QR Scanner**: Detects QR codes for sorting logic.
- **MG996R Servo Motors**: Direct packages to designated outputs.

---

## **Software Details**
- **Platform**: Arduino IDE
- **Libraries Used**:
  - Servo library for controlling servo motors.
  - SoftwareSerial library for communication with the QR scanner.

---

## **System Workflow**
### **Phase 1: Packaging Process**
1. A box is placed on the conveyor belt.
2. The IR sensor detects the box and starts the tape dispenser motor.
3. The tape is applied as the conveyor runs.
4. After 15 seconds, the conveyor stops, and a servo motor cuts the tape.
5. The conveyor resumes, moving the box to the next stage.

### **Phase 2: Sorting Process**
1. A package is placed on the second conveyor belt.
2. The MH ET LIVE QR scanner reads the QR code on the package.
3. Based on the QR code, servo motors adjust their position to direct the package to one of three predefined output directions.

---

## **Setup Instructions**
### **Hardware Setup**
1. Assemble the conveyor belts and mount the motors and sensors.
2. Connect the components to the Arduino and L298 motor driver as per the wiring diagram.
3. Ensure proper power supply for all components.

### **Software Setup**
1. Install the Arduino IDE on your computer.
2. Upload the respective Arduino sketches for Phase 1 and Phase 2 to the Arduino Uno.

---

## **Usage Instructions**
1. Power on the system using the main switches.
2. For **Phase 1**, place boxes on the first conveyor belt. The system will seal and cut the tape automatically.
3. For **Phase 2**, place packages on the second conveyor belt. The system will scan QR codes and sort the packages accordingly.

---

## **Testing and Results**
- **Phase 1**:
  - Successfully seals and cuts tape for boxes within 15 seconds.
- **Phase 2**:
  - Accurate QR code detection and sorting with over 95% accuracy.

---

## **Advantages**
- Cost-effective automation for small-scale businesses.
- Reduces manual labor and operational costs.
- Environmentally sustainable with reduced energy consumption.
- Scalable and adaptable to different business needs.

---

## **Limitations**
- Limited to three sorting positions in Phase 2.
- Requires precise calibration for sensors and motors.

---

## **Applications**
- Packaging and sorting in e-commerce fulfillment centers.
- Automated packaging for small-scale manufacturing.
- Inventory management in warehouses.

---

## **Future Scope**
- Expand the sorting capability to handle more positions.
- Integrate a display system for real-time process monitoring.
- Add IoT connectivity for remote operation and analytics.

---

## **Contributors**
- **Gunveer Kocchhar**  
- **Sarvesh Nair**  
- **Disha Karpe**  

**Supervisor**: Prof. Nirmal Thakur  

---

## **License**
This project is licensed under the [MIT License](LICENSE).

---
