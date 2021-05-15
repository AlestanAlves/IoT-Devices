import network 
import machine
from time import sleep_ms
from urequests import get
from config import ssid, password

def connect_wifi():
    station = network.WLAN(network.STA_IF)
    if station.isconnected() == True:
        return
    station.active(True)
    station.connect(ssid, password)
    i = 0
    while station.isconnected() == False:
        sleep_ms(100)
        i += 1
        if(i == 100):
            machine.reset()
        pass
    print('Connected to wifi')

connect_wifi()