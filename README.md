# Smart Cane with Voice Guidance

## Overview
This Arduino-based smart cane assists visually impaired individuals by detecting obstacles and providing voice-guided navigation. It uses an ultrasonic sensor to detect objects and gives directional guidance through a speaker or headphones.

## Features
- **Obstacle Detection**: Uses an ultrasonic sensor to detect objects in front of the user.
- **Voice Guidance**: Uses the Talkie library to provide audio instructions.
- **Buzzer Alerts**: Emits a sound when an obstacle is detected.
- **Directional Assistance**: Checks left and right for possible paths and provides navigation instructions.
- **Serial Debugging**: Prints distance readings and system logs for troubleshooting.

## Hardware Requirements
- **Arduino Board** (Uno, Mega, Nano, etc.)
- **Ultrasonic Sensor** (HC-SR04)
- **Passive Buzzer**
- **TRRS Audio Output Module**
- **Speaker or Headphones**

## Wiring Diagram
| Component        | Arduino Pin |
|-----------------|-------------|
| Ultrasonic TRIG | 6           |
| Ultrasonic ECHO | 7           |
| Buzzer         | 12          |
| Audio Output   | 4           |

## Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/yourusername/smart-cane.git
   ```
2. Open the project in the Arduino IDE.
3. Install the **Talkie** library if not already installed.
4. Connect the hardware components as per the wiring diagram.
5. Upload the `TalkieVocabularyDemo.cpp` file to your Arduino board.
6. Open the Serial Monitor to debug and view distance readings.

## How It Works
1. The ultrasonic sensor continuously measures the distance to obstacles.
2. If an obstacle is detected within **30 cm**:
   - The buzzer activates.
   - The system checks the **left** side. If clear, it says "Proceed."
   - If left is blocked, it checks the **right** side. If clear, it says "Proceed."
   - If both sides are blocked, no further action is taken.
3. The voice output guides the user to navigate safely.

## Debugging
Use the Serial Monitor (set to **9600 baud rate**) to see:
- Distance readings
- Voice output messages
- Obstacle detection status

## Future Improvements
- Add Bluetooth connectivity for wireless audio feedback.
- Implement AI-based object recognition.
- Integrate GPS for location tracking.

## License
This project is licensed under the **GNU General Public License v3.0**. See the LICENSE file for details.

---
Developed by **raizengxd** 🚀

