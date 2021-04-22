#!/usr/bin/env python3

import os
import sys
import requests
import string

# Scrape real time temperature data, in degrees Celsius, from the internet

def load_weather(url):

	# Makes request to website data
	result = requests.get(url)
	
	# Makes file from gathered data
	data = result.text

	return data

# Converts the list created in data to a string to be able to parse through
def listToString(list):
	str = ''
	return(str.join(list))

# Uses parameters to isolate the temperature from the other HTML code and writes it to the file
def temperature(new):

	new = new.replace(" ","")

	new = new.rsplit()
	for line in new:
		if 'myforecast-current-sm' in line:
			newline = line
			info = (newline.split('>'))[1]
			if '&' in info:
				degree = (info.split('&'))[0]

				# Writes out to a file called weather_data.txt
				with open('weather_data.txt','a+') as f:
					f.write(degree + '\n')



def main():
	
	# Specify a range of temperatures based on zip code, this can vary based on user preference
	# Note: the program takes a while if you choose too many zipcodes
	for i in range(46556,46570):
		url = 'https://forecast.weather.gov/zipcity.php?inputstring='+str(i)
		data = load_weather(url)
		newstring = listToString(data)
		temperature(newstring)


if __name__ == '__main__':
	main()
