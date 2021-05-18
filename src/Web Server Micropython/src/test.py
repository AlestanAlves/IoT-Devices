import network 
import machine
from time import sleep_ms
import socket
from urequests import get
from config import ssid, password

def connect_wifi():
    station = network.WLAN(network.STA_IF)
    station.active(True)
    station.connect(ssid, password)
    if station.isconnected() == False:
        print('Connected refused...')
        pass

    print('Connected to wifi')
    
print(sta_if.isconnected())

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

        </body>
    </html>
     """
    return html

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
orig = ('',80)
tcp.bind(orig)
tcp.listen(5)

while True:
    conn, addr = tcp.accept()
    print('New Connection in API' % str(addr))
    request = conn.recv(1024)
    print('Request' % str(request))
    response = web_page()
    conn.send('HTTP/1.1 200 OK\n')
    conn.send('Content-Type: text/html\n')
    conn.send('Connection: close\n\n')
    conn.sendall(response)
    conn.close()