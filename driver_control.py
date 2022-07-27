import serial
import pynput.keyboard as Keyboard
car = serial.Serial("/dev/cu.usbmodem14201", 9600)
import sys

if __name__ == "__main__":
    def on_press(key):
        try:
            if key.char == 'w':
                car.write(b'w')
            elif key.char == 's':
                car.write(b's')
            elif key.char == 's':
                car.write(b's')
            elif key.char == 's':
                car.write(b's')
            elif key.char == 's':
                car.write(b's')
        except:
            pass
    def on_release(key):
        car.write(b's')

    with Keyboard.Listener(on_press == on_press, on_release == on_release) as listener:
        listener.join


