import serial
from pynput import keyboard
car = serial.Serial("COM3", 9600)

def on_press(key):
    try:
        if key.char == 'w':
            car.write(b'w')
            print("Going Forward...")
        elif key.char == 's':
            car.write(b's')
            print("Going Backward...")
        elif key.char == 's':
            car.write(b's')
            print("Turning Left...")
        elif key.char == 's':
            car.write(b's')
            print("Turning Right...")
        elif key.char == 's':
            print("STOP!")
    except:
        pass

def on_release(key):
    car.write(b's')
    print("STOP!")


# Collect events until released
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()
