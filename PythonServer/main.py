# from wireless import Wireless
# wireless = Wireless() 
# wireless.connect(ssid='ssid', password='password') 

from http.server import BaseHTTPRequestHandler, HTTPServer
import logging
#import serial

#ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

class Server(BaseHTTPRequestHandler):
    def _set_response(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        if str(self.path) == "/move/fata/":
            #ser.write("Fata\n".encode('utf-8'))
            print("Fata")
        if str(self.path) == "/move/spate/":
           # ser.write("Spate\n".encode('utf-8'))
           print("Spate")
        if str(self.path) == "/move/stanga/": 
           # ser.write("Stanga\n".encode('utf-8'))
           print("Stanga")
        if str(self.path) == "/move/dreapta/": 
            #ser.write("Dreapta\n".encode('utf-8'))
            print("Dreapta")
        if str(self.path) == "/gheara/open/": 
            #ser.write("Open\n".encode('utf-8'))
            print("Open")
        if str(self.path) == "/gheara/close/": 
           # ser.write("Close\n".encode('utf-8'))
           print("Close")

        self._set_response()
        self.wfile.write("GET request for {}".format(self.path).encode('utf-8'))

def run(server_class=HTTPServer, handler_class=Server, port=8080):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    logging.info('Starting httpd...\n')
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    logging.info('Stopping httpd...\n')

if __name__ == '__main__':
    from sys import argv

    if len(argv) == 2:
        run(port=int(argv[1]))
    else:
        run()