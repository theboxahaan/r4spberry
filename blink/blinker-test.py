import time
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(42,GPIO.OUT)
GPIO.output(42, GPIO.HIGH)
time.sleep(2)
GPIO.output(42, GPIO.LOW)

