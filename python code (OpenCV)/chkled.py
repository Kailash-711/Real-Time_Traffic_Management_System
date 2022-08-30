import serial
import argparse
import time
parser = argparse.ArgumentParser(description='To Check LED')  
parser.add_argument('port', type=str, help='Com Port Arduino Board Connected To')
parser.add_argument('pin', type=str, help='Pin LED Connected To')
args = parser.parse_args()
ard=serial.Serial(args.port,9600,timeout=30)
time.sleep(2)

led = '#0#' + args.pin + ',B,0,1000,10000,#\n'
ard.write(led.encode('utf-8'))
ard.flush()
msg=ard.read_until()
if len(msg) > 0 :
    s=msg.decode('utf-8')
    print ( 'Read From Arduino - ', s )
else :
    print ( 'No Data Read From Arduino - '  + args.pin )
