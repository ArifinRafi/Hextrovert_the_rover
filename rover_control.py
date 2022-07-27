import serial, keyboard
car = serial.Serial("/dev/cu.usbmodem14201", 9600)
while True:
    if keyboard.is_pressed('w'):
        car.write(b'w')
    elif keyboard.is_pressed('s'):
        car.write(b's')
    elif keyboard.is_pressed('d'):
        car.write(b'd')
    elif keyboard.is_pressed('a'):
        car.write(b'a')
    elif keyboard.is_pressed('x'):
        car.write(b'x')
