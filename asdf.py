import serial
import matplotlib.pyplot as plt

# Configure the serial port
ser = serial.Serial('COM12', 115200, timeout=1)  # Replace 'COM12' with your Arduino's port

# Initialize real-time 2D plotting
plt.ion()
fig, ax = plt.subplots(figsize=(12, 10))

x_pos, y_pos = [], []  # Position data for X, Y
vel_x, vel_y = 0, 0    # Initial velocity for X, Y
pos_x, pos_y = 0, 0    # Initial position for X, Y
dt = 0.005  # Sampling interval in seconds for maximum responsiveness

def parse_acc_line(line):
    """Extract acceleration values from the serial input line."""
    try:
        if line.startswith("Acc:"):  # Only process lines starting with 'Acc:'
            data = line.split(":")[-1].strip()
            acc_values = [float(value.strip()) for value in data.split(",")]
            if len(acc_values) == 3:  # Ensure exactly 3 values (X, Y, Z)
                return acc_values
    except ValueError as e:
        print(f"ValueError while parsing: {line} -> {e}")
    except Exception as e:
        print(f"Unexpected error: {line} -> {e}")
    return None

# Configure 2D plot
line, = ax.plot([], [], label="Trajectory", color='orange', linewidth=1)
ax.set_xlim(-1000, 1000)  # X-axis range in cm
ax.set_ylim(-1000, 1000)  # Y-axis range in cm
ax.set_xlabel("Position X (cm)")
ax.set_ylabel("Position Y (cm)")
ax.legend()
ax.grid(True)

while True:
    try:
        # Read a line from the serial port
        line_input = ser.readline().decode('utf-8').strip()
        acc_data = parse_acc_line(line_input)  # Try to extract acceleration data
        if acc_data:
            print("Parsed Acc Data:", acc_data)  # Debugging parsed acceleration values

            # Gravity compensation
            acc_data[0] -= 0.03  # Remove small bias from X-axis
            acc_data[1] -= 0.03  # Remove small bias from Y-axis

            # Calculate velocity using acceleration
            vel_x += acc_data[0] * dt
            vel_y += acc_data[1] * dt

            # Calculate position using velocity (convert to cm)
            pos_x += vel_x * dt * 100  # Convert meters to centimeters
            pos_y += vel_y * dt * 100  # Convert meters to centimeters

            # Update position data lists
            x_pos.append(pos_x)
            y_pos.append(pos_y)

            # Limit the number of points
            if len(x_pos) > 200:  # Keep only the last 200 points for plotting
                x_pos.pop(0)
                y_pos.pop(0)

            # Update plot line
            line.set_data(x_pos, y_pos)
            ax.set_xlim(min(x_pos) - 10, max(x_pos) + 10)
            ax.set_ylim(min(y_pos) - 10, max(y_pos) + 10)

            plt.draw()
            plt.pause(0.001)  # Short pause for faster updates
        else:
            print("Non-numeric or irrelevant data:", line_input)
    except KeyboardInterrupt:
        print("Stopping...")
        break

ser.close()
