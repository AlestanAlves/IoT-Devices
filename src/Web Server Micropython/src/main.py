import network 
import machine
from time import sleep_ms
import socket
from urequests import get
from config import ssid, password

led = machine.Pin(2, machine.Pin.OUT)

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
    print(station.ifconfig())

def web_page():
    html = """
    <html lang="en">
        <head>
            <meta charset="UTF-8">
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Eea</title>
        </head>
        <body>
            <h1>API</h1>
            <img src="https://user-images.githubusercontent.com/48387196/118347983-85e52c80-b51d-11eb-8717-0b2ec65053fc.png" alt="img1">
        </body>
    </html>
     """
    return html

connect_wifi()
tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
orig = ('', 80)
tcp.bind(orig)
tcp.listen(5)

try:
    while True:
        led.on()
        conn, addr = tcp.accept()
        print('New Connection in API', str(addr))
        request = conn.recv(1024)
        print('Request', str(request))
        response = web_page()
        conn.send('HTTP/1.1 200 OK\n')
        conn.send('Content-Type: text/html\n')
        conn.send('Connection: close\n\n')
        conn.sendall(response)
        conn.close()
except:
    led.off()
    sleep_ms(5 * 1000)  # 5 seconds
    machine.reset()