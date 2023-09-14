from math import cos, sin, acos, sqrt, pi as PI
import sys
read = sys.stdin.readline

def latLon2xyz(lat, lon):
    cosLat = cos(lat)
    return [cosLat*cos(lon), cosLat*sin(lon), sin(lat)]

def product(dimension, coord1, coord2):
    result = 0
    for i in range(dimension):
        result += coord1[i] * coord2[i]
    return result

def main():
    R = 6371009
    T = int(read())
    for _ in range(T):
        lat1, lon1, lat2, lon2 = map(
            lambda x: float(x) * PI / 180, read().split())
        origin = latLon2xyz(lat1, lon1)
        destination = latLon2xyz(lat2, lon2)
        cosTheta = product(3, origin, destination)
        theta = acos(cosTheta)
        straight = sqrt(2 - 2 * cosTheta)
        result = R * (theta - straight)
        print(round(result))

main()