import serial
import time
from SwSpotify import spotify

ser = serial.Serial('COM3', 9600)  # serial port

pause = ("No connection...")  # string displayed when pause
error = ("ERROR")  # string displayed when other error occur

while True:  # loop

    try:
        song = (spotify.song() + " - " + spotify.artist())  # code to try


    except spotify.SpotifyNotRunning:  # block of code executed when spotify is paused or closed
        ser.write(pause.encode())  # sends pause to serial port
        time.sleep(1)

    except:  # block of code executed when other error occur
        ser.write(error.encode())  # sends error to serial port
        time.sleep(1)

    else:  # block of code executed if no errors
        ser.write(song.encode())  # sends song to serial port
        time.sleep(1)
