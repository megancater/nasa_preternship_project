#!/usr/bin/env python3

# carbon.py

import requests
from datetime import date, timedelta
import threading as th

# Constants
URL = 'https://api.carbonintensity.org.uk/intensity/date/'
keep_going = True

# Waits for keyboard press of 'enter' to quit
def key_capture_thread():
	global keep_going
	input()
	keep_going = False # ends data loading

# Loads carbon data from a specific day using the carbon intensity API
def load_carbon_data(url, day):
	# Generates the day's url
	url = url + day

	# Gets response data as json from url
	data = requests.get(url).json()

	# If an error is not returned, yield data from each half hour period
	if data.get('data', 0):
		for period in data['data']:
			yield str(period['intensity']['actual'])

def main():
	today = date.today()
	day = 1

	# Begins the wait for user input
	th.Thread(target=key_capture_thread, args=(), name='key_capture_thread', daemon=True).start()

	# Writes data to file for each day while user wants to keep going
	with open('carbon_data.txt', 'w+') as f:
		while keep_going:
			for data in load_carbon_data(URL, str(today - timedelta(day))):
				f.write(data + '\n')
			day = day + 1 # moves to previous day


if __name__ == '__main__':
	main()
