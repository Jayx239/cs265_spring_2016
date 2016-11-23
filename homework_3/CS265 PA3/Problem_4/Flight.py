from __future__ import division

import re
import sys
from math import pow, sqrt


class FlightData:
    def __init__(self, windSpeed, height, windAngle, latitude, longitude, temperature, machNumber, speed,
                 minVerticalAcceleration, maxVerticalAcceleration, aircraftWeight):
        self.windSpeed = windSpeed
        self.height = height
        self.windAngle = windAngle
        self.latitude = latitude
        self.longitude = longitude
        self.temperature = temperature
        self.machNumber = machNumber
        self.speed = speed
        self.minVerticalAcceleration = minVerticalAcceleration
        self.maxVerticalAcceleration = maxVerticalAcceleration
        self.aircraftWeight = aircraftWeight


class Flight:
    def __init__(self, origin=None, destination=None):
        self.origin = origin
        self.destination = destination
        self.flights = []

    def add_flight(self, data):
        self.flights.append(data)

    def getAvgFlightHeight(self):
        sum = 0
        for flight_data in self.flights:
            sum += int(flight_data.height)

        return sum / len(self.flights)

    def getAvgWindSpeed(self):
        sum = 0

        for flight_data in self.flights:
            sum += int(flight_data.windSpeed)

        return sum / len(self.flights)

    def getAvgTemperature(self):
        sum = 0

        for flight_data in self.flights:
            sum += float(flight_data.temperature)

        return sum / len(self.flights)

    def getFlightHeightStd(self):
        sum = 0

        for flight_data in self.flights:
            sum += pow(float(flight_data.height) - float(self.getAvgFlightHeight()), 2)

        return sqrt(sum / len(self.flights))

    def getWindSpeedStd(self):
        sum = 0

        for flight_data in self.flights:
            sum += pow(float(flight_data.windSpeed) - float(self.getAvgWindSpeed()), 2)

        return sqrt(sum / len(self.flights))

    def getTemperatureStd(self):
        sum = 0

        for flight_data in self.flights:
            sum += pow(float(flight_data.temperature) - float(self.getAvgTemperature()), 2)

        return sqrt(sum / len(self.flights))


if (len(sys.argv) > 1) and (sys.argv[1] == 'Test'):
    print(
        "Flight should be from JNB to LHR. With a wind speed of 20 knots height of 28989 feet and temperature of -26 C")

flights = []

for line in sys.stdin:
    s = line.strip()
    s = re.sub("\s+", ",", s)
    l = s.split(',')
    flight = Flight()
    if s.startswith('ACMC'):
        flight = Flight(l[1], l[2])
        flights.append(flight)
    else:
        flight = flights[-1]
        flight.add_flight(FlightData(l[3], l[4], l[5], l[6], l[7], l[8], l[9], l[10], l[11], l[12], l[13]))

for f in flights:
    print(
        "Flight %s to %s\n\tAverage flight height: %d feet w/ std deviation of %.2f feet" %
        (f.origin, f.destination,
         f.getAvgFlightHeight(),
         f.getFlightHeightStd()))
    print(
        "\tAverage wind speed: %d knots w/ std deviation of %.2f knots" %
        (f.getAvgWindSpeed(),
         f.getWindSpeedStd()))

    print("\tAverage temperature: %.2f C w/ std deviation of %.2f C\n" %
          (f.getAvgTemperature(),
           f.getTemperatureStd()))
